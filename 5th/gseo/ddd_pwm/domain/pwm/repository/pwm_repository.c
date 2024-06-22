#include "pwm_repository.h"
#include "../form/pwm_control_form.h"
#include <stdio.h>
#include <avr/io.h>

void set_compare_output_mode(struct _pwm_request pwm_request){
    switch(pwm_request.compare_output_value){
        case 0:
            break;
        case 1:
            break;
        case 2:
            TCCR1A |= (1<<COM1A1); //비반전 모드
            break;
        case 3:
            break;
        default:
            printf("Error ! invalid compare output mode value\n");
            break;
    }
}

void set_wave_generation_mode(struct _pwm_request pwm_request){
    switch(pwm_request.wave_generation_value){
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
            break;
        case 14:
            TCCR1A |= (1<<WGM11);
            TCCR1B |= (1<<WGM12) | (1<<WGM13); //고속 PWM 모드, TOP : ICR1
            break;
        case 15:
            break;
        
    }
}

void set_prescale(struct _pwm_request pwm_request){
    switch(pwm_request.pwm_prescale_value){
        case 0:
            break;
        case 1:
            break;
        case 2:
            TCCR1B |= (1<<CS11); //분주율 8, 2MHz
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
    }
}

void set_pwm_spec_for_sg90_servo_motor(struct _pwm_request pwm_request){
    
    set_compare_output_mode(pwm_request);
    set_wave_generation_mode(pwm_request);
    set_prescale(pwm_request);

    ICR1 = 40000; // 20ms period
}
