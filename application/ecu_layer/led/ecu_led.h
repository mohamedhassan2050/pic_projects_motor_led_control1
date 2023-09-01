/*
 * File:   ecu_led.h
 * Author: mohamed hassan
 *
 * Created on 10 ?????, 2023, 05:04 ?
 */

#ifndef ECU_LED_H
#define	 ECU_LED_H
/*****************************Section: Include Section*****************************/
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"
/*****************************Section: Macro Declaration*****************************/

/*****************************Section: Macro Function*****************************/

/*****************************Section: Data Type Declaration*****************************/
typedef enum{
    Led_off,
    Led_on,
}led_status_t;
typedef struct{
    uint8 port_name:3;
    uint8 pin:3;
    uint8 led_status:1;
    uint8 led_reserved:1;
}led_t;    
/*****************************Section: Function Declaration*****************************/
Std_Return_type led_initialize(const led_t *led);
Std_Return_type led_turn_on(const led_t *led);
Std_Return_type led_turn_off(const led_t *led);
Std_Return_type led_turn_toggle(const led_t *led);
#endif	/* ECU_LED_H */

