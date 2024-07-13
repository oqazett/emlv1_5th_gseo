#include "pwm_repository.h"
#include "../form/pwm_control_form.h"
#include <stdio.h>
#include <avr/io.h>


void set_compare_output_mode(struct _pwm_request pwm_request){

    tc16_compare_output_mode_table[pwm_request.compare_output_value](pwm_request);

}

void set_wave_generation_mode(struct _pwm_request pwm_request){

    tc16_wave_generation_mode_table[pwm_request.wave_generation_value](pwm_request);

}

void set_prescale(struct _pwm_request pwm_request){
    tc16_prescale_mode_table[pwm_request.pwm_prescale_value](pwm_request);
}

void set_pwm_spec_for_sg90_servo_motor(struct _pwm_request pwm_request){

    set_compare_output_mode(pwm_request);
    set_wave_generation_mode(pwm_request);
    set_prescale(pwm_request);

    ICR1 = SG90_PWM_PERIOD_TIME_20MS; // 20ms period
}

void set_pwm_spec_for_rotate_sg90_90_degree_cw(struct _pwm_request pwm_request){
    printf("[PWM REPOSITORY] ROTATE SG90 MOTOR 90 DEGREE CW\n");

    OCR1A = 1000;
    
}

void set_pwm_spec_for_rotate_sg90_90_degree_ccw(struct _pwm_request pwm_request){
    printf("[PWM REPOSITORY] ROTATE SG90 MOTOR 90 DEGREE CCW\n");

    OCR1A = 3000;
    
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

const TC16_prescale_handler tc16_prescale_mode_table[] = {
    TC16_prescale_mode_value_0,
    TC16_prescale_mode_value_1,
    TC16_prescale_mode_value_2,
    TC16_prescale_mode_value_3,
    TC16_prescale_mode_value_4,
    TC16_prescale_mode_value_5,
    TC16_prescale_mode_value_6,
    TC16_prescale_mode_value_7

};

/* *****************************************************
    ATmega328p Timer/Counter 1 - Compare Output Mode
***************************************************** */

void TC16_compare_output_mode_value_0(struct _pwm_request pwm_request){

}
void TC16_compare_output_mode_value_1(struct _pwm_request pwm_request){

}
void TC16_compare_output_mode_value_2(struct _pwm_request pwm_request){
    printf("[PWM REPOSITORY] Compare Output Mode : non-inverting mode settings..");
    *(volatile unsigned char*)pwm_request.hw_pwm_address |= (pwm_request.compare_output_value<<6);
    
    printf(" Done!\n");
    printf("[PWM REPOSITORY] TCCR1A = 0x%x\n", TCCR1A);
}
void TC16_compare_output_mode_value_3(struct _pwm_request pwm_request){

}

/* *****************************************************
    ATmega328p Timer/Counter 1 - Wave Generation Mode
***************************************************** */

void TC16_wave_generation_mode_value_0(struct _pwm_request pwm_request){

}
void TC16_wave_generation_mode_value_1(struct _pwm_request pwm_request){

}
void TC16_wave_generation_mode_value_2(struct _pwm_request pwm_request){

}
void TC16_wave_generation_mode_value_3(struct _pwm_request pwm_request){

}
void TC16_wave_generation_mode_value_4(struct _pwm_request pwm_request){

}
void TC16_wave_generation_mode_value_5(struct _pwm_request pwm_request){

}
void TC16_wave_generation_mode_value_6(struct _pwm_request pwm_request){

}
void TC16_wave_generation_mode_value_7(struct _pwm_request pwm_request){

}
void TC16_wave_generation_mode_value_8(struct _pwm_request pwm_request){

}
void TC16_wave_generation_mode_value_9(struct _pwm_request pwm_request){

}
void TC16_wave_generation_mode_value_10(struct _pwm_request pwm_request){

}
void TC16_wave_generation_mode_value_11(struct _pwm_request pwm_request){

}
void TC16_wave_generation_mode_value_12(struct _pwm_request pwm_request){

}
void TC16_wave_generation_mode_value_13(struct _pwm_request pwm_request){

}
void TC16_wave_generation_mode_value_14(struct _pwm_request pwm_request){
    printf("[PWM REPOSITORY] Wave Generation Mode : Fast PWM, TOP : ICR1 settings...");
    *(volatile unsigned char*)(pwm_request.hw_pwm_address+TIMER_COUNTER_CONTROL_REGISTER_A) |= \
                                                    (pwm_request.wave_generation_value & 0x3);
    *(volatile unsigned char*)(pwm_request.hw_pwm_address+TIMER_COUNTER_CONTROL_REGISTER_B) |= \
                                                    (((pwm_request.wave_generation_value>>2) & 0x3)<<3);
    
    printf(" Done!\n");
    printf("[PWM REPOSITORY] TCCR1A = 0x%x\n", TCCR1A);
    printf("[PWM REPOSITORY] TCCR1B = 0x%x\n", TCCR1B);
}
void TC16_wave_generation_mode_value_15(struct _pwm_request pwm_request){

}

/* ***********************************************
    ATmega328p Timer/Counter 1 - Prescale Mode
*********************************************** */

void TC16_prescale_mode_value_0(struct _pwm_request pwm_request){

}
void TC16_prescale_mode_value_1(struct _pwm_request pwm_request){

}
void TC16_prescale_mode_value_2(struct _pwm_request pwm_request){
    printf("[PWM REPOSITORY] Presale value : 8 (2MHz) settings...");
    *(volatile unsigned char*)(pwm_request.hw_pwm_address + TIMER_COUNTER_CONTROL_REGISTER_B) |= \
                                                    pwm_request.pwm_prescale_value;
    
    printf(" Done!\n");
    printf("[PWM REPOSITORY] TCCR1B = 0x%x\n", TCCR1B);
}
void TC16_prescale_mode_value_3(struct _pwm_request pwm_request){

}
void TC16_prescale_mode_value_4(struct _pwm_request pwm_request){

}
void TC16_prescale_mode_value_5(struct _pwm_request pwm_request){

}
void TC16_prescale_mode_value_6(struct _pwm_request pwm_request){

}
void TC16_prescale_mode_value_7(struct _pwm_request pwm_request){

}
