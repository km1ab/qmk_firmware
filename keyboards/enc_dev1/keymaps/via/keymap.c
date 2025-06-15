// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ A │ W │ S │ D │
     * ├───┼───┼───┼───┤
     * │   │ Tb│ TG│en*│ *:no switch
     * ├───┼───┼───┼───┼───┐
     * │   │   │Esc│ en│ SP│
     * └───┴───┴───┴───┘───┘
     */
    [0] = LAYOUT(KC_A,  KC_W,   KC_S,   KC_D,
                        KC_TAB, TG(1),  XXXXXXX,
                                KC_ESC, KC_B,   KC_SPC), //
    /*
     * ┌───┬───┬───┬───┐
     * │ A │ W │ S │ D │
     * ├───┼───┼───┼───┤
     * │   │ Tb│ TG│en*│ *:no switch
     * ├───┼───┼───┼───┼───┐
     * │   │   │Esc│ en│ SP│
     * └───┴───┴───┴───┘───┘
     */
    [1] = LAYOUT(KC_A,  KC_W,   KC_S,   KC_D,
                        KC_TAB, TG(1),  XXXXXXX,
                                KC_ESC, KC_B,   KC_SPC), //
    /*
     * ┌───┬───┬───┬───┐
     * │ A │ W │ S │ D │
     * ├───┼───┼───┼───┤
     * │   │ Tb│ TG│en*│ *:no switch
     * ├───┼───┼───┼───┼───┐
     * │   │   │Esc│ en│ SP│
     * └───┴───┴───┴───┘───┘
     */
    [2] = LAYOUT(KC_A,  KC_W,   KC_S,   KC_D,
                        KC_TAB, TG(1),  XXXXXXX,
                                KC_ESC, KC_B,   KC_SPC), //
    /*
     * ┌───┬───┬───┬───┐
     * │ A │ W │ S │ D │
     * ├───┼───┼───┼───┤
     * │   │ Tb│ TG│en*│ *:no switch
     * ├───┼───┼───┼───┼───┐
     * │   │   │Esc│ en│ SP│
     * └───┴───┴───┴───┘───┘
     */
    [3] = LAYOUT(KC_A,  KC_W,   KC_S,   KC_D,
                        KC_TAB, TG(1),  XXXXXXX,
                                KC_ESC, KC_B,   KC_SPC), //
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = // layer 0
    {
        // KiCad mode sample
        // - vertical move
        // - horizontal move
        ENCODER_CCW_CW(LCTL(KC_MS_WH_UP), LCTL(KC_MS_WH_DOWN)), // encoder 1
        ENCODER_CCW_CW(LSFT(KC_MS_WH_UP), LSFT(KC_MS_WH_DOWN))  // encoder 2
    }, //
    [1] = // layer 1
    {
        // KiCad mode sample
        // - vertical move
        // - horizontal move
        ENCODER_CCW_CW(LCTL(KC_MS_WH_UP), LCTL(KC_MS_WH_DOWN)), // encoder 1
        ENCODER_CCW_CW(LSFT(KC_MS_WH_UP), LSFT(KC_MS_WH_DOWN))  // encoder 2
    }, //
    [2] = // layer 2
    {
        // KiCad mode sample
        // - vertical move
        // - horizontal move
        ENCODER_CCW_CW(LCTL(KC_MS_WH_UP), LCTL(KC_MS_WH_DOWN)), // encoder 1
        ENCODER_CCW_CW(LSFT(KC_MS_WH_UP), LSFT(KC_MS_WH_DOWN))  // encoder 2
    }, //
    [3] = // layer 3
    {
        // KiCad mode sample
        // - vertical move
        // - horizontal move
        ENCODER_CCW_CW(LCTL(KC_MS_WH_UP), LCTL(KC_MS_WH_DOWN)), // encoder 1
        ENCODER_CCW_CW(LSFT(KC_MS_WH_UP), LSFT(KC_MS_WH_DOWN))  // encoder 2
    }, //
};
#endif

