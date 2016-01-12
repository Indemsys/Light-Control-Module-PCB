#ifndef INDICATOR_H
  #define INDICATOR_H

void Application(void);
void SysTick_ISR_procedure(void);
void Show_float(const char *fmt, float val);
void Show_int(const char *fmt, int val);
void ADC_isr_procedure(void);

#endif // INDICATOR_H



