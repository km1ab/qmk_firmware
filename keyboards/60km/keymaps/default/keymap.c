// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_number {
  _BASE = 0,
  _L1,
  _L2,
  _L3,
};

#define LAYER_POS_LED_IDX (7)

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
        TG(_L2), RGB_HUI, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
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

const rgblight_segment_t PROGMEM rgb_default_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 16, HSV_BLUE}
);

const rgblight_segment_t PROGMEM rgb_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 1, HSV_RED}
);

const rgblight_segment_t PROGMEM rgb_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 1, HSV_PURPLE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_default_layer,
    rgb_lower_layer,
    rgb_raise_layer
);

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    return state;
}
//A description for expressing the layer position in LED mode.
layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
#if 0
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
        rgblight_set_effect_range(0, 16);
    }
    else
    {
        for(int i=0; i<LAYER_POS_LED_IDX; i++){
            rgblight_sethsv_at( 0, 0, 0, i);
        }
        rgblight_set_effect_range(8, 8);
    }
#else
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, _L1));
    rgblight_set_layer_state(2, layer_state_cmp(state, _L2));
#endif
#endif
return state;
}
