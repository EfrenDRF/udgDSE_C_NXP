/*
 * Button_Debounce.c
 *
 *  Created on: 29 oct. 2021
 *      Author: Efren Del Real
 */



#include "sdk_project_config.h"
#include "Button_Debounce.h"


/*Local Macro_______________________________________________________________*/
#define BUTTON_NOT_PRESSENT     DIO_LOW
#define BUTTON_PRESSENT         DIO_HIGH
#define COUNTER_RESET           (0x00u)


/* ============================================================================
 * Function Name: ButtonDeb_StateMachine
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
void ButtonDeb_StateMachine( ButtonDeb_varData_t * const xButtonDeb_varPtr,
                                    const ButtonDeb_cfgData_t * const xButtonDeb_cfgPtr)
{
    PIN_VALUE inputState = BUTTON_NOT_PRESSENT;

    if (NULL != xButtonDeb_cfgPtr->Dio_ReadFunc)
    {
        inputState = xButtonDeb_cfgPtr->Dio_ReadFunc();
    }

    switch (xButtonDeb_varPtr->debState)
    {
        case eBUTTON_NOT_DEBOUNCED:
        {
            if (BUTTON_PRESSENT == inputState)
            {
                if (xButtonDeb_cfgPtr->debThreshold1 >= xButtonDeb_varPtr->debCounter)
                {
                    xButtonDeb_varPtr->debCounter++;
                }
                else
                {
                    xButtonDeb_varPtr->debState = eBUTTON_DEBOUNCED_ACT1;
                    xButtonDeb_varPtr->debEvent = eREACHED_ACT1;
                }
            }
            else
            {
                xButtonDeb_varPtr->debCounter = COUNTER_RESET;
            }
        }break;

        case eBUTTON_DEBOUNCED_ACT1:
        {
            if (BUTTON_PRESSENT == inputState)
            {
                if ((xButtonDeb_cfgPtr->debThreshold1 <  xButtonDeb_varPtr->debCounter) &&
                    (xButtonDeb_cfgPtr->debThreshold2 >= xButtonDeb_varPtr->debCounter))
                {
                    xButtonDeb_varPtr->debCounter++;
                }
                else
                {
                    xButtonDeb_varPtr->debState = eBUTTON_DEBOUNCED_ACT2;
                    xButtonDeb_varPtr->debEvent = eREACHED_ACT2;
                }
            }
            else
            {
                xButtonDeb_varPtr->debState = eBUTTON_NOT_DEBOUNCED;
                xButtonDeb_varPtr->debEvent = eRELEACED_ACT1;
                xButtonDeb_varPtr->debCounter = COUNTER_RESET;
            }
        }break;

        case eBUTTON_DEBOUNCED_ACT2:
        {
            if (BUTTON_NOT_PRESSENT == inputState)
            {
                xButtonDeb_varPtr->debState = eBUTTON_NOT_DEBOUNCED;
                xButtonDeb_varPtr->debEvent = eRELEACED_ACT2;
                xButtonDeb_varPtr->debCounter = COUNTER_RESET;
            }
        }break;
        
        default:
        {
            /* Avoid MISRA - No action required */
        }break;
    }

}
