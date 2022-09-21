/*
 * TIMER.c
 *
 *  Created on: Sep 19, 2022
 *      Author: shirehan Medhat
 */
#include "../MISC/STD_Types.h"
#include "../MISC/Utils.h"
#include "TIMER.h"
void TIMER0_INIT_DELAY_halfseconds(char numOfhalfSeconds)
{
	Set_Bit (TCCR0 , FOC0); // NOT PWM MODE
	Set_Bit (TCCR0 , CS00); //1024
	Set_Bit (TCCR0 , CS02);//1024
	TCNT0 =6; //
	for (char i=0 ; i<2*numOfhalfSeconds ; i++)
	{
		 while (TCNT0 !=250);
		 TCNT0=6;
	}

}

