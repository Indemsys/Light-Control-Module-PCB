#ifndef APP_H
  #define APP_H

#define BIT( val )  (1 << val)
#define LSHIFT( val, n ) ( val << n )

#define BIT_PTA0 BIT(0 )
#define BIT_PTA1 BIT(1 )
#define BIT_PTA2 BIT(2 )
#define BIT_PTA3 BIT(3 )
#define BIT_PTA4 BIT(4 )
#define BIT_PTA5 BIT(5 )
#define BIT_PTA6 BIT(6 )
#define BIT_PTA7 BIT(7 )
#define BIT_PTB0 BIT(8 )
#define BIT_PTB1 BIT(9 )
#define BIT_PTB2 BIT(10)
#define BIT_PTB3 BIT(11)
#define BIT_PTB4 BIT(12)
#define BIT_PTB5 BIT(13)
#define BIT_PTB6 BIT(14)
#define BIT_PTB7 BIT(15)
#define BIT_PTC0 BIT(16)
#define BIT_PTC1 BIT(17)
#define BIT_PTC2 BIT(18)
#define BIT_PTC3 BIT(19)
#define BIT_PTC4 BIT(20)
#define BIT_PTC5 BIT(21)
#define BIT_PTC6 BIT(22)
#define BIT_PTC7 BIT(23)
#define BIT_PTD0 BIT(24)
#define BIT_PTD1 BIT(25)
#define BIT_PTD2 BIT(26)
#define BIT_PTD3 BIT(27)
#define BIT_PTD4 BIT(28)
#define BIT_PTD5 BIT(29)
#define BIT_PTD6 BIT(30)
#define BIT_PTD7 BIT(31)

#define SEG_A  ( BIT( 7 ) )
#define SEG_B  ( BIT( 6 ) )
#define SEG_C  ( BIT( 5 ) )
#define SEG_D  ( BIT( 4 ) )
#define SEG_E  ( BIT( 3 ) )
#define SEG_F  ( BIT( 2 ) )
#define SEG_G  ( BIT( 1 ) )
#define SEG_H  ( BIT( 0 ) )


#define DISPLEN  3
#define RTT_STR_SZ 128
#define UART_STR_SZ 128


#define TSLOPE_LOW   0.003266
#define TSLOPE_HIGH  0.003638
#define T25VOLT      1.396
#define T25SMPL      1396


#include "intrinsics.h"
#include "stdio.h"
#include "stdarg.h"
#include "SKEAZN642.h"
#include "App_io.h"
#include "App_ADC.h"
#include "App_UART.h"
#include "PWM_gen.h"
#include "Indicator.h"
#include "Measurements.h"
#include "./RTT/SEGGER_RTT.h"

#ifdef _GLOBALS_

volatile unsigned int VAN_adcr;
volatile unsigned int VOLTAGE_adcr;
volatile unsigned int TEMPER_adcr;
volatile unsigned int INTTEMPER_adcr;

char rtt_str[RTT_STR_SZ+1];
char uart_str[UART_STR_SZ+1];

const unsigned char Mnemonic_t[] =
{
  SEG_D + SEG_E + SEG_F + SEG_G,
  SEG_G ,
  0
};
const unsigned char Mnemonic_v[] =
{
  SEG_C + SEG_D + SEG_E,
  SEG_G ,
  0
};

#else

extern volatile unsigned int VAN_adcr;
extern volatile unsigned int VOLTAGE_adcr;
extern volatile unsigned int TEMPER_adcr;
extern volatile unsigned int INTTEMPER_adcr;

extern char rtt_str[];
extern char uart_str[];

extern const unsigned char Mnemonic_t[];
extern const unsigned char Mnemonic_v[];
#endif


#endif // APP_H



