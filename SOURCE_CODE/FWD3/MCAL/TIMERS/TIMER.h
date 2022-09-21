/*
 * TIMER.h
 *
 *  Created on: Sep 19, 2022
 *      Author: shirehan Medhat
 */

#ifndef MCAL_TIMERS_TIMER_H_
#define MCAL_TIMERS_TIMER_H_
//TIMER0 REGS
#define TCCR0 (*(volatile unsigned char*)0x53)
#define TCNT0 (*(volatile unsigned char*)0x52)
#define TIFR (*(volatile unsigned char*)0x58)
//MACOS FOR TIMER 0
#define TOV0 0
#define OCF0 1
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define WGM00 6
#define FOC0 7
//**************************/
void TIMER0_INIT_DELAY_halfseconds(char numOfhalfSeconds);

#endif /* MCAL_TIMERS_TIMER_H_ */
