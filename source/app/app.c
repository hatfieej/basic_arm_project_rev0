// ----------------------------------------------------------------------------
// app.c - MPF - 03/2013
// ----------------------------------------------------------------------------

// includes
#include <stdint.h>
#include "app.h"
#include "hal/io.h"

// definitions
#define COUNT_RELOAD 500

// variables
int32_t led_count;
int32_t led_state;

// ----------------------------------------------------------------------------
// application initialize
// ----------------------------------------------------------------------------
void app_initialize(void){
	// initialize IO
	io_initialize();

	// initialize count and LED state
	led_count = 0;
	led_state = 0;
}

// ----------------------------------------------------------------------------
// application event - call this every 500ms
// ----------------------------------------------------------------------------
void app_event(void){
	// if count is not zero, decrement
	if (led_count!=0) {
		led_count--;
	}
	// else toggle LED and reload count
	else {
		led_count = COUNT_RELOAD;
		// if LED is OFF, turn ON and save state
		if (led_state == 0){
			io_set(IO_LED);
			led_state = 1;
		}
		// if LED is ON, turn OFF and save state
		else {
			io_reset(IO_LED);
			led_state = 0;
		}
	}
}



