#ifndef __mqx_tasks_H
  #define __mqx_tasks_H

  #include "PE_Types.h"
  #include "PE_Error.h"
  #include "PE_Const.h"
  #include "IO_Map.h"
  #include "GPIOA.h"
  #include "PORT.h"
  #include "PIT.h"
  #include "ADC.h"
  #include "SPI0.h"
  #include "MQX1.h"
  #include "SystemTimer1.h"

void Main_task(uint32_t task_init_data);

void Console_task(uint32_t task_init_data);


void RTT_printf(const char *fmt, ...);
void Get_unique_identificator(unsigned int *uid);

#endif

