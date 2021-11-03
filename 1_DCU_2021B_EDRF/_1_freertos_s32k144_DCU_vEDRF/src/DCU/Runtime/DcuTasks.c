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

/*Local Macros______________________________________________________________*/
#define ACT_3_5
#define ACT_3_6
#define ACT_3_7

#define app_10ms_TASK_PRIORITY      ( tskIDLE_PRIORITY + 3u )
#define app_20ms_TASK_PRIORITY      ( tskIDLE_PRIORITY + 2u )
#define app_100ms_TASK_PRIORITY     ( tskIDLE_PRIORITY + 1u )

#ifdef ACT_3_5
#define ACT_3_5_ANTIPINCH_LIMIT     (500UL)
#endif

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
    
    Signals_Init();

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
    TickType_t xNextWakeTime;

# ifdef ACT_3_5
    PIN_VALUE  DoorUnlockPin_value;
# endif

# ifdef ACT_3_6
    PIN_VALUE      DoorLockPin_value;
    BUTTON_STATUS  button_value;
# endif

# ifdef ACT_3_7
	SIGNAL_ERROR error_code;
	uint8_t signal_value;
# endif
    

    /* Casting pvParameters to void because it is unused */
    (void)pvParameters;

    /* Initialize xNextWakeTime - this only needs to be done once. */
    xNextWakeTime = xTaskGetTickCount();

    for( ;; )
    {

        Adc_Run();
        
# ifdef ACT_3_5
		if (ACT_3_5_ANTIPINCH_LIMIT <= Adc_Get_AntiPinch_Value())
		{
			/* Toogle Green LED */
			DoorUnlockPin_value ^= DIO_HIGH;
		}
		else
		{
			/* Turn off Green LED */
			DoorUnlockPin_value = DIO_HIGH;	
		}

		Dio_Write_DoorUnlock_Led(DoorUnlockPin_value);
# endif

# ifdef ACT_3_6
        button_value = Button_Get_Window_Close();
        
        if(BUTTON_PRESSED == button_value)
        {
            Button_CleanStatus(BUTTON_CFG_CLOSE_BTN_IDX);
            DoorLockPin_value ^= DIO_HIGH;
        }
        else
        {
           DoorLockPin_value = DIO_HIGH; 
        }

        Dio_Write_DoorLock_Led(DoorLockPin_value);
# endif

# ifdef ACT_3_7
		error_code = Signals_Get_SysPwrMode(&signal_value);

		if ((SIGNAL_ERROR_NO == error_code) && (SYSPWRMODE_SNA != signal_value))
		{
			Signals_Set_WindowOp(&signal_value);
		}
# endif

        /* Place this task in the blocked state until it is time to run again.
        The block time is specified in ticks, the constant used converts ticks
        to ms.  While in the Blocked state this task will not consume any CPU
        time. */
        vTaskDelayUntil( &xNextWakeTime, pdMS_TO_TICKS( 100u ) );

    }
}
