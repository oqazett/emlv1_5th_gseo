#ifndef __PWM_REPOSITORY_TABLE_H__
#define __PWM_REPOSITORY_TABLE_H__

#include "pwm_repository.h"

typedef void (* pwm_repository_call_ptr_t) (struct _pwm_request);

const pwm_repository_call_ptr_t pwm_repository_call_table[] = {
    set_compare_output_mode,
    set_wave_generation_mode,
    set_prescale,
};

#endif