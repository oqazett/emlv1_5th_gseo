#include "pwm_service.h"
// #include "../repository/pwm_repository_table.h"

void set_pwm_compare_output_mode (struct _pwm_request pwm_request)
{
    printf("pwm domain service : compare output mode\n");
    // pwm_repository_call_table[SET_COMPARE_OUTPUT_MODE](pwm_port_request);    
}

void set_pwm_wave_generation_mode (struct _pwm_request pwm_request)
{
    printf("pwm domain service : wave generation mode\n");
    // pwm_repository_call_table[SET_WAVE_GENERATION_MODE](pwm_port_request);
}

void set_pwm_prescale (struct _pwm_request pwm_request)
{
    printf("pwm domain service : pwm prescale\n");
    //  pwm_repository_call_table[SET_PRESCALE](pwm_port_request);
}