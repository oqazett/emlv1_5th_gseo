#ifndef __PWM_CONTROL_FORM_H__
#define __PWM_CONTROL_FORM_H__

#include "../pwm_mode.h"
#include "../../pin/service/request/pin_request.h"

struct _pwm_control_form
{
    PWM_CHANNEL pwm_channel;
    COMPARE_OUTPUT_MODE compare_output_mode;
    WAVE_GENERATION_MODE  wave_generation_mode;
    PRESCALE_SELECT_BIT pwm_prescale;
};

struct _pwm_control_form pwm_control_form;

void set_pwm_control_form(PWM_CHANNEL pwm_channel, COMPARE_OUTPUT_MODE com_output_mode, WAVE_GENERATION_MODE wave_gen_mode, PRESCALE_SELECT_BIT pwm_prescale);



#endif