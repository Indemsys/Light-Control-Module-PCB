// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 2016.01.25
// 22:02:10
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#include "App.h"
#include "Cpu.h"
#include "mqx_tasks.h"



T_func_gen_cbl fgcbl;

/*------------------------------------------------------------------------------



 \param ticks
 ------------------------------------------------------------------------------*/
static int Delay_ticks(unsigned int ticks)
{
  int i;
  for (i = 0; i < ticks; i++)
  {
    // Здесь обслуживаем протоко обмена с компьютером
    if (Protocol_function() != 0) return 1;
    _time_delay_ticks(1);
  }
  return 0;
}

/*------------------------------------------------------------------------------



 \return int
 ------------------------------------------------------------------------------*/
int Gen_get_mode(void)
{
  return fgcbl.gen_mode;
}

/*------------------------------------------------------------------------------



 \return int
 ------------------------------------------------------------------------------*/
int Gen_get_param(void)
{
  switch (fgcbl.gen_mode)
  {
  case GMOD_SWEEP_UP_OR_DOWN:
    return fgcbl.freq;
  case GMOD_SWEEP_UP_AND_DOWN:
    return fgcbl.freq;
  }
  return 0;
}
/*------------------------------------------------------------------------------


 ------------------------------------------------------------------------------*/
void Gen_set_func(T_func_gen_cbl *pfgcbl)
{
  memcpy(&fgcbl, pfgcbl, sizeof(fgcbl));
}

/*------------------------------------------------------------------------------


 ------------------------------------------------------------------------------*/
void Gen_default_func1(void)
{
  fgcbl.gen_mode = GMOD_SWEEP_UP_OR_DOWN;
  fgcbl.min_freq = 100;
  fgcbl.max_freq = 300;
  fgcbl.d_freq = 1;
  fgcbl.d_ticks = 10;
}

/*------------------------------------------------------------------------------


 ------------------------------------------------------------------------------*/
void Gen_default_func2(void)
{
  fgcbl.gen_mode = GMOD_SWEEP_UP_AND_DOWN;
  fgcbl.min_freq = 100;
  fgcbl.max_freq = 300;
  fgcbl.d_freq = 1;
  fgcbl.d_ticks = 1;
}
/*-------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------*/
void Gen_Freq_Sweep_Up_or_Down(void)
{
  fgcbl.freq = fgcbl.min_freq;
  while (1)
  {
    Set_pwm_freq(fgcbl.freq);
    fgcbl.freq = fgcbl.freq + fgcbl.d_freq;
    if (fgcbl.freq > fgcbl.max_freq)
    {
      fgcbl.freq = fgcbl.min_freq;
    }
    if (fgcbl.freq < fgcbl.min_freq)
    {
      fgcbl.freq = fgcbl.max_freq;
    }
    if (Delay_ticks(fgcbl.d_ticks) != 0) return;
  }
}

/*-------------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------------*/
void Gen_Freq_Sweep_Up_and_Down(void)
{
  fgcbl.freq = fgcbl.min_freq;
  while (1)
  {
    Set_pwm_freq(fgcbl.freq);
    fgcbl.freq = fgcbl.freq + fgcbl.d_freq;
    if (fgcbl.freq > fgcbl.max_freq)
    {
      fgcbl.d_freq = -fgcbl.d_freq;
      fgcbl.freq = fgcbl.max_freq;
    }
    if (fgcbl.freq < fgcbl.min_freq)
    {
      fgcbl.d_freq = -fgcbl.d_freq;
      fgcbl.freq = fgcbl.min_freq;
    }
    if (Delay_ticks(fgcbl.d_ticks) != 0) return;
  }
}

/*------------------------------------------------------------------------------


 ------------------------------------------------------------------------------*/
void Functional_generator(void)
{
  switch (fgcbl.gen_mode)
  {
  case GMOD_SWEEP_UP_OR_DOWN:
    Gen_Freq_Sweep_Up_or_Down();
    break;
  case GMOD_SWEEP_UP_AND_DOWN:
    Gen_Freq_Sweep_Up_and_Down();
    break;
  }
}
