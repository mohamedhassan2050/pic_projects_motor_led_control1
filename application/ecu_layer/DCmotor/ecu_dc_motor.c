/* 
 * File:   ecu_dc_motor.c
 * Author: moha0
 *
 * Created on August 10, 2023, 4:42 PM
 */
#include "ecu_dc_motor.h"
static pin_config_t motor_pin_1;
static pin_config_t motor_pin_2;
Std_Return_type dc_motor_initialize(const dc_motor_t *_dc_motor)
{
    Std_Return_type ret = E_OK;
    if (NULL == _dc_motor) {
        ret = E_NOT_OK;
    } else {
        pin_config_t motor_pin_1={
        .port=_dc_motor->dc_motor[DC_MOTOR_PIN1].dc_motor_port,
        .pin=_dc_motor->dc_motor[DC_MOTOR_PIN1].dc_motor_pin,
        .diretion=GPIO_DIRECTION_OUTPUT,
        .logic=_dc_motor->dc_motor[DC_MOTOR_PIN1].dc_motor_status,
        };
        
        pin_config_t motor_pin_2={
        .port=_dc_motor->dc_motor[DC_MOTOR_PIN2].dc_motor_port,
        .pin=_dc_motor->dc_motor[DC_MOTOR_PIN2].dc_motor_pin,
        .diretion=GPIO_DIRECTION_OUTPUT,
        .logic=_dc_motor->dc_motor[DC_MOTOR_PIN2].dc_motor_status,
        };
        
        gpio_pin_intialize(&motor_pin_1);
        gpio_pin_intialize(&motor_pin_2);
    }
    return ret;
}
Std_Return_type dc_motor_move_right(const dc_motor_t *_dc_motor)
{
    Std_Return_type ret = E_OK;
    if (NULL == _dc_motor) {
        ret = E_NOT_OK;
    } else {
        pin_config_t motor_pin_1={
        .port=_dc_motor->dc_motor[DC_MOTOR_PIN1].dc_motor_port,
        .pin=_dc_motor->dc_motor[DC_MOTOR_PIN1].dc_motor_pin,
        .diretion=GPIO_DIRECTION_OUTPUT,
        .logic=_dc_motor->dc_motor[DC_MOTOR_PIN1].dc_motor_status,
        };
        
        pin_config_t motor_pin_2={
        .port=_dc_motor->dc_motor[DC_MOTOR_PIN2].dc_motor_port,
        .pin=_dc_motor->dc_motor[DC_MOTOR_PIN2].dc_motor_pin,
        .diretion=GPIO_DIRECTION_OUTPUT,
        .logic=_dc_motor->dc_motor[DC_MOTOR_PIN2].dc_motor_status,
        };
        gpio_pin_write_logic(&motor_pin_1,GPIO_HIGH);
        gpio_pin_write_logic(&motor_pin_2,GPIO_LOW);
    }
    return ret;
}
Std_Return_type dc_motor_move_left(const dc_motor_t *_dc_motor)
{
    Std_Return_type ret = E_OK;
    if (NULL == _dc_motor) {
        ret = E_NOT_OK;
    } else {
        pin_config_t motor_pin_1={
        .port=_dc_motor->dc_motor[DC_MOTOR_PIN1].dc_motor_port,
        .pin=_dc_motor->dc_motor[DC_MOTOR_PIN1].dc_motor_pin,
        .diretion=GPIO_DIRECTION_OUTPUT,
        .logic=_dc_motor->dc_motor[DC_MOTOR_PIN1].dc_motor_status,
        };
        
        pin_config_t motor_pin_2={
        .port=_dc_motor->dc_motor[DC_MOTOR_PIN2].dc_motor_port,
        .pin=_dc_motor->dc_motor[DC_MOTOR_PIN2].dc_motor_pin,
        .diretion=GPIO_DIRECTION_OUTPUT,
        .logic=_dc_motor->dc_motor[DC_MOTOR_PIN2].dc_motor_status,
        };
        gpio_pin_write_logic(&motor_pin_1,GPIO_LOW);
        gpio_pin_write_logic(&motor_pin_2,GPIO_HIGH);
    }
    return ret;
}
Std_Return_type dc_motor_stop(const dc_motor_t *_dc_motor)
{
    Std_Return_type ret = E_OK;
    if (NULL == _dc_motor) {
        ret = E_NOT_OK;
    } else {
        pin_config_t motor_pin_1={
        .port=_dc_motor->dc_motor[DC_MOTOR_PIN1].dc_motor_port,
        .pin=_dc_motor->dc_motor[DC_MOTOR_PIN1].dc_motor_pin,
        .diretion=GPIO_DIRECTION_OUTPUT,
        .logic=_dc_motor->dc_motor[DC_MOTOR_PIN1].dc_motor_status,
        };
        
        pin_config_t motor_pin_2={
        .port=_dc_motor->dc_motor[DC_MOTOR_PIN2].dc_motor_port,
        .pin=_dc_motor->dc_motor[DC_MOTOR_PIN2].dc_motor_pin,
        .diretion=GPIO_DIRECTION_OUTPUT,
        .logic=_dc_motor->dc_motor[DC_MOTOR_PIN2].dc_motor_status,
        };
        gpio_pin_write_logic(&motor_pin_1,GPIO_LOW);
        gpio_pin_write_logic(&motor_pin_2,GPIO_LOW);
    }
    return ret;
}

