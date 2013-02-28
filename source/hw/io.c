// ----------------------------------------------------------------------------
// io.c - MPF - 03/2013
// ----------------------------------------------------------------------------

// includes
#include "stm32f4xx.h"
#include "hal/io.h"

// ----------------------------------------------------------------------------
// initialize IO
// ----------------------------------------------------------------------------
void io_initialize(void){
	// enable clock to GPIOC
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

	// configure PC13 as output
	GPIOC->MODER &= ~((int32_t)3<<26);
	GPIOC->MODER |=  ((int32_t)1<<26);
}

// ----------------------------------------------------------------------------
// set IO
// ----------------------------------------------------------------------------
void io_set(io_t io){
	if (io == IO_LED) GPIOC->BSRRL = ((uint16_t)1<<13);
}

// ----------------------------------------------------------------------------
// reset IO
// ----------------------------------------------------------------------------
void io_reset(io_t io){
	if (io==IO_LED) GPIOC->BSRRH = ((uint16_t)1<<13);
}
