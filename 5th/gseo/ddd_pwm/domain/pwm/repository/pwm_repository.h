#ifndef __PWM_REPOSITORY_H__
#define __PWM_REPOSITORY_H__

#include "../service/request/pwm_request.h"

#define NUMBER_OF_TC16_COMPARE_OUTPUT_MODE            4
#define NUMBER_OF_TC16_WAVE_GENERATION_MODE           16
#define NUMBER_OF_TC16_PRESCALE_MODE                  8

#define TIMER_COUNTER_CONTROL_REGISTER_A              0
#define TIMER_COUNTER_CONTROL_REGISTER_B              1

#define SG90_PWM_PERIOD_TIME_20MS              39999

enum _pwm_domain_repository{
    SET_PWM_SPEC_FOR_SG90_SERVO_MOTOR,
    SET_PWM_SPEC_FOR_ROTATE_SG90_90_DEGREE_CW,
    SET_PWM_SPEC_FOR_ROTATE_SG90_90_DEGREE_CCW

};

void set_compare_output_mode(struct _pwm_request);
void set_wave_generation_mode(struct _pwm_request);
void set_prescale(struct _pwm_request);

typedef void (* TC16_compare_output_mode_handler) (struct _pwm_request);
typedef void (* TC16_wave_generation_mode_handler) (struct _pwm_request);
typedef void (* TC16_prescale_handler) (struct _pwm_request);

const TC16_compare_output_mode_handler \
      tc16_compare_output_mode_table[NUMBER_OF_TC16_COMPARE_OUTPUT_MODE];
const TC16_wave_generation_mode_handler \
      tc16_wave_generation_mode_table[NUMBER_OF_TC16_WAVE_GENERATION_MODE];
const TC16_prescale_handler \
      tc16_prescale_mode_table[NUMBER_OF_TC16_PRESCALE_MODE];

void set_pwm_spec_for_sg90_servo_motor (struct _pwm_request);
void set_pwm_spec_for_rotate_sg90_90_degree_cw (struct _pwm_request);
void set_pwm_spec_for_rotate_sg90_90_degree_ccw (struct _pwm_request);



void TC16_compare_output_mode_value_0(struct _pwm_request);
void TC16_compare_output_mode_value_1(struct _pwm_request);
void TC16_compare_output_mode_value_2(struct _pwm_request);
void TC16_compare_output_mode_value_3(struct _pwm_request);

void TC16_wave_generation_mode_value_0(struct _pwm_request);
void TC16_wave_generation_mode_value_1(struct _pwm_request);
void TC16_wave_generation_mode_value_2(struct _pwm_request);
void TC16_wave_generation_mode_value_3(struct _pwm_request);
void TC16_wave_generation_mode_value_4(struct _pwm_request);
void TC16_wave_generation_mode_value_5(struct _pwm_request);
void TC16_wave_generation_mode_value_6(struct _pwm_request);
void TC16_wave_generation_mode_value_7(struct _pwm_request);
void TC16_wave_generation_mode_value_8(struct _pwm_request);
void TC16_wave_generation_mode_value_9(struct _pwm_request);
void TC16_wave_generation_mode_value_10(struct _pwm_request);
void TC16_wave_generation_mode_value_11(struct _pwm_request);
void TC16_wave_generation_mode_value_12(struct _pwm_request);
void TC16_wave_generation_mode_value_13(struct _pwm_request);
void TC16_wave_generation_mode_value_14(struct _pwm_request);
void TC16_wave_generation_mode_value_15(struct _pwm_request);

void TC16_prescale_mode_value_0(struct _pwm_request);
void TC16_prescale_mode_value_1(struct _pwm_request);
void TC16_prescale_mode_value_2(struct _pwm_request);
void TC16_prescale_mode_value_3(struct _pwm_request);
void TC16_prescale_mode_value_4(struct _pwm_request);
void TC16_prescale_mode_value_5(struct _pwm_request);
void TC16_prescale_mode_value_6(struct _pwm_request);
void TC16_prescale_mode_value_7(struct _pwm_request);






#endif