/* 
 * File:   ecu_ch_lcd_cfg.h
 * Author: mohamed hassan
 *
 * Created on August 18, 2023, 3:24 PM
 */


#include "ecu_ch_lcd.h"
/**********************************helper functions  decleration**************************/
static Std_Return_type lcd_send_4bit(const chr_lcd_4bit_t *lcd, uint8 _data_command);
static Std_Return_type lcd_send_4bit_enable_signal(const chr_lcd_4bit_t *lcd);
static Std_Return_type lcd_send_8bit(const chr_lcd_8bit_t *lcd, uint8 _data_command);
static Std_Return_type lcd_send_8bit_enable_signal(const chr_lcd_8bit_t *lcd);
static Std_Return_type lcd_8bit_set_curser(const chr_lcd_8bit_t *lcd, uint8 row, uint8 coloum);
static Std_Return_type lcd_4bit_set_curser(const chr_lcd_4bit_t *lcd, uint8 row, uint8 coloum);

/**********************************lcd function definition**************************/
Std_Return_type lcd_4bit_initalize(const chr_lcd_4bit_t *lcd) {
    uint8 lcd_data_counter = ZEROINTI;
    Std_Return_type ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_intialize(&(lcd->lcd_rs));
        ret = gpio_pin_intialize(&(lcd->lcd_en));
        for (lcd_data_counter = ZEROINTI; lcd_data_counter < 4; lcd_data_counter++) {
            ret = gpio_pin_intialize(&(lcd->lcd_data[lcd_data_counter]));
        }
        __delay_ms(20);
        ret = lcd_4bit_send_comand(lcd, LCD_8BIT_MODE_2LINE);
        __delay_ms(5);
        ret = lcd_4bit_send_comand(lcd, LCD_8BIT_MODE_2LINE);
        __delay_us(150);
        ret = lcd_4bit_send_comand(lcd, LCD_8BIT_MODE_2LINE);
        ret = lcd_4bit_send_comand(lcd, LCD_CLEAR);
        ret = lcd_4bit_send_comand(lcd, LCD_RETURN_HOME);
        ret = lcd_4bit_send_comand(lcd, LCD_ENTRY_MODE_INCREMENT);
        ret = lcd_4bit_send_comand(lcd, LCD_CURSUR_OFF_DISPLAY_ON);
        ret = lcd_4bit_send_comand(lcd, LCD_4BIT_MODE_2LINE);
        ret = lcd_4bit_send_comand(lcd, 0x80);
    }
    return ret;
}

Std_Return_type lcd_4bit_send_comand(const chr_lcd_4bit_t *lcd, uint8 comand) {
    Std_Return_type ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), GPIO_LOW);
        ret = lcd_send_4bit(lcd, comand >> 4);
        ret = lcd_send_4bit_enable_signal(lcd);
        ret = lcd_send_4bit(lcd, comand);
        ret = lcd_send_4bit_enable_signal(lcd);
    }
    return ret;
}

Std_Return_type lcd_4bit_send_char_data(const chr_lcd_4bit_t *lcd, uint8 data) {
    Std_Return_type ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), GPIO_HIGH);
        ret = lcd_send_4bit(lcd, data >> 4);
        ret = lcd_send_4bit_enable_signal(lcd);
        ret = lcd_send_4bit(lcd, data);
        ret = lcd_send_4bit_enable_signal(lcd);
    }
    return ret;
}

Std_Return_type lcd_4bit_send_char_data_pos(const chr_lcd_4bit_t *lcd, uint8 row, uint8 coloum, uint8 data) {
    Std_Return_type ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = lcd_4bit_set_curser(lcd, row, coloum);
        ret = lcd_4bit_send_char_data(lcd, data);

    }
    return ret;
}

Std_Return_type lcd_4bit_send_string(const chr_lcd_4bit_t *lcd, uint8 *str) {
    Std_Return_type ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        while (*str) {
            ret = lcd_4bit_send_char_data(lcd, *str++);
        }
    }
    return ret;
}

Std_Return_type lcd_4bit_send_string_pos(const chr_lcd_4bit_t *lcd, uint8 row, uint8 coloum, uint8 *str) {
    Std_Return_type ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = ret = lcd_4bit_set_curser(lcd, row, coloum);
        ret = lcd_4bit_send_string(lcd, str);
    }
    return ret;
}

Std_Return_type lcd_4bit_send_custom_char(const chr_lcd_4bit_t *lcd, uint8 row,
        uint8 coloum, uint8 ch[], uint8 mempos) {
    uint8 lcd_counter=ZEROINTI;
    Std_Return_type ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
         ret = lcd_4bit_send_comand(lcd, (LCD_CGRAM_START + (mempos * 8)));
        for (lcd_counter = ZEROINTI; lcd_counter < 8; lcd_counter++) {
            ret= lcd_4bit_send_char_data(lcd,ch[lcd_counter]);
        }
        ret= lcd_4bit_send_char_data_pos(lcd,row,coloum,mempos);
    }
    return ret;
}

Std_Return_type lcd_8bit_initalize(const chr_lcd_8bit_t *lcd) {
    uint8 lcd_data_counter = ZEROINTI;
    Std_Return_type ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_intialize(&(lcd->lcd_rs));
        ret = gpio_pin_intialize(&(lcd->lcd_en));
        for (lcd_data_counter = ZEROINTI; lcd_data_counter < 8; lcd_data_counter++) {
            ret = gpio_pin_intialize(&(lcd->lcd_data[lcd_data_counter]));
        }
        __delay_ms(20);
        ret = lcd_8bit_send_comand(lcd, LCD_8BIT_MODE_2LINE);
        __delay_ms(5);
        ret = lcd_8bit_send_comand(lcd, LCD_8BIT_MODE_2LINE);
        __delay_us(150);
        ret = lcd_8bit_send_comand(lcd, LCD_8BIT_MODE_2LINE);
        ret = lcd_8bit_send_comand(lcd, LCD_CLEAR);
        ret = lcd_8bit_send_comand(lcd, LCD_RETURN_HOME);
        ret = lcd_8bit_send_comand(lcd, LCD_ENTRY_MODE_INCREMENT);
        ret = lcd_8bit_send_comand(lcd, LCD_CURSUR_OFF_DISPLAY_ON);
        ret = lcd_8bit_send_comand(lcd, LCD_8BIT_MODE_2LINE);
    }
    return ret;
}

Std_Return_type lcd_8bit_send_comand(const chr_lcd_8bit_t *lcd, uint8 comand) {
    Std_Return_type ret = E_OK;
    uint8 lcd_counter_pin = ZEROINTI;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), GPIO_LOW);
        ret = lcd_send_8bit(lcd, comand);
        ret = lcd_send_8bit_enable_signal(lcd);

    }
}

Std_Return_type lcd_8bit_send_char_data(const chr_lcd_8bit_t *lcd, uint8 data) {
    Std_Return_type ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), GPIO_HIGH);
        ret = lcd_send_8bit(lcd, data);
        ret = lcd_send_8bit_enable_signal(lcd);
    }
    return ret;
}

Std_Return_type lcd_8bit_send_char_data_pos(const chr_lcd_8bit_t *lcd, uint8 row, uint8 coloum, uint8 data) {
    Std_Return_type ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = lcd_8bit_set_curser(lcd, row, coloum);
        ret = lcd_8bit_send_char_data(lcd, data);
    }
    return ret;
}

Std_Return_type lcd_8bit_send_string(const chr_lcd_8bit_t *lcd, uint8 *str) {
    Std_Return_type ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        while (*str) {
            ret = lcd_8bit_send_char_data(lcd, *str++);
        }

    }
    return ret;
}

Std_Return_type lcd_8bit_send_string_pos(const chr_lcd_8bit_t *lcd, uint8 row, uint8 coloum, uint8 *str) {
    Std_Return_type ret = E_OK;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = lcd_8bit_set_curser(lcd, row, coloum);
        ret = lcd_8bit_send_string(lcd, str);
    }
    return ret;
}

Std_Return_type lcd_8bit_send_custom_char(const chr_lcd_8bit_t *lcd, uint8 row,
                                                        uint8 coloum, uint8 ch[], uint8 mempos) {
    Std_Return_type ret = E_OK;
    uint8 lcd_counter=ZEROINTI;
    if (NULL == lcd) {
        ret = E_NOT_OK;
    } else {
        ret = lcd_8bit_send_comand(lcd, (LCD_CGRAM_START + (mempos * 8)));
        for (lcd_counter = ZEROINTI; lcd_counter < 8; lcd_counter++) {
            ret= lcd_8bit_send_char_data(lcd,ch[lcd_counter]);
        }
        ret= lcd_8bit_send_char_data_pos(lcd,row,coloum,mempos);
    }
    return ret;
}

/**********************************conversion from number to string  **************************/
Std_Return_type convert_byte_to_string(uint8 value, uint8 *str) {
    Std_Return_type ret = E_OK;
    if (NULL == str) {
        ret = E_NOT_OK;
    } else {
        memset(str, '\0', 4);
        sprintf(str, "%i", value);
    }
    return ret;
}

Std_Return_type convert_short_to_string(uint16 value, uint8 *str) {
    Std_Return_type ret = E_OK;
    if (NULL == str) {
        ret = E_NOT_OK;
    } else {
        memset(str, '\0', 6);
        sprintf(str, "%i", value);
    }
    return ret;
}

Std_Return_type convert_int_to_string(uint32 value, uint8 *str) {
    Std_Return_type ret = E_OK;
    if (NULL == str) {
        ret = E_NOT_OK;
    } else {
        memset(str, '\0', 11);
        sprintf(str, "%i", value);
    }
    return ret;
}

/**********************************helper functions **************************/

static Std_Return_type lcd_send_4bit(const chr_lcd_4bit_t *lcd, uint8 _data_command) {
    Std_Return_type ret = E_OK;
    uint8 lcd_counter_pin = ZEROINTI;
    for (lcd_counter_pin = ZEROINTI; lcd_counter_pin < 4; lcd_counter_pin++) {
        ret = gpio_pin_write_logic(&(lcd->lcd_data[lcd_counter_pin]), (_data_command >> lcd_counter_pin)& (uint8) 0x01);
    }
    return ret;
}

static Std_Return_type lcd_send_8bit(const chr_lcd_8bit_t *lcd, uint8 _data_command) {
    Std_Return_type ret = E_OK;
    uint8 lcd_counter_pin = ZEROINTI;
    for (lcd_counter_pin = ZEROINTI; lcd_counter_pin < 8; lcd_counter_pin++) {
        ret = gpio_pin_write_logic(&(lcd->lcd_data[lcd_counter_pin]), (_data_command >> lcd_counter_pin)& (uint8) 0x01);
    }
    return ret;
}

static Std_Return_type lcd_send_4bit_enable_signal(const chr_lcd_4bit_t *lcd) {
    Std_Return_type ret = E_OK;
    ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_HIGH);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_LOW);
    return ret;
}

static Std_Return_type lcd_send_8bit_enable_signal(const chr_lcd_8bit_t *lcd) {
    Std_Return_type ret = E_OK;
    ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_HIGH);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_LOW);
    return ret;
}

static Std_Return_type lcd_4bit_set_curser(const chr_lcd_4bit_t *lcd, uint8 row, uint8 coloum) {
    Std_Return_type ret = E_OK;
    coloum--;
    switch (row) {
        case 1: ret = lcd_4bit_send_comand(lcd, (0x80 + coloum));
            break;
        case 2: ret = lcd_4bit_send_comand(lcd, (0xc0 + coloum));
            break;
        case 3: ret = lcd_4bit_send_comand(lcd, (0x94 + coloum));
            break;
        case 4: ret = lcd_4bit_send_comand(lcd, (0xd4 + coloum));
            break;
        default: break;
    }
}

static Std_Return_type lcd_8bit_set_curser(const chr_lcd_8bit_t *lcd, uint8 row, uint8 coloum) {
    Std_Return_type ret = E_OK;
    coloum--;
    switch (row) {
        case 1: ret = lcd_8bit_send_comand(lcd, (0x80 + coloum));
            break;
        case 2: ret = lcd_8bit_send_comand(lcd, (0xc0 + coloum));
            break;
        case 3: ret = lcd_8bit_send_comand(lcd, (0x94 + coloum));
            break;
        case 4: ret = lcd_8bit_send_comand(lcd, (0xd4 + coloum));
            break;
        default: break;
    }
}
