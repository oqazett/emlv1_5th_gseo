#include "pin_control_form.h"
#include "../service/request/pin_request.h"
#include "../global_pin_map.h"

void set_pin_control_form(PIN_MAP pin_number, PIN_OPS_MODE pin_direction)
{
    pin_control_form.pin_number = pin_number;
    pin_control_form.pin_direction = pin_direction;
}

struct _pin_request convert_pin_control_data(struct _pin_control_form pin_contorl_form)
{
    // 07 - 00 0111
    // 15 - 00 1111
    // 23 - 01 0111
    //--------------
    //      00 0111
    // 24 - 01 1000

    pin_request.hw_pin_address  = pin_map_address_vo[pin_control_form.pin_number>>3];
    pin_request.hw_pin_value    = 1<< (pin_control_form.pin_number & ~(24));

    return pin_request;
}
