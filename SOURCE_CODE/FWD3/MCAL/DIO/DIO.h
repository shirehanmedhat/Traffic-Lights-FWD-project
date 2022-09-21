/**********************************************************************/
/******************** Name    : Shirehan Medhat ***********************/
/******************** Date    : 19/9/2021     *************************/
/******************** SWC     : DIO           *************************/
/******************** Version : 1.0        ***************************/

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

/*Macros For Ports */
#define DIO_u8_PORTA  0
#define DIO_u8_PORTB  1
#define DIO_u8_PORTC  2
#define DIO_u8_PORTD  3

/*Macros For Pins*/
#define DIO_u8_PIN0   0
#define DIO_u8_PIN1   1
#define DIO_u8_PIN2   2
#define DIO_u8_PIN3   3
#define DIO_u8_PIN4   4
#define DIO_u8_PIN5   5
#define DIO_u8_PIN6   6
#define DIO_u8_PIN7   7

/*Macros For Pin Direction*/

#define DIO_u8_OUTPUT 1
#define DIO_u8_INPUT  0

/*Macros For Pin Value */
#define DIO_u8_HIGH 1
#define DIO_u8_LOW  0


u8 DIO_u8SetPinDirection  (u8 Copy_u8PortId, u8 Copy_u8PinId , u8 Copy_u8PinDirection);

u8 DIO_u8SetPinValue      (u8 Copy_u8PortId, u8 Copy_u8PinId , u8 Copy_u8PinValue);

u8 DIO_u8GetPinValue      (u8 Copy_u8PortId , u8 Copy_u8PinId,u8 *Copy_u8ReturnedPinValue );

u8 DIO_u8SetPortDirection (u8 Copy_u8PortId, u8 Copy_u8PortDirection);

u8 DIO_u8SetPortValue     (u8 Copy_u8PortId, u8 Copy_u8PortValue);

u8 DIO_u8GetPortValue      (u8 Copy_u8PortId , u8 *Copy_u8ReturnedPortValue );
/***************************************************************************/

#define DIO_u8_PORTA_REG  *((volatile u8*)0x3B)
#define DIO_u8_DDRA_REG   *((volatile u8*)0x3A)
#define DIO_u8_PINA_REG   *((volatile u8*)0x39)

#define DIO_u8_PORTB_REG  *((volatile u8*)0x38)
#define DIO_u8_DDRB_REG   *((volatile u8*)0x37)
#define DIO_u8_PINB_REG   *((volatile u8*)0x36)

#define DIO_u8_PORTC_REG  *((volatile u8*)0x35)
#define DIO_u8_DDRC_REG   *((volatile u8*)0x34)
#define DIO_u8_PINC_REG   *((volatile u8*)0x33)

#define DIO_u8_PORTD_REG  *((volatile u8*)0x32)
#define DIO_u8_DDRD_REG   *((volatile u8*)0x31)
#define DIO_u8_PIND_REG   *((volatile u8*)0x30)


#endif /* MCAL_DIO_DIO_H_ */
