#include <stdio.h>

#include "pwm_service.h"
#include "../repository/pwm_repository_table.h"


void rotate_servo_90_degrees (struct _pwm_request pwm_request)
{
    printf("\n ROTATE THE SERVO MOTOR 90 DEGREES\n");
    pwm_repository_call_table[SET_ROTATE_SERVO_90_DEGREES](pwm_request);
}
