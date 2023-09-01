/* 
 * File:   ecu_dc_motor.h
 * Author: mohamed hassan
 *
 * Created on August 10, 2023, 4:41 PM
 */

#ifndef ECU_MOTOR_H
#define	ECU_MOTOR_H
/*****************************Section: Include Section*****************************/
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "ecu_dc_motor_cfg.h"
/*****************************Section: Macro Declaration*****************************/
#define DC_MOTOR_ON_STATUS  0x01U
#define DC_MOTOR_OFF_STATUS  0x00U

#define DC_MOTOR_PIN1   0x00U 
#define DC_MOTOR_PIN2   0x01U 

/*****************************Section: Macro Function*****************************/

/*****************************Section: Data Type Declaration*****************************/
typedef struct{
    uint8 dc_motor_port  :4;
    uint8 dc_motor_pin   :3;
    uint8 dc_motor_status :1;
}dc_motor_pin_t;

typedef struct{
    dc_motor_pin_t dc_motor[2];
}dc_motor_t;
/*********************************function decleration*********************/
Std_Return_type dc_motor_initialize(const dc_motor_t *_dc_motor);
Std_Return_type dc_motor_move_right(const dc_motor_t *_dc_motor);
Std_Return_type dc_motor_move_left(const dc_motor_t *_dc_motor);
Std_Return_type dc_motor_stop(const dc_motor_t *_dc_motor);

#endif	/* ECU_MOTOR_H */

