/*
 * HwConfig.h
 *
 *  Created on: 2 ago. 2021
 *      Author: uid87544
 */

#ifndef ECUABSTRACTION_HWCONFIG_H_
#define ECUABSTRACTION_HWCONFIG_H_
/*Global typedef____________________________________________________________*/
typedef uint8  HW_CONFIG;

/*Global Macro______________________________________________________________*/
#define HWCONFIG_UNKNOWN    ((HW_CONFIG)0x00)
#define HWCONFIG_DRIVER     ((HW_CONFIG)0x01)
#define HWCONFIG_PASSENGER  ((HW_CONFIG)0x02)
#define HWCONFIG_REAR_LEFT  ((HW_CONFIG)0x04)
#define HWCONFIG_REAR_RIGHT ((HW_CONFIG)0x08)

/*Global function def_______________________________________________________*/
extern void HwConfig_Init(void);

extern HW_CONFIG HwConfig_Get(void);

# if(0)
extern boolean   HwConfig_IsAny(HW_CONFIG config, HW_CONFIG config_mask);
#endif

#endif /* ECUABSTRACTION_HWCONFIG_H_ */
