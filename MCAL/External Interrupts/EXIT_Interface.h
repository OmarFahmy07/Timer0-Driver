/*
 * EXIT_Interface.h
 *
 *  Created on: Sep 14, 2020
 *      Author: Omar Fahmy
 */

#ifndef EXIT_INTERFACE_H_
#define EXIT_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

/**************************************************************************************/
/*					  USEFUL MACROS AS FUNCTIONS' ARGUMENTS						      */
/**************************************************************************************/
#define EXIT0_RISING_EDGE		3
#define EXIT0_FALLING_EDGE		2
#define EXIT0_LOGIC_CHANGE		1
#define EXIT0_LOW_LEVEL			0

#define EXIT1_RISING_EDGE		3
#define EXIT1_FALLING_EDGE		2
#define EXIT1_LOGIC_CHANGE		1
#define EXIT1_LOW_LEVEL			0

#define EXIT2_RISING_EDGE		3
#define EXIT2_FALLING_EDGE		2
/**************************************************************************************/


/**************************************************************************************/
/*							   FUNCTIONS PROTOTYPES								   	  */
/**************************************************************************************/

/**************************************************************************************/
/* Description: Initialize sense control for external interrupt 0				   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
extern u8 EXIT_U8EXIT0Init(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: set sense control for external interrupt 0						   	  */
/* Input      : source for triggering                                                 */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
u8 EXIT_U8EXIT0SenseControl(const u8 LOC_U8Source);
/**************************************************************************************/

/**************************************************************************************/
/* Description: enable interrupt for external interrupt 0						   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
extern u8 EXIT_U8EXIT0Enable(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: disable interrupt for external interrupt 0						   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
extern u8 EXIT_U8EXIT0Disable(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: takes a pointer to function that is to be executed on triggering	  */
/* external interrupt 0.									   						  */
/*	Inputs: pointer to a function that takes no arguments and returns no value	  	  */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
extern u8 EXIT_U8EXIT0SetCallBack(void (*LOC_VidPtrToFun)(void));
/**************************************************************************************/

/**************************************************************************************/
/* Description: Initialize sense control for external interrupt 1				   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
extern u8 EXIT_U8EXIT1Init(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: set sense control for external interrupt 1						   	  */
/* Input      : source for triggering                                                 */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
u8 EXIT_U8EXIT1SenseControl(const u8 LOC_U8Source);
/**************************************************************************************/

/**************************************************************************************/
/* Description: enable interrupt for external interrupt 1						   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
extern u8 EXIT_U8EXIT1Enable(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: disable interrupt for external interrupt 1						   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
extern u8 EXIT_U8EXIT1Disable(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: takes a pointer to function that is to be executed on triggering	  */
/* external interrupt 1.									   						  */
/*	Inputs: pointer to a function that takes no arguments and returns no value	  	  */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
extern u8 EXIT_U8EXIT1SetCallBack(void (*LOC_VidPtrToFun)(void));
/**************************************************************************************/

/**************************************************************************************/
/* Description: Initialize sense control for external interrupt 2				   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
extern u8 EXIT_U8EXIT2Init(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: set sense control for external interrupt 2						   	  */
/* Input      : source for triggering                                                 */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
u8 EXIT_U8EXIT2SenseControl(const u8 LOC_U8Source);
/**************************************************************************************/

/**************************************************************************************/
/* Description: enable interrupt for external interrupt 2						   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
extern u8 EXIT_U8EXIT2Enable(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: disable interrupt for external interrupt 2						   	  */
/* Input      : Nothing			                                                      */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
extern u8 EXIT_U8EXIT2Disable(void);
/**************************************************************************************/

/**************************************************************************************/
/* Description: takes a pointer to function that is to be executed on triggering	  */
/* external interrupt 2.									   						  */
/*	Inputs: pointer to a function that takes no arguments and returns no value	  	  */
/* Output     : Error Checking                                                        */
/**************************************************************************************/
extern u8 EXIT_U8EXIT2SetCallBack(void (*LOC_VidPtrToFun)(void));
/**************************************************************************************/


#endif /* EXIT_INTERFACE_H_ */
