/*
 * Dio.c
 *
 *  Created on: 2 ago. 2021
 *      Author: uid87544
 */

#include "BasicTypes.h"
#include "Dio.h"
#include "sdk_project_config.h"

/*Local Macro_________________________________________________________________________*/


static PIN_VALUE xDio_Get_WindowLED(PIN_VALUES windowLED, PIN_VALUES values)
{
    PIN_VALUE pinValue = DIO_LOW;
    pinValue = ((values & windowLED) != 0x00u)? DIO_HIGH : DIO_LOW;

    return pinValue;
}

static PIN_VALUE xDio_Read_Pin(const GPIO_Type * const portPtr, uint8_t pin)
{
    PIN_VALUE pinValue = DIO_LOW;
    uint16_t portValue = 0x0000UL;

    portValue = PINS_DRV_ReadPins(portPtr);
    pinValue = ((portValue & (1u << pin)) != 0x000u)? DIO_HIGH : DIO_LOW;

    return pinValue;
}

void Dio_Init(void)
{
    /* Init IO HAL */
    PINS_DRV_Init( NUM_OF_CONFIGURED_PINS0, g_pin_mux_InitConfigArr0 );
}

void Dio_Write_DoorUnlock_Led(PIN_VALUE value)
{
    PINS_DRV_WritePin(GREEN_LED_PORT, GREEN_LED_PIN, value);
}

void Dio_Write_DoorLock_Led(PIN_VALUE value)
{
    PINS_DRV_WritePin(RED_LED_PORT, RED_LED_PIN, value);
}

void Dio_Write_Window_Leds(PIN_VALUES values)
{
    PINS_DRV_WritePin(WINDOW_LED1_PORT,  WINDOW_LED1_PIN,  xDio_Get_WindowLED(DIO_WINDOW_LED1 ,values));
    PINS_DRV_WritePin(WINDOW_LED2_PORT,  WINDOW_LED2_PIN,  xDio_Get_WindowLED(DIO_WINDOW_LED2 ,values));
    PINS_DRV_WritePin(WINDOW_LED3_PORT,  WINDOW_LED3_PIN,  xDio_Get_WindowLED(DIO_WINDOW_LED3 ,values));
    PINS_DRV_WritePin(WINDOW_LED4_PORT,  WINDOW_LED4_PIN,  xDio_Get_WindowLED(DIO_WINDOW_LED4 ,values));
    PINS_DRV_WritePin(WINDOW_LED5_PORT,  WINDOW_LED5_PIN,  xDio_Get_WindowLED(DIO_WINDOW_LED5 ,values));
    PINS_DRV_WritePin(WINDOW_LED6_PORT,  WINDOW_LED6_PIN,  xDio_Get_WindowLED(DIO_WINDOW_LED6 ,values));
    PINS_DRV_WritePin(WINDOW_LED7_PORT,  WINDOW_LED7_PIN,  xDio_Get_WindowLED(DIO_WINDOW_LED7 ,values));
    PINS_DRV_WritePin(WINDOW_LED8_PORT,  WINDOW_LED8_PIN,  xDio_Get_WindowLED(DIO_WINDOW_LED8 ,values));
    PINS_DRV_WritePin(WINDOW_LED9_PORT,  WINDOW_LED9_PIN,  xDio_Get_WindowLED(DIO_WINDOW_LED9 ,values));
    PINS_DRV_WritePin(WINDOW_LED10_PORT, WINDOW_LED10_PIN, xDio_Get_WindowLED(DIO_WINDOW_LED10 ,values));
}

PIN_VALUE Dio_Read_DoorUnlock(void)
{
    return xDio_Read_Pin(DOOR_UNLOCKED_PORT, DOOR_UNLOCKED_PIN);
}

PIN_VALUE Dio_Read_DoorLock(void)
{
    return xDio_Read_Pin(SW_DOOR_LOCKED_PORT, SW_DOOR_LOCKED_PIN);
}

PIN_VALUE Dio_Read_Window_Open(void)
{
    return xDio_Read_Pin(SW_WINDOW_OPEN_PORT), SW_WINDOW_OPEN_PIN);
}

PIN_VALUE Dio_Read_Window_Closed(void)
{    
    return xDio_Read_Pin(SW_WINDOW_CLOSE_PORT, SW_WINDOW_CLOSE_PIN);
}

PIN_VALUE Dio_Read_DoorLock_Button(void)
{
    return xDio_Read_Pin(LOCK_BTN_PORT, LOCK_BTN_PIN);
}

PIN_VALUE Dio_Read_DoorUnlock_Button(void)
{
    return xDio_Read_Pin(UNLOCK_BTN_PORT, UNLOCK_BTN_PIN);
}

PIN_VALUE Dio_Read_WindowOpen_Button(void)
{
    return xDio_Read_Pin(OPEN_BTN_PORT, OPEN_BTN_PIN);
}

PIN_VALUE Dio_Read_WindowClose_Button(void)
{
    return xDio_Read_Pin(CLOSE_BTN_PORT, CLOSE_BTN_PIN);
}

PIN_VALUE Dio_Read_PassengerWindowOpen_Button(void)
{    
    return xDio_Read_Pin(PASSENGER_OPEN_BTN_PORT, PASSENGER_OPEN_BTN_PIN);
}

PIN_VALUE Dio_Read_PassengerWindowClose_Button(void)
{    
    return xDio_Read_Pin(PASSENGER_CLOSE_BTN_PORT, PASSENGER_CLOSE_BTN_PIN);
}

PIN_VALUE Dio_Read_RearLeftWindowOpen_Button(void)
{
    return xDio_Read_Pin(REARLEFT_OPEN_BTN_PORT, REARLEFT_OPEN_BTN_PIN);
}

PIN_VALUE Dio_Read_RearLeftWindowClose_Button(void)
{    
    return xDio_Read_Pin(REARLEFT_CLOSE_BTN_PORT, REARLEFT_CLOSE_BTN_PIN);
}

PIN_VALUE Dio_Read_RearRightWindowOpen_Button(void)
{
    return xDio_Read_Pin(REARRIGHT_OPEN_BTN_PORT, REARRIGHT_OPEN_BTN_PIN);
}

PIN_VALUE Dio_Read_RearRightWindowClose_Button(void)
{
    return xDio_Read_Pin(REARRIGHT_CLOSE_BTN_PORT, REARRIGHT_CLOSE_BTN_PIN);
}

PIN_VALUE Dio_Read_RearWindowLock_Button(void)
{
    return xDio_Read_Pin(REAR_WINDOW_LOCK_BTN_PORT, REAR_WINDOW_LOCK_BTN_PIN);
}

PIN_VALUE Dio_Read_Jumper0(void)
{
    return xDio_Read_Pin(JUMPER0_PORT, JUMPER0_PIN);
}

PIN_VALUE Dio_Read_Jumper1(void)
{
    return xDio_Read_Pin(JUMPER1_PORT, JUMPER1_PIN);
}


