/*
 * main.c
 *
 *  Created on: Sep 30, 2020
 *      Author: Omar Fahmy
 */

/* HAL LAYER */
#include "../HAL/LCD/LCD_Interface.h"
/* MCAL LAYER */
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/Timer0/Timer0_Interface.h"
#include "../MCAL/Timer1/Timer1_Interface.h"
#include "../MCAL/Global Interrupt/GI_Interface.h"

#include <util/delay.h>

#define FCLK			8000000UL
/* Timer 1 settings */
#define PRESCALER		8UL
#define RESOLUTION		65536UL

u64 onCounts, offCounts;
u32 numOfOverflows;
u8 flag;

void ICU_ISR(void);
void OVF_ISR(void);

int main (void)
{
	f64 Ton, Toff, dutyCycle, frequency;

	Timer0_U8Init();
	Timer1_U8Init();
	LCD_U8Init();

	LCD_U8SendString("D.C. = ");
	LCD_U8SetPosition(LCD_FIRST_ROW, LCD_TWELFTH_COLUMN);
	LCD_U8SendString("%");
	LCD_U8SetPosition(LCD_SECOND_ROW, LCD_FIRST_COLUMN);
	LCD_U8SendString("Freq. = ");
	LCD_U8SetPosition(LCD_SECOND_ROW, LCD_FIFTEENTH_COLUMN);
	LCD_U8SendString("Hz");

	DIO_U8SetPinDirection(DIO_PORTB, DIO_PIN3, DIO_PIN_OUTPUT); // OC0 output
	DIO_U8SetPinDirection(DIO_PORTD, DIO_PIN6, DIO_PIN_INPUT); // ICP1

	Timer1_U8CaptureEventEnableInterrupt();
	Timer1_U8CaptureEventSetCallBack(ICU_ISR);

	Timer1_U8EnableOVFInterrupt();
	Timer1_U8OVFSetCallBack(OVF_ISR);

	Timer1_U8ICEdgeSelect(TIMER1_RISING_EDGE);
	/* Setting dutycycle to 100% would result in an always-high signal on the OC0 pin.
	 * Hence, timer1 will just keep overflowing and ICU interrupt will never be
	 * requested.
	 */
	Timer0_U8SetDutyCycle(50);

	Timer0_U8Start();
	Timer1_U8Start();
	GI_U8Enable();

	while (1)
	{
		if(flag == 3) /* Only if a complete period has been detected */
		{
			Ton = onCounts * PRESCALER * 1000.0 / FCLK;
			Toff = offCounts * PRESCALER * 1000.0 / FCLK;
			if (Ton + Toff != 0)
			{
				dutyCycle = (Ton * 100) / (Ton + Toff);
				frequency = 1000 / (Ton + Toff);
			}
			dutyCycle = (Ton * 100) / (Ton + Toff);
			frequency = 1000 / (Ton + Toff);
			LCD_U8SetPosition(LCD_FIRST_ROW, LCD_EIGHTH_COLUMN);
			LCD_U8SendNumber( dutyCycle );
			LCD_U8SetPosition(LCD_SECOND_ROW, LCD_NINTH_COLUMN);
			LCD_U8SendNumber( frequency );
			flag = 0;
		}
	}

	return 0;
}

void ICU_ISR(void)
{
	switch (flag)
	{
	case 0:
		Timer1_U8Preload(0); //Reset timer1
		Timer1_U8ICEdgeSelect(TIMER1_FALLING_EDGE);
		flag = 1;
		numOfOverflows = 0;
		break;

	case 1:
		Timer1_U8GetCapturedValue(&onCounts);
		onCounts += numOfOverflows * RESOLUTION;
		Timer1_U8ICEdgeSelect(TIMER1_RISING_EDGE);
		Timer1_U8Preload(0);
		numOfOverflows = 0;
		flag = 2;
		break;

	case 2:
		Timer1_U8GetCapturedValue(&offCounts);
		offCounts += numOfOverflows * RESOLUTION;
		Timer1_U8ICEdgeSelect(TIMER1_RISING_EDGE);
		flag = 3;
		break;
	}
}

void OVF_ISR(void)
{
	numOfOverflows++;
}
