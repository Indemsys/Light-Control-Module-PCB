#ifndef APP_H
  #define APP_H

#include "stdint.h"
#include "Cpu.h"
#include "GPIOA.h"
#include "PORT.h"
#include "PIT.h"
#include "SysTick.h"
#include "ADC.h"
#include "SPI0.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#define BIT( val )  ((uint32_t)1 << val)
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

#define TSLOPE_LOW   0.003266
#define TSLOPE_HIGH  0.003638
#define T25VOLT      1.396
#define T25SMPL      1396

#define RTT_STR_SZ 128

#define EEPROM_START 0x10000000
#define EEPROM_SIZE  256

typedef struct
{
  uint16_t vcal;
  uint16_t tcal;
  uint32_t   vint;
  uint8_t  vch;
  unsigned long  vlng;
  float          f1;
  float          f2;
}
T_calibr_constants;


#ifdef _GLOBALS_

__no_init const T_calibr_constants vcal @ EEPROM_START;

volatile uint32_t VAN_adcr;
volatile uint32_t VOLTAGE_adcr;
volatile uint32_t TEMPER_adcr;
volatile uint32_t INTTEMPER_adcr;

int32_t                   tick_500ms;
char                  rtt_str[RTT_STR_SZ+1];

uint8_t Mnemonic_t[] =
{
  SEG_D + SEG_E + SEG_F + SEG_G,
  SEG_G ,
  0
};
uint8_t Mnemonic_v[] =
{
  SEG_C + SEG_D + SEG_E,
  SEG_G ,
  0
};


#else

extern const T_calibr_constants vcal;
extern volatile uint32_t VAN_adcr;
extern volatile uint32_t VOLTAGE_adcr;
extern volatile uint32_t TEMPER_adcr;
extern volatile uint32_t INTTEMPER_adcr;

extern int32_t            tick_500ms;
extern char           rtt_str[RTT_STR_SZ+1];

extern uint8_t Mnemonic_t[];
extern uint8_t Mnemonic_v[];

#endif


#include "intrinsics.h"
#include "stdio.h"
#include "stdarg.h"
#include "SKEAZN642.h"
#include "App_ADC.h"
#include "App_EEPROM.h"
#include "Indicator.h"
#include "Measurements.h"
#include "SEGGER_RTT.h"



void Get_unique_identificator(uint32_t *uid);
void RTT_printf(const char *fmt, ...);
void Cpu_OnNMIINT(void);


#endif // APP_H



