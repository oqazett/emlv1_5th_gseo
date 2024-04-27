#ifndef __PWM_CONTROL_FORM_H__
#define __PWM_CONTROL_FORM_H__

#include "../pwm_mode.h"

struct _pwm_control_form
{
    COMP_OUTPUT_MODE com_output_mode;
    WAVE_GEN_MODE  wave_gen_mode;
    CLK_SELECT_BIT pwm_prescale;
};

struct _pwm_control_form pwm_control_form;

void set_pwm_control_form(COMP_OUTPUT_MODE com_output_mode, WAVE_GEN_MODE wave_gen_mode, CLK_SELECT_BIT pwm_prescale);



#endif