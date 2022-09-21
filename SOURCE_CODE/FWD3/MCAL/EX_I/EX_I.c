/*
 * EX_I.c
 *
 *  Created on: Sep 19, 2022
 *      Author: shirehan Medhat
 */

#include "../MISC/STD_Types.h"
#include "../MISC/Utils.h"
#include "../DIO/DIO.h"
#include "EX_I.h"
//#include "avr/interrupt.h"

void EXI0_INIT(void)
{
	DIO_u8SetPinDirection (DIO_u8_PORTD , DIO_u8_PIN2 , DIO_u8_INPUT );
	Set_Bit (MCUCR ,ISC01 );
  //Set_Bit (MCUCR ,ISC00 );
	Set_Bit (GICR ,INT0 );
	Set_Bit (SREG ,ISREG );

}
void EXI0_DISABLE (void)
{
	GICR &= ~ (1<<INT0);
}

void GLOBAL_INTERRUPT_ENABLE (void)
{
	Set_Bit (SREG ,ISREG );
}

void GLOBAL_INTERRUPT_DISABLE (void)
{
	Clr_Bit (SREG ,ISREG );
}

void SET_INTERRUPT_FLAGE (void)
{

	Set_Bit (GIFR ,INTF0 );
}




