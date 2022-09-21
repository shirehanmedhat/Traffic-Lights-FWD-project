/*
 * APPLICATION.c
 *
 *  Created on: Sep 19, 2022
 *      Author: shirehan Medhat
 */
#include "../MCAL/MISC/STD_Types.h"
#include "../MCAL/MISC/Utils.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/EX_I/EX_I.h"
#include "../MCAL/TIMERS/TIMER.h"
#include "../HAL/LEDS/LED.h"
#include "../HAL/PUSH_BUTTON/PUSH_BUTTON.h"
#include "APPLICATION.h"
void ALL_INIT ()
{
	EXI0_INIT ();
	PUSH_BUTTON_INIT ();
    CAR_LEDS_INIT ();
    PEDSTRAINS_LEDS_INIT ();
}

void NORMAL_MODE (void)
{
	CAR_PRIORITY ();
	TIMER0_INIT_DELAY_halfseconds (FIVE_SECONS);
	TRANSIENT_CASE ();
	PEDSTRAINS_PRIORITY ();
	TIMER0_INIT_DELAY_halfseconds (FIVE_SECONS);
	TRANSIENT_CASE ();
}


void GREEN_REEDING_WITH_PESS (void)
{
	TIMER0_INIT_DELAY_halfseconds (FIVE_SECONS);
	TRANSIENT_CASE ();
	PEDSTRAINS_PRIORITY ();
	TIMER0_INIT_DELAY_halfseconds (FIVE_SECONS);
	TRANSIENT_CASE ();
	NORMAL_MODE ();
}


void YELLOW_REEDING_WITH_PESS (void)
{
	TRANSIENT_CASE ();
	PEDSTRAINS_PRIORITY ();
	TIMER0_INIT_DELAY_halfseconds (FIVE_SECONS);
	TRANSIENT_CASE ();
	NORMAL_MODE ();

}


