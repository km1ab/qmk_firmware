#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#define RGBLIGHT_LAYERS

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_LED_COUNT 20     // Number of LEDs in your strip
#define RGBLED_SPLIT {10,10}
// However, there may be a change in qmk specifications
// ----------------------- *  *  *  *  *
// ----------------index-- 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19
// -----------LED number--20,19,10, 9, 8, 1, 2, 3, 4, 5, 6, 7,11,12,13,14,15,16,17,18
#define RGBLIGHT_LED_MAP {19,18, 9, 8, 7, 0, 1, 2, 3, 4, 5, 6,10,11,12,13,14,15,16,17 }
