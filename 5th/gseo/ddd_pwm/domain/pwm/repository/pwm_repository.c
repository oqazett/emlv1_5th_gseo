#include "pwm_repository.h"
#include "../form/pwm_control_form.h"
#include <stdio.h>
#include <avr/io.h>


void set_compare_output_mode(struct _pwm_request pwm_request){

    tc16_compare_output_mode_table[pwm_request.compare_output_value]();

}

void set_wave_generation_mode(struct _pwm_request pwm_request){

    tc16_wave_generation_mode_table[pwm_request.wave_generation_value]();

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

const TC16_compare_output_mode_handler tc16_compare_output_mode_table[] = {
    TC16_compare_output_mode_value_0,
    TC16_compare_output_mode_value_1,
    TC16_compare_output_mode_value_2,
    TC16_compare_output_mode_value_3,

};

const TC16_wave_generation_mode_handler tc16_wave_generation_mode_table[] = {
    TC16_wave_generation_mode_value_0,
    TC16_wave_generation_mode_value_1,
    TC16_wave_generation_mode_value_2,
    TC16_wave_generation_mode_value_3,
    TC16_wave_generation_mode_value_4,
    TC16_wave_generation_mode_value_5,
    TC16_wave_generation_mode_value_6,
    TC16_wave_generation_mode_value_7,
    TC16_wave_generation_mode_value_8,
    TC16_wave_generation_mode_value_9,
    TC16_wave_generation_mode_value_10,
    TC16_wave_generation_mode_value_11,
    TC16_wave_generation_mode_value_12,
    TC16_wave_generation_mode_value_13,
    TC16_wave_generation_mode_value_14,
    TC16_wave_generation_mode_value_15

};


void TC16_compare_output_mode_value_0(void){

}
void TC16_compare_output_mode_value_1(void){

}
void TC16_compare_output_mode_value_2(void){
    printf("[PWM REPOSITORY] Compare Output Mode : non-inserting mode settings...");
    TCCR1A |= (1<<COM1A1); //비반전 모드

    printf(" Done!\n");
}
void TC16_compare_output_mode_value_3(void){

}

void TC16_wave_generation_mode_value_0(void){

}
void TC16_wave_generation_mode_value_1(void){

}
void TC16_wave_generation_mode_value_2(void){

}
void TC16_wave_generation_mode_value_3(void){

}
void TC16_wave_generation_mode_value_4(void){

}
void TC16_wave_generation_mode_value_5(void){

}
void TC16_wave_generation_mode_value_6(void){

}
void TC16_wave_generation_mode_value_7(void){

}
void TC16_wave_generation_mode_value_8(void){

}
void TC16_wave_generation_mode_value_9(void){

}
void TC16_wave_generation_mode_value_10(void){

}
void TC16_wave_generation_mode_value_11(void){

}
void TC16_wave_generation_mode_value_12(void){

}
void TC16_wave_generation_mode_value_13(void){

}
void TC16_wave_generation_mode_value_14(void){
    printf("[PWM REPOSITORY] Wave Generation Mode : Fast PWM, TOP : ICR1 settings...");
    TCCR1A |= (1<<WGM11);
    TCCR1B |= (1<<WGM12) | (1<<WGM13); //고속 PWM 모드, TOP : ICR1

    printf(" Done!\n");
}
void TC16_wave_generation_mode_value_15(void){

}
