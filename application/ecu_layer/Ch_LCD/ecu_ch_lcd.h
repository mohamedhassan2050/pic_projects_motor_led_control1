 /* 
 * File:   ecu_ch_lcd.h
 * Author: mohamed hassan
 *
 * Created on August 18, 2023, 3:24 PM
 */

#ifndef ECU_CH_LCD_H
#define	ECU_CH_LCD_H

/*****************************Section: Include Section*****************************/
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "ecu_ch_lcd_cfg.h"
/*****************************Section: Macro Declaration*****************************/
#define LCD_CLEAR                              0x01
#define LCD_RETURN_HOME                        0X02

#define LCD_ENTRY_MODE_DCREMENT                0X04
#define LCD_ENTRY_MODE_SHIFT                   0X05
#define LCD_ENTRY_MODE_INCREMENT               0X06
#define LCD_ENTRY_MODE_INCREMENT_WITHSHIFT     0X07

#define LCD_CURSUR_OFF_DISPLAY_ON              0X0C
#define LCD_CURSUR_OFF_DISPLAY_OFF             0X08
#define LCD_CURSUR_ON_BLINK_ON                 0X0F
#define LCD_CURSUR_ON_BLINK_OFF                0X0E

#define LCD_DISPLAY_SHIFT_RIGHT                0X1C
#define LCD_DISPLAY_SHIFT_LEFT                 0X18

#define LCD_8BIT_MODE_2LINE                    0X38
#define LCD_4BIT_MODE_2LINE                    0X28

#define LCD_CGRAM_START                        0X40
#define LCD_DDRAM_START                        0X80


/*****************************Section: Macro Function*****************************/

/*****************************Section: Data Type Declaration*****************************/
typedef struct{
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[4];
}chr_lcd_4bit_t;

typedef struct{
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[8];
}chr_lcd_8bit_t;

/****************************Section: Function Declaration*****************************/
Std_Return_type  lcd_4bit_initalize(const chr_lcd_4bit_t *lcd);
Std_Return_type  lcd_4bit_send_comand(const chr_lcd_4bit_t *lcd,uint8 comand);
Std_Return_type  lcd_4bit_send_char_data(const chr_lcd_4bit_t *lcd,uint8 data);
Std_Return_type  lcd_4bit_send_char_data_pos(const chr_lcd_4bit_t *lcd, uint8 row, uint8 coloum, uint8 data);
Std_Return_type  lcd_4bit_send_string(const chr_lcd_4bit_t *lcd, uint8 *str);
Std_Return_type  lcd_4bit_send_string_pos(const chr_lcd_4bit_t *lcd, uint8 row, uint8 coloum, uint8 *str);
Std_Return_type  lcd_4bit_send_custom_char(const chr_lcd_4bit_t *lcd, uint8 row,
                                           uint8 coloum, uint8 ch[], uint8 mempos);

Std_Return_type  lcd_8bit_initalize(const chr_lcd_8bit_t *lcd);
Std_Return_type  lcd_8bit_send_comand(const chr_lcd_8bit_t *lcd,uint8 comand);
Std_Return_type  lcd_8bit_send_char_data(const chr_lcd_8bit_t *lcd,uint8 data);
Std_Return_type  lcd_8bit_send_char_data_pos(const chr_lcd_8bit_t *lcd, uint8 row, uint8 coloum, uint8 data);
Std_Return_type  lcd_8bit_send_string(const chr_lcd_8bit_t *lcd, uint8 *str);
Std_Return_type  lcd_8bit_send_string_pos(const chr_lcd_8bit_t *lcd, uint8 row, uint8 coloum, uint8 *str);
Std_Return_type  lcd_8bit_send_custom_char(const chr_lcd_8bit_t *lcd, uint8 row,
                                           uint8 coloum, uint8 ch[], uint8 mempos);

Std_Return_type convert_byte_to_string(uint8 value,uint8 *str);
Std_Return_type convert_short_to_string(uint16 value,uint8 *str);
Std_Return_type convert_int_to_string(uint32 value,uint8 *str);
#endif	/* ECU_CH_LCD_H */

