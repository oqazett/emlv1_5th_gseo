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
#include "domain/pwm/service/pwm_service_table.h"

#define F_CPU       16000000L

void LED_Toggle(void)
{
    PORTB = 0x00;
    _delay_ms(500);
    PORTB = 0x20;
    _delay_ms(500);
}

/* BASIC SERVO MOTOR TEST */
#if 0
#define PULSE_MIN 1000 //최소 펄스 지정
#define PULSE_MAX 5000 //최대 펄스 지정

void INIT_TIMER(void)
{
  TCCR1A |= (1<<WGM11);
  TCCR1B |= (1<<WGM12) | (1<<WGM13); //고속 PWM 모드, TOP : ICR1
  TCCR1B |= (1<<CS11); //분주율 8, 2MHz
  ICR1 = 40000; //20ms주기
  TCCR1A |= (1<<COM1A1); //비반전 모드
  DDRB |= (1<<PB1); //디지털 9번 핀
}
#endif

int main(void)
{
    //  [DDD-PWM-6]
    //  TODO : Add USART0 Initialization for Putty Debug Message.
    usart_initialize();
    stdout = &uart_output;
	_delay_ms(10);

    printf("\n Eddi Robot Academy's Embedded Master LV.1\n1. Project Name    : DDD-PWM\r\n");
    printf("2. Chipset         : ATmega328p\r\n");
    printf("3. Peripheral      : PWM\r\n");
    printf("4. Software Design : Domain-Driven Design.\r\n\n");
    //  [DDD-PWM-0]
    //  TODO : Developer can choose the pin to control.
    //  [DDD-PWM-7]
    //  TODO : Developer can choose the pin direction.

#if 0
    TCCR0A = 0x00; // 노멀모드 초기화
    TCCR0B = 0x03; //분주비 64
    TCNT0 = 250;
    TIMSK0 = 0x01; // overflow 인터럽트 발생가능
    sei(); // 인터럽트 사용
#endif
    // [DDD-PWM-1]
    // TODO : Developers can set the PWM Mode.
    // [DDD-PWM-7]
    // TODO : Timer/Counter0,1,2 Select

// 240619 22:11
#if 0
    set_pin_control_form(PIN_PD6, PIN_OUTPUT_MODE);
    pin_service_call_table[PIN_DIRECTION] (
        convert_pin_control_data(pin_control_form)
    );

    // [DDD-PWM-3]
    // TODO : Developers choose specification of Timer/Counter
    set_pwm_control_form(PWM_CHANNEL_OC0A, COMPARE_OUTPUT_SET, FAST_PWM_OCRx, PWM_PRESCALE_64);
    pwm_service_call_table[PWM_COMPARE_OUTPUT_MODE](
        convert_pwm_control_data(pwm_control_form) );
    pwm_service_call_table[PWM_WAVE_GENERATION_MODE](
        convert_pwm_control_data(pwm_control_form) );
    pwm_service_call_table[PWM_PRESCALE](
        convert_pwm_control_data(pwm_control_form) );


    //  [DDD-PWM-0]
    //  TODO : Developer can choose the pin to control.
    //  [DDD-PWM-7]
    //  TODO : Developer can choose the pin direction.
    set_pin_control_form(PIN_PB5, PIN_OUTPUT_MODE);
    pin_service_call_table[PIN_DIRECTION] (
        convert_pin_control_data(pin_control_form) );

    TIMSK0 = 0x01; // overflow 인터럽트 발생가능
    OCR0A = 0xff;
    sei(); // 인터럽트 사용
#endif   

/* 240621 Code Revision */
#if 1
    // [DDD-PWM-9]
    // TODO : control form에 50Hz PWM 파형을 생성하기 위한 
    //        compare output mode, wave generation mode, precale 정보를 전달한다.
    set_pwm_control_form(NON_INVERTING_MODE, FAST_PWM_TOP_ICR1, PRESCALE_8);
    
    // [DDD-PWM-8]
    // TODO : 서보모터의 각도를 90도 회전하는 명령을 PWM Service에 요청한다.
    pwm_service_call_table[ROTATE_SERVO_90_DEGREES](
        convert_pwm_control_data(pwm_control_form)
    );
#endif

    // INIT_TIMER();
    int i, j = 0;

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

        /**************************************/
        // for(i=PULSE_MIN; i<=PULSE_MAX; i+=20)
        // {
        //     OCR1A = i;
        //     _delay_ms(10);
        // }
        // for(j=PULSE_MAX; j>=PULSE_MIN; j-=20)
        // {
        //     OCR1A = j;
        //     _delay_ms(10);
        // }

	}

}
