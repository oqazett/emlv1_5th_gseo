#ifndef __PWM_REPOSITORY_H__
#define __PWM_REPOSITORY_H__

#include "../service/request/pwm_request.h"

#define NUMBER_OF_TC16_WAVE_GENERATION_MODE     16

enum _pwm_domain_repository{
    SET_PWM_SPEC_FOR_SG90_SERVO_MOTOR
};

void set_compare_output_mode(struct _pwm_request);
void set_wave_generation_mode(struct _pwm_request);
void set_prescale(struct _pwm_request);

typedef void (* TC16_wave_generation_mode_handler) (void);

const TC16_wave_generation_mode_handler \
      tc16_wave_generation_mode_table[NUMBER_OF_TC16_WAVE_GENERATION_MODE];

void set_pwm_spec_for_sg90_servo_motor (struct _pwm_request);


void TC16_wave_generation_mode_value_0(void);
void TC16_wave_generation_mode_value_1(void);
void TC16_wave_generation_mode_value_2(void);
void TC16_wave_generation_mode_value_3(void);
void TC16_wave_generation_mode_value_4(void);
void TC16_wave_generation_mode_value_5(void);
void TC16_wave_generation_mode_value_6(void);
void TC16_wave_generation_mode_value_7(void);
void TC16_wave_generation_mode_value_8(void);
void TC16_wave_generation_mode_value_9(void);
void TC16_wave_generation_mode_value_10(void);
void TC16_wave_generation_mode_value_11(void);
void TC16_wave_generation_mode_value_12(void);
void TC16_wave_generation_mode_value_13(void);
void TC16_wave_generation_mode_value_14(void);
void TC16_wave_generation_mode_value_15(void);




#endif