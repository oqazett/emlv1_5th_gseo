#include "pwm_repository.h"
#include "../form/pwm_control_form.h"
#include <stdio.h>
#include <avr/io.h>

uint8_t TCCRnx_LOWER_4BITS_ADDRESS = 0;

void set_timer_counter_register_address_lower_4bits(struct _pwm_request pwm_request){
    if(pwm_request.pwm_channel_address<=(volatile unsigned char *)PWM_CHANNEL_OC0B) TCCRnx_LOWER_4BITS_ADDRESS = 0x4;
    else TCCRnx_LOWER_4BITS_ADDRESS = 0x0;
}

void clear_compare_output_bits(struct _pwm_request pwm_request){
    if(pwm_request.pwm_channel_address==(volatile unsigned char *)PWM_CHANNEL_OC0A){
        (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS)) &= 0x3f;
    }
    else if(pwm_request.pwm_channel_address==(volatile unsigned char *)PWM_CHANNEL_OC0B){
        (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS)) &= 0xcf;
    }
}

void clear_wave_generation_bits(struct _pwm_request pwm_request){
    if(pwm_request.pwm_channel_address<=(volatile unsigned char *)PWM_CHANNEL_OC0B){
        (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS)) &= 0xf0;
        (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS + 0x1)) &= 0xf7;
    }
    else if(pwm_request.pwm_channel_address<=(volatile unsigned char *)PWM_CHANNEL_OC1B){
        /* TBD */
    }
    else{
        (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS)) &= 0xf0;
        (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS + 0x1)) &= 0xf7;
    }
}

void set_compare_output_mode(struct _pwm_request pwm_request)
{
    set_timer_counter_register_address_lower_4bits(pwm_request);
    clear_compare_output_bits(pwm_request);

    (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS)) |= pwm_request.compare_output_value;

#if DEBUG_MESSAGE    
    printf("[PWM REPOSITORY] - Compare Output Mode\n");
    printf("pwm_channer_address = 0x%x\n", pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS);
    printf("pwm_channer_address's value = 0x%x\n", (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS)));
    printf("TCCR0A = 0x%x\n", TCCR0A);
#endif
    printf("Compare output mode setting has beend completed!\n\n");
}

void set_wave_generation_mode(struct _pwm_request pwm_request)
{
    set_timer_counter_register_address_lower_4bits(pwm_request);
    clear_wave_generation_bits(pwm_request);

    (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS)) |= (pwm_request.wave_generation_value&0x3);
    (*((volatile unsigned char *)pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS + 0x1)) |= ((pwm_request.wave_generation_value&0x4)<<1);

#if DEBUG_MESSAGE    
    printf("[PWM REPOSITORY] - Compare Output Mode\n");
    printf("pwm_channer_address = 0x%x\n", pwm_request.pwm_channel_address + TCCRnx_LOWER_4BITS_ADDRESS);
    printf("TCCR0A = 0x%x\n", TCCR0A);
    printf("TCCR0B = 0x%x\n", TCCR0B);
#endif
}

void set_prescale(struct _pwm_request pwm_request)
{
    
}
