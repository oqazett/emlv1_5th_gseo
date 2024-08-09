#ifndef __PWM_CONTROL_FORM_H__
#define __PWM_CONTROL_FORM_H__

#include "../pwm_register_info.h"
#include "../service/request/pwm_request.h"

struct _pwm_control_form
{
    PWM_TIMER_COUNTER_NUMBER    pwm_timer_counter_number;
    COMPARE_OUTPUT_MODE    compare_output_mode;
    WAVE_GENERATION_MODE   wave_generation_mode;
    SELECT_PRESCALE_VALUE       pwm_prescale;
};

struct _pwm_control_form pwm_control_form;

void set_pwm_control_form(PWM_TIMER_COUNTER_NUMBER  pwm_timer_counter_nunmber,
                          COMPARE_OUTPUT_MODE  compare_output_mode, 
                          WAVE_GENERATION_MODE wave_generation_mode, 
                          SELECT_PRESCALE_VALUE     pwm_prescale);
                          
struct _pwm_request convert_pwm_control_data(struct _pwm_control_form pwm_control_form);


#endif