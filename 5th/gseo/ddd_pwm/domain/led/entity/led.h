#ifndef __LED_H__
#define __LED_H__

#include "../../pin/pin_map.h"

#include <stdint.h>

typedef enum _LED_STATUS LED_STATUS;
enum _LED_STATUS
{
    LED_STATUS_OFF = 0,
    LED_STATUS_ON,
    LED_STATUS_TOGGLE,
    END
};

typedef struct _led led;
struct _led
{
    LED_STATUS status;
    pin_vo pin;
};

led led_entity;

void led_entity_init(PIN_MAP pin_map, PIN_OPS_MODE pin_io_mode, LED_STATUS status);
LED_STATUS get_led_status (void);
void set_led_status (LED_STATUS status);
pin_vo get_led_pin (void);

#endif