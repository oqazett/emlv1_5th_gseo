#ifndef __PWM_REPOSITORY_H__
#define __PWM_REPOSITORY_H__

#include "../service/request/pwm_request.h"

enum _pwm_domain_repository{
    SET_PWM_SPEC_FOR_SG90_SERVO_MOTOR
};

void set_compare_output_mode(struct _pwm_request);
void set_wave_generation_mode(struct _pwm_request);
void set_prescale(struct _pwm_request);

void set_pwm_spec_for_sg90_servo_motor (struct _pwm_request);


#endif