#include "ecu_iniatize.h"
/**************************led_light********************************/
led_t led_1={
  .port_name=PORTB_INDEX,
  .pin=GPIO_PIN0,
  .led_status=Led_off,
};
led_t led_2={
  .port_name=PORTB_INDEX,
  .pin=GPIO_PIN1,
  .led_status=Led_off,  
};
/**************************DC Motor********************************/
dc_motor_t DcMotor_1 = {
    .dc_motor[0].dc_motor_port = PORTA_INDEX,
    .dc_motor[0].dc_motor_pin = GPIO_PIN0,
    .dc_motor[0].dc_motor_status = DC_MOTOR_OFF_STATUS,
    .dc_motor[1].dc_motor_port = PORTA_INDEX,
    .dc_motor[1].dc_motor_pin = GPIO_PIN1,
    .dc_motor[1].dc_motor_status = DC_MOTOR_OFF_STATUS,
};
dc_motor_t DcMotor_2 = {
    .dc_motor[0].dc_motor_port = PORTA_INDEX,
    .dc_motor[0].dc_motor_pin = GPIO_PIN2,
    .dc_motor[0].dc_motor_status = DC_MOTOR_OFF_STATUS,
    .dc_motor[1].dc_motor_port = PORTA_INDEX,
    .dc_motor[1].dc_motor_pin = GPIO_PIN3,
    .dc_motor[1].dc_motor_status = DC_MOTOR_OFF_STATUS,
};
/***************************lcd_4bit*********************************/
chr_lcd_4bit_t lcd_1 = {
    .lcd_rs.port = PORTC_INDEX,
    .lcd_rs.pin = GPIO_PIN0,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_rs.diretion = GPIO_DIRECTION_OUTPUT,
    .lcd_en.port = PORTC_INDEX,
    .lcd_en.pin = GPIO_PIN1,
    .lcd_en.logic = GPIO_LOW,
    .lcd_en.diretion = GPIO_DIRECTION_OUTPUT,
    .lcd_data[0].port = PORTC_INDEX,
    .lcd_data[0].pin = GPIO_PIN2,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[0].diretion = GPIO_DIRECTION_OUTPUT,
    .lcd_data[1].port = PORTC_INDEX,
    .lcd_data[1].pin = GPIO_PIN3,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[1].diretion = GPIO_DIRECTION_OUTPUT,
    .lcd_data[2].port = PORTC_INDEX,
    .lcd_data[2].pin = GPIO_PIN4,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[2].diretion = GPIO_DIRECTION_OUTPUT,
    .lcd_data[3].port = PORTC_INDEX,
    .lcd_data[3].pin = GPIO_PIN5,
    .lcd_data[3].logic = GPIO_LOW,
    .lcd_data[3].diretion = GPIO_DIRECTION_OUTPUT,
};
///***************************keypad**********************/
keypad_t keypad1 = {
    .keypad_row_pins[0].port = PORTD_INDEX,
    .keypad_row_pins[0].pin = GPIO_PIN0,
    .keypad_row_pins[0].logic = GPIO_LOW,
    .keypad_row_pins[0].diretion = GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[1].port = PORTD_INDEX,
    .keypad_row_pins[1].pin = GPIO_PIN1,
    .keypad_row_pins[1].logic = GPIO_LOW,
    .keypad_row_pins[1].diretion = GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[2].port = PORTD_INDEX,
    .keypad_row_pins[2].pin = GPIO_PIN2,
    .keypad_row_pins[2].logic = GPIO_LOW,
    .keypad_row_pins[2].diretion = GPIO_DIRECTION_OUTPUT,
    .keypad_row_pins[3].port = PORTD_INDEX,
    .keypad_row_pins[3].pin = GPIO_PIN3,
    .keypad_row_pins[3].logic = GPIO_LOW,
    .keypad_row_pins[3].diretion = GPIO_DIRECTION_OUTPUT,
    .keypad_col_pins[0].port = PORTD_INDEX,
    .keypad_col_pins[0].pin = GPIO_PIN4,
    .keypad_col_pins[0].logic = GPIO_LOW,
    .keypad_col_pins[0].diretion = GPIO_DIRECTION_INPUT,
    .keypad_col_pins[1].port = PORTD_INDEX,
    .keypad_col_pins[1].pin = GPIO_PIN5,
    .keypad_col_pins[1].logic = GPIO_LOW,
    .keypad_col_pins[1].diretion = GPIO_DIRECTION_INPUT,
    .keypad_col_pins[2].port = PORTD_INDEX,
    .keypad_col_pins[2].pin = GPIO_PIN6,
    .keypad_col_pins[2].logic = GPIO_LOW,
    .keypad_col_pins[2].diretion = GPIO_DIRECTION_INPUT,
    .keypad_col_pins[3].port = PORTD_INDEX,
    .keypad_col_pins[3].pin = GPIO_PIN7,
    .keypad_col_pins[3].logic = GPIO_LOW,
    .keypad_col_pins[3].diretion = GPIO_DIRECTION_INPUT,
};

/*****************************function defination****************************/
void ecu_intialize(void) {
    Std_Return_type ret = E_NOT_OK;
    ret = lcd_4bit_initalize(&lcd_1);
    ret = keypad_initialize(&keypad1);
    ret = dc_motor_initialize(&DcMotor_1);
    ret = dc_motor_initialize(&DcMotor_2);
    ret = led_initialize(&led_1);
    ret = led_initialize(&led_2);
}
