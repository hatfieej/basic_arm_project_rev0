// ----------------------------------------------------------------------------
// main.c - MPF - 02/21013
// ----------------------------------------------------------------------------

// includes
#include "stm32f4xx.h"

// definitions
#define COUNT_RELOAD 500

// variables
int32_t led_count;
int32_t led_state;

// prototypes

// ----------------------------------------------------------------------------
// main
// ----------------------------------------------------------------------------
int main(void){

	// enable clock to GPIOC
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;

	// configure PC13 as output
	GPIOC->MODER &= ~((int32_t)3<<26);
	GPIOC->MODER |=  ((int32_t)1<<26);

	// initialize count and LED state
	led_count = 0;
	led_state = 0;

	// configure systick
	SysTick_Config(168000);

	// loop forever
	while(1);
}

// ----------------------------------------------------------------------------
// systick
// ----------------------------------------------------------------------------
void SysTick_Handler(void){
	// if count is not zero, decrement
	if (led_count!=0) {
		led_count--;
	}
	// else toggle LED and reload count
	else {
		led_count = COUNT_RELOAD;
		// if LED is OFF, turn ON and save state
		if (led_state == 0){
			GPIOC->BSRRL = ((uint16_t)1<<13);
			led_state = 1;
		}
		// if LED is ON, turn OFF and save state
		else {
			GPIOC->BSRRH = ((uint16_t)1<<13);
			led_state = 0;
		}
	}
}
