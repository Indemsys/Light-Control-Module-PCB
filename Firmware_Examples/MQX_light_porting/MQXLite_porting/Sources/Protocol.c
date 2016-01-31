// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 2016.01.25
// 22:50:14
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include   "App.h"



/*------------------------------------------------------------------------------


 ------------------------------------------------------------------------------*/
int Protocol_function(void)
{
  int s;
  if (UART_check_sym() == 1)
  {
    s = UART_wait_sym(1);

    switch (s)
    {
    case '1':
      Gen_default_func1();
      UART_printf("Selected func1.\r\n");
      return 1;
    case '2':
      Gen_default_func2();
      UART_printf("Selected func2.\r\n");
      return 1;
    }
  }
  return 0;
}


