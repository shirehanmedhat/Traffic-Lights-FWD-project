/**********************************************************************/
/******************** Name    : Shirehan Medhat ***********************/
/******************** Date    : 19/9/2021     *************************/
/******************** SWC     : DIO           *************************/
/******************** Version : 1.0        ***************************/


#include "../MISC/STD_Types.h"
#include "../MISC/Utils.h"
#include "DIO.h"




u8 DIO_u8SetPinDirection  (u8 Copy_u8PortId, u8 Copy_u8PinId , u8 Copy_u8PinDirection)
{
	u8 Local_u8ErrorState=STD_TYPES_OK ;
	if((Copy_u8PortId <= DIO_u8_PORTD) && (Copy_u8PinId <= DIO_u8_PIN7) && ((Copy_u8PinDirection == DIO_u8_OUTPUT) || (Copy_u8PinDirection == DIO_u8_INPUT)))
	{
		switch (Copy_u8PortId)
		{
		case DIO_u8_PORTA:
			switch(Copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT: Set_Bit( DIO_u8_DDRA_REG,Copy_u8PinId);break;
				case DIO_u8_INPUT : Clr_Bit( DIO_u8_DDRA_REG,Copy_u8PinId);break;
			}
			break;

		case DIO_u8_PORTB:
			switch(Copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT: Set_Bit( DIO_u8_DDRB_REG,Copy_u8PinId);break;
				case DIO_u8_INPUT : Clr_Bit( DIO_u8_DDRB_REG,Copy_u8PinId);break;
		    }
			break;

		case DIO_u8_PORTC:
			switch(Copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT: Set_Bit( DIO_u8_DDRC_REG,Copy_u8PinId);break;
				case DIO_u8_INPUT : Clr_Bit( DIO_u8_DDRC_REG,Copy_u8PinId);break;
		    }
			break;

		case DIO_u8_PORTD:
			switch(Copy_u8PinDirection)
			{
				case DIO_u8_OUTPUT: Set_Bit( DIO_u8_DDRD_REG,Copy_u8PinId);break;
				case DIO_u8_INPUT : Clr_Bit( DIO_u8_DDRD_REG,Copy_u8PinId);break;
		    }
			break;
		}

	}

	else
	{
		Local_u8ErrorState=STD_TYPES_NOK ;
	}
	 return Local_u8ErrorState;

}

u8 DIO_u8SetPinValue      (u8 Copy_u8PortId, u8 Copy_u8PinId , u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState=STD_TYPES_OK ;
	if ((Copy_u8PortId<=DIO_u8_PORTD )&& (Copy_u8PinId<=DIO_u8_PIN7)&&((Copy_u8PinValue==DIO_u8_HIGH)||(Copy_u8PinValue==DIO_u8_LOW)))
	{
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA:
			switch(Copy_u8PinValue)
			{
				case DIO_u8_HIGH:Set_Bit(DIO_u8_PORTA_REG,Copy_u8PinId);break;
				case DIO_u8_LOW :Clr_Bit(DIO_u8_PORTA_REG,Copy_u8PinId);break;
			}
			break;

			case DIO_u8_PORTB:
			switch(Copy_u8PinValue)
			{
				case DIO_u8_HIGH:Set_Bit(DIO_u8_PORTB_REG,Copy_u8PinId);break;
				case DIO_u8_LOW :Clr_Bit(DIO_u8_PORTB_REG,Copy_u8PinId);break;
			}
			break;

			case DIO_u8_PORTC:
			switch(Copy_u8PinValue)
			{
				case DIO_u8_HIGH:Set_Bit(DIO_u8_PORTC_REG,Copy_u8PinId);break;
				case DIO_u8_LOW :Clr_Bit(DIO_u8_PORTC_REG,Copy_u8PinId);break;
			}
			break;

			case DIO_u8_PORTD:
			switch(Copy_u8PinValue)
			{
				case DIO_u8_HIGH:Set_Bit(DIO_u8_PORTD_REG,Copy_u8PinId);break;
				case DIO_u8_LOW :Clr_Bit(DIO_u8_PORTD_REG,Copy_u8PinId);break;
			}
			break;
		}
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOK ;
	}

	return Local_u8ErrorState;
}

u8 DIO_u8GetPinValue (u8 Copy_u8PortId , u8 Copy_u8PinId,u8 *Copy_u8ReturnedPinValue )
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if ((Copy_u8PortId<=DIO_u8_PORTD)&&(Copy_u8PinId<=DIO_u8_PIN7)&&(Copy_u8ReturnedPinValue != NULL))
	{
		switch(Copy_u8PortId)
		{
			case DIO_u8_PORTA: *Copy_u8ReturnedPinValue= Get_Bit(DIO_u8_PINA_REG,Copy_u8PinId);break;
			case DIO_u8_PORTB: *Copy_u8ReturnedPinValue= Get_Bit(DIO_u8_PINB_REG,Copy_u8PinId);break;
			case DIO_u8_PORTC: *Copy_u8ReturnedPinValue= Get_Bit(DIO_u8_PINC_REG,Copy_u8PinId);break;
			case DIO_u8_PORTD: *Copy_u8ReturnedPinValue= Get_Bit(DIO_u8_PIND_REG,Copy_u8PinId);break;

		}
	}
	else{
			Local_u8ErrorState=STD_TYPES_NOK;
	    }
		return Local_u8ErrorState;

}

u8 DIO_u8SetPortDirection (u8 Copy_u8PortId, u8 Copy_u8PortDirection)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if((Copy_u8PortId<=DIO_u8_PORTD)&&((Copy_u8PortDirection==DIO_u8_OUTPUT)||(Copy_u8PortDirection==DIO_u8_INPUT)) )
	{
		switch (Copy_u8PortId)
		{
			case DIO_u8_PORTA:
			switch(Copy_u8PortDirection)
			{
			case DIO_u8_OUTPUT:DIO_u8_DDRA_REG = 0xff;break;
			case DIO_u8_INPUT :DIO_u8_DDRA_REG = 0x00;break;
			}
			break;

			case DIO_u8_PORTB:
			switch(Copy_u8PortDirection)
			{
			case DIO_u8_OUTPUT:DIO_u8_DDRB_REG = 0xff;break;
			case DIO_u8_INPUT :DIO_u8_DDRB_REG = 0x00;break;
			}
			break;

			case DIO_u8_PORTC:
			switch(Copy_u8PortDirection)
			{
			case DIO_u8_OUTPUT:DIO_u8_DDRC_REG = 0xff;break;
			case DIO_u8_INPUT :DIO_u8_DDRC_REG = 0x00;break;
			}
			break;

			case DIO_u8_PORTD:
			switch(Copy_u8PortDirection)
			{
			case DIO_u8_OUTPUT:DIO_u8_DDRD_REG = 0xff;break;
			case DIO_u8_INPUT :DIO_u8_DDRD_REG = 0x00;break;
			}
			break;


		}
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOK;
	}
	return Local_u8ErrorState;

}

u8 DIO_u8SetPortValue     (u8 Copy_u8PortId, u8 Copy_u8PortValue)
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if((Copy_u8PortId<=DIO_u8_PORTD)&&((Copy_u8PortValue==DIO_u8_HIGH)||(Copy_u8PortValue==DIO_u8_LOW)))
	{
		switch (Copy_u8PortId)
		{
			case DIO_u8_PORTA:
			switch(Copy_u8PortValue)
			{
				case DIO_u8_HIGH:DIO_u8_PORTA_REG= 0xff;break;
				case DIO_u8_LOW :DIO_u8_PORTA_REG= 0x00;break;
			}
			break;

			case DIO_u8_PORTB:
			switch(Copy_u8PortValue)
			{
				case DIO_u8_HIGH:DIO_u8_PORTB_REG= 0xff;break;
				case DIO_u8_LOW :DIO_u8_PORTB_REG= 0x00;break;
			}
			break;

			case DIO_u8_PORTC:
			switch(Copy_u8PortValue)
			{
				case DIO_u8_HIGH:DIO_u8_PORTC_REG= 0xff;break;
				case DIO_u8_LOW :DIO_u8_PORTC_REG= 0x00;break;
			}
			break;

			case DIO_u8_PORTD:
			switch(Copy_u8PortValue)
			{
				case DIO_u8_HIGH:DIO_u8_PORTD_REG= 0xff;break;
				case DIO_u8_LOW :DIO_u8_PORTD_REG= 0x00;break;
			}
			break;
		}
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8GetPORTValue      (u8 Copy_u8PortId , u8 *Copy_u8ReturnedPortValue )
{
	u8 Local_u8ErrorState=STD_TYPES_OK;
	if ((Copy_u8PortId<=DIO_u8_PORTD)&&(Copy_u8ReturnedPortValue!=NULL))
	{
		switch (Copy_u8PortId)
		{
			case DIO_u8_PORTA:*Copy_u8ReturnedPortValue= DIO_u8_PINA_REG;break;
			case DIO_u8_PORTB:*Copy_u8ReturnedPortValue= DIO_u8_PINB_REG;break;
		    case DIO_u8_PORTC:*Copy_u8ReturnedPortValue= DIO_u8_PINC_REG;break;
			case DIO_u8_PORTD:*Copy_u8ReturnedPortValue= DIO_u8_PIND_REG;break;
		}
	}
	else
	{
		Local_u8ErrorState=STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}
