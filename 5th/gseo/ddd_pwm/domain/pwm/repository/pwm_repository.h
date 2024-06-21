#ifndef __PWM_REPOSITORY_H__
#define __PWM_REPOSITORY_H__

#include "../service/request/pwm_request.h"

enum _pwm_domain_repository{
    SET_ROTATE_SERVO_90_DEGREES
};

void set_compare_output_mode(struct _pwm_request);
void set_wave_generation_mode(struct _pwm_request);
void set_prescale(struct _pwm_request);

void set_rotate_servo_90_degrees (struct _pwm_request);


#endif