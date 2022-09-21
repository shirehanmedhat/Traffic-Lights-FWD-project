/*
 * PUSH_BUTTON.c
 *
 *  Created on: Sep 19, 2022
 *      Author: shire
 */
#include "../../MCAL/MISC/STD_Types.h"
#include "../../MCAL/MISC/Utils.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/EX_I/EX_I.h"
#include "../../MCAL/TIMERS/TIMER.h"
#include "PUSH_BUTTON.h"
void PUSH_BUTTON_INIT (void)
{
	DIO_u8SetPinDirection (DIO_u8_PORTD , DIO_u8_PIN2 , DIO_u8_INPUT);
}

