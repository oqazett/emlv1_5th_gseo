#include "pwm_control_form.h"
#include "../../pin/global_pin_map.h"
#include <stdio.h>

void set_pwm_control_form(PWM_CHANNEL_ADDRESS pwm_channel_address, COMPARE_OUTPUT_MODE compare_output_mode, WAVE_GENERATION_MODE wave_generation_mode, PRESCALE_SELECT_BIT pwm_prescale)
{
    pwm_control_form.pwm_channel_address = pwm_channel_address;
    pwm_control_form.compare_output_mode = compare_output_mode;
    pwm_control_form.wave_generation_mode = wave_generation_mode;
    pwm_control_form.pwm_prescale = pwm_prescale;
}

struct _pwm_request convert_pwm_control_data(struct _pwm_control_form pwm_control_form)
{
    pwm_request.pwm_channel_address = (volatile unsigned char *)pwm_control_form.pwm_channel_address;
    pwm_request.compare_output_value = (pwm_control_form.compare_output_mode<<COMPARE_OUTPUT_BIT_SHIFT);
    pwm_request.wave_generation_value = pwm_control_form.wave_generation_mode;
    pwm_request.pwm_prescale_value = pwm_control_form.pwm_prescale;

#if 0
    printf("pwm_channel_address = 0x%x\n",pwm_request.pwm_channel_address);
    printf("compare_output_value = 0x%x\n",pwm_request.compare_output_value);
    printf("wave_generation_value = 0x%x\n",pwm_request.wave_generation_value);
    printf("prescale value = 0x%x\n",pwm_request.pwm_prescale_value);
#endif

    return pwm_request;
}