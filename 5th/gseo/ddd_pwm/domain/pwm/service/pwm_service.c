#include <stdio.h>

#include "pwm_service.h"
#include "../repository/pwm_repository_table.h"


void pwm_setting_sg90_servo_motor (struct _pwm_request pwm_request)
{
    printf("\n PWM SETTING FOR SG90 SERVO MOTOR [PWM SERVICE]\n");
    pwm_repository_call_table[SET_PWM_SPEC_FOR_SG90_SERVO_MOTOR](pwm_request);
}
