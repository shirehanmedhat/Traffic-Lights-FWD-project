/*
 * Utiles.h
 *
 *  Created on: Sep 19, 2022
 *      Author: shirehan Medhat
 */

#ifndef MISC_INC_UTILS_H_
#define MISC_INC_UTILS_H_

#define Set_Bit(Var,BitNo)   	Var |= (1<<BitNo)|Var
#define Clr_Bit(Var,BitNo)   	Var &= (~(1<<BitNo))
#define Toggle_Bit(Var,BitNo)	Var ^=(1<<BitNo))
#define Get_Bit(Var,BitNo)   	((Var>>BitNo)&1)

#endif /* MISC_INC_UTILS_H_ */
