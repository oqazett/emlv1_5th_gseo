#ifndef __PWM_CONTROL_FORM_H__
#define __PWM_CONTROL_FORM_H__

#include "../pwm_register_info.h"
#include "../service/request/pwm_request.h"

struct _pwm_control_form
{
    TC16_COMPARE_OUTPUT_MODE compare_output_mode;
    TC16_WAVE_GENERATION_MODE  wave_generation_mode;
    SELECT_PRESCALE_VALUE pwm_prescale;
};

struct _pwm_control_form pwm_control_form;

void set_pwm_control_form(TC16_COMPARE_OUTPUT_MODE com_output_mode, TC16_WAVE_GENERATION_MODE wave_gen_mode, SELECT_PRESCALE_VALUE pwm_prescale);
struct _pwm_request convert_pwm_control_data(struct _pwm_control_form pwm_control_form);


#endif