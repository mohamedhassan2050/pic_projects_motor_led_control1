/* 
 * File:   ecu_led.c
 * Author: The LapTop Shop
 *
 * Created on 10 ?????, 2023, 04:38 ?
 */
#include "ecu_led.h"

/**
 * 
 * @param led
 * @return 
 */
Std_Return_type led_initialize(const led_t *led) {
    Std_Return_type ret = E_OK;
    pin_config_t _pin_obj = {
        .port = led->port_name,
        .pin = led->pin,
        .diretion = GPIO_DIRECTION_OUTPUT,
        .logic = led->led_status
    };
    if (NULL == led) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_intialize(&_pin_obj);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_Return_type led_turn_on(const led_t *led) {
    Std_Return_type ret = E_OK;
    pin_config_t _pin_obj = {
        .port = led->port_name,
        .pin = led->pin,
        .diretion = GPIO_DIRECTION_OUTPUT,
        .logic = led->led_status
    };
    if (NULL == led) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_write_logic(&_pin_obj, GPIO_HIGH);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_Return_type led_turn_off(const led_t *led) {
    Std_Return_type ret = E_OK;
    pin_config_t _pin_obj = {
        .port = led->port_name,
        .pin = led->pin,
        .diretion = GPIO_DIRECTION_OUTPUT,
        .logic = led->led_status
    };
    if (NULL == led) {
        ret = E_NOT_OK;
    } else {
        ret= gpio_pin_write_logic(&_pin_obj, GPIO_LOW);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return 
 */
Std_Return_type led_turn_toggle(const led_t *led) {
    Std_Return_type ret = E_OK;
    pin_config_t _pin_obj = {
        .port = led->port_name,
        .pin = led->pin,
        .diretion = GPIO_DIRECTION_OUTPUT,
        .logic = led->led_status
    };
    if (NULL == led) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_toggle_logic(&_pin_obj);
    }
    return ret;
}
