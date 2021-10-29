/*
 * Button_Debounce.h
 *
 *  Created on: 29 oct. 2021
 *      Author: Efren Del Real
 */

#ifndef DCU_ECUABSTRACTION_BUTTON_BUTTON_DEBOUNCE_H_
#define DCU_ECUABSTRACTION_BUTTON_BUTTON_DEBOUNCE_H_

#include "BasicTypes.h"
#include "Dio.h"

/*Global typedef____________________________________________________________*/
typedef enum
{
   eBUTTON_NOT_DEBOUNCED,
   eBUTTON_DEBOUNCED_ACT1,
   eBUTTON_DEBOUNCED_ACT2 
}ButtonDebState_t;

typedef enum
{
    eUNKNOWN,
    eREACHED_ACT1,
    eRELEACED_ACT1,
    eREACHED_ACT2,
    eRELEACED_ACT2
}ButtonDebEvent_t;

typedef uint32 ButtonDebData_t;

typedef PIN_VALUE (*DioReadFunc_t)(void);

typedef struct 
{
    ButtonDebState_t    debState;
    ButtonDebEvent_t    debEvent;
    ButtonDebData_t     debCounter;
}ButtonDeb_varData_t;


typedef struct 
{
    ButtonDebData_t     debThreshold1;
    ButtonDebData_t     debThreshold2;
    DioReadFunc_t       Dio_ReadFunc;
}ButtonDeb_cfgData_t;

/*Global Macro______________________________________________________________*/


/*Global Function Def_______________________________________________________*/
extern void ButtonDeb_StateMachine( const ButtonDeb_varData_t * xButtonDeb_varPtr,
                                    const ButtonDeb_cfgData_t * const xButtonDeb_cfgPtr);

#endif /* DCU_ECUABSTRACTION_BUTTON_BUTTON_DEBOUNCE_H_ */
