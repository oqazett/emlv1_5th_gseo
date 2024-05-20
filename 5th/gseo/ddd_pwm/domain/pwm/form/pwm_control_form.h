#ifndef __PWM_CONTROL_FORM_H__
#define __PWM_CONTROL_FORM_H__

#include "../pwm_register_info.h"
#include "../service/request/pwm_request.h"

struct _pwm_control_form
{
    PWM_CHANNEL_ADDRESS pwm_channel_address;
    COMPARE_OUTPUT_MODE compare_output_mode;
    WAVE_GENERATION_MODE  wave_generation_mode;
    PRESCALE_SELECT_BIT pwm_prescale;
};

struct _pwm_control_form pwm_control_form;

void set_pwm_control_form(PWM_CHANNEL_ADDRESS pwm_channel_address, COMPARE_OUTPUT_MODE com_output_mode, WAVE_GENERATION_MODE wave_gen_mode, PRESCALE_SELECT_BIT pwm_prescale);
struct _pwm_request convert_pwm_control_data(struct _pwm_control_form pwm_control_form);

#define COMPARE_OUTPUT_BIT_SHIFT    (6-((pwm_control_form.pwm_channel_address&0x1)*2))

#endif