/*
 * ButtonDriver.c
 *
 *  Created on: 2 ago. 2021
 *      Author: uid87544
 */

#include <string.h>
#include "BasicTypes.h"
#include "Dio.h"
#include "HwConfig.h"
#include "Button.h"
#include "Button_Debounce.h"
#include "Button_Cfg.h"

/*Global Macro______________________________________________________________*/


/*Local variable____________________________________________________________*/
static ButtonDeb_varData_t xButtonVar_table[BUTTON_CFG_TABLE_LEN];

/*Local function def________________________________________________________*/
static BUTTON_STATUS Button_GetStatus(uint8 index);

/* ============================================================================
 * Function Name: Button_Init
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
void Button_Init(void)
{
	(void) memset(xButtonVar_table, 0x00u, sizeof(xButtonVar_table));
}

//10 ms
/* ============================================================================
 * Function Name: Button_Run
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
void Button_Run(void)
{
	static uint8 idx = 0x00u;

	for (idx = 0x00u; (BUTTON_CFG_TABLE_LEN > idx); idx++)
	{
		ButtonDeb_StateMachine(&xButtonVar_table[idx], &xButtonCfg_table[idx]);
	}
}

/* ============================================================================
 * Function Name: Button_Get_Door_Lock
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
BUTTON_STATUS Button_Get_Door_Lock(void)
{
    return Button_GetStatus(BUTTON_CFG_LOCK_BTN_IDX);
}

/* ============================================================================
 * Function Name: Button_Get_Door_Unlock
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
BUTTON_STATUS Button_Get_Door_Unlock(void)
{
	return Button_GetStatus(BUTTON_CFG_UNLOCK_BTN_IDX);
}

/* ============================================================================
 * Function Name: Button_Get_Window_Open
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
BUTTON_STATUS Button_Get_Window_Open(void)
{
	return Button_GetStatus(BUTTON_CFG_OPEN_BTN_IDX);
}

/* ============================================================================
 * Function Name: Button_Get_Window_Close
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
BUTTON_STATUS Button_Get_Window_Close(void)
{
	return Button_GetStatus(BUTTON_CFG_CLOSE_BTN_IDX);
}

//driver
/* ============================================================================
 * Function Name: Button_Get_PassengerWindow_Open
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
BUTTON_STATUS Button_Get_PassengerWindow_Open(void)
{
	return Button_GetStatus(BUTTON_CFG_PASSENGER_OPEN_BTN_IDX);
}

//driver
/* ============================================================================
 * Function Name: Button_Get_PassengerWindow_Close
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
BUTTON_STATUS Button_Get_PassengerWindow_Close(void)
{
	return Button_GetStatus(BUTTON_CFG_PASSENGER_CLOSE_BTN_IDX);
}

//driver
/* ============================================================================
 * Function Name: Button_Get_RearLeftWindow_Open
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
BUTTON_STATUS Button_Get_RearLeftWindow_Open(void)
{
	return Button_GetStatus(BUTTON_CFG_REARLEFT_OPEN_BTN_IDX);
}

//driver
/* ============================================================================
 * Function Name: Button_Get_RearLeftWindow_Close
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
BUTTON_STATUS Button_Get_RearLeftWindow_Close(void)
{
	return Button_GetStatus(BUTTON_CFG_REARLEFT_CLOSE_BTN_IDX);
}

//driver
/* ============================================================================
 * Function Name: Button_Get_RearRightWindow_Open
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
BUTTON_STATUS Button_Get_RearRightWindow_Open(void)
{
	return Button_GetStatus(BUTTON_CFG_REARRIGHT_OPEN_BTN_IDX);
}

//driver
/* ============================================================================
 * Function Name: Button_Get_RearRightWindow_Close
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
BUTTON_STATUS Button_Get_RearRightWindow_Close(void)
{
	return Button_GetStatus(BUTTON_CFG_REARRIGHT_CLOSE_BTN_IDX);
}

//driver
/* ============================================================================
 * Function Name: Button_Get_RearWindow_Lock
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
BUTTON_STATUS Button_Get_RearWindow_Lock(void)  //switch
{
	return Button_GetStatus(BUTTON_CFG_REAR_WINDOW_LOCK_BTN_IDX);
}

/* ============================================================================
 * Function Name: Button_CleanStatus
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
void Button_CleanStatus(uint8 index)
{
    xButtonVar_table[index].debEvent = eUNKNOWN;
}

/* ============================================================================
 * Function Name: Button_GetStatus
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
static BUTTON_STATUS Button_GetStatus(uint8 index)
{
	BUTTON_STATUS ret_val = BUTTON_NOT_PRESSED;

    switch (xButtonVar_table[index].debEvent)
    {
        case eREACHED_ACT1:
        {
			ret_val = BUTTON_PRESSED;
        }break;
# if(0)
        case eRELEACED_ACT1:
        {
			ret_val = BUTTON_PRESSED;
        }break;
# endif
        case eREACHED_ACT2:
        {
			ret_val = BUTTON_LONG_PRESSED;
        }break;
# if(0)
        case eRELEACED_ACT2:
        {
			ret_val = BUTTON_LONG_PRESSED;
        }break;	
# endif
        default:
		{
			/* Avoid MISRA - No action required*/
		}break;
	}

	return ret_val;
}

