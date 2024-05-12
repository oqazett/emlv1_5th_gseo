#ifndef __PWM_SERVICE_H__
#define __PWM_SERVICE_H__

#include "request/pwm_request.h"

enum _pwm_domain_service{
    PWM_COMPARE_OUTPUT_MODE,
    PWM_WAVE_GENERATION_MODE,
    PWM_PRESCALE,
    PWM_SERVICE_END
};

void pwm_service_compare_output_mode (struct _pwm_request);
void pwm_service_wave_generation_mode(struct _pwm_request);
void pwm_service_prescale(struct _pwm_request);


#endif