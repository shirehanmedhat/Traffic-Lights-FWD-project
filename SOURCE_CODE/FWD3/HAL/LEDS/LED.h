/*
 * LED.h
 *
 *  Created on: Sep 19, 2022
 *      Author: shirehan Medhat
 */

#ifndef HAL_LEDS_LED_H_
#define HAL_LEDS_LED_H_
#define RED		0
#define YELLOW	1
#define GREEN   2
#define HALF_SECOND 1
void CAR_LEDS_INIT (void);
void PEDSTRAINS_LEDS_INIT (void);
void LED_CAR_ON (char PIN_NUMBER);
void LED_CAR_OFF (char PIN_NUMBER);
void LED_PEDSTRAINS_ON (char PIN_NUMBER);
void LED_PEDSTRAINS_OFF (char PIN_NUMBER);
void CAR_PRIORITY (void);
void PEDSTRAINS_PRIORITY (void);
void YELLOW_BLINK (void);
void TRANSIENT_CASE (void);
char GET_PORT_STATE (void);
#endif /* HAL_LEDS_LED_H_ */
