#ifndef __PWM_SERVICE_H__
#define __PWM_SERVICE_H__

#include "request/pwm_request.h"

enum _pwm_domain_service{
    PWM_SETTING_SG90_SERVO_MOTOR
};

void pwm_setting_sg90_servo_motor (struct _pwm_request);



#endif