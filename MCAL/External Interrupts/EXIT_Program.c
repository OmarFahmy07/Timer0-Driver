/*
 * EXIT_Program.c
 *
 *  Created on: Sep 14, 2020
 *      Author: Omar Fahmy
 */

/*	LIB LAYER */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../../LIB/STD_TYPES.h"
/* MCAL LAYER */
#include "../External Interrupts/EXIT_Configure.h"
#include "../External Interrupts/EXIT_Private.h"

/* Array of Global Pointers to Functions for Calling Back */
void (*GLOB_VidINTPtrCallBack[NUM_OF_EX_INTERRUPTS])(void) = {NULL, NULL, NULL};

/************************************************************************************/
/*						PUBLIC FUNCTIONS IMPLEMENTATION								*/
/************************************************************************************/

u8 EXIT_U8EXIT0Init(void)
{
	/* Configure Sense Control */
#if EXIT0_SENSE_CONTROL == LOW_LEVEL
	CLR_BIT(MCUCR, ISC00);
	CLR_BIT(MCUCR, ISC01);
#elif EXIT0_SENSE_CONTROL == LOGIC_CHANGE
	SET_BIT(MCUCR, ISC00);
	CLR_BIT(MCUCR, ISC01);
#elif EXIT0_SENSE_CONTROL == FALLING_EDGE
	CLR_BIT(MCUCR, ISC00);
	SET_BIT(MCUCR, ISC01);
#elif EXIT0_SENSE_CONTROL == RISING_EDGE
	SET_BIT(MCUCR, ISC00);
	SET_BIT(MCUCR, ISC01);
#else
#error "Incorrect sense control configuration for external interrupt 0"
#endif
	return NO_ERROR;
}

u8 EXIT_U8EXIT0SenseControl(const u8 LOC_U8Source)
{
	if (LOC_U8Source == LOW_LEVEL)
	{
		CLR_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);
		return NO_ERROR;
	}
	else if (LOC_U8Source == LOGIC_CHANGE)
	{
		SET_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);
		return NO_ERROR;
	}
	else if (LOC_U8Source == FALLING_EDGE)
	{
		CLR_BIT(MCUCR, ISC00);
		SET_BIT(MCUCR, ISC01);
		return NO_ERROR;
	}
	else if (LOC_U8Source == RISING_EDGE)
	{
		SET_BIT(MCUCR, ISC00);
		SET_BIT(MCUCR, ISC01);
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}


u8 EXIT_U8EXIT0Enable(void)
{
	/* Peripheral Interrupt Enable */
	SET_BIT(GICR, INT0);
	return NO_ERROR;
}

u8 EXIT_U8EXIT0Disable(void)
{
	/* Peripheral Interrupt Disable */
	CLR_BIT(GICR, INT0);
	return NO_ERROR;
}

u8 EXIT_U8EXIT0SetCallBack(void (*LOC_VidPtrToFun)(void))
{
	if ( LOC_VidPtrToFun != NULL)
	{
		/* Set the global pointer to point to the passed function */
		GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT0] = LOC_VidPtrToFun;
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}

u8 EXIT_U8EXIT1Init(void)
{
	/* Configure Sense Control */
#if EXIT1_SENSE_CONTROL == LOW_LEVEL
	CLR_BIT(MCUCR, ISC11);
	CLR_BIT(MCUCR, ISC10);
#elif EXIT1_SENSE_CONTROL == LOGIC_CHANGE
	SET_BIT(MCUCR, ISC10);
	CLR_BIT(MCUCR, ISC11);
#elif EXIT1_SENSE_CONTROL == FALLING_EDGE
	CLR_BIT(MCUCR, ISC10);
	SET_BIT(MCUCR, ISC11);
#elif EXIT1_SENSE_CONTROL == RISING_EDGE
	SET_BIT(MCUCR, ISC11);
	SET_BIT(MCUCR, ISC10);
#else
#error "Incorrect sense control configuration for external interrupt 1"
#endif
	return NO_ERROR;
}

u8 EXIT_U8EXIT1SenseControl(const u8 LOC_U8Source)
{
	if (LOC_U8Source == LOW_LEVEL)
	{
		CLR_BIT(MCUCR, ISC11);
		CLR_BIT(MCUCR, ISC10);
		return NO_ERROR;
	}
	else if (LOC_U8Source == LOGIC_CHANGE)
	{
		SET_BIT(MCUCR, ISC10);
		CLR_BIT(MCUCR, ISC11);
		return NO_ERROR;
	}
	else if (LOC_U8Source == FALLING_EDGE)
	{
		CLR_BIT(MCUCR, ISC10);
		SET_BIT(MCUCR, ISC11);
		return NO_ERROR;
	}
	else if (LOC_U8Source == RISING_EDGE)
	{
		SET_BIT(MCUCR, ISC11);
		SET_BIT(MCUCR, ISC10);
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}

u8 EXIT_U8EXIT1Enable(void)
{
	/* Peripheral Interrupt Enable */
	SET_BIT(GICR, INT1);
	return NO_ERROR;
}

u8 EXIT_U8EXIT1Disable(void)
{
	/* Peripheral Interrupt Disable */
	CLR_BIT(GICR, INT1);
	return NO_ERROR;
}

u8 EXIT_U8EXIT1SetCallBack(void (*LOC_VidPtrToFun)(void))
{
	if ( LOC_VidPtrToFun != NULL)
	{
		/* Set the global pointer to point to the passed function */
		GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT1] = LOC_VidPtrToFun;
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}

u8 EXIT_U8EXIT2Init(void)
{
	/* When Changing the ISC2 bit, an interrupt can occur. Therefore, it is recommended
	 * to first disable INT2 by clearing its interrupt Enable bit in GICR. Then, the
	 * ISC2 bit can be changed. Finally, the INT2 Interrupt Flag should be cleared by
	 * writing a logical one to its Interrupt Flag bit (INTF2) in GIFR before the
	 * interrupt is re-enabled
	 */
	CLR_BIT(GICR, INT2);
	/* Configure Sense Control */
#if EXIT2_SENSE_CONTROL == FALLING_EDGE
	CLR_BIT(MCUCSR, ISC2);
#elif EXIT2_SENSE_CONTROL == RISING_EDGE
	SET_BIT(MCUCSR, ISC2);
#else
#error "Incorrect sense control configuration for external interrupt 2"
#endif
	/* CLEAR INT2 Interrupt Flag */
	SET_BIT(GIFR, INTF2);
	return NO_ERROR;
}

u8 EXIT_U8EXIT2SenseControl(const u8 LOC_U8Source)
{
	/* When Changing the ISC2 bit, an interrupt can occur. Therefore, it is recommended
	 * to first disable INT2 by clearing its interrupt Enable bit in GICR. Then, the
	 * ISC2 bit can be changed. Finally, the INT2 Interrupt Flag should be cleared by
	 * writing a logical one to its Interrupt Flag bit (INTF2) in GIFR before the
	 * interrupt is re-enabled
	 */
	CLR_BIT(GICR, INT2);
	if (LOC_U8Source == FALLING_EDGE)
	{
		CLR_BIT(MCUCSR, ISC2);
		/* CLEAR INT2 Interrupt Flag */
		SET_BIT(GIFR, INTF2);
		return NO_ERROR;
	}
	else if (LOC_U8Source == RISING_EDGE)
	{
		SET_BIT(MCUCSR, ISC2);
		/* CLEAR INT2 Interrupt Flag */
		SET_BIT(GIFR, INTF2);
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}

u8 EXIT_U8EXIT2Enable(void)
{
	/* Peripheral Interrupt Enable */
	SET_BIT(GICR, INT2);
	return NO_ERROR;
}

u8 EXIT_U8EXIT2Disable(void)
{
	/* Peripheral Interrupt Disable */
	CLR_BIT(GICR, INT2);
	return NO_ERROR;
}

u8 EXIT_U8EXIT2SetCallBack(void (*LOC_VidPtrToFun)(void))
{
	if ( LOC_VidPtrToFun != NULL)
	{
		/* Set the global pointer to point to the passed function */
		GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT2] = LOC_VidPtrToFun;
		return NO_ERROR;
	}
	else
	{
		return ERROR;
	}
}

/************************************************************************************/
/*						PRIVATE FUNCTIONS IMPLEMENTATION							*/
/************************************************************************************/

/* Interrupt Service Routine (ISR) of external interrupt 0 */
void __vector_1 (void)
{
	if (GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT0] != NULL)
	{
		(*GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT0])();
	}
}

/* Interrupt Service Routine (ISR) of external interrupt 1 */
void __vector_2 (void)
{
	if (GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT1] != NULL)
	{
		(*GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT1])();
	}
}

/* Interrupt Service Routine (ISR) of external interrupt 2 */
void __vector_3 (void)
{
	if (GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT2] != NULL)
	{
		(*GLOB_VidINTPtrCallBack[EXTERNAL_INTERRUPT2])();
	}
}
