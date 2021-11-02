/*
 * Signals_Cfg.h
 *
 *  Created on: 2 nov. 2021
 *      Author: Efren Del Real
 */

#ifndef ECUABSTRACTION_SIGNALS_CFG_H_
#define ECUABSTRACTION_SIGNALS_CFG_H_

#include "BasicTypes.h"

/*Global Macro______________________________________________________________*/
#define SIGNAL_CFG_GETDIRECT_SysPwrMode_IDX            (0x00u)
#define SIGNAL_CFG_GETDIRECT_ConfortCmd_IDX            (0x01u)
#define SIGNAL_CFG_GETDIRECT_VehSpeed_IDX              (0x02u)
#define SIGNAL_CFG_GETDIRECT_ShiftLeverPos_IDX         (0x03u)
#define SIGNAL_CFG_GETDIRECT_ShiftLeverEng_IDX         (0x04u)
#define SIGNAL_CFG_GETDIRECT_DCU_1_LockingReq_IDX      (0x05u)
#define SIGNAL_CFG_GETDIRECT_DCU_2_LockingReq_IDX      (0x06u)
#define SIGNAL_CFG_GETDIRECT_DCU_1_RearWindowLock_IDX  (0x07u)
#define SIGNAL_CFG_GETDIRECT_DCU_1_DoorLockSts_IDX     (0x08u)
#define SIGNAL_CFG_GETDIRECT_DCU_2_DoorLockSts_IDX     (0x09u)
#define SIGNAL_CFG_GETDIRECT_DCU_3_DoorLockSts_IDX     (0x0Au)
#define SIGNAL_CFG_GETDIRECT_DCU_4_DoorLockSts_IDX     (0x0Bu)
#define SIGNAL_CFG_GETDIRECT_DCU_1_WdwCtrl_Pas_IDX     (0x0Cu)
#define SIGNAL_CFG_GETDIRECT_DCU_1_WdwCtrl_RL_IDX      (0x0Du)
#define SIGNAL_CFG_GETDIRECT_DCU_1_WdwCtrl_RR_IDX      (0x0Eu)
#define SIGNAL_CFG_GETDIRECT_TABLE_LEN                 (0x0Fu)

#define SIGNAL_CFG_UPDATEDIRECT_DCU_1_WindowPos_IDX        (0x00u)
#define SIGNAL_CFG_UPDATEDIRECT_DCU_1_LockingReq_IDX       (0x01u)
#define SIGNAL_CFG_UPDATEDIRECT_DCU_1_WindowOp_IDX         (0x02u)
#define SIGNAL_CFG_UPDATEDIRECT_DCU_1_RearWindowLock_IDX   (0x03u)
#define SIGNAL_CFG_UPDATEDIRECT_DCU_1_DoorLockSts_IDX      (0x04u)
#define SIGNAL_CFG_UPDATEDIRECT_DCU_1_WdwCtrl_Pas_IDX      (0x05u)
#define SIGNAL_CFG_UPDATEDIRECT_DCU_1_WdwCtrl_RL_IDX       (0x06u)
#define SIGNAL_CFG_UPDATEDIRECT_DCU_1_WdwCtrl_RR_IDX       (0x07u)
#define SIGNAL_CFG_UPDATEDIRECT_TABLE_LEN                  (0x08u)

#define SIGNAL_CFG_DCU1_IDX                         (0x00u)
#define SIGNAL_CFG_DCU2_IDX                         (0x01u)
#define SIGNAL_CFG_DCU3_IDX                         (0x02u)
#define SIGNAL_CFG_DCU4_IDX                         (0x03u)
#define SIGNAL_CFG_DCU_TOTAL                        (0x04u)

extern const uint8_t * const signalsCfg_getDirectTable[SIGNAL_CFG_GETDIRECT_TABLE_LEN][SIGNAL_CFG_DCU_TOTAL];
extern uint8_t * const signalsCfg_updateDirectTable[SIGNAL_CFG_UPDATEDIRECT_TABLE_LEN][SIGNAL_CFG_DCU_TOTAL];

#endif /* ECUABSTRACTION_SIGNALS_CFG_H_ */