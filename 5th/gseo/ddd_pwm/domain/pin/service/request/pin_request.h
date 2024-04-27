#ifndef __PIN_REQUEST_H__
#define __PIN_REQUEST_H__

#include "stdint.h"

struct _pin_request
{
    volatile unsigned char *hw_pin_address;
    uint8_t hw_pin_value;
};

struct _pin_request pin_request;
struct _pin_request led_port_request;
struct _pin_request pwm_port_request;

#endif