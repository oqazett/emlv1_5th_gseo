#include "pwm_control_form.h"

void set_pwm_control_form(COMP_OUTPUT_MODE com_output_mode, WAVE_GEN_MODE wave_gen_mode, CLK_SELECT_BIT pwm_prescale)
{
    pwm_control_form.com_output_mode = com_output_mode;
    pwm_control_form.wave_gen_mode = wave_gen_mode;
    pwm_control_form.pwm_prescale = pwm_prescale;
}