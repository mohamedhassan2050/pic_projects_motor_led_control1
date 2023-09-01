/* 
 * File:   hal_gpio.c
 * Author: The LapTop Shop
 *
 * Created on 10 ?????, 2023, 04:38 ?
 */
#include "hal_gpio.h"
/*Reference to Data Direction Control Register*/
volatile uint8 *tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
/*Reference to Data Latch Control Register(write or read data )*/
volatile uint8 *lat_registers[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
/*Reference to Data Port Status Register*/
 volatile uint8 *port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};


/**
 * 
 * @param _pin_config pointer to the @ref _pin_config
 * @return state of the function
 *          (E_OK) if the function done successfully
 *           (E_NOT_OK) if the function done successfully    
 */
#if GPIO_PORT_PIN_CONFIGURATION == CONFIG_ENABLE
Std_Return_type gpio_pin_direction_intialize(const pin_config_t *_pin_config) {
    
    Std_Return_type ret = E_OK;

    if ((NULL == _pin_config) || ((_pin_config->pin) > PORT_MAX_PIN_NUMBER-1) ) {
        ret = E_NOT_OK;
    } else {
        switch ( _pin_config->diretion ) {
            case GPIO_DIRECTION_OUTPUT:
                REG_CLEARBIT(*tris_registers[_pin_config->port], _pin_config->pin);
                break;
            case GPIO_DIRECTION_INPUT:
                REG_SETBIT(*tris_registers[_pin_config->port], _pin_config->pin);
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config pointer to the @ref _pin_config
 * @param direction_status
 * @return state of the function
 *          (E_OK) if the function done successfully
 *           (E_NOT_OK) if the function done successfully    
 */
#if GPIO_PORT_PIN_CONFIGURATION == CONFIG_ENABLE
Std_Return_type gpio_pin_get_direction_status(const pin_config_t *_pin_config, direction_t *direction_status) {
    Std_Return_type ret = E_OK;
    if ((NULL == _pin_config) || (direction_status==NULL) || ((_pin_config->pin) > PORT_MAX_PIN_NUMBER-1)) {
        ret = E_NOT_OK;
    } else {
        *direction_status=READ_BIT(*tris_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config pointer to the @ref _pin_config
 * @param logic_t
 * @return state of the function
 *          (E_OK) if the function done successfully
 *           (E_NOT_OK) if the function done successfully    
 */
#if GPIO_PORT_PIN_CONFIGURATION == CONFIG_ENABLE
Std_Return_type gpio_pin_write_logic(const pin_config_t *_pin_config,logic_t logic){
    Std_Return_type ret = E_OK;
    if ((NULL == _pin_config)||((_pin_config->pin) > PORT_MAX_PIN_NUMBER-1)) {
        ret = E_NOT_OK;
    } else {
        switch( logic )
        {
            case GPIO_LOW:
                REG_CLEARBIT(*lat_registers[_pin_config->port], _pin_config->pin);
                break;
            case GPIO_HIGH:
                REG_SETBIT(*lat_registers[_pin_config->port], _pin_config->pin);
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config pointer to the @ref _pin_config
 * @param logic_t
 * @return state of the function
 *          (E_OK) if the function done successfully
 *           (E_NOT_OK) if the function done successfully           
 */
#if GPIO_PORT_PIN_CONFIGURATION == CONFIG_ENABLE
Std_Return_type gpio_pin_read_logic(const pin_config_t *_pin_config,logic_t *logic) {
    Std_Return_type ret = E_OK;
    if ((NULL == _pin_config) || (logic == NULL ) || (_pin_config->pin > PORT_MAX_PIN_NUMBER-1) ) {
        ret = E_NOT_OK;
    } else {
        *logic=READ_BIT(*port_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
}
#endif
/**
 * 
 * @param _pin_config pointer to the @ref _pin_config
 * @returnstate of the function
 *          (E_OK) if the function done successfully
 *           (E_NOT_OK) if the function done successfully     
 */
#if GPIO_PORT_PIN_CONFIGURATION == CONFIG_ENABLE
Std_Return_type gpio_pin_toggle_logic(const pin_config_t *_pin_config) {
    Std_Return_type ret = E_OK;
    if ((NULL == _pin_config)||((_pin_config->pin) > PORT_MAX_PIN_NUMBER-1)) {
        ret = E_NOT_OK;
    } else {
        REG_TOGGLEBIT(*lat_registers[_pin_config->port], _pin_config->pin);
    }
    return ret;
}
/**
 * 
 * @param _pin_config pointer to the @ref _pin_config
 * @return state of the function
 *          (E_OK) if the function done successfully
 *           (E_NOT_OK) if the function done successfully  
 */
Std_Return_type gpio_pin_intialize(const pin_config_t *_pin_config)
{
    Std_Return_type ret = E_OK;
    if ((NULL == _pin_config)||((_pin_config->pin) > PORT_MAX_PIN_NUMBER-1)) {
        ret = E_NOT_OK;
    } else {
        ret=gpio_pin_direction_intialize(_pin_config);
        ret=gpio_pin_write_logic(_pin_config,_pin_config->logic);
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @return state of the function
 *          (E_OK) if the function done successfully
 *           (E_NOT_OK) if the function done successfully    
 */
#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
Std_Return_type gpio_port_direction_intialize(port_index_t port,uint8 direction) {
    Std_Return_type ret = E_OK;
    if(port > PORT_MAX_NUMBER-1)
    {
        ret = E_NOT_OK;
    }else{
        *tris_registers[port]=direction;
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param direction_status
 * @return state of the function
 *          (E_OK) if the function done successfully
 *           (E_NOT_OK) if the function done successfully    
 */
#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
Std_Return_type gpio_port_get_direction_status(port_index_t port, uint8 *direction_status) {
    Std_Return_type ret = E_OK;
    if ((direction_status==NULL)||(port > PORT_MAX_NUMBER-1) ) {
        ret = E_NOT_OK;
    } else {
       *direction_status =*tris_registers[port];
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return state of the function
 *          (E_OK) if the function done successfully
 *           (E_NOT_OK) if the function done successfully    
 */
#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
Std_Return_type gpio_port_write_logic(port_index_t port, uint8 logic) {
    Std_Return_type ret = E_OK;
    if (port > PORT_MAX_NUMBER-1) {
        ret = E_NOT_OK;
    } else {
       *lat_registers[port]=logic;
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return state of the function
 *          (E_OK) if the function done successfully
 *           (E_NOT_OK) if the function done successfully    
 */
#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
Std_Return_type gpio_port_read_logic(port_index_t port, uint8 *logic) {
    Std_Return_type ret = E_OK;
    if ( (NULL == logic)||(port > PORT_MAX_NUMBER-1) ) {
        ret = E_NOT_OK;
    } else {
        *logic=*lat_registers[port];
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @return state of the function
 *          (E_OK) if the function done successfully
 *           (E_NOT_OK) if the function done successfully    
 */
#if GPIO_PORT_CONFIGURATION == CONFIG_ENABLE
Std_Return_type gpio_port_toggle_logic(port_index_t port) {
    Std_Return_type ret = E_OK;
    if (port > PORT_MAX_NUMBER-1){
        ret = E_NOT_OK;
    } else {
        *lat_registers[port] ^= PORTC_MASK;
    }
    return ret;
}
#endif




