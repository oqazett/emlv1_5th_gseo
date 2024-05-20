#ifndef __PWM_REPOSITORY_H__
#define __PWM_REPOSITORY_H__

#include "../service/request/pwm_request.h"

enum _pwm_domain_repository{
    SET_COMPARE_OUTPUT_MODE,
    SET_WAVE_GENERATION_MODE,
    SET_PRESCALE,
    PWM_REPOSITORY_END
};

void clear_compare_output_bits(struct _pwm_request);
void clear_wave_generation_bits(struct _pwm_request);
void set_timer_counter_register_address_lower_4bits(struct _pwm_request);


void set_compare_output_mode (struct _pwm_request);
void set_wave_generation_mode (struct _pwm_request);
void set_prescale (struct _pwm_request);


#endif