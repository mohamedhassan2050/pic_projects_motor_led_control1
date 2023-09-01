/* 
 * File:   application.c
 * Author: mohamed_hassan_abd_elrhman
 *
 * Created on 10 ?????, 2023, 04:38 ?
 */

/*****************************Section: Include Section**********************************/
#include "application.h"
/*****************************Section: Macro Declaration********************************/
/*******************************Section: Global Variables*******************************/
extern chr_lcd_4bit_t lcd_1;
extern keypad_t keypad1;
extern dc_motor_t DcMotor_1;
extern dc_motor_t DcMotor_2;
extern led_t led_1;
extern led_t led_2;
Std_Return_type ret = E_NOT_OK;
uint8 keypVal1 = 0;
/*****************************Section: Macro Function***********************************/

/*****************************Section: Data Type Declaration****************************/
void led_light_choice(void);
void DC_motor_choice(void);
void DC_motor_2_func(void);
void DC_motor_1_func(void);
void Led1_func(void);
void Led2_func(void);
void choice_start(void);
void Lcd_StartUP(void);

int main() {
    application_initialize();
    Lcd_StartUP();
    choice_start();
    while (1) {
        
    }
    return (EXIT_SUCCESS);
}

void application_initialize(void) {
    Std_Return_type ret = E_NOT_OK;
    ecu_intialize();
}

void DC_motor_1_func(void) {
    ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
    while (1) {
        ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, " 1.turn right");
        ret = lcd_4bit_send_string_pos(&lcd_1, 2, 1, " 2.turn left");
        ret = lcd_4bit_send_string_pos(&lcd_1, 3, 1, " 3.turn off");
        ret = lcd_4bit_send_string_pos(&lcd_1, 4, 1, " 4.exit");
        ret = keypad_write_value(&keypad1, &keypVal1);
        if (keypVal1 == '1') {
            ret = dc_motor_move_right(&DcMotor_1);
            keypVal1='1';
        } else if (keypVal1 == '2') {
            ret = dc_motor_move_left(&DcMotor_1);
            keypVal1='2';
        } else if (keypVal1 == '3') {
            ret = dc_motor_stop(&DcMotor_1);
            keypVal1='3';
        } else if (keypVal1 == '4') {
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Loading");
            __delay_ms(250);
            keypVal1 = 0;
            break;
        } else if (keypVal1 == 0) {
            /*No thing*/
        } else {
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Wrong try again");
            __delay_ms(500);
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            keypVal1 = 0;
        }
    }
    keypVal1 = 0;
}
void DC_motor_2_func(void) {
    ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
    while (1) {
        ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, " 1.turn right");
        ret = lcd_4bit_send_string_pos(&lcd_1, 2, 1, " 2.turn left");
        ret = lcd_4bit_send_string_pos(&lcd_1, 3, 1, " 3.turn off");
        ret = lcd_4bit_send_string_pos(&lcd_1, 4, 1, " 4.exit");
        ret = keypad_write_value(&keypad1, &keypVal1);
        if (keypVal1 == '1') {
            ret = dc_motor_move_right(&DcMotor_2);
            keypVal1='1';
        } else if (keypVal1 == '2') {
            ret = dc_motor_move_left(&DcMotor_2);
            keypVal1='2';
        } else if (keypVal1 == '3') {
            ret = dc_motor_stop(&DcMotor_2);
            keypVal1='3';
        } else if (keypVal1 == '4') {
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Loading");
            __delay_ms(250);
            keypVal1 = 0;
            break;
        } else if (keypVal1 == 0) {
            /*No thing*/
        } else {
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Wrong try again");
            __delay_ms(500);
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            keypVal1 = 0;
        }
    }
    keypVal1 = 0;
}
void Led1_func(void){
    ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
    while (1) {
        ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, " 1.turn on");
        ret = lcd_4bit_send_string_pos(&lcd_1, 2, 1, " 2.turn off");
        ret = lcd_4bit_send_string_pos(&lcd_1, 3, 1, " 3.turn toggle");
        ret = lcd_4bit_send_string_pos(&lcd_1, 4, 1, " 4.exit");
        ret = keypad_write_value(&keypad1, &keypVal1);
        if (keypVal1 == '1') {
            ret = led_turn_on(&led_1);
            keypVal1='1';
        } else if (keypVal1 == '2') {
            ret = led_turn_off(&led_1);
            keypVal1='2';
        } else if (keypVal1 == '3') {
            ret = led_turn_toggle(&led_1);
            keypVal1='3';
        } else if (keypVal1 == '4') {
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Loading");
            __delay_ms(250);
            keypVal1 = 0;
            break;
        } else if (keypVal1 == 0) {
            /*No thing*/
        } else {
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Wrong try again");
            __delay_ms(500);
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            keypVal1 = 0;
        }
    }
    keypVal1 = 0;
}
void Led2_func(void){
    ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
    while (1) {
        ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, " 1.turn on");
        ret = lcd_4bit_send_string_pos(&lcd_1, 2, 1, " 2.turn off");
        ret = lcd_4bit_send_string_pos(&lcd_1, 3, 1, " 3.turn toggle");
        ret = lcd_4bit_send_string_pos(&lcd_1, 4, 1, " 4.exit");
        ret = keypad_write_value(&keypad1, &keypVal1);
        if (keypVal1 == '1') {
            ret = led_turn_on(&led_2);
            keypVal1='1';
        } else if (keypVal1 == '2') {
            ret = led_turn_off(&led_2);
            keypVal1='2';
        } else if (keypVal1 == '3') {
            ret = led_turn_toggle(&led_2);
            keypVal1='3';
        } else if (keypVal1 == '4') {
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Loading");
            __delay_ms(250);
            keypVal1 = 0;
            break;
        } else if (keypVal1 == 0) {
            /*No thing*/
        } else {
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Wrong try again");
            __delay_ms(500);
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            keypVal1 = 0;
        }
    }
    keypVal1 = 0;
}
void led_light_choice(void) {
    ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
    while (1) {
        ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, " 1.led1");
        ret = lcd_4bit_send_string_pos(&lcd_1, 2, 1, " 2.led2");
        ret = lcd_4bit_send_string_pos(&lcd_1, 3, 1, " 3.exit");
        ret = keypad_write_value(&keypad1, &keypVal1);
        if (keypVal1 == '1') {
            keypVal1 = 0;
            __delay_ms(200);
            Led1_func();
        } else if (keypVal1 == '2') {
            keypVal1 = 0;
            __delay_ms(200);
            Led2_func();
        } else if (keypVal1 == '3') {
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Loading");
            __delay_ms(250);
            keypVal1 = 0;
            break;
        } else if (keypVal1 == 0) {
            /*No thing*/
        } else {
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Wrong try again");
            __delay_ms(500);
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            keypVal1 = 0;
        }
    }
}
void DC_motor_choice(void) {
    ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
    while (1) {
        ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, " 1.DCmotor1");
        ret = lcd_4bit_send_string_pos(&lcd_1, 2, 1, " 2.DCmotor2");
        ret = lcd_4bit_send_string_pos(&lcd_1, 3, 1, " 3.exit");
        ret = keypad_write_value(&keypad1, &keypVal1);
        if (keypVal1 == '1') {
            keypVal1 = 0;
            __delay_ms(200);
            DC_motor_1_func();
        } else if (keypVal1 == '2') {
            keypVal1 = 0;
            __delay_ms(200);
            DC_motor_2_func();
        } else if (keypVal1 == '3') {
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Loading");
            __delay_ms(250);
            keypVal1 = 0;
            break;
        } else if (keypVal1 == 0) {
            /*No thing*/
        } else {
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Wrong try again");
            __delay_ms(500);
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            keypVal1 = 0;
        }
    }
}

void choice_start(void) {
    while (1) {
        ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, " 1.DCmotor");
        ret = lcd_4bit_send_string_pos(&lcd_1, 2, 1, " 2.led_light ");
        ret = lcd_4bit_send_string_pos(&lcd_1, 3, 1, " 3.turn_off");
        ret = keypad_write_value(&keypad1, &keypVal1);
        if (keypVal1 == '1') {
            keypVal1 = 0;
            __delay_ms(100);
            DC_motor_choice();
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            keypVal1 = 0;
        } else if (keypVal1 == '2') {
            keypVal1 = 0;
            __delay_ms(100);
            led_light_choice();
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            keypVal1 = 0;
        } else if (keypVal1 == '3') {
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            ret = dc_motor_stop(&DcMotor_1);
            ret = dc_motor_stop(&DcMotor_2);
            ret = led_turn_off(&led_1);
            ret = led_turn_off(&led_2);
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Loading");
            __delay_ms(250);
            keypVal1 = 0;
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            break;
        } else if (keypVal1 == 0) {
            /*No thing*/
        } else {
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            ret = lcd_4bit_send_string_pos(&lcd_1, 1, 1, "Wrong try again");
            __delay_ms(500);
            ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
            keypVal1 = 0;
        }
    }

}

void Lcd_StartUP(void) {
    ret = lcd_4bit_send_string_pos(&lcd_1, 1, 7, "welcome");
    ret = lcd_4bit_send_string_pos(&lcd_1, 2, 1, "Loading");
    __delay_ms(100);
    for (uint8 j = 0; j < 3; j++) {
        for (uint8 i = 8; i < 16; i++) {
            ret = lcd_4bit_send_char_data_pos(&lcd_1, 2, i, '.');
            __delay_ms(50);
        }
        ret = lcd_4bit_send_string_pos(&lcd_1, 2, 8, "        ");
        __delay_ms(50);
    }

    ret = lcd_4bit_send_comand(&lcd_1, LCD_CLEAR);
}