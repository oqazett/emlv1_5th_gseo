#ifndef __PWM_SERVICE_H__
#define __PWM_SERVICE_H__

#include "request/pwm_request.h"

enum _pwm_domain_service{
    ROTATE_SERVO_90_DEGREES
};

void rotate_servo_90_degrees (struct _pwm_request);



#endif