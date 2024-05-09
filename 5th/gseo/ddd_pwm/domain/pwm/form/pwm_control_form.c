#include "pwm_control_form.h"
#include "../../pin/global_pin_map.h"
#include <stdio.h>

void set_pwm_control_form(PWM_CHANNEL pwm_channel, COMPARE_OUTPUT_MODE compare_output_mode, WAVE_GENERATION_MODE wave_generation_mode, PRESCALE_SELECT_BIT pwm_prescale)
{
    pwm_control_form.pwm_channel = pwm_channel;
    pwm_control_form.compare_output_mode = compare_output_mode;
    pwm_control_form.wave_generation_mode = wave_generation_mode;
    pwm_control_form.pwm_prescale = pwm_prescale;
}

struct _pwm_request convert_pwm_control_data(struct _pwm_control_form pwm_control_form)
{
    pwm_port_request.pwm_channel_address = pwm_map_address_vo[pwm_control_form.pwm_channel];
    pwm_port_request.compare_output_value = (pwm_control_form.compare_output_mode<<(6-((pwm_control_form.pwm_channel&0x1)*2)));
    
    if(pwm_port_request.pwm_channel_address==0x80){ // 16-bit Timer/Counter 1
        
    }
    else{   // 8-bit Timer/Counter 0,2          bit3=WGM2, bit1=WGM1, bit0=WGM0
        pwm_port_request.wave_generation_value = (
            ((pwm_control_form.wave_generation_mode&4)<<1) | (pwm_control_form.wave_generation_mode&3) );
    }

    pwm_port_request.pwm_prescale_value = pwm_control_form.pwm_prescale;

    printf("pwm_channel_address = 0x%x\n",pwm_port_request.pwm_channel_address);
    printf("compare_output_value = 0x%x\n",pwm_port_request.compare_output_value);
    printf("wave_generation_value = 0x%x\n",pwm_port_request.wave_generation_value);
    printf("prescale value = 0x%x\n",pwm_port_request.pwm_prescale_value);

    return pwm_port_request;
}