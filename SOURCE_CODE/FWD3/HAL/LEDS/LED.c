/*
 * LED.c
 *
 *  Created on: Sep 19, 2022
 *      Author: shirehan Medhat
 */
#include "../../MCAL/MISC/STD_Types.h"
#include "../../MCAL/MISC/Utils.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/EX_I/EX_I.h"
#include "../../MCAL/TIMERS/TIMER.h"
#include "LED.h"

void CAR_LEDS_INIT (void)
{
	DIO_u8SetPinDirection (DIO_u8_PORTA , DIO_u8_PIN0 , DIO_u8_OUTPUT);
	DIO_u8SetPinDirection (DIO_u8_PORTA , DIO_u8_PIN1 , DIO_u8_OUTPUT);
	DIO_u8SetPinDirection (DIO_u8_PORTA , DIO_u8_PIN2 , DIO_u8_OUTPUT);
	DIO_u8SetPinValue (DIO_u8_PORTA , DIO_u8_PIN0 , DIO_u8_LOW);
	DIO_u8SetPinValue (DIO_u8_PORTA , DIO_u8_PIN1 , DIO_u8_LOW);
	DIO_u8SetPinValue (DIO_u8_PORTA , DIO_u8_PIN2 , DIO_u8_LOW);
}
void PEDSTRAINS_LEDS_INIT (void)
{
	 DIO_u8SetPinDirection (DIO_u8_PORTB , DIO_u8_PIN0 , DIO_u8_OUTPUT);
	 DIO_u8SetPinDirection (DIO_u8_PORTB , DIO_u8_PIN1 , DIO_u8_OUTPUT);
     DIO_u8SetPinDirection (DIO_u8_PORTB , DIO_u8_PIN2 , DIO_u8_OUTPUT);
     DIO_u8SetPinValue (DIO_u8_PORTB , DIO_u8_PIN0 , DIO_u8_LOW);
     DIO_u8SetPinValue (DIO_u8_PORTB , DIO_u8_PIN1 , DIO_u8_LOW);
     DIO_u8SetPinValue (DIO_u8_PORTB , DIO_u8_PIN2 , DIO_u8_LOW);
}

void LED_CAR_ON (char PIN_NUMBER)
{
	DIO_u8SetPinValue (DIO_u8_PORTA , PIN_NUMBER, DIO_u8_HIGH);
}

void LED_CAR_OFF (char PIN_NUMBER)
{
	DIO_u8SetPinValue (DIO_u8_PORTA , PIN_NUMBER, DIO_u8_LOW);
}

void LED_PEDSTRAINS_ON (char PIN_NUMBER)
{
	DIO_u8SetPinValue (DIO_u8_PORTB , PIN_NUMBER, DIO_u8_HIGH);
}

void LED_PEDSTRAINS_OFF (char PIN_NUMBER)
{
	DIO_u8SetPinValue (DIO_u8_PORTB , PIN_NUMBER, DIO_u8_LOW);
}

void CAR_PRIORITY (void)
{
	LED_CAR_ON (GREEN);
	LED_CAR_OFF (YELLOW);
	LED_CAR_OFF (RED);

	LED_PEDSTRAINS_ON (RED);
	LED_PEDSTRAINS_OFF (YELLOW);
	LED_PEDSTRAINS_OFF (GREEN);
}

void PEDSTRAINS_PRIORITY (void)
{
	    LED_PEDSTRAINS_ON (GREEN);
		LED_PEDSTRAINS_OFF (YELLOW);
		LED_PEDSTRAINS_OFF (RED);

		LED_CAR_ON (RED);
		LED_CAR_OFF (YELLOW);
		LED_CAR_OFF (GREEN);

}

void YELLOW_BLINK (void)
{
	char i=0;
	for ( ;i<5 ;i++)
	{
	LED_PEDSTRAINS_ON (YELLOW);
	LED_CAR_ON (YELLOW);
	TIMER0_INIT_DELAY_halfseconds(HALF_SECOND);
	LED_PEDSTRAINS_OFF (YELLOW);
	LED_CAR_OFF (YELLOW);
	TIMER0_INIT_DELAY_halfseconds(HALF_SECOND);
	}
}
void TRANSIENT_CASE (void)
{
	LED_CAR_OFF (GREEN);
	LED_CAR_OFF (RED);

	LED_PEDSTRAINS_OFF (GREEN);
	LED_PEDSTRAINS_OFF (RED);
	YELLOW_BLINK ();

}

char GET_PORT_STATE (void)
{
	return DIO_u8_PINA_REG ;

}
