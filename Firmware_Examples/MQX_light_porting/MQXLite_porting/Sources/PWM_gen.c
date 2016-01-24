// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 2016.01.23
// 16:06:26
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include   "cpu.h"
#include   "app.h"




/*-------------------------------------------------------------------------------------------------------------
  Инициализация модуля тамера FTM2 генерирующего сигнал ШИМ для соленоидов
-------------------------------------------------------------------------------------------------------------*/
void PWM_init(void)
{
  FTM_MemMapPtr FTM2 = FTM2_BASE_PTR;

  // Разрешаем тактирование FTM2
  SIM_SCGC |= BIT(7); // Bus clock to the FTM2 module is enabled.


  // Включаем полную функциональность модуля таймера и разрешаем запись во все поля регистров
  FTM2->MODE = 0
               + LSHIFT(0, 7) // FAULTIE | Fault Interrupt Enable   |
               + LSHIFT(0, 5) // FAULTM  | Fault Control Mode       | 00 Fault control is disabled for all channels.
               + LSHIFT(0, 4) // CAPTEST | Capture Test Mode Enable
               + LSHIFT(0, 3) // PWMSYNC | PWM Synchronization Mode
               + LSHIFT(1, 2) // WPDIS   | Write Protection Disable | 1 Write protection is disabled.
               + LSHIFT(0, 1) // INIT    | Initialize the Channels Output | When a 1 is written to INIT bit the channels output is initialized according to the state of their corresponding bit in the OUTINIT register
               + LSHIFT(1, 0) // FTMEN   | FTM Enable | 1 All registers including the FTM-specific registers (second set of registers) are available for use with no restrictions.
  ;

  FTM2->CONF = 0
               + LSHIFT(0, 10) // GTBEOUT | Global time base output
               + LSHIFT(0, 9)  // GTBEEN  | Global time base enable
               + LSHIFT(3, 6)  // BDMMODE | Selects the FTM behavior in BDM mode | В режиме отладки сохраняется полная выходов FTM
               + LSHIFT(0, 0)  // NUMTOF  | TOF Frequency | NUMTOF = 0: The TOF bit is set for each counter overflow.
  ;

  // Таймер остановлен
  FTM2->SC = 0
             + LSHIFT(0, 7) // TOF   | 1 FTM counter has overflowed. | Сброс в 0
             + LSHIFT(0, 6) // TOIE  | 1 Enable TOF interrupts. An interrupt is generated when TOF equals one.
             + LSHIFT(1, 5) // CPWMS | 1 FTM counter operates in up-down counting mode.
             + LSHIFT(0, 3) // CLKS  | 00 Модуль таймера остановлен
             + LSHIFT(1, 0) // PS    | Prescale Factor Selection. 000 Divide by 1. Предделитель = 1, 001 Divide by 2
  ;

  FTM2->SYNCONF = 0
                  + LSHIFT(0, 20) // HWSOC.      1 A hardware trigger activates the SWOCTRL register synchronization.
                  + LSHIFT(0, 19) // HWINVC.     1 A hardware trigger activates the INVCTRL register synchronization.
                  + LSHIFT(0, 18) // HWOM.       1 A hardware trigger activates the OUTMASK register synchronization.
                  + LSHIFT(0, 17) // HWWRBUF.    1 A hardware trigger activates MOD, CNTIN, and CV registers synchronization.
                  + LSHIFT(0, 16) // HWRSTCNT.   1 A hardware trigger activates the FTM counter synchronization.
                  + LSHIFT(0, 12) // SWSOC.      1 The software trigger activates the SWOCTRL register synchronization.
                  + LSHIFT(0, 11) // SWINVC.     1 The software trigger activates the INVCTRL register synchronization.
                  + LSHIFT(1, 10) // SWOM.       1 The software trigger activates the OUTMASK register synchronization.
                  + LSHIFT(1, 9) // SWWRBUF.    1 The software trigger activates MOD, CNTIN, and CV registers synchronization
                  + LSHIFT(1, 8) // SWRSTCNT.   1 обновления регистров MOD, CNTIN, and CV произойдет сразу после установки флага SWSYNC. Если 0, то в точке загрузки при установленном флаге SWSYNC.
                  + LSHIFT(1, 7) // SYNCMODE.   1 Enhanced PWM synchronization is selected.
                  + LSHIFT(0, 5) // SWOC.       1 SWOCTRL регистр будет обновлен в точке зугрузки при наличии флага синхронизации, если 0 то будет обновлен сразу
                  + LSHIFT(0, 4) // INVC.       1 INVCTRL регистр будет обновлен в точке зугрузки при наличии флага синхронизации, если 0 то будет обновлен сразу
                  + LSHIFT(0, 2) // CNTINC.     1 CNTIN регистр будет обновлен в точке зугрузки при наличии флага синхронизации, если 0 то будет обновлен сразу
                  + LSHIFT(0, 1) // HWTRIGMODE. 1 FTM does not clear the TRIGj bit when the hardware trigger j is detected.
  ;



  FTM2->MOD = PWM_MODULO;    // Установка регистра перезагрузки.
  FTM2->CNTIN = 0;    // Начальное значение счетчика
  FTM2->CNT = 0;    // Запись в регистр счетчка любого значения приводит к записи значения из CNTIN и установке начального состояния выходов
  FTM2->OUTINIT = 0;    //
  FTM2->OUTMASK = 0;    //
  FTM2->COMBINE = 0;
  FTM2->DEADTIME = 0;
  FTM2->INVCTRL = 0;

  FTM2->FILTER = 0;     // Фильтры не используем


  FTM2->CONTROLS[0].CnV = 0;
  FTM2->CONTROLS[1].CnV = 0;

  FTM2->CONTROLS[0].CnSC = 0
                           + LSHIFT(0, 6) // CHIE. 0 Disable channel interrupts. Use software polling.
                           + LSHIFT(1, 3) // ELSB. Edge or Level Select. ELSB=1,ELSA=0 - установка низкого уровня на входе при совпадении
                           + LSHIFT(0, 2) // ELSA. Edge or Level Select  ELSB=1,ELSA=1 - установка высокого уровня на входе при совпадении
                           + LSHIFT(0, 0) // DMA.  0 Disable DMA transfers.
  ;
  FTM2->CONTROLS[1].CnSC = 0
                           + LSHIFT(0, 6) // CHIE. 0 Disable channel interrupts. Use software polling.
                           + LSHIFT(1, 3) // ELSB. Edge or Level Select
                           + LSHIFT(0, 2) // ELSA. Edge or Level Select
                           + LSHIFT(0, 0) // DMA.  0 Disable DMA transfers.
  ;


  FTM2->SYNC = 0
               + LSHIFT(1, 7)  // SWSYNC  | PWM Synchronization Software Trigger. The software trigger happens when a 1 is written to this bit.
               + LSHIFT(0, 6)  // TRIG2   | PWM Synchronization Hardware Trigger 2
               + LSHIFT(0, 5)  // TRIG1   | PWM Synchronization Hardware Trigger 1
               + LSHIFT(0, 4)  // TRIG0   | PWM Synchronization Hardware Trigger 0
               + LSHIFT(0, 3)  // SYNCHOM | 0 OUTMASK register is updated with the value of its buffer in all rising edges of the system clock
               + LSHIFT(0, 2)  // REINIT  | FTM Counter Reinitialization by Synchronization | 0 FTM counter continues to count normally.
               + LSHIFT(0, 1)  // CNTMAX  | 1 The maximum loading point is enabled.
               + LSHIFT(0, 0)  // CNTMIN  | 1 The minimum loading point is enabled
  ;

  FTM2->SWOCTRL = 0x00; // Выходы включены

  // Запускаем системный тактирующий сигнал на таймер
  FTM2->SC = 0
             + LSHIFT(0, 6) // TOIE. 1 Enable TOF interrupts. An interrupt is generated when TOF equals one.
             + LSHIFT(1, 5) // CPWMS. 1 -FTM counter operates in up-down counting mode.
             + LSHIFT(1, 3) // CLKS. 01 System clock
             + LSHIFT(0, 0) // PS. Prescale Factor Selection. 000 Divide by 1
  ;
}


