/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : GPIOA.h
**     Project     : MQXLite_porting
**     Processor   : SKEAZN64MLC2
**     Component   : Init_GPIO
**     Version     : Component 01.006, Driver 01.06, CPU db: 3.00.000
**     Repository  : Kinetis
**     Compiler    : IAR ARM C Compiler
**     Date/Time   : 2016-01-20, 22:06, # CodeGen: 0
**     Abstract    :
**          This file implements the GPIO (GPIOA) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : GPIOA
**          Device                                         : GPIOA
**          Settings                                       : 
**            Pin 0                                        : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 1                                        : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : 0
**              Pull resistor                              : No initialization
**            Pin 2                                        : Do not initialize
**            Pin 3                                        : Do not initialize
**            Pin 4                                        : Do not initialize
**            Pin 5                                        : Do not initialize
**            Pin 6                                        : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 7                                        : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 8                                        : Initialize
**              Pin direction                              : Input
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 9                                        : Initialize
**              Pin direction                              : Input
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 10                                       : Initialize
**              Pin direction                              : Input
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 11                                       : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 12                                       : Initialize
**              Pin direction                              : Input
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 13                                       : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 14                                       : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 15                                       : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 16                                       : Initialize
**              Pin direction                              : Input
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 17                                       : Initialize
**              Pin direction                              : Input
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 18                                       : Initialize
**              Pin direction                              : Input
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 19                                       : Initialize
**              Pin direction                              : Input
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 20                                       : Do not initialize
**            Pin 21                                       : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 22                                       : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 23                                       : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 24                                       : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 25                                       : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 26                                       : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**            Pin 27                                       : Initialize
**              Pin direction                              : Output
**              Pin input                                  : Disabled
**              Output value                               : No initialization
**              Pull resistor                              : No initialization
**          Pin selection/routing                          : 
**            Pin 0                                        : Enabled
**              Pin                                        : PTA0/KBI0_P0/FTM0_CH0/ACMP0_IN0/ADC0_SE0
**              Pin signal                                 : 
**            Pin 1                                        : Enabled
**              Pin                                        : PTA1/KBI0_P1/FTM0_CH1/ACMP0_IN1/ADC0_SE1
**              Pin signal                                 : 
**            Pin 2                                        : Disabled
**            Pin 3                                        : Disabled
**            Pin 4                                        : Disabled
**            Pin 5                                        : Disabled
**            Pin 6                                        : Enabled
**              Pin                                        : PTA6/FTM2_FLT1/ACMP1_IN0/ADC0_SE2
**              Pin signal                                 : 
**            Pin 7                                        : Enabled
**              Pin                                        : PTA7/FTM2_FLT2/ACMP1_IN1/ADC0_SE3
**              Pin signal                                 : 
**            Pin 8                                        : Enabled
**              Pin                                        : PTB0/KBI0_P4/UART0_RX/ADC0_SE4
**              Pin signal                                 : 
**            Pin 9                                        : Enabled
**              Pin                                        : PTB1/KBI0_P5/UART0_TX/ADC0_SE5
**              Pin signal                                 : 
**            Pin 10                                       : Disabled
**            Pin 11                                       : Disabled
**            Pin 12                                       : Disabled
**            Pin 13                                       : Disabled
**            Pin 14                                       : Enabled
**              Pin                                        : PTB6/I2C0_SDA/XTAL
**              Pin signal                                 : 
**            Pin 15                                       : Enabled
**              Pin                                        : PTB7/I2C0_SCL/EXTAL
**              Pin signal                                 : 
**            Pin 16                                       : Enabled
**              Pin                                        : PTC0/FTM2_CH0/ADC0_SE8
**              Pin signal                                 : 
**            Pin 17                                       : Enabled
**              Pin                                        : PTC1/FTM2_CH1/ADC0_SE9
**              Pin signal                                 : 
**            Pin 18                                       : Enabled
**              Pin                                        : PTC2/FTM2_CH2/ADC0_SE10
**              Pin signal                                 : 
**            Pin 19                                       : Enabled
**              Pin                                        : PTC3/FTM2_CH3/ADC0_SE11
**              Pin signal                                 : 
**            Pin 20                                       : Disabled
**            Pin 21                                       : Enabled
**              Pin                                        : PTC5/FTM1_CH1/RTCO
**              Pin signal                                 : 
**            Pin 22                                       : Enabled
**              Pin                                        : PTC6/UART1_RX
**              Pin signal                                 : 
**            Pin 23                                       : Enabled
**              Pin                                        : PTC7/UART1_TX
**              Pin signal                                 : 
**            Pin 24                                       : Enabled
**              Pin                                        : PTD0/KBI1_P0/FTM2_CH2/SPI1_SCK
**              Pin signal                                 : 
**            Pin 25                                       : Enabled
**              Pin                                        : PTD1/KBI1_P1/FTM2_CH3/SPI1_MOSI
**              Pin signal                                 : 
**            Pin 26                                       : Enabled
**              Pin                                        : PTD2/KBI1_P2/SPI1_MISO
**              Pin signal                                 : 
**            Pin 27                                       : Enabled
**              Pin                                        : PTD3/KBI1_P3/SPI1_PCS0
**              Pin signal                                 : 
**          Initialization                                 : 
**            Call Init method                             : yes
**     Contents    :
**         Init - void GPIOA_Init(void);
**
**     Copyright : 1997 - 2015 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file GPIOA.h
** @version 01.06
** @brief
**          This file implements the GPIO (GPIOA) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup GPIOA_module GPIOA module documentation
**  @{
*/         

#ifndef GPIOA_H_
#define GPIOA_H_

/* MODULE GPIOA. */

/* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

/* Peripheral base address parameter */
#define GPIOA_DEVICE GPIOA_BASE_PTR

/* Peripheral port base address parameter */
#define GPIOA_PORT_DEVICE PORT_BASE_PTR



/*
** ===================================================================
**     Method      :  GPIOA_Init (component Init_GPIO)
**     Description :
**         This method initializes registers of the GPIO module
**         according to the Peripheral Initialization settings.
**         Call this method in user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void GPIOA_Init(void);


/* END GPIOA. */
#endif /* #ifndef __GPIOA_H_ */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
