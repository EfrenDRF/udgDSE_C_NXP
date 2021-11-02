/*
 * Signals.c
 *
 *  Created on: 2 ago. 2021
 *      Author: uid87544
 */

#include "sdk_project_config.h"

#include "BasicTypes.h"
#include "HwConfig.h"
#include "Signals.h"
#include "Signals_Cfg.h"
#include "CANpal.h"
#include "comgen_CAN_includes.h"

/* Local typedef____________________________________________________________*/
typedef struct
{
	uint8_t      value;
	SIGNAL_ERROR errorCode;
}Signal_Get_t;


/*Local Macro_______________________________________________________________*/


/*Local variables____________________________________________________________*/

/*Local function def_________________________________________________________*/
static uint8_t      Signals_Get_DCU_ModuleIdx();
static Signal_Get_t Signals_SiganlGetDirect(uint8_t signalGetDirect_idx);

/* ============================================================================
 * Function Name: Signals_Init
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
void Signals_Init(void)
{
	/* ----------------------- */
	/* Init CAN driver and PAL */
	/* ----------------------- */
	CANpal_init();

	/* ---------------------- */
	/* Init interaction layer */
	/* ---------------------- */
    switch (HwConfig_Get())
    {
        case HWCONFIG_DRIVER:
        {
            can_DCM_DR_coreInit();
        }break;
        case HWCONFIG_PASSENGER:
        {
            can_DCM_PS_coreInit();
        }break;
        case HWCONFIG_REAR_LEFT:
        {
            can_DCM_RL_coreInit();
        }break;
        case HWCONFIG_REAR_RIGHT:
        {
            can_DCM_RR_coreInit();
        }break;
        default:
        {
            /* Avoid Misra - No action required */
        }break;
    }

}

//10 ms
/* ============================================================================
 * Function Name: Signals_RunTx
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
void Signals_RunTx(void)
{
    switch (HwConfig_Get())
    {
        case HWCONFIG_DRIVER:
        {
            can_DCM_DR_txRetry();
            can_task_10ms_DCM_DR_txProcess();
        }break;
        case HWCONFIG_PASSENGER:
        {
            can_DCM_PS_txRetry();
            can_task_10ms_DCM_PS_txProcess();
        }break;
        case HWCONFIG_REAR_LEFT:
        {
            can_DCM_RL_txRetry();
            can_task_10ms_DCM_RL_txProcess();
        }break;
        case HWCONFIG_REAR_RIGHT:
        {
            can_DCM_RR_txRetry();
            can_task_10ms_DCM_RR_txProcess();
        }break;
        default:
        {
            /* Avoid Misra - No action required */
        }break;
    }
}

//20 ms
/* ============================================================================
 * Function Name: Signals_RunRx
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
void Signals_RunRx(void)
{
	/* Call CAN RX timeout process function */

    switch (HwConfig_Get())
    {
        case HWCONFIG_DRIVER:
        {
            can_task_20ms_DCM_DR_rxProcess();
        }break;
        case HWCONFIG_PASSENGER:
        {
           can_task_20ms_DCM_PS_rxProcess();
        }break;
        case HWCONFIG_REAR_LEFT:
        {
            can_task_20ms_DCM_RL_rxProcess();
        }break;
        case HWCONFIG_REAR_RIGHT:
        {
            can_task_20ms_DCM_RR_rxProcess();
        }break;
        default:
        {
            /* Avoid Misra - No action required */
        }break;
    }
}

SIGNAL_ERROR Signals_Get_SysPwrMode(uint8 * value)
{
	Signal_Get_t return_object;

	return_object = Signals_SiganlGetDirect(SIGNAL_CFG_GETDIRECT_SysPwrMode_IDX);
	*value = return_object.value;

	return return_object.errorCode;
}

SIGNAL_ERROR Signals_Get_ConfortCmd(uint8 * value)
{
	Signal_Get_t return_object;

	return_object = Signals_SiganlGetDirect(SIGNAL_CFG_GETDIRECT_ConfortCmd_IDX);
	*value = return_object.value;

	return return_object.errorCode;
}

SIGNAL_ERROR Signals_Get_VehSpeed(uint8 * value)
{
	Signal_Get_t return_object;

	return_object = Signals_SiganlGetDirect(SIGNAL_CFG_GETDIRECT_VehSpeed_IDX);
	*value = return_object.value;

	return return_object.errorCode;
}

SIGNAL_ERROR Signals_Get_ShiftLeverPos(uint8 * value)
{
	Signal_Get_t return_object;

	return_object = Signals_SiganlGetDirect(SIGNAL_CFG_GETDIRECT_ShiftLeverPos_IDX);
	*value = return_object.value;

	return return_object.errorCode;
}

SIGNAL_ERROR Signals_Get_ShiftLeverEng(uint8* value)
{
	Signal_Get_t return_object;

	return_object = Signals_SiganlGetDirect(SIGNAL_CFG_GETDIRECT_ShiftLeverEng_IDX);
	*value = return_object.value;

	return return_object.errorCode;
}

void Signals_Set_WindowPos(const uint8 *value)
{
	uint8_t dcu_idx = Signals_Get_DCU_ModuleIdx();

	CALVOS_CRITICAL_ENTER();
		*signalsCfg_updateDirectTable[SIGNAL_CFG_UPDATEDIRECT_DCU_1_WindowPos_IDX][dcu_idx] = *value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_LockingReq(const uint8 *value)
{
	uint8_t dcu_idx = Signals_Get_DCU_ModuleIdx();

	CALVOS_CRITICAL_ENTER();
		*signalsCfg_updateDirectTable[SIGNAL_CFG_UPDATEDIRECT_DCU_1_LockingReq_IDX][dcu_idx] = *value;
	CALVOS_CRITICAL_EXIT();
}

SIGNAL_ERROR Signals_Get_LockingReq_Driver(uint8 * value)
{
	Signal_Get_t return_object;

	return_object = Signals_SiganlGetDirect(SIGNAL_CFG_GETDIRECT_DCU_1_LockingReq_IDX);
	*value = return_object.value;

	return return_object.errorCode;
}

SIGNAL_ERROR Signals_Get_LockingReq_Passenger(uint8 * value)
{
	Signal_Get_t return_object;

	return_object = Signals_SiganlGetDirect(SIGNAL_CFG_GETDIRECT_DCU_2_LockingReq_IDX);
	*value = return_object.value;

	return return_object.errorCode;
}

void Signals_Set_WindowOp(const uint8* value)
{
	uint8_t dcu_idx = Signals_Get_DCU_ModuleIdx();

	CALVOS_CRITICAL_ENTER();
		*signalsCfg_updateDirectTable[SIGNAL_CFG_UPDATEDIRECT_DCU_1_WindowOp_IDX][dcu_idx] = *value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_RearWindowLock(const uint8 *value)
{
	uint8_t dcu_idx = Signals_Get_DCU_ModuleIdx();

	CALVOS_CRITICAL_ENTER();
		*signalsCfg_updateDirectTable[SIGNAL_CFG_UPDATEDIRECT_DCU_1_RearWindowLock_IDX][dcu_idx] = *value;
	CALVOS_CRITICAL_EXIT();
}

SIGNAL_ERROR Signals_Get_RearWindowLock(uint8 *value)
{
	Signal_Get_t return_object;

	return_object = Signals_SiganlGetDirect(SIGNAL_CFG_GETDIRECT_DCU_1_RearWindowLock_IDX);
	*value = return_object.value;

	return return_object.errorCode;
}

void Signals_Set_DoorLockSts(const uint8 *value)
{
	uint8_t dcu_idx = Signals_Get_DCU_ModuleIdx();

	CALVOS_CRITICAL_ENTER();
		*signalsCfg_updateDirectTable[SIGNAL_CFG_UPDATEDIRECT_DCU_1_DoorLockSts_IDX][dcu_idx] = *value;
	CALVOS_CRITICAL_EXIT();
}

SIGNAL_ERROR Signals_Get_Passenger_DoorLockSts(uint8 * value)
{
	Signal_Get_t return_object;

	return_object = Signals_SiganlGetDirect(SIGNAL_CFG_GETDIRECT_DCU_2_DoorLockSts_IDX);
	*value = return_object.value;

	return return_object.errorCode;
}

SIGNAL_ERROR Signals_Get_RearLeft_DoorLockSts(uint8 * value)
{
	Signal_Get_t return_object;

	return_object = Signals_SiganlGetDirect(SIGNAL_CFG_GETDIRECT_DCU_3_DoorLockSts_IDX);
	*value = return_object.value;

	return return_object.errorCode;
}

SIGNAL_ERROR Signals_Get_RearRight_DoorLockSts(uint8 * value)
{
	Signal_Get_t return_object;

	return_object = Signals_SiganlGetDirect(SIGNAL_CFG_GETDIRECT_DCU_4_DoorLockSts_IDX);
	*value = return_object.value;

	return return_object.errorCode;
}

void Signals_Set_WindowControl_Passenger(const uint8 *value)
{
	uint8_t dcu_idx = Signals_Get_DCU_ModuleIdx();

	CALVOS_CRITICAL_ENTER();
		*signalsCfg_updateDirectTable[SIGNAL_CFG_UPDATEDIRECT_DCU_1_WdwCtrl_Pas_IDX][dcu_idx] = *value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_WindowControl_RearLeft(const uint8 *value)
{
	uint8_t dcu_idx = Signals_Get_DCU_ModuleIdx();
	
	CALVOS_CRITICAL_ENTER();
		*signalsCfg_updateDirectTable[SIGNAL_CFG_UPDATEDIRECT_DCU_1_WdwCtrl_RL_IDX][dcu_idx] = *value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_WindowControl_RearRight(const uint8 *value)
{
	CALVOS_CRITICAL_ENTER();
		*signalsCfg_updateDirectTable[SIGNAL_CFG_UPDATEDIRECT_DCU_1_WdwCtrl_RR_IDX][dcu_idx] = *value;
	CALVOS_CRITICAL_EXIT();
}

SIGNAL_ERROR Signals_Get_WindowControl_Passenger(uint8 *value)
{
	Signal_Get_t return_object;

	return_object = Signals_SiganlGetDirect(SIGNAL_CFG_GETDIRECT_DCU_1_WdwCtrl_Pas_IDX);
	*value = return_object.value;

	return return_object.errorCode;
}

SIGNAL_ERROR Signals_Get_WindowControl_RearLeft(uint8 *value)
{
	Signal_Get_t return_object;

	return_object = Signals_SiganlGetDirect(SIGNAL_CFG_GETDIRECT_DCU_1_WdwCtrl_RL_IDX);
	*value = return_object.value;

	return return_object.errorCode;
}

SIGNAL_ERROR Signals_Get_WindowControl_RearRight(uint8 *value)
{
	Signal_Get_t return_object;

	return_object = Signals_SiganlGetDirect(SIGNAL_CFG_GETDIRECT_DCU_1_WdwCtrl_RR_IDX);
	*value = return_object.value;

	return return_object.errorCode;
}

static uint8 Signals_Get_DCU_ModuleIdx()
{
	uint8_t ret_value = 0x00;

	switch(HwConfig_Get())
	{
		case HWCONFIG_DRIVER:
			ret_value = SIGNAL_CFG_DCU1_IDX
			break;
		case HWCONFIG_PASSENGER:
			ret_value = SIGNAL_CFG_DCU2_IDX
			break;
		case HWCONFIG_REAR_LEFT:
			ret_value = SIGNAL_CFG_DCU3_IDX
			break;
		case HWCONFIG_REAR_RIGHT:
			ret_value = SIGNAL_CFG_DCU4_IDX
			break;
		default:
			/* Avoid Misra - No action required */
			break:
	}

	return ret_value;
}

static Signal_Get_t Signals_SiganlGetDirect(const uint8_t signalGetDirect_idx)
{
	const uint8_t * signalGetDirectPtr = NULL;
	Signal_Get_t return_object = {.value = 0x00u, .errorCode = SIGNAL_ERROR_NO};
	uint8_t dcu_idx = 0x00u;
	

	if (SIGNAL_CFG_GETDIRECT_TABLE_LEN > signalGetDirect_idx)
	{
		dcu_idx = Signals_Get_DCU_ModuleIdx();

		signalGetDirectPtr = signalsCfg_getDirectTable[signalGetDirect_idx][dcu_idx];
		
		if (NULL != signalGetDirectPtr)
		{
			CALVOS_CRITICAL_ENTER();
				return_object.value = *signalGetDirectPtr;
			CALVOS_CRITICAL_EXIT();
		}
		else
		{
			return_object.errorCode = SIGNAL_ERROR_ERROR;			
		}
	}
	else
	{
		return_object.errorCode = SIGNAL_ERROR_ERROR;
	}
	
	return return_object;
}