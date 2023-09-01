/* 
 * File:   ecu_key_pad.h
 * Author: mohamed hassan
 *
 * Created on August 17, 2023, 11:24 AM
 */

#ifndef ECU_KEY_PAD_H
#define	ECU_KEY_PAD_H

/*****************************Section: Include Section*****************************/

#include "ecu_key_pad_cfg.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"
/*****************************Section: Macro Declaration*****************************/
#define ECU_KEYPAD_ROW      4
#define ECU_KEYPAD_COLOUM   4 
/*****************************Section: Macro Function*****************************/

/*****************************Section: Data Type Declaration*****************************/
typedef struct{
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROW];
    pin_config_t keypad_col_pins[ECU_KEYPAD_COLOUM];
}keypad_t;
/*****************************Section: Function Declaration*****************************/

Std_Return_type keypad_initialize(const keypad_t * _key_pad);
Std_Return_type keypad_write_value(const keypad_t * _key_pad, uint8 * value);

#endif	/* ECU_KEY_PAD_H */

