/*
 * EX_I.h
 *
 *  Created on: Sep 19, 2022
 *      Author: shirehan Medhat
 */

#ifndef MCAL_EX_I_EX_I_H_
#define MCAL_EX_I_EX_I_H_
/*MACROS FOR REISTERS */
#define MCUCR    *((volatile u8*)0x55)       //Control Register
#define GICR     *((volatile u8*)0x5B)       // Enable EXI
#define GIFR     *((volatile u8*)0x5A)       // Flag
#define SREG	 *((volatile u8*)0x5f)       // GLOBAL Interrupt
/****************************************************************************/
/*MACROS FOR BITS*/
#define ISREG         7		// I BIT
#define ISC01         1		//Sense Control
#define ISC00         0		//Sense Control
#define INT0          6		//INT0 Enable
#define INTF0         6		// INT0 FLAGE
/*********************************************************************/
void EXI0_INIT(void);
void EXI0_DISABLE (void);
void GLOBAL_INTERRUPT_ENABLE (void);
void GLOBAL_INTERRUPT_DISABLE (void);
void SET_INTERRUPT_FLAGE (void);



void EXI0_INIT(void);
void EXI0_DISABLE (void);





#endif /* MCAL_EX_I_EX_I_H_ */
