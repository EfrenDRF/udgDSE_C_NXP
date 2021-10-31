/*
 * Tasks.c
 *
 *  Created on: 8 sep. 2021
 *      Author: uid87544
 */

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

/* SDK includes. */
#include "sdk_project_config.h"


#include "BasicTypes.h"
#include "Window.h"
#include "Door.h"
#include "Button.h"
#include "Button_Cfg.h"
#include "DoorApp.h"
#include "WindowApp.h"
#include "Wdg.h"
#include "Mcu.h"
#include "Mpu.h"
#include "Adc.h"
#include "Dio.h"
#include "HwConfig.h"
#include "..\Communication\Signals\Signals.h"
#include "DcuTasks.h"

/*Local Macro__________________________________________________________________*/
#define app_10ms_TASK_PRIORITY      ( tskIDLE_PRIORITY + 3u )
#define app_20ms_TASK_PRIORITY      ( tskIDLE_PRIORITY + 2u )
#define app_100ms_TASK_PRIORITY     ( tskIDLE_PRIORITY + 1u )

#define ANTIPINCH_LIMIT             (500UL)

/* Local Function Prototypes */
static void Tasks_StartOS(void);

static void app_task_10ms( void *pvParameters );
static void app_task_20ms( void *pvParameters );
static void app_task_100ms( void *pvParameters );

static void Tasks_StartOS(void)
{
    (void) xTaskCreate(app_task_10ms,  "app10ms",  configMINIMAL_STACK_SIZE, NULL, app_10ms_TASK_PRIORITY,  NULL);
    (void) xTaskCreate(app_task_20ms,  "app20ms",  configMINIMAL_STACK_SIZE, NULL, app_20ms_TASK_PRIORITY,  NULL);
    (void) xTaskCreate(app_task_100ms, "app100ms", configMINIMAL_STACK_SIZE, NULL, app_100ms_TASK_PRIORITY, NULL);

    Mpu_Init();

    /* Start the tasks and timer running. */
    vTaskStartScheduler();
}

void init_hook(void)
{
    Mcu_Init();

    Wdg_Init();

    Dio_Init();

    Adc_Init();
    
    HwConfig_Init();

    Button_Init();

    Tasks_StartOS();
}


/* ============================================================================
 * Function Name:
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
static void app_task_10ms( void *pvParameters )
{
    TickType_t xNextWakeTime;

    /* Casting pvParameters to void because it is unused */
    (void)pvParameters;

    /* Initialize xNextWakeTime - this only needs to be done once. */
    xNextWakeTime = xTaskGetTickCount();

    for( ;; )
    {
        Signals_RunTx();

        Button_Run();

        /* Place this task in the blocked state until it is time to run again.
        The block time is specified in ticks, the constant used converts ticks
        to ms.  While in the Blocked state this task will not consume any CPU
        time. */
        vTaskDelayUntil( &xNextWakeTime, pdMS_TO_TICKS( 10u ) );

    }
}

/* ============================================================================
 * Function Name:
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
void app_task_20ms( void *pvParameters )
{
    TickType_t xNextWakeTime;

    /* Casting pvParameters to void because it is unused */
    (void)pvParameters;

    /* Initialize xNextWakeTime - this only needs to be done once. */
    xNextWakeTime = xTaskGetTickCount();

    for( ;; )
    {
        Signals_RunRx();

        /* Place this task in the blocked state until it is time to run again.
        The block time is specified in ticks, the constant used converts ticks
        to ms.  While in the Blocked state this task will not consume any CPU
        time. */
        vTaskDelayUntil( &xNextWakeTime, pdMS_TO_TICKS( 20u ) );

    }
}

/* ============================================================================
 * Function Name:
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
static void app_task_100ms( void *pvParameters )
{
    static PIN_VALUE      toogleVal = DIO_LOW;
    static BUTTON_STATUS  buttonVal = BUTTON_NOT_PRESSED;
    TickType_t xNextWakeTime;

    /* Casting pvParameters to void because it is unused */
    (void)pvParameters;

    /* Initialize xNextWakeTime - this only needs to be done once. */
    xNextWakeTime = xTaskGetTickCount();

    for( ;; )
    {

        Adc_Run();
        
        if (Adc_Get_AntiPinch_Value() >= ANTIPINCH_LIMIT)
        {
            toogleVal ^= DIO_HIGH;
            Dio_Write_DoorUnlock_Led(toogleVal);
            Dio_Write_DoorLock_Led(DIO_HIGH);
        }
        else
        {
            buttonVal = Button_Get_Window_Close();

            if(BUTTON_PRESSED == buttonVal )
            {
                Button_CleanStatus(BUTTON_CFG_CLOSE_BTN_IDX);
                toogleVal ^= DIO_HIGH; 
            }
            Dio_Write_DoorUnlock_Led( DIO_HIGH );
            Dio_Write_DoorLock_Led(toogleVal);
        }

        /* Place this task in the blocked state until it is time to run again.
        The block time is specified in ticks, the constant used converts ticks
        to ms.  While in the Blocked state this task will not consume any CPU
        time. */
        vTaskDelayUntil( &xNextWakeTime, pdMS_TO_TICKS( 100u ) );

    }
}
