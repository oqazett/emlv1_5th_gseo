#include "pwm_control_form.h"

void set_pwm_control_form(PWM_CHANNEL pwm_channel, COMPARE_OUTPUT_MODE compare_output_mode, WAVE_GENERATION_MODE wave_generation_mode, PRESCALE_SELECT_BIT pwm_prescale)
{
    pwm_control_form.pwm_channel = pwm_channel;
    pwm_control_form.compare_output_mode = compare_output_mode;
    pwm_control_form.wave_generation_mode = wave_generation_mode;
    pwm_control_form.pwm_prescale = pwm_prescale;
}

struct _pin_request convert_pwm_control_data(struct _pwm_control_form pwm_control_form)
{
    // pwm_port_request.hw_pin_address = 
}