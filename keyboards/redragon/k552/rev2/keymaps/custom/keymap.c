/*
Copyright 2019 Stephen Peery

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H


#if !defined(RGB_MATRIX_MAXIMUM_BRIGHTNESS) || RGB_MATRIX_MAXIMUM_BRIGHTNESS > UINT8_MAX
#    undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS UINT8_MAX
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _BASE,
    _CONTROLS,
    _NUMPAD
};

enum my_keycodes {
    IND_MOD = SAFE_RANGE,   // Toggles between indicator modes
    WLK_AWY,                //
    LGO_MOD                 // Rotates through logo display modes
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*  Row:        0                       1           2           3       4           5        6       7           8           9           10          11          12          13          14          15          16          17          18          19          20     */
    [_BASE] = LAYOUT_ansi(
                KC_ESC,                             KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_PSCR,   TO(_NUMPAD), RGB_TOG,
                KC_GRV,                 KC_1,       KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_INS,    KC_HOME,     KC_PGUP,
                KC_TAB,                 KC_Q,       KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_DEL,    KC_END,      KC_PGDN,
                LT(_CONTROLS, KC_CAPS), KC_A,       KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,                KC_ENT,
                KC_LSPO,                            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                KC_RSPC,               KC_UP,
                KC_LCTL,                KC_LGUI,    KC_LALT,                            KC_SPC,                                      KC_RALT,    KC_RGUI,    KC_APP,     KC_RCTL,    KC_LEFT,   KC_DOWN,     KC_RIGHT
            ),
    [_CONTROLS] = LAYOUT_ansi(
                _______,                   _______,       _______,   _______,       _______,    _______,   _______,       _______,       _______,       _______,     _______,    _______,     _______,     RGB_RMOD,    RGB_MOD,    _______,
                _______,    _______,       _______,       _______,   _______,       _______,    _______,   _______,       _______,       _______,       _______,     _______,    _______,       RESET,     RGB_HUI,     RGB_SAI,    RGB_VAI,
                _______,    _______,       _______,       _______,   _______,       _______,    _______,   _______,       _______,       _______,       _______,     _______,    _______,     IND_MOD,     RGB_HUD,     RGB_SAD,    RGB_VAD,
                _______,    _______,       _______,       _______,   _______,       _______,    _______,   _______,       _______,       _______,       _______,     _______,                 LGO_MOD,
                _______,                   _______,       _______,   _______,       _______,    _______,   _______,       _______,       _______,       _______,     _______,                 _______,                  KC_VOLU,
                _______,    _______,       _______,                                             KC_MPLY,                                                _______,     _______,    _______,     WLK_AWY,     KC_MPRV,     KC_VOLD,    KC_MNXT
            ),
    [_NUMPAD] = LAYOUT_ansi(
            _______,                   _______,       _______,   _______,       _______,    _______,   _______,       _______,       _______,       _______,     _______,    _______,     TG(_NUMPAD), KC_P7,       KC_P8,      KC_P9,
            _______,    _______,       _______,       _______,   _______,       _______,    _______,   _______,       _______,       _______,       _______,     _______,    _______,     KC_BSPC,     KC_P4,       KC_P5,      KC_P6,
            _______,    _______,       _______,       _______,   _______,       _______,    _______,   _______,       _______,       _______,       _______,     _______,    _______,     KC_NO,       KC_P1,       KC_P2,      KC_P3,
            _______,    _______,       _______,       _______,   _______,       _______,    _______,   _______,       _______,       _______,       _______,     _______,                 KC_NO,
            _______,                   _______,       _______,   _______,       _______,    _______,   _______,       _______,       _______,       _______,     _______,                 KC_P0,                    KC_UP,
            _______,    _______,       _______,                                              KC_SPC,                                                _______,     _______,    _______,     KC_NO,       KC_LEFT,     KC_DOWN,    KC_RIGHT
    )
};


bool inc_matrix_mode = false;
bool caps = false;
int strip = 0; // 0 = normal part of matrix; 1 = caps indicator; 2 = solid white; 3 = off

bool led_update_user(led_t led_state) {
    caps = led_state.caps_lock;
    return false;
}

void rgb_matrix_set_strip(uint8_t red, uint8_t green, uint8_t blue) {
    rgb_matrix_set_color(87, red, green, blue);
    rgb_matrix_set_color(88, red, green, blue);
    rgb_matrix_set_color(89, red, green, blue);
    rgb_matrix_set_color(90, red, green, blue);
    rgb_matrix_set_color(91, red, green, blue);
    rgb_matrix_set_color(92, red, green, blue);
    rgb_matrix_set_color(93, red, green, blue);
    rgb_matrix_set_color(94, red, green, blue);
}

void rgb_matrix_indicators_user(void) {
    HSV h = rgb_matrix_get_hsv();
    h.v = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
    h.s = UINT8_MAX;
    RGB color = hsv_to_rgb(h);
    if (inc_matrix_mode && strip != 1) {
        if (caps) rgb_matrix_set_color(51, color.r, color.g, color.b);
        else rgb_matrix_set_color(51, 0, 0, 0);
    }
    switch (strip) {
        case 0:
            break;
        case 1:
            if (caps) rgb_matrix_set_strip(color.r, color.g, color.b);
            else rgb_matrix_set_strip(0, 0, 0);
            break;
        case 2:
            rgb_matrix_set_strip(255, 255, 255);
            break;
        case 3:
            rgb_matrix_set_strip(0, 0, 0);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case IND_MOD:
            if (record->event.pressed) {
                inc_matrix_mode = !inc_matrix_mode;
            }
            return false;
            break;
        case WLK_AWY:
            if (record->event.pressed) {
                tap_code(KC_MSTP);
                register_code(KC_LGUI);
                tap_code(KC_L);
                unregister_code(KC_LGUI);
            }
            return false;
            break;
        case LGO_MOD:
            if (record->event.pressed) {
                if (strip < 3) strip++;
                else strip = 0;
            }
            return false;
            break;
    }
    return true;
}
