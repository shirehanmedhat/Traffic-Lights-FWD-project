/*
 * main.c
 *
 *  Created on: Sep 19, 2022
 *      Author: shirehan Medhat
 */
#include "MCAL/MISC/STD_Types.h"
#include "MCAL/MISC/Utils.h"
#include "MCAL/DIO/DIO.h"
#include "MCAL/EX_I/EX_I.h"
#include "MCAL/TIMERS/TIMER.h"
#include "HAL/PUSH_BUTTON/PUSH_BUTTON.h"
#include "HAL/LEDS/LED.h"
#include "APPLICATION/APPLICATION.h"
#include <avr/interrupt.h>
volatile char FLAGE = 55 ; //Volatile to prevent the optimizer from deleting this variable

ISR (INT0_vect)
{
	EXI0_DISABLE ();
	FLAGE =  GET_PORT_STATE ();
	switch (FLAGE)
				{

				case 0x01:
					break;
				case 0x02:
				case 0x00:
					YELLOW_REEDING_WITH_PESS ();
					break;
				case 0x04:
					GREEN_REEDING_WITH_PESS ();
					break;


				}
	EXI0_INIT ();
	SET_INTERRUPT_FLAGE ();
}
int main (void)
{
	ALL_INIT ();

		while(1)
			{
			NORMAL_MODE ();

			}

	return 0;
}
