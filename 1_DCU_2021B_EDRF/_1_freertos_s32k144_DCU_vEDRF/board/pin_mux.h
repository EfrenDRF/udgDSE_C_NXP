#ifndef _PIN_MUX_H_
#define _PIN_MUX_H_

#include "pins_driver.h"

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/

/*!
 * @addtogroup pin_mux
 * @{
 */

/***********************************************************************************************************************
 * API
 **********************************************************************************************************************/

#if defined(__cplusplus)
extern "C" {
#endif


/*! @brief Definitions/Declarations for BOARD_InitPins Functional Group */
/*! @brief User definition pins */
#define RED_LED_PORT    PTD
#define RED_LED_PIN     15U
#define ANTIPINCH_SIGNAL_PORT    PTC
#define ANTIPINCH_SIGNAL_PIN     14U
#define GREEN_LED_PORT    PTD
#define GREEN_LED_PIN     16U
#define PASSENGER_OPEN_BTN_PORT    PTB
#define PASSENGER_OPEN_BTN_PIN     6U
#define PASSENGER_CLOSE_BTN_PORT    PTB
#define PASSENGER_CLOSE_BTN_PIN     7U
#define REARRIGHT_OPEN_BTN_PORT    PTC
#define REARRIGHT_OPEN_BTN_PIN     5U
#define REARRIGHT_CLOSE_BTN_PORT    PTC
#define REARRIGHT_CLOSE_BTN_PIN     4U
#define REAR_WINDOW_LOCK_BTN_PORT    PTC
#define REAR_WINDOW_LOCK_BTN_PIN     17U
#define WINDOW_LED2_PORT    PTB
#define WINDOW_LED2_PIN     12U
#define WINDOW_LED1_PORT    PTD
#define WINDOW_LED1_PIN     4U
/*! @brief User number of configured pins */
#define NUM_OF_CONFIGURED_PINS0 12
/*! @brief User configuration structure */
extern pin_settings_config_t g_pin_mux_InitConfigArr0[NUM_OF_CONFIGURED_PINS0];


#if defined(__cplusplus)
}
#endif

/*!
 * @}
 */
#endif /* _PIN_MUX_H_ */

/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/

