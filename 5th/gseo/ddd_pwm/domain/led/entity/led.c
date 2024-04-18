#include "led.h"
#include "../../pin/pin_map.h"

void led_entity_init(PIN_MAP pin_map, PIN_OPS_MODE pin_io_mode, LED_STATUS status)
{
    led_entity.pin.pin_map = pin_map;
    led_entity.pin.pin_io_mode = pin_io_mode;

    led_entity.status = status;
}

LED_STATUS get_led_status (void)
{
    return led_entity.status;
}

void set_led_status (LED_STATUS status)
{
    led_entity.status = status;
}

pin_vo get_led_pin (void)
{
    return led_entity.pin;
}