// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┐
     * │ A │ D │
     * └───┴───┘
     */
    [0] = LAYOUT(KC_A, KC_D, XXXXXXX, XXXXXXX), //
    /*
     * ┌───┬───┐
     * │ A │ D │
     * └───┴───┘
     */
    [1] = LAYOUT(KC_A, KC_D, XXXXXXX, XXXXXXX), //
    /*
     * ┌───┬───┐
     * │ A │ D │
     * └───┴───┘
     */
    [2] = LAYOUT(KC_A, KC_D, XXXXXXX, XXXXXXX), //
    /*
     * ┌───┬───┐
     * │ A │ D │
     * └───┴───┘
     */
    [3] = LAYOUT(KC_A, KC_D, XXXXXXX, XXXXXXX) //
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

void keyboard_post_init_user(void) {
    gpio_set_pin_output(GP11); // set OUTPUT to NEO_PWR pin of XIAO RP2040
    gpio_write_pin_high(GP11); // set HIGH to NEO_PWR pin of XIAO RP2040

    rgblight_sethsv(190, 200, 200); // blue??
    // rgblight_sethsv_at(190, 255, 255, 0);   // blue??
    // rgblight_sethsv_at(127, 255, 100, 0);   // 1st LED CYAN
    // rgblight_sethsv_at(0, 255, 100, 1);   // 2nd LED RED
    // rgblight_enable();
    rgblight_disable();
    rgblight_toggle();
    rgblight_mode(RGBLIGHT_MODE_BREATHING + 1); // animation default
}

// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (index == 0) { /* First encoder */
//         if (clockwise) {
//             tap_code(KC_PGDN);
//         } else {
//             tap_code(KC_PGUP);
//         }
//     } else if (index == 1) { /* Second encoder */
//         if (clockwise) {
//             tap_code(KC_PGDN);
//         } else {
//             tap_code(KC_PGUP);
//         }
//     }
//     return false;
// }
