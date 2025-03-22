// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/*
    "encoder": {
        "rotary": [
                { "pin_a": "GP1", "pin_b": "GP2", "resolution": 2 },
                { "pin_a": "GP4", "pin_b": "GP3", "resolution": 2 }
        ]
    },
    
    "encoder": {
        "rotary": [
                { "pin_a": "GP26", "pin_b": "GP27", "resolution": 2 },
                { "pin_a": "GP1", "pin_b": "GP2", "resolution": 2 }
        ]
    },

*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ A │ B │ C │ D │
     * └───┴───┴───┴───┘
     */
     [0] = LAYOUT(
        KC_A
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  }
    // [0] =   { ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  }
    //                  Encoder 1                                     Encoder 2
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

