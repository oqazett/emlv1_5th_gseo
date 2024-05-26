#include <stdio.h>

#include "pwm_service.h"
#include "../repository/pwm_repository_table.h"


void pwm_service_compare_output_mode (struct _pwm_request pwm_request)
{
    printf("\n[PWM SERVICE] - Compare Output Mode\n");
    pwm_repository_call_table[SET_COMPARE_OUTPUT_MODE](pwm_request);
}

void pwm_service_wave_generation_mode (struct _pwm_request pwm_request)
{
    printf("\n[PWM SERVICE] - Wave Generation Mode\n");
    pwm_repository_call_table[SET_WAVE_GENERATION_MODE](pwm_request);
}

void pwm_service_prescale (struct _pwm_request pwm_request)
{
    printf("\npwm domain service : pwm prescale\n");
    pwm_repository_call_table[SET_PRESCALE](pwm_request);
}
