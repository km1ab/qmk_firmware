// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
// #define RGBLIGHT_ENABLE // already enabled at keyboard.json

enum layer_number {
  _BASE = 0,
  _L1,
  _L2,
  _L3,
};

#define LAYER_POS_LED_IDX (7)
#define NUMLOCK_STATUS_LED_IDX (8)
#define CAPSLOCK_STATUS_LED_IDX (9)
#define XXX_STATUS_LED_IDX (18)
#define YYY_STATUS_LED_IDX (19)

// static bool is_numlock = false;
// static bool is_capslock = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
    //,--------------------------------------------------------------------------------------------------------------------------------------.
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,  KC_GRV, KC_BSPC,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_GRV, MO(_L1),
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        TG(_L1), KC_LCTL, KC_LALT,  KC_SPC, KC_LGUI,  KC_DEL, KC_RSFT,                   KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX
    //`--------------------------------------------------------------------------------------------------------------------'
    ),
    [_L1] = LAYOUT(
    //,--------------------------------------------------------------------------------------------------------------------------------------.
        TG(_L2),   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______, _______,   KC_UP, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP,  KC_END, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGDN, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______
    //`--------------------------------------------------------------------------------------------------------------------'
    ),
    [_L2] = LAYOUT(
    //,--------------------------------------------------------------------------------------------------------------------------------------.
        TG(_L2), RGB_HUI, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, QK_BOOT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        RGB_TOG, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        RGB_SAI,   TO(0), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        RGB_SAD, RGB_HUD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    //`--------------------------------------------------------------------------------------------------------------------'
    ),
    [_L3] = LAYOUT(
    //,--------------------------------------------------------------------------------------------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    //`--------------------------------------------------------------------------------------------------------------------'
    )
};

#if 1//def RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{NUMLOCK_STATUS_LED_IDX, 1, HSV_GREEN}       // Light 4 LEDs, starting with LED 6
);
// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{CAPSLOCK_STATUS_LED_IDX, 1, HSV_GREEN}       // Light 4 LEDs, starting with LED 6
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {LAYER_POS_LED_IDX, 1, 0,0,0}
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM L1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {LAYER_POS_LED_IDX, 1, HSV_BLUE},
    {XXX_STATUS_LED_IDX, 2, HSV_BLUE}
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM L2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {LAYER_POS_LED_IDX, 1, HSV_RED}
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM L3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {LAYER_POS_LED_IDX, 1, HSV_PURPLE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    numlock_layer,
    capslock_layer,
	base_layer,
	L1_layer,
	L2_layer,
	L3_layer
);

void keyboard_post_init_user(void) {
	// Enable the LED layers
	rgblight_layers = rgb_layers;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_TOG:
            // Play a tone when enter is pressed
            if (record->event.pressed) {
                if(rgblight_is_enabled())
                {
                    rgblight_sethsv_at( 0, 0, 0, LAYER_POS_LED_IDX);
                    rgblight_sethsv_at( 0, 0, 0, NUMLOCK_STATUS_LED_IDX);
                    rgblight_sethsv_at( 0, 0, 0, CAPSLOCK_STATUS_LED_IDX);
                }
                else
                {
                    // rgblight_enable_noeeprom();
                    // if (is_numlock) {
                    //     rgblight_sethsv_at(HSV_GREEN, NUMLOCK_STATUS_LED_IDX);
                    // }
                    // if (is_capslock) {
                    //     rgblight_sethsv_at(HSV_GREEN, CAPSLOCK_STATUS_LED_IDX);
                    // }
                }
            }
            return true; // Let QMK send the enter press/release events
        // case RGB_M_P:
        //     // Play a tone when enter is pressed
        //     if (record->event.pressed) {
        //         rgblight_set_effect_range(19, 1);
        //         for (int i = 0; i < LAYER_POS_LED_IDX; i++) {
        //             rgblight_sethsv_at(0, 0, 0, i);
        //         }
        //         for (int i = CAPSLOCK_STATUS_LED_IDX+1; i < 20; i++) {
        //             rgblight_sethsv_at(0, 0, 0, i);
        //         }
        //         rgblight_set();
        //     }
        //     return true; // Let QMK send the enter press/release events
        default:
            return true; // Process all other keycodes normally
    }
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.num_lock);
    rgblight_set_layer_state(1, led_state.caps_lock);
    return true;
}
#if 0
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        // gpio_write_pin sets the pin high for 1 and low for 0.
        // In this example the pins are inverted, setting
        // it low/0 turns it on, and high/1 turns the LED off.
        // This behavior depends on whether the LED is between the pin
        // and VCC or the pin and GND.
        // gpio_write_pin(B0, !led_state.num_lock);
        // gpio_write_pin(B1, !led_state.caps_lock);
#ifdef RGBLIGHT_ENABLE
        // if (led_state.num_lock) {
        //     rgblight_sethsv_at(HSV_GREEN, NUMLOCK_STATUS_LED_IDX);
        //     is_numlock = true;
        // } else {
        //     rgblight_sethsv_at(0, 0, 0, NUMLOCK_STATUS_LED_IDX);
        //     is_numlock = false;
        // }
        if (led_state.caps_lock) {
            rgblight_sethsv_at(HSV_GREEN, CAPSLOCK_STATUS_LED_IDX);
            is_capslock = true;
        } else {
            rgblight_sethsv_at(0, 0, 0, CAPSLOCK_STATUS_LED_IDX);
            is_capslock = false;
        }
            rgblight_sethsv_at(0, 0, 0, XXX_STATUS_LED_IDX);
            rgblight_sethsv_at(0, 0, 0, YYY_STATUS_LED_IDX);
        // if ((led_state.num_lock) || (led_state.caps_lock)) {
        //     for (int i = 0; i < LAYER_POS_LED_IDX; i++) {
        //         rgblight_sethsv_at(0, 0, 0, i);
        //     }
        //     rgblight_set_effect_range(10, 10);
        // }
#endif
        // gpio_write_pin(B2, !led_state.scroll_lock);
        // gpio_write_pin(B3, !led_state.compose);
        // gpio_write_pin(B4, !led_state.kana);
    }

    return res;
}
#endif
//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
#if 1
#if 1//def RGBLIGHT_LAYERS
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(2, (get_highest_layer(state)==_BASE));
    rgblight_set_layer_state(3, (get_highest_layer(state)==_L1));
    rgblight_set_layer_state(4, (get_highest_layer(state)==_L2));
    rgblight_set_layer_state(5, (get_highest_layer(state)==_L3));
#endif
#else
#ifdef RGBLIGHT_ENABLE
    bool is_base = false;
    switch (get_highest_layer(state)) {
    case _L1:
      rgblight_sethsv_at(HSV_BLUE, LAYER_POS_LED_IDX);
      break;
    case _L2:
      rgblight_sethsv_at(HSV_RED, LAYER_POS_LED_IDX);
      break;
    case _L3:
      rgblight_sethsv_at(HSV_PURPLE, LAYER_POS_LED_IDX);
      break;
    default: //  for any other layers, or the default layer
      rgblight_sethsv_at( 0, 0, 0, LAYER_POS_LED_IDX);
      is_base = true;
      break;
    }
    if(is_base)
    {
        rgblight_set_clipping_range(0, 20);
        rgblight_set_effect_range(0, 20);
    }
    else
    {
        // for(int i=0; i<LAYER_POS_LED_IDX; i++){
        //     rgblight_sethsv_at( 0, 0, 0, i);
        // }
        // // for(int i=LAYER_POS_LED_IDX+1; i<=LAYER_POS_LED_IDX+2; i++){
        // //     rgblight_sethsv_at( 0, 0, 0, i);
        // // }
        // rgblight_set_effect_range(10, 10);
    }

#endif
#endif
return state;
}


/*
    "rgblight": {
        "split": true,
        "hue_steps": 10,
        "led_count": 20,
        "split_count": [10, 10],
        "led_map": [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19],
        "animations": {
            "breathing": true,
            "rainbow_mood": true,
            "rainbow_swirl": true,
            "snake": true,
            "knight": true,
            "christmas": true,
            "static_gradient": true,
            "rgb_test": true,
            "alternating": true,
            "twinkle": true
        }
    },
 */
