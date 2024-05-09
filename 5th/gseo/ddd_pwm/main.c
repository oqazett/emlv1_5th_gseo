/*
 */

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <avr/interrupt.h>

#include <util/delay.h>
#include <stdio.h>

#include "domain/console/usart_printf.h"

#include "domain/led/entity/led.h"
#include "domain/led/service/led_service_table.h"

#include "domain/led/form/led_control_form.h"

#include "domain/pin/pin_map.h"

#include "domain/pin/form/pin_control_form.h"
#include "domain/pin/service/pin_service_table.h"

#include "domain/pwm/form/pwm_control_form.h"

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

volatile int x = 0;
ISR(TIMER0_OVF_vect)
{
    x++;
    if(x<=999){
        set_led_control_form(LED_STATUS_ON);
		led_service_call_table[LED_ON](
            convert_led_control_data(led_control_form));
    }
    else if(x>999 && x<2000)
    {
        set_led_control_form(LED_STATUS_OFF);
		led_service_call_table[LED_OFF](
            convert_led_control_data(led_control_form));
    }
    else{
        x=0;
    }
}

int main(void)
{
    //  [DDD-PWM-6]
    //  TODO : Add USART0 Initialization for Putty Debug Message.
    usart_initialize();
    stdout = &uart_output;
	_delay_ms(10);

    printf("1. Project Name    : DDD-PWM\r\n");
    printf("2. Chipset         : ATmega328p\r\n");
    printf("3. Peripheral      : PWM\r\n");
    printf("4. Software Design : Domain-Driven Design.\r\n");
    //  [DDD-PWM-0]
    //  TODO : Developer can choose the pin to control.
    //  [DDD-PWM-7]
    //  TODO : Developer can choose the pin direction.
    set_pin_control_form(PIN_PB5, PIN_OUTPUT_MODE);
    pin_service_call_table[PIN_DIRECTION] (
        convert_pin_control_data(pin_control_form) );
#if 0 
    TCCR0A = 0x00; // 노멀모드 초기화 
    TCCR0B = 0x03; //분주비 64
    TCNT0 = 250;
    TIMSK0 = 0x01; // overflow 인터럽트 발생가능
    sei(); // 인터럽트 사용
#endif
    // [DDD-PWM-1]
    // TODO : Developers can set the PWM Mode.
    // [DDD-PWM-9]
    // TODO : Timer/Counter0,1,2 Select

    set_pin_control_form(PIN_PD6, PIN_OUTPUT_MODE);
    pin_service_call_table[PIN_DIRECTION] (
        convert_pin_control_data(pin_control_form)
    );
    set_pwm_control_form(PWM_CHANNEL_OC0A, COMPARE_OUTPUT_CLEAR, FAST_PWM_OxFF, PWM_PRESCALE_64);
    struct _pwm_request test_pwm_form;
    test_pwm_form = convert_pwm_control_data(pwm_control_form);\
    // pwm_service_call_table[COM_OUTPUT_MODE](
    //     convert_pwm_control_data(pwm_control_form) );
    // pwm_service_call_table[WAVE_GEN_MODE](
    //     convert_pwm_control_data(pwm_control_form) );
    // pwm_service_call_table[PRESCALE](
    //     convert_pwm_control_data(pwm_control_form) );

    for(;;)
    {
        // [DDD-PWM-8]
        //  TODO : Developer can change status of LED.

		// set_led_control_form(LED_STATUS_OFF);
		// led_service_call_table[LED_OFF](
        //     convert_led_control_data(led_control_form));
        // _delay_ms(500);
        // set_led_control_form(LED_STATUS_ON);
		// led_service_call_table[LED_ON](
        //     convert_led_control_data(led_control_form));
        // _delay_ms(500);

	}

    return 0;
}
