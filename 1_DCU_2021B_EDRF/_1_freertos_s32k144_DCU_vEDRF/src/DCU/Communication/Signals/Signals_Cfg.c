/*
 * Signals_Cfg.c
 *
 *  Created on: 2 nov. 2021
 *      Author: Efren Del Real
 */

#include "comgen_CAN_includes.h"
#include "Signals_Cfg.h"
#include "sdk_project_config.h"

/*Global const _____________________________________________________________*/

const uint8_t * const signalsCfg_getDirectTable[SIGNAL_CFG_GETDIRECT_TABLE_LEN][SIGNAL_CFG_DCU_TOTAL] =
{
    /*  0 */ { &CAN_DCM_DR_get_direct_SysPwrMode(),           &CAN_DCM_PS_get_direct_SysPwrMode(),           &CAN_DCM_RL_get_direct_SysPwrMode(),           &CAN_DCM_RR_get_direct_SysPwrMode()           },
    /*  1 */ { &CAN_DCM_DR_get_direct_ConfortCmd(),           &CAN_DCM_PS_get_direct_ConfortCmd(),           &CAN_DCM_RL_get_direct_ConfortCmd(),           &CAN_DCM_RR_get_direct_ConfortCmd()           },
    /*  2 */ { &CAN_DCM_DR_get_direct_VehSpeed(),             &CAN_DCM_PS_get_direct_VehSpeed(),             &CAN_DCM_RL_get_direct_VehSpeed(),             &CAN_DCM_RR_get_direct_VehSpeed()             },
    /*  3 */ { &CAN_DCM_DR_get_direct_ShiftLeverPos(),        &CAN_DCM_PS_get_direct_ShiftLeverPos(),        &CAN_DCM_RL_get_direct_ShiftLeverPos(),        &CAN_DCM_RR_get_direct_ShiftLeverPos()        },
    /*  4 */ { &CAN_DCM_DR_get_direct_ShiftLeverEng(),        &CAN_DCM_PS_get_direct_ShiftLeverEng(),        &CAN_DCM_RL_get_direct_ShiftLeverEng(),        &CAN_DCM_RR_get_direct_ShiftLeverEng()        },
    /*  5 */ { &CAN_DCM_DR_get_direct_DCU_1_LockingReq(),     &CAN_DCM_PS_get_direct_DCU_1_LockingReq(),     &CAN_DCM_RL_get_direct_DCU_1_LockingReq(),     &CAN_DCM_RR_get_direct_DCU_1_LockingReq()     },
    /*  6 */ { &CAN_DCM_DR_get_direct_DCU_2_LockingReq(),     &CAN_DCM_PS_get_direct_DCU_2_LockingReq(),     &CAN_DCM_RL_get_direct_DCU_2_LockingReq(),     &CAN_DCM_RR_get_direct_DCU_2_LockingReq()     },
    /*  7 */ { &CAN_DCM_DR_get_direct_DCU_1_RearWindowLock(), &CAN_DCM_PS_get_direct_DCU_1_RearWindowLock(), &CAN_DCM_RL_get_direct_DCU_1_RearWindowLock(), &CAN_DCM_RR_get_direct_DCU_1_RearWindowLock() },
    /*  8 */ { &CAN_DCM_DR_get_direct_DCU_1_DoorLockSts(),    &CAN_DCM_PS_get_direct_DCU_1_DoorLockSts(),    &CAN_DCM_RL_get_direct_DCU_1_DoorLockSts(),    &CAN_DCM_RR_get_direct_DCU_1_DoorLockSts()    },
    /*  9 */ { &CAN_DCM_DR_get_direct_DCU_2_DoorLockSts(),    &CAN_DCM_PS_get_direct_DCU_2_DoorLockSts(),    &CAN_DCM_RL_get_direct_DCU_2_DoorLockSts(),    &CAN_DCM_RR_get_direct_DCU_2_DoorLockSts()    },
    /* 10 */ { NULL,                                          NULL,                                          &CAN_DCM_RL_get_direct_DCU_3_DoorLockSts(),    NULL                                          },
    /* 11 */ { NULL,                                          NULL,                                          NULL,                                          &CAN_DCM_RR_get_direct_DCU_4_DoorLockSts()    },
    /* 12 */ { &CAN_DCM_DR_get_direct_DCU_1_WdwCtrl_Pas(),    &CAN_DCM_PS_get_direct_DCU_1_WdwCtrl_Pas(),    &CAN_DCM_RL_get_direct_DCU_1_WdwCtrl_Pas(),    &CAN_DCM_RR_get_direct_DCU_1_WdwCtrl_Pas()    },
    /* 13 */ { &CAN_DCM_DR_get_direct_DCU_1_WdwCtrl_RL(),     &CAN_DCM_PS_get_direct_DCU_1_WdwCtrl_RL(),     &CAN_DCM_RL_get_direct_DCU_1_WdwCtrl_RL(),     &CAN_DCM_RR_get_direct_DCU_1_WdwCtrl_RL()     },
    /* 14 */ { &CAN_DCM_DR_get_direct_DCU_1_WdwCtrl_RR(),     &CAN_DCM_PS_get_direct_DCU_1_WdwCtrl_RR(),     &CAN_DCM_RL_get_direct_DCU_1_WdwCtrl_RR(),     &CAN_DCM_RR_get_direct_DCU_1_WdwCtrl_RR()     }
};

uint8_t * const signalsCfg_updateDirectTable[SIGNAL_CFG_UPDATEDIRECT_TABLE_LEN][SIGNAL_CFG_DCU_TOTAL] =
{
    /*  0 */ { &CAN_DCM_DR_get_direct_DCU_1_WindowPos(),      &CAN_DCM_PS_get_direct_DCU_1_WindowPos(),      &CAN_DCM_RL_get_direct_DCU_1_WindowPos(),      &CAN_DCM_RR_get_direct_DCU_1_WindowPos()      },
    /*  1 */ { &CAN_DCM_DR_get_direct_DCU_1_LockingReq(),     &CAN_DCM_PS_get_direct_DCU_1_LockingReq(),     &CAN_DCM_RL_get_direct_DCU_1_LockingReq(),     &CAN_DCM_RR_get_direct_DCU_1_LockingReq()     },
    /*  2 */ { &CAN_DCM_DR_get_direct_DCU_1_WindowOp(),       &CAN_DCM_PS_get_direct_DCU_1_WindowOp(),       &CAN_DCM_RL_get_direct_DCU_1_WindowOp(),       &CAN_DCM_RR_get_direct_DCU_1_WindowOp()       },
    /*  3 */ { &CAN_DCM_DR_get_direct_DCU_1_RearWindowLock(), &CAN_DCM_PS_get_direct_DCU_1_RearWindowLock(), &CAN_DCM_RL_get_direct_DCU_1_RearWindowLock(), &CAN_DCM_RR_get_direct_DCU_1_RearWindowLock() },
    /*  4 */ { &CAN_DCM_DR_get_direct_DCU_1_DoorLockSts(),    &CAN_DCM_PS_get_direct_DCU_1_DoorLockSts(),    &CAN_DCM_RL_get_direct_DCU_1_DoorLockSts(),    &CAN_DCM_RR_get_direct_DCU_1_DoorLockSts()    },
    /*  5 */ { &CAN_DCM_DR_get_direct_DCU_1_WdwCtrl_Pas(),    &CAN_DCM_PS_get_direct_DCU_1_WdwCtrl_Pas(),    &CAN_DCM_RL_get_direct_DCU_1_WdwCtrl_Pas(),    &CAN_DCM_RR_get_direct_DCU_1_WdwCtrl_Pas()    },    
    /*  6 */ { &CAN_DCM_DR_get_direct_DCU_1_WdwCtrl_RL(),     &CAN_DCM_PS_get_direct_DCU_1_WdwCtrl_RL(),     &CAN_DCM_RL_get_direct_DCU_1_WdwCtrl_RL(),     &CAN_DCM_RR_get_direct_DCU_1_WdwCtrl_RL()     },
    /*  7 */ { &CAN_DCM_DR_get_direct_DCU_1_WdwCtrl_RR(),     &CAN_DCM_PS_get_direct_DCU_1_WdwCtrl_RR(),     &CAN_DCM_RL_get_direct_DCU_1_WdwCtrl_RR(),     &CAN_DCM_RR_get_direct_DCU_1_WdwCtrl_RR()     }
};