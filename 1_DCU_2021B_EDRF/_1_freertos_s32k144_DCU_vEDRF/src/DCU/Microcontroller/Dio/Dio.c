/*
 * Dio.c
 *
 *  Created on: 2 ago. 2021
 *      Author: uid87544
 */

#include "BasicTypes.h"
#include "Dio.h"

#include "sdk_project_config.h"


void Dio_Init(void)
{

	/* Init IO HAL */
	PINS_DRV_Init( NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0 );
}

void Dio_Write_DoorUnlock_Led(PIN_VALUE value)
{

}

void Dio_Write_DoorLock_Led(PIN_VALUE value)
{

}
void Dio_Write_Window_Leds(PIN_VALUES values)
{
    PINS_DRV_WritePin( WINDOW_LED1_PORT,  (1u << WINDOW_LED1_PIN ),  ( values & DIO_WINDOW_LED1 ));
    PINS_DRV_WritePin( WINDOW_LED2_PORT,  (1u << WINDOW_LED2_PIN ),  ( values & DIO_WINDOW_LED2 ));
    PINS_DRV_WritePin( WINDOW_LED3_PORT,  (1u << WINDOW_LED3_PIN ),  ( values & DIO_WINDOW_LED3 ));
    PINS_DRV_WritePin( WINDOW_LED4_PORT,  (1u << WINDOW_LED4_PIN ),  ( values & DIO_WINDOW_LED4 ));
	PINS_DRV_WritePin( WINDOW_LED5_PORT,  (1u << WINDOW_LED5_PIN ),  ( values & DIO_WINDOW_LED5 ));
	PINS_DRV_WritePin( WINDOW_LED6_PORT,  (1u << WINDOW_LED6_PIN ),  ( values & DIO_WINDOW_LED6 ));
	PINS_DRV_WritePin( WINDOW_LED7_PORT,  (1u << WINDOW_LED7_PIN ),  ( values & DIO_WINDOW_LED7 ));
	PINS_DRV_WritePin( WINDOW_LED8_PORT,  (1u << WINDOW_LED8_PIN ),  ( values & DIO_WINDOW_LED8 ));
	PINS_DRV_WritePin( WINDOW_LED9_PORT,  (1u << WINDOW_LED9_PIN ),  ( values & DIO_WINDOW_LED9 ));
	PINS_DRV_WritePin( WINDOW_LED10_PORT, (1u << WINDOW_LED10_PIN ), ( values & DIO_WINDOW_LED10 ));
}

PIN_VALUE Dio_Read_DoorUnlock(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_DoorLock(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_Window_Open(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_Window_Closed(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_DoorLock_Button(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_DoorUnlock_Button(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_WindowOpen_Button(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_WindowClose_Button(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_PassengerWindowOpen_Button(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_PassengerWindowClose_Button(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_RearLeftWindowOpen_Button(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_RearLeftWindowClose_Button(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_RearRightWindowOpen_Button(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_RearRightWindowClose_Button(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_RearWindowLock_Button(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_Jumper0(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}

PIN_VALUE Dio_Read_Jumper1(void)
{
	return PINS_DRV_ReadPins( , (1u << ));
}


