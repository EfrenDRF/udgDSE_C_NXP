/*
 * ADC.c
 *
 *  Created on: 2 ago. 2021
 *      Author: uid87544
 */

#include "BasicTypes.h"
#include "Adc.h"
#include "sdk_project_config.h"

ASIL_A_VAR_NOINIT static ADC_VALUE  Adc_AntiPinch;

void Adc_Init(void)
{
    status_t status;

    status = ADC_Init(&adc_pal_1_instance, &adc_pal_1_cfg);

    if (status != STATUS_SUCESS)
    {
        //@TODO
    }
    status = ADC_StartGroupConversions(&adc_pal_1_instance, 0x00u);
    

    Adc_AntiPinch = ADC_MIN;
}

//100 ms
void Adc_Run(void)
{
    Adc_AntiPinch = adc_pal_1_results0[0];
}


ADC_VALUE Adc_Get_AntiPinch_Value(void)
{
    return Adc_AntiPinch;
}


