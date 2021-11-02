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
#include "CANpal.h"
#include "comgen_CAN_includes.h"

/*Global Macro______________________________________________________________*/


/*Local variables____________________________________________________________*/


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
	SIGNAL_ERROR return_value;

	*value = 0; // Dummy sentence to assign some value for missing switch cases
	return_value = SIGNAL_ERROR_NO; // Assuming signal is always valid for now (no timeout strategy yet in place)

	switch(HwConfig_Get())
	{
		case HWCONFIG_DRIVER:
			CALVOS_CRITICAL_ENTER();
			*value = CAN_DCM_DR_get_direct_SysPwrMode();
			CALVOS_CRITICAL_EXIT();
			break;
		case HWCONFIG_PASSENGER:
			break;
		case HWCONFIG_REAR_LEFT:
			break;
		case HWCONFIG_REAR_RIGHT:
			break;
	}

	return return_value;
}

SIGNAL_ERROR Signals_Get_ConfortCmd(uint8 * value)
{
	(void)value;
	return SIGNAL_ERROR_NEVER_RECEIVED;
}

SIGNAL_ERROR Signals_Get_VehSpeed(uint8 * value)
{
	(void)value;
	return SIGNAL_ERROR_NEVER_RECEIVED;
}

SIGNAL_ERROR Signals_Get_ShiftLeverPos(uint8 * value)
{
	(void)value;
	return SIGNAL_ERROR_NEVER_RECEIVED;
}

SIGNAL_ERROR Signals_Get_ShiftLeverEng(uint8* value)
{
	(void)value;
	return SIGNAL_ERROR_NEVER_RECEIVED;
}

void Signals_Set_WindowPos(const uint8 *value)
{
	switch(HwConfig_Get())
	{
		case HWCONFIG_DRIVER:
			CALVOS_CRITICAL_ENTER();
			CAN_DCM_DR_update_direct_DCU_1_WindowPos(*value);
			CALVOS_CRITICAL_EXIT();
			break;
		case HWCONFIG_PASSENGER:
			break;
		case HWCONFIG_REAR_LEFT:
			break;
		case HWCONFIG_REAR_RIGHT:
			break;
	}
}

void Signals_Set_LockingReq(const uint8 *value)
{
	(void)value;
}

SIGNAL_ERROR Signals_Get_LockingReq_Driver(uint8 * value)
{
	(void)value;
	return SIGNAL_ERROR_NEVER_RECEIVED;
}

SIGNAL_ERROR Signals_Get_LockingReq_Passenger(uint8 * value)
{
	(void)value;
	return SIGNAL_ERROR_NEVER_RECEIVED;
}

void Signals_Set_WindowOp(const uint8* value)
{
	(void)value;
}

void Signals_Set_RearWindowLock(const uint8 *value)
{
	(void)value;
}

SIGNAL_ERROR Signals_Get_RearWindowLock(uint8 *value)
{
	(void)value;
	return SIGNAL_ERROR_NEVER_RECEIVED;
}

void Signals_Set_DoorLockSts(const uint8 *value)
{
	(void)value;
}

SIGNAL_ERROR Signals_Get_Passenger_DoorLockSts(uint8 * value)
{
	(void)value;
	return SIGNAL_ERROR_NEVER_RECEIVED;
}

SIGNAL_ERROR Signals_Get_RearLeft_DoorLockSts(uint8 * value)
{
	(void)value;
	return SIGNAL_ERROR_NEVER_RECEIVED;
}

SIGNAL_ERROR Signals_Get_RearRight_DoorLockSts(uint8 * value)
{
	(void)value;
	return SIGNAL_ERROR_NEVER_RECEIVED;
}

void Signals_Set_WindowControl_Passenger(const uint8 *value)
{
	(void)value;
}

void Signals_Set_WindowControl_RearLeft(const uint8 *value)
{
	(void)value;
}

void Signals_Set_WindowControl_RearRight(const uint8 *value)
{
	(void)value;
}

SIGNAL_ERROR Signals_Get_WindowControl_Passenger(uint8 *value)
{
	(void)value;
	return SIGNAL_ERROR_NEVER_RECEIVED;
}

SIGNAL_ERROR Signals_Get_WindowControl_RearLeft(uint8 *value)
{
	(void)value;
	return SIGNAL_ERROR_NEVER_RECEIVED;
}

SIGNAL_ERROR Signals_Get_WindowControl_RearRight(uint8 *value)
{
	(void)value;
	return SIGNAL_ERROR_NEVER_RECEIVED;
}


# if(0)
/* --------------------------- */
/* Get timeout flags functions */
/* --------------------------- */
boolean Signals_Get_Timeout_BCM_5()
{
	return TRUE;
}

boolean Signals_Get_Timeout_BCM_2()
{
	return TRUE;
}

boolean Signals_Get_Timeout_BRAKE_2()
{
	return TRUE;
}

boolean Signals_Get_Timeout_TRANSM_2()
{
	return TRUE;
}

boolean Signals_Get_Timeout_TRANSM_4()
{
	return TRUE;
}


/* -------------------- */
/* Get signal functions */
/* -------------------- */

t_BCM_5_MC Signals_Get_BCM_5_MC()
{
	t_BCM_5_MC value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

t_SysPwrMode Signals_Get_SysPwrMode()
{
	t_SysPwrMode value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

t_BCM_5_CMAC Signals_Get_BCM_5_CMAC()
{
	t_BCM_5_CMAC value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

t_BCM_2_MC Signals_Get_BCM_2_MC()
{
	t_BCM_2_MC value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

t_ConfortCmd Signals_Get_ConfortCmd()
{
	t_ConfortCmd value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

t_BCM_2_CMAC Signals_Get_BCM_2_CMAC()
{
	t_BCM_2_CMAC value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

t_VehSpeed Signals_Get_VehSpeed()
{
	t_VehSpeed value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

t_BRAKE_2_MC Signals_Get_BRAKE_2_MC()
{
	t_BRAKE_2_MC value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

t_BRAKE_2_CRC Signals_Get_BRAKE_2_CRC()
{
	t_BRAKE_2_CRC value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

t_ShiftLeverPos Signals_Get_ShiftLeverPos()
{
	t_ShiftLeverPos value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

t_TRANSM_2_MC Signals_Get_TRANSM_2_MC()
{
	t_TRANSM_2_MC value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

t_TRANSM_2_CRC Signals_Get_TRANSM_2_CRC()
{
	t_TRANSM_2_CRC value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

t_ShiftLeverEng Signals_Get_ShiftLeverEng()
{
	t_ShiftLeverEng value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

t_TRANSM_4_MC Signals_Get_TRANSM_4_MC()
{
	t_TRANSM_4_MC value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

t_TRANSM_4_CRC Signals_Get_TRANSM_4_CRC()
{
	t_TRANSM_4_CRC value;
	CALVOS_CRITICAL_ENTER();
	/* Place code to access signal from buffer */
	CALVOS_CRITICAL_EXIT();

 	return value;
}

/* -------------------- */
/* Set signal functions */
/* -------------------- */

void Signals_Set_DCU_1_WindowPos(t_WindowPos value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_1_LockingReq(t_LockingReq value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_1_WindowOp(t_WindowOp value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_1_RearWindowLock(t_RearWindowLock value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_1_DoorLockSts(t_DoorLockSts value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_1_WdwCtrl_RR(t_WindowControl value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_1_WdwCtrl_RL(t_WindowControl value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_1_WdwCtrl_Pas(t_WindowControl value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_1_MC(t_DCU_1_MC value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_1_CRC(t_DCU_1_CRC value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_2_WindowPos(t_WindowPos value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_2_LockingReq(t_LockingReq value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_2_WindowOp(t_WindowOp value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_2_DoorLockSts(t_DoorLockSts value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_2_MC(t_DCU_2_MC value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_2_CRC(t_DCU_2_CRC value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_3_WindowPos(t_WindowPos value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_3_WindowOp(t_WindowOp value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_3_DoorLockSts(t_DoorLockSts value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_3_MC(t_DCU_3_MC value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_3_CRC(t_DCU_3_CRC value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_4_WindowPos(t_WindowPos value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_4_WindowOp(t_WindowOp value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_4_DoorLockSts(t_DoorLockSts value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_4_MC(t_DCU_4_MC value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}

void Signals_Set_DCU_4_CRC(t_DCU_4_CRC value)
{
	CALVOS_CRITICAL_ENTER();
	/* Place code to write value to buffer */
	(void) value;
	CALVOS_CRITICAL_EXIT();
}
# endif
