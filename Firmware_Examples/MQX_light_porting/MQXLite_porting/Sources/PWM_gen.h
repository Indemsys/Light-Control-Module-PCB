#ifndef PWM_GEN_H
  #define PWM_GEN_H


#define PWMFREQ 200
#define PWM_MODULO   (CPU_BUS_CLK_HZ_CONFIG_0/(2*2*PWMFREQ))
// 199 -> 20100
// 200 -> 20000
// 201 -> 19900

void PWM_init(void);
void Set_pwm_freq(unsigned int freq);

#endif // PWM_GEN_H



