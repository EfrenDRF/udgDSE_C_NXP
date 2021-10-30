/*
 * Button_Cfg.h
 *
 *  Created on: 29 oct. 2021
 *      Author: Efren Del Real
 */

#ifndef DCU_ECUABSTRACTION_BUTTON_BUTTON_CFG_H_
#define DCU_ECUABSTRACTION_BUTTON_BUTTON_CFG_H_

#include "Button_Debounce.h"

/*Global Macro______________________________________________________________*/
#define BUTTON_CFG_LOCK_BTN_IDX                  (0x00u)
#define BUTTON_CFG_UNLOCK_BTN_IDX                (0x01u)
#define BUTTON_CFG_OPEN_BTN_IDX                  (0x02u)
#define BUTTON_CFG_CLOSE_BTN_IDX                 (0x03u)
#define BUTTON_CFG_PASSENGER_OPEN_BTN_IDX        (0x04u)
#define BUTTON_CFG_PASSENGER_CLOSE_BTN_IDX       (0x05u)
#define BUTTON_CFG_REARLEFT_OPEN_BTN_IDX         (0x06u)
#define BUTTON_CFG_REARLEFT_CLOSE_BTN_IDX        (0x07u)
#define BUTTON_CFG_REARRIGHT_OPEN_BTN_IDX        (0x08u)
#define BUTTON_CFG_REARRIGHT_CLOSE_BTN_IDX       (0x09u)
#define BUTTON_CFG_REAR_WINDOW_LOCK_BTN_IDX      (0x0Au)

#define BUTTON_CFG_TABLE_LEN                     (0x0Bu)

/*Global const def__________________________________________________________*/
extern const ButtonDeb_cfgData_t xButtonCfg_table[BUTTON_CFG_TABLE_LEN];

#endif /* DCU_ECUABSTRACTION_BUTTON_BUTTON_CFG_H_ */
