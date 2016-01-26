#define _GLOBALS_
#include "Cpu.h"
#include "mqx_tasks.h"
#include "app.h"

static uint8_t f_init;
/*------------------------------------------------------------------------------



 \return int
 ------------------------------------------------------------------------------*/
2int main(void)
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
  UART0_Init(125000);
  ADC_prepere();
  Clear_display();
  // Выводим в интерфейс RTT информацию о чипе и его уникальный идентификатор
  Get_unique_identificator(uuid);
  UART_printf("\r\n\r\nS9KEAZN64AMLC (64 KB FLASH, 4 KB RAM) UUID=%08X-%08X\r\n", uuid[0], uuid[1]);

  //_task_ready(_task_get_td(_task_get_id_from_name( "console" )));


  f_init = 1;
  for (;;)
  {
    int gmode;

    gmode = Gen_get_mode();
    if (gmode == GMOD_IDLE)
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
    else
    {
      //Show_mnemonic(Mnemonic_f);
      //_time_delay_ticks(5);
      Show_int("%d", Gen_get_param());
      _time_delay_ticks(10);
    }
  }
}



/*------------------------------------------------------------------------------



 \param task_init_data
 ------------------------------------------------------------------------------*/
void Console_task(uint32_t task_init_data)
{
  while (f_init==0) _time_delay_ticks(1);

  Gen_default_func1();
  do
  {
    Functional_generator();
  }
  while (1);
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


