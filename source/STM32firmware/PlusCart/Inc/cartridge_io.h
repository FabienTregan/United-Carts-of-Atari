#ifndef CARTRIDGE_IO_H
#define CARTRIDGE_IO_H

#include "stm32f4xx.h"
#include <stdint.h>


#if HARDWARE_TYPE == UNOCART
 #define ADDR_IN ((uint16_t)(GPIOD->IDR))
 #define DATA_IN ((uint16_t)(GPIOE->IDR))
 #define DATA_IN_BYTE (GPIOE->IDR & 0xFF)
 #define DATA_OUT GPIOE->ODR
 #define CONTROL_IN GPIOC->IDR
 #define SET_DATA_MODE_IN GPIOE->MODER = 0x00000000;
 #define SET_DATA_MODE_OUT GPIOE->MODER = 0x55550000;
#else
 #define ADDR_IN ((uint16_t)(GPIOD->IDR))
 #define DATA_IN ((uint16_t)(GPIOC->IDR))
 #define DATA_IN_BYTE (GPIOC->IDR & 0xFF)
 #define DATA_OUT GPIOC->ODR
 #define SET_DATA_MODE_IN GPIOC->MODER = 0x00000000;
 #define SET_DATA_MODE_OUT GPIOC->MODER = 0x00005555;
#endif

#endif // CARTRIDGE_IO_H
