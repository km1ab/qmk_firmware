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

#define LAYER_POS_LED_IDX (0)
#define NUMLOCK_STATUS_LED_IDX (1)
#define CAPSLOCK_STATUS_LED_IDX (2)
#define XXX_STATUS_LED_IDX (18)
#define YYY_STATUS_LED_IDX (19)

// static bool is_numlock = false;
// static bool is_capslock = false;
static bool numlock_led_enable = false;

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

#ifdef RGBLIGHT_ENABLE
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
    {XXX_STATUS_LED_IDX, 2, 0,0,0}
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM L1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {LAYER_POS_LED_IDX, 1, HSV_BLUE}
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

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, ((led_state.num_lock) && (numlock_led_enable)));
    rgblight_set_layer_state(1, led_state.caps_lock);
    return true;
}

//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
    if(get_highest_layer(state) != _L2)
    {
        numlock_led_enable = false;
    }
    else
    {
        numlock_led_enable = true;
    }
    // Both layers will light up if both kb layers are active
    // rgblight_set_layer_state(2, (get_highest_layer(state)==_BASE));
    rgblight_set_layer_state(3, (get_highest_layer(state)==_L1));
    rgblight_set_layer_state(4, (get_highest_layer(state)==_L2));
    rgblight_set_layer_state(5, (get_highest_layer(state)==_L3));
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
