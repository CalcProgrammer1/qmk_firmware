#include <string.h>
#include "rgb.h"
#include "rgb_matrix.h"
#include "rgb_matrix_types.h"
#include "color.h"
#include "ws2812.c"
#include "config_led.h"

/*
    COLS key / led
    PWM PWM00A - PWM21A (PWM15A unused)
    2ty transistors PNP driven high
    base      - GPIO
    collector - LED Col pins
    emitter   - VDD

    VDD     GPIO
    (E)     (B)
     |  PNP  |
     |_______|
         |
         |
        (C)
        LED

    ROWS RGB
    PWM PWM22A - PWM21B (PWM10B unused)
    C 0-15
    j3y transistors NPN driven low
    base      - GPIO
    collector - LED RGB row pins
    emitter   - GND

        LED
        (C)
         |
         |
      _______
     |  NPN  |
     |       |
    (B)     (E)
    GPIO    GND
*/

LED_TYPE led_state[LED_MATRIX_ROWS * LED_MATRIX_COLS];
LED_TYPE new_led_state[DRIVER_LED_TOTAL];
LED_TYPE rgb_matrix_ws2812_array[RGBLED_NUM];
uint8_t led_pos[DRIVER_LED_TOTAL];
extern volatile int strip;

void init(void) {
    unsigned int i = 0;
    for (unsigned int y = 0; y < LED_MATRIX_ROWS; y++) {
        for (unsigned int x = 0; x < LED_MATRIX_COLS; x++) {
            if (g_led_config.matrix_co[y][x] != NO_LED) {
                led_pos[g_led_config.matrix_co[y][x]] = i;
            }
            i++;
        }
    }
}
bool ws_changed = false;
static void flush(void) {

    for (int i=0; i<DRIVER_LED_TOTAL; i++) {
        if (i > 86) {
            convert_rgb_to_rgbw(&new_led_state[i]);
            if (rgb_matrix_ws2812_array[DRIVER_LED_TOTAL - i - 1].r != new_led_state[i].r
                || rgb_matrix_ws2812_array[DRIVER_LED_TOTAL - i - 1].g != new_led_state[i].g
                || rgb_matrix_ws2812_array[DRIVER_LED_TOTAL - i - 1].b != new_led_state[i].b
                || rgb_matrix_ws2812_array[DRIVER_LED_TOTAL - i - 1].w != new_led_state[i].w)
            {
                rgb_matrix_ws2812_array[DRIVER_LED_TOTAL - i - 1] = new_led_state[i];
                ws_changed = true;
            }
        } else {
            led_state[led_pos[i]] = new_led_state[i];
        }
    }
    if (strip == 0 || ws_changed) {
        ws2812_setleds(rgb_matrix_ws2812_array, RGBLED_NUM);
        ws_changed = false;
    }
}

void set_color(int index, uint8_t r, uint8_t g, uint8_t b) {
    new_led_state[index].r = r;
    new_led_state[index].g = g;
    new_led_state[index].b = b;
}

static void set_color_all(uint8_t r, uint8_t g, uint8_t b) {
    for (int i=0; i<(DRIVER_LED_TOTAL); i++)
        set_color(i, r, g, b);
}

const rgb_matrix_driver_t rgb_matrix_driver = {
    .init          = init,
    .flush         = flush,
    .set_color     = set_color,
    .set_color_all = set_color_all,
};

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        writePin(LED_CAPS_LOCK_PIN, !led_state.caps_lock);
        writePin(LED_SCROLL_LOCK_PIN, !led_state.scroll_lock);
    }
    return res;
}
