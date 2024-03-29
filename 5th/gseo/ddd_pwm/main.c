/*
 */

#include <avr/io.h>
#include <avr/sfr_defs.h>

#include <util/delay.h>
#include <stdio.h>

#include "domain/console/usart_printf.h"


#include "domain/pin/pin_map.h"
#include "domain/pin/form/pin_control_form.h"
#include "domain/pin/service/pin_service_table.h"

#define F_CPU       16000000L

void LED_Toggle(void)
{
    PORTB = 0x00;
    _delay_ms(500);
    PORTB = 0x20;
    _delay_ms(500);
}

int main(void)
{
    //  [DDD-PWM-6]
    //  TODO : Add USART0 Initialization for Putty Debug Message.
    usart_initialize();
    stdout = &uart_output;
	_delay_ms(10);

    //  [DDD-PWM-0]
    //  TODO : Developer can choose the pin to control.
    //  [DDD-PWM-7]
    //  TODO : Developer can choose the pin direction.
    set_pin_control_form(PIN_PB5, PIN_OUTPUT_MODE);
    pin_service_call_table[PIN_DIRECTION] ( 
        convert_pin_control_data(pin_control_form) );

    for(;;)
    {
		// printf("Hello AVR printf\n");
		LED_Toggle();
		_delay_ms(500);
	}

    return 0;
}
