#include "pwm_control_form.h"
#include "../../pin/global_pin_map.h"
#include <stdio.h>

void set_pwm_control_form(TC16_COMPARE_OUTPUT_MODE compare_output_mode, TC16_WAVE_GENERATION_MODE wave_generation_mode, SELECT_PRESCALE_VALUE pwm_prescale)
{
    // [DDD-PWM-9]
    // TODO : 50Hz 주기의 PWM 파형에 대한 셋팅 정보를 저장할 control form을 공간을 만든다.
    pwm_control_form.compare_output_mode = compare_output_mode;
    pwm_control_form.wave_generation_mode = wave_generation_mode;
    pwm_control_form.pwm_prescale = pwm_prescale;
}

struct _pwm_request convert_pwm_control_data(struct _pwm_control_form pwm_control_form)
{
    // [DDD-PWM-10]
    // TODO : control form에 저장되어 있는 16bit fast pwm mode 정보 값을 request form으로 변환한다.
    pwm_request.compare_output_value = pwm_control_form.compare_output_mode;
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