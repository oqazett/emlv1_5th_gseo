#include "pwm_repository.h"
#include "../form/pwm_control_form.h"
#include <stdio.h>
#include <avr/io.h>

uint8_t TCCRnx_LOWER_4BITS_ADDRESS = 0;

void clear_compare_output_bits(void){
    if(pwm_control_form.pwm_channel==PWM_CHANNEL_OC0A){
        (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS)) &= 0x3f;
    }
    else if(pwm_control_form.pwm_channel==PWM_CHANNEL_OC0B){
        (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS)) &= 0xcf;
    }
}

void clear_wave_generation_bits(void){
    if(pwm_control_form.pwm_channel<=PWM_CHANNEL_OC0B){
        (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS)) &= 0xf0;
        (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS + 0x1)) &= 0xf7;
    }
    else if(pwm_control_form.pwm_channel<=PWM_CHANNEL_OC1B){
        /* TBD */
    }
    else{
        (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS)) &= 0xf0;
        (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS + 0x1)) &= 0xf7;
    }
}

void set_compare_output_mode(struct _pwm_request pwm_request)
{
    if(pwm_control_form.pwm_channel<=1) TCCRnx_LOWER_4BITS_ADDRESS = 0x4;
    else TCCRnx_LOWER_4BITS_ADDRESS = 0x0;

    clear_compare_output_bits();

    (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS)) |= pwm_request.compare_output_value;
    printf("\n[PWM REPOSITORY] - Compare Output Mode\n");
    printf("pwm_channer_address = 0x%x\n", pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS);
    printf("pwm_channer_address's value = 0x%x\n", (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS)));
    printf("TCCR0A = 0x%x\n", TCCR0A);
    printf("Compare output mode setting is done!\n\n");

}

void set_wave_generation_mode(struct _pwm_request pwm_request)
{
    clear_wave_generation_bits();
}

void set_prescale(struct _pwm_request pwm_request)
{
    
}
