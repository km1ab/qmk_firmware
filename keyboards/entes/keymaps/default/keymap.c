// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ A │ B │ C │ D │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT(KC_A) //
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
    } //
};
#endif

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
