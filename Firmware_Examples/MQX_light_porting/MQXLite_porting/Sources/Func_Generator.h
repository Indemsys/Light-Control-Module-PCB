#ifndef FUNC_GENERATOR_H
  #define FUNC_GENERATOR_H

  #define GMOD_IDLE              0
  #define GMOD_SWEEP_UP_OR_DOWN  1
  #define GMOD_SWEEP_UP_AND_DOWN 2

typedef struct
{
  int gen_mode;
  unsigned int min_freq;
  unsigned int max_freq;
  int          d_freq;
  unsigned int d_ticks;
  unsigned int freq;

} T_func_gen_cbl;

int  Gen_get_mode(void);
int  Gen_get_param(void);
void Gen_default_func1(void);
void Gen_default_func2(void);
void Gen_set_func(T_func_gen_cbl *pfgcbl);
void Gen_Freq_Sweep_Up_or_Down(void);
void Gen_Freq_Sweep_Up_and_Down(void);
void Functional_generator(void);

#endif // FUNC_GENERATOR_H



