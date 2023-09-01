/* 
 * File:   ecu_iniatize.h
 * Author: mohamed hassan
 *
 * Created on August 17, 2023, 11:16 AM
 */

#ifndef ECU_INIATIZE_H
#define	ECU_INIATIZE_H

/****************************Section: Include Section*****************************/
#include "../led/ecu_led.h"
#include "../button/ecu_button.h"
#include "../Relay/ecu_relay.h"
#include "../DCmotor/ecu_dc_motor.h"
#include "../7_Segment/ecu_seven_segment.h"
#include "../key_pad/ecu_key_pad.h"
#include "../Ch_LCD/ecu_ch_lcd.h"
/*****************************Section: Macro Declaration*****************************/

/*****************************Section: Macro Function*****************************/

/*****************************Section: Data Type Declaration*****************************/

/*****************************Section: Function Declaration*****************************/
void ecu_intialize(void);
#endif	/* ECU_INIATIZE_H */

