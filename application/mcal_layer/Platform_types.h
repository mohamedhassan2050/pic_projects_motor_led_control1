/* 
 * File:   Platform_types.h
 * Author: moha0
 *
 * Created on July 16, 2023, 6:03 PM
 */

#ifndef PLATFORM_TYPES_H
#define	PLATFORM_TYPES_H

#define CPU_TYPE_8 (8)
#define CPU_TYPE_16 (16)
#define CPU_TYPE_32 (32)
#define CPU_TYPE_64 (64)

#define CPU_TYPE (CPU_TYPE_64)

#if ( CPU_TYPE == CPU_TYPE_64 )
typedef unsigned char boolen;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed int sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#elif (CPU_TYPE==CPU_TYPE_32)
typedef unsigned char boolen;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#elif (CPU_TYPE==CPU_TYPE_16)

typedef unsigned char boolen;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef unsigned long long uint64;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef signed long long sint64;
typedef float float32;
typedef double float64;

#elif (CPU_TYPE == CPU_TYPE_8)

typedef unsigned char boolen;
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;
typedef signed char sint8;
typedef signed short sint16;
typedef signed long sint32;
typedef float float32;

#endif

#endif	/* PLATFORM_TYPES_H */

