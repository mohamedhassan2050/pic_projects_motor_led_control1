#include "ecu_key_pad.h"

uint8 col_logic_value=0;
uint8 key_pad_matrix[ECU_KEYPAD_ROW][ECU_KEYPAD_COLOUM] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'#', '0', '=', '+'}
};

Std_Return_type keypad_initialize(const keypad_t * _key_pad) {
    Std_Return_type ret = E_OK;
    uint8 row_counter = 0, col_counter = 0;
    if (NULL == _key_pad) {
        ret = E_NOT_OK;
    } else {
        for (row_counter = 0; row_counter < ECU_KEYPAD_ROW; row_counter++) {
            gpio_pin_intialize(&(_key_pad->keypad_row_pins[row_counter]));
        }
        for (col_counter = 0; col_counter < ECU_KEYPAD_ROW; col_counter++) {
            gpio_pin_direction_intialize(&(_key_pad->keypad_col_pins[col_counter]));
        }
    }
    return ret;
}

Std_Return_type keypad_write_value(const keypad_t * _key_pad, uint8 * value) {
    uint8 row_count_val = 0, col_count_val = 0;
    uint8 row_counter_l=0;
    Std_Return_type ret = E_OK;
    if ((NULL == _key_pad) || (value == NULL)) {
        ret = E_NOT_OK;
    } else {
        for (row_count_val = 0; row_count_val < ECU_KEYPAD_ROW; row_count_val++) {
            for (row_counter_l = 0; row_counter_l < ECU_KEYPAD_ROW; row_counter_l++) {
                gpio_pin_write_logic(&(_key_pad->keypad_row_pins[row_counter_l]), GPIO_LOW);
            }
            gpio_pin_write_logic(&(_key_pad->keypad_row_pins[row_count_val]), GPIO_HIGH);
            
            for (col_count_val = 0; col_count_val < ECU_KEYPAD_COLOUM; col_count_val++) {
                gpio_pin_read_logic(&(_key_pad->keypad_col_pins[col_count_val]),&col_logic_value);
                if(col_logic_value == GPIO_HIGH){
                    *value=key_pad_matrix[row_count_val][col_count_val];
                }
            }
        }
    }
    return ret;
}