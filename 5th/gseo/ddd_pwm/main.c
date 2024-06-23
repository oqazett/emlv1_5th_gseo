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

/* 240621 Code Revision */
#if 1
    // [DDD-PWM-9]
    // TODO : control form에 50Hz PWM 파형을 생성하기 위한
    //        compare output mode, wave generation mode, precale 정보를 전달한다.
    set_pwm_control_form(NON_INVERTING_MODE, FAST_PWM_TOP_ICR1, PRESCALE_8);
    
    // [DDD-PWM-8]
    // TODO : 개발자는 SG90 서보모터를 동작시키기 위해
    //        PWM를 설정해야 하는데, 이 때 PWM Setting을 Service에 요청하는 코드를 작성한다.
    pwm_service_call_table[PWM_SETTING_SG90_SERVO_MOTOR](
        convert_pwm_control_data(pwm_control_form)
    );

    set_pin_control_form(PIN_PB1, PIN_OUTPUT_MODE);
    pin_service_call_table[PIN_DIRECTION] (
        convert_pin_control_data(pin_control_form)
    );
#endif

    for(;;)
    {
        OCR1A = 1000;
        _delay_ms(1000);
        OCR1A = 3000;
        _delay_ms(1000);
	}

}
