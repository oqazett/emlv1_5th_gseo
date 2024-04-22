/*
 */

#include <avr/io.h>
#include <avr/sfr_defs.h>

#include <util/delay.h>
#include <stdio.h>

#include "domain/console/usart_printf.h"

#include "domain/led/entity/led.h"
#include "domain/led/service/led_service_table.h"

#include "domain/led/form/led_control_form.h"

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

void pwm_init(void)
{
    
}

int main(void)
{
    //  [DDD-PWM-6]
    //  TODO : Add USART0 Initialization for Putty Debug Message.
    usart_initialize();
    stdout = &uart_output;
	_delay_ms(10);

    printf("The PWM based on domain driven design\r\n");
    printf("Chipset : ATmega328p\r\n");
    //  [DDD-PWM-0]
    //  TODO : Developer can choose the pin to control.
    //  [DDD-PWM-7]
    //  TODO : Developer can choose the pin direction.
    set_pin_control_form(PIN_PB5, PIN_OUTPUT_MODE);
    pin_service_call_table[PIN_DIRECTION] (
        convert_pin_control_data(pin_control_form) );
    
    // [DDD-PWM-1]
    // TODO : Developers can set the PWM Mode.

    for(;;)
    {
        // [DDD-PWM-8]
        //  TODO : Developer can change status of LED.
		set_led_control_form(LED_STATUS_OFF);
		led_service_call_table[LED_OFF](
            convert_led_control_data(led_control_form));
        _delay_ms(500);
        set_led_control_form(LED_STATUS_ON);
		led_service_call_table[LED_ON](
            convert_led_control_data(led_control_form));
        _delay_ms(500);
	}

    return 0;
}
