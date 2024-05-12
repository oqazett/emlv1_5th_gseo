#ifndef __PIN_SERVICE_H__
#define __PIN_SERVICE_H__

#include "request/pwm_request.h"

enum _pwm_domain_service{
    PWM_COMPARE_OUTPUT_MODE,
    PWM_WAVE_GENERATION_MODE,
    PWM_PRESCALE,
    PWM_END
};

void set_pwm_direction (struct _pwm_request);
void set_pwm_wave_generation_mode(struct _pwm_request);
void set_pwm_prescale(struct _pwm_request);


#endif