/*
 * HwConfig.c
 *
 *  Created on: 2 ago. 2021
 *      Author: uid87544
 */
#include "BasicTypes.h"
#include "HwConfig.h"
#include "Dio.h"

/*
SW Variant Configuration will be done through 2 configuration jumpers.
Depending on the state of the jumpers is the intended behavior of the DCU.
Jumper 0	Jumper 1	Variant Behavior
0	          0	        Driver Door
0	          1	        Passenger Door
1	          0	        RearLeft Door
1	          1	        RearRight Door
*/

/*Local variables_____________________________________________________________*/
static HW_CONFIG HwConfig_variant = HWCONFIG_UNKNOWN;


/* ============================================================================
 * Function Name: HwConfig_Init
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
void HwConfig_Init(void)
{
	uint8 sw_variant = 0x00u;

	sw_variant  = ((uint8)Dio_Read_Jumper0() << 0x01u);
	sw_variant |= (uint8)Dio_Read_Jumper1();

	HwConfig_variant = (0x01u << (HW_CONFIG)sw_variant);
}

/* ============================================================================
 * Function Name: HwConfig_Get
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
HW_CONFIG HwConfig_Get(void)
{
	return HwConfig_variant;
}

# if(0)
/* ============================================================================
 * Function Name:
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
boolean HwConfig_IsAny(HW_CONFIG config, HW_CONFIG config_mask)
{
	(void)config;
	(void)config_mask;
	return FALSE;
}
# endif