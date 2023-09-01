/* 
 * File:   mcal_std_type.h
 * Author: mohamed hassan
 *
 * Created on 10 ?????, 2023, 04:57 ?
 */

#ifndef MCAL_STD_TYPE_H
#define	MCAL_STD_TYPE_H


/*****************************Section: Include Section*****************************/
#include "compiler.h"
#include "device_config.h"
#include "Platform_types.h"
#include "std_liberaries.h"
/*****************************Section: Macro Function*****************************/

/*****************************Section: Data Type Declaration*****************************/
typedef uint8 Std_Return_type;


/*****************************Section: Macro Declaration*****************************/
#define STD_HIGH          (0X01)
#define STD_LOW           (0X00)

#define STD_ON            (0X01)
#define STD_OFF           (0X00)

#define STD_ACTIVE        (0X01)
#define STD_IDLE          (0X00)

#define E_NOT_OK              ((Std_Return_type)0X01)
#define E_OK                  ((Std_Return_type)0X00)

/*****************************Section: Function Declaration*****************************/



#endif	/* MCAL_STD_TYPE_H */

