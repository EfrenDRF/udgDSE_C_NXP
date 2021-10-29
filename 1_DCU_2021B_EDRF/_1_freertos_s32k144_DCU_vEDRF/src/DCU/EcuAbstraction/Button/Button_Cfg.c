/*
 * Button_Cfg.c
 *
 *  Created on: 29 oct. 2021
 *      Author: Efren Del Real
 */


#include "Button_Cfg.h"
#include "Dio.h"

/*Global Macro______________________________________________________________*/
#define THRESHOLD1   ((ButtonDebData_t) 0x05u)
#define THRESHOLD2   ((ButtonDebData_t) 0x64u)

/*Global const _____________________________________________________________*/

const ButtonDeb_cfgData_t xButtonCfg_table[BUTTON_CFG_TABLE_LEN] =
{
 /*  0 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_DoorUnlock                   },
 /*  1 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_DoorLock                     },
 /*  2 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_Window_Open                  },
 /*  2 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_Window_Closed                },
 /*  3 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_DoorLock_Button              },
 /*  4 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_DoorUnlock_Button            },
 /*  5 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_WindowOpen_Button            },
 /*  6 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_WindowClose_Button           },
 /*  7 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_PassengerWindowOpen_Button   },
 /*  8 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_PassengerWindowClose_Button  },
 /*  9 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_RearLeftWindowOpen_Button    },
 /* 10 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_RearLeftWindowClose_Button   },
 /* 11 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_RearRightWindowOpen_Button   },
 /* 12 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_RearRightWindowClose_Button  },
 /* 13 */ {.debThreshold1 = THRESHOLD1, .debThreshold2 = THRESHOLD2,.Dio_ReadFunc = Dio_Read_RearWindowLock_Button        } 
}