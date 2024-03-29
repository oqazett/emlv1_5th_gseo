#ifndef __PIN_CONTROL_FORM_H__
#define __PIN_CONTROL_FORM_H__

#include "../pin_map.h"

struct _pin_control_form
{
    PIN_MAP pin_number;
    PIN_OPS_MODE pin_direction;
};

struct _pin_control_form pin_control_form;

void set_pin_control_form(PIN_MAP pin_number, PIN_OPS_MODE pin_direction);
struct _pin_request convert_pin_control_data(struct _pin_control_form pin_contorl_form);


#endif