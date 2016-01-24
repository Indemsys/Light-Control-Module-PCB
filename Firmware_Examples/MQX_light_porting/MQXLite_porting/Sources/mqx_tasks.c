#define _GLOBALS_
#include "Cpu.h"
#include "mqx_tasks.h"
#include "app.h"

/*------------------------------------------------------------------------------



 \return int
 ------------------------------------------------------------------------------*/
int main(void)
{
  PE_low_level_init(); // Обязательный вызов внутри которого будет вызвана функция _mqxlite_init
  _mqxlite();          // Запуск операционной системы
}



/*------------------------------------------------------------------------------



 \param task_init_data
 ------------------------------------------------------------------------------*/
void Main_task(uint32_t task_init_data)
{
  float f;
  unsigned int uuid[2];

  PWM_init();
  ADC_prepere();
  Clear_display();
  // Выводим в интерфейс RTT информацию о чипе и его уникальный идентификатор
  Get_unique_identificator(uuid);
  RTT_printf("\r\n\r\nS9KEAZN64AMLC (64 KB FLASH, 4 KB RAM) UUID=%08X-%08X\r\n", uuid[0], uuid[1]);

  //_task_ready(_task_get_td(_task_get_id_from_name( "console" )));

  for (;;)
  {
    Show_mnemonic(Mnemonic_t);
    _time_delay_ticks(50);

    f = Get_internal_temperature();
    Show_float("%0.1f", f);
    _time_delay_ticks(200);

    Show_mnemonic(Mnemonic_v);
    _time_delay_ticks(50);

    f = Get_power_voltage();
    Show_float("%0.1f", f);
    _time_delay_ticks(200);
  }
}



/*------------------------------------------------------------------------------



 \param task_init_data
 ------------------------------------------------------------------------------*/
void Console_task(uint32_t task_init_data)
{
  int counter = 0;
  unsigned int freq;

  freq = 100;

  while (1)
  {
    counter++;

    _time_delay_ticks(10);

    Set_pwm_freq(freq);

    freq++;
    if (freq==300)
    {
      freq = 100;
    }
  }
}

/*------------------------------------------------------------------------------
  Выводим форматированную строку в RTT
 \param BufferIndex
 \param sFormat
 ------------------------------------------------------------------------------*/
void RTT_printf(const char *fmt, ...)
{
  int n;
  va_list           ap;
  va_start(ap, fmt);
  n = vsnprintf(rtt_str, RTT_STR_SZ, (char *)fmt, ap);
  va_end(ap);
  SEGGER_RTT_Write(0, rtt_str, n);
}

/*------------------------------------------------------------------------------



 \param uid
 ------------------------------------------------------------------------------*/
void Get_unique_identificator(unsigned int *uid)
{
  SIM_MemMapPtr  SIM  = SIM_BASE_PTR;

  uid[0] = SIM->UUIDH;
  uid[1] = SIM->UUIDL;
}


