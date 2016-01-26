#ifndef APP_UART_H
  #define APP_UART_H


void UART0_Init(unsigned int speed);
int  UART0_send_buffer(char *buf, int len);
int  UART_wait_sym(unsigned int ticks);
int  UART_check_sym(void);
void UART_printf(const char *fmt, ...);

#endif // APP_UART_H



