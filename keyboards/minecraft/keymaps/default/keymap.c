/* Copyright 2022 KM
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#undef LAYOUT
#define LAYOUT( \
    l00, l01, l02,  \
    l10, l11, l12,  \
    l20, l21, l22  \
  ) \
  { \
    { l00, l01, l02  }, \
    { l10, l11, l12  }, \
    { l20, l21, l22  } \
  }

#define KEY_3X3_LAYOUT LAYOUT
#define KEY_3X3_LAYOUT_NORMAL(nm, a,b,c, d,f,g, h,i,j) \
  	[LAYER_##nm] = KEY_3X3_LAYOUT(    \
    a,     b,     c,          \
    d,     f,     g,          \
    h,     i,     j           \
  )

#define KEY_3X3_LAYOUT_WITH_TO(nm, a,b,c, d,f,g, h,  j) \
  KEY_3X3_LAYOUT_NORMAL(nm, a,b,c, d,f,g, h,TO(LAYER_##nm##_NEXT),j)

// Case for x is same keymap in any group.
#define KEY_3X3_LAYOUT_WITH_TO_A(nm,x) KEY_3X3_LAYOUT_WITH_TO(nm, x)

// next layer mode, here
// (ex) DEFAULT --> CMD1 --> ... -->
#define LAYER_CMD_LIST(x) \
	LAYER_CMD1##x, /* reserved!! */ \
	LAYER_CMD2##x, \
	LAYER_CMD3##x, \
	LAYER_CMD4##x

#define LAYER_LIST(x) \
	LAYER_DEFAULT##x,  /* reserved!! */ \
	LAYER_FN1##x, \
  LAYER_CMD_LIST(x), \
  LAYER_TERM##x, \
	LAYER_MAX##x

enum {
  LAYER_LIST()
};

enum {
  LAYER_NEXT_NONE=0,
  LAYER_LIST(_NEXT)
};

enum {
  LAYER_CMD_INIT=LAYER_CMD1-1,
  LAYER_CMD_LIST(ID),
  LAYER_CMD_TERM
};

#define CMDX_DEF_KEY_MAP \
    KC_ESCAPE,KC_W,     KC_E, \
    KC_A,     KC_S,     KC_D, \
    KC_LSHIFT,          KC_LEAD


// #define INIT_LAYER()
// enum {
//   LAYER_LIST
// };

// for us, so convert jp.
#define JP_TILD SS_LSFT("=")
#define JP_HAT  "="

#define MICRA_CMD_FILL(x,y,z,block) \
	SEND_STRING("/fill " JP_TILD " " JP_TILD " " JP_TILD " " JP_TILD #x " " JP_TILD #y " " JP_TILD #z " " #block "\n")

#define MICRA_CMD_FILL_SUB(sx,sz,x,y,z,block) \
	SEND_STRING("/fill " JP_TILD #sx " " JP_TILD " " JP_TILD #sz " " JP_TILD #x " " JP_TILD #y " " JP_TILD #z " " #block "\n")

#define MICRA_CMD_FILL2_SUB2(fn,sx,sy,sz,x,y,z,block) \
	fn("/fill " JP_HAT #sx " " JP_HAT #sy " " JP_HAT #sz " " JP_HAT #x " " JP_HAT #y " " JP_HAT #z " " #block "\n\0")

//"/fill ^1 ^0 ^0 ^-1 ^3 ^20 air"
#define MICRA_CMD_FILL2_SUB(sx,sy,sz,x,y,z,block) \
	MICRA_CMD_FILL2_SUB2(SEND_STRING,sx,sy,sz,x,y,z,block)

#define NONFN(x) x

#define MICRA_CMD_FILL2_SUB_STR(sx,sy,sz,x,y,z,block) \
	MICRA_CMD_FILL2_SUB2(NONFN,sx,sy,sz,x,y,z,block)


	//"/fill " JP_HAT #sx " " JP_HAT #sy " " JP_HAT #sz " " JP_HAT #x " " JP_HAT #y " " JP_HAT #z " " #block "\n\0"

/*
    MICRA_CMD_FILL2_AIR(start_x, end_x y, z)
    start_x : player pos=0, x is minus
    end_x   : player pos=0, x is plus
    y       : player pos=0, y is plus or minus
    z       : player pos=0, z is plus or minus
*/
#define MICRA_CMD_FILL2_AIR(sx,x,y,z) \
	MICRA_CMD_FILL2_SUB_STR(sx,0,0,x,y,z,air)

#define MICRA_MENU_CHAT micra_menu_chat

#define CMD_SIZE (32)

struct commandList {
    char dummy;
    PGM_P  cmd;
};

struct commandIndexList {
    uint16_t code;
    char dummy;
};

#define OLED_MODE_DISP(x) oled_write_P(PSTR(x), false)
#define OLED_MODE_KEYMAP(mode) \
case LAYER_##mode: \
OLED_MODE_DISP_##mode; \
break


#define OLED_MODE_DISP_DEFAULT OLED_MODE_DISP( \
          "Default\n" \
          " esc w e\n" \
          "   a s d\n")

#define OLED_MODE_DISP_TERM OLED_MODE_DISP( \
          "Term\n" \
          " esc w e\n" \
          "   a s d\n")

#define OLED_MODE_DISP_FN1 OLED_MODE_DISP( \
          "FN1    \n" \
					"  q 1 2\n" \
					"  3 4 5\n")

#define OLED_MODE_DISP_CMDX(x) OLED_MODE_DISP( \
          #x "\n" \
					"  x x x\n" \
					"  x x x\n")

#define OLED_MODE_DISP_CMD1 OLED_MODE_DISP_CMDX(CMD1)
#define OLED_MODE_DISP_CMD2 OLED_MODE_DISP_CMDX(CMD2)
#define OLED_MODE_DISP_CMD3 OLED_MODE_DISP_CMDX(CMD3)
#define OLED_MODE_DISP_CMD4 OLED_MODE_DISP_CMDX(CMD4)

#define OLED_MODE_KEYMAP_ALL() \
	OLED_MODE_KEYMAP(DEFAULT); \
	OLED_MODE_KEYMAP(FN1); \
	OLED_MODE_KEYMAP(CMD1); \
	OLED_MODE_KEYMAP(CMD2); \
	OLED_MODE_KEYMAP(CMD3); \
	OLED_MODE_KEYMAP(CMD4); \
	OLED_MODE_KEYMAP(TERM)

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  SEND_00 = SAFE_RANGE,
  SEND_000
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default Layer
   *  Master Side (USB Cable Connected Side)
   *  ,-----------------------------------------
   *  |    =    (    )   BS XXXX XXXX XXXX XXXX
   *  | NmLk  KP/  KP*  Tab XXXX XXXX XXXX XXXX
   *  |  KP7  KP8  KP9  KP- XXXX XXXX XXXX XXXX
   *  |  KP4  KP5  KP6  KP+ XXXX XXXX XXXX XXXX
   *  |  KP1  KP2  KP3 Entr XXXX XXXX XXXX XXXX
   *  |  KP0   00    .    , XXXX XXXX XXXX XXXX
   *  `-----------------------------------------
   *  Slave Side (USB Cable Not Connected Side)
   *  ,-----------------------------------------
   *  | XXXX XXXX XXXX XXXX XXXX XXXX XXXX XXXX
   *  | XXXX XXXX XXXX XXXX XXXX XXXX XXXX XXXX
   *  | XXXX XXXX XXXX XXXX XXXX XXXX XXXX XXXX
   *  | XXXX XXXX XXXX XXXX XXXX XXXX XXXX XXXX
   *  | XXXX XXXX XXXX XXXX XXXX XXXX XXXX XXXX
   *  | XXXX XXXX XXXX XXXX XXXX XXXX XXXX XXXX
   *  `-----------------------------------------
   */

	KEY_3X3_LAYOUT_WITH_TO(DEFAULT,
    KC_ESCAPE,KC_W,     KC_E,
    KC_A,     KC_S,     KC_D,
    KC_LSHIFT,          KC_SPACE
  ),

  KEY_3X3_LAYOUT_WITH_TO(FN1,
    KC_Q,     KC_1,     KC_2,
    KC_3,     KC_4,     KC_5,
    KC_6,               KC_7
  ),

  KEY_3X3_LAYOUT_WITH_TO_A(CMD1,CMDX_DEF_KEY_MAP),
  KEY_3X3_LAYOUT_WITH_TO_A(CMD2,CMDX_DEF_KEY_MAP),
  KEY_3X3_LAYOUT_WITH_TO_A(CMD3,CMDX_DEF_KEY_MAP),
  KEY_3X3_LAYOUT_WITH_TO_A(CMD4,CMDX_DEF_KEY_MAP),

	KEY_3X3_LAYOUT_NORMAL(TERM,
    KC_ESCAPE,KC_W,     KC_E,
    KC_A,     KC_S,     KC_D,
    KC_LSHIFT,TO(LAYER_DEFAULT),          KC_SPACE
  ),
};

#define CMD_NUM_PER_GROUP (6)
static const signed char commans[][CMD_SIZE] PROGMEM ={
  // CMD1
    {MICRA_CMD_FILL2_AIR(1,-1,3,20)},         // W
    {MICRA_CMD_FILL2_AIR(4,-4, 6, 20)},       // ESC
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // E
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // A
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // S
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // D
  // CMD2
    {MICRA_CMD_FILL2_AIR(1,-1,3,20)},         // W
    {MICRA_CMD_FILL2_AIR(4,-4, 6, 20)},       // ESC
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // E
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // A
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // S
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // D
  // CMD3
    {MICRA_CMD_FILL2_AIR(1,-1,3,20)},         // W
    {MICRA_CMD_FILL2_AIR(4,-4, 6, 20)},       // ESC
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // E
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // A
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // S
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // D
  // CMD4
    {MICRA_CMD_FILL2_AIR(1,-1,3,20)},         // W
    {MICRA_CMD_FILL2_AIR(4,-4, 6, 20)},       // ESC
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // E
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // A
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // S
    {MICRA_CMD_FILL2_AIR(2,-2, 6, 20)},       // D
};

static const struct commandIndexList PROGMEM keylist[]={
  {KC_W,0},
  {KC_ESC,0},
  {KC_E,0},
  {KC_A,0},
  {KC_S,0},
  {KC_D,0},
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SEND_00:
      if (record->event.pressed) {
        // when keycode SEND_00 is pressed
        SEND_STRING("00");
      } else {
        // when keycode SEND_00 is released
      }
      break;
    case SEND_000:
      if (record->event.pressed) {
        // when keycode SEND_000 is pressed
        //SEND_STRING("000" SS_TAP(X_ENTER));
        SEND_STRING("000");
      } else {
        // when keycode SEND_000 is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {
}

void micra_menu_chat(void){
	SEND_STRING("t");
	wait_ms(500);
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();
  	signed char s=-1;
    uint16_t code = get_highest_layer(layer_state);
    if(LAYER_CMD_INIT < code && code < LAYER_CMD_TERM)
    {
        MICRA_MENU_CHAT();
    }

    uint8_t i=0;
    uint8_t gp=code - LAYER_CMD1;
    uint8_t sz = sizeof(struct commandIndexList);
    uint8_t n=sizeof(keylist) / sz;
    struct commandIndexList data;
    for(i=0; i<n; i++){
      memcpy_P(&data, &keylist[i], sz);
      SEQ_ONE_KEY(data.code){
        s = i + gp * CMD_NUM_PER_GROUP;
        break;
      }
    }

  	if(s>=0){
  		send_string_P((PGM_P)&commans[s]);
  	}
  }
}

void led_set_user(uint8_t usb_led) {

}
#if 0
static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}
#endif
static void render_minecraft_logo(void) {
  // 128x27 image, 16 columns, 3 rows
/*	static const char PROGMEM raw_logo[] = {
	    0,  0,  0,  0,  0,  0,  0, 64,112,112,112,112,128,  0,  0,  0,  0,128,128,112,240,240,240, 32,  0,224,240,240,240,112,  0,192,240,240,240,240,128,  0,  0,128,240,240,240,240,  0,  0,224,240,240,240,240,112,112,112,112,112,112,  0,  0,240,240,240,240,240,112,112,112,112,112,112,  0,  0,112,  0,240,240,112,112,240,240,240,240,224,  0,  0,240,240,240,112,112,240,112,112,240,240,224,  0, 96,240,240,240,240,224, 80, 80, 48,112,112, 64,  0,112,112,112,112,240,240,240,240,128,112,112,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,224,222, 63,255,127, 31,159,255,252,124, 28,157,253,253,254,253, 61,  1,224,254,255,255,255, 15,  0,184,191,191,191,191, 15,  7, 60,188,191,127,255,255,  7,  0,124,255,255,255,255, 28, 28, 28, 28, 28, 28, 12,  0,  0,190,192,254,254,128,  0,  0,  0,  0,  0,  0,  0,  0,255,254,253,127,188, 28, 31,191,255,255,251,128,  0,255,255,255,230,242,113,114,102,255,255,255,248,  0, 15,191,191,127,254,252, 28, 28, 12, 28, 28, 24,  0,  0,  0,  0,  3, 63,223,223,223,216,128,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  7,  7,  7,  7,  7,  0,  0,  0,  0,  0,  0,  0,  7,  7,  7,  7,  3,  0,  0,  7,  7,  7,  7,  3,  0,  4,  7,  7,  7,  7,  1,  0,  0,  0,  7,  7,  0,  7,  7,  0,  0,  7,  0,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  0,  0,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  0,  0,  7,  7,  7,  0,  7,  0,  0,  7,  7,  7,  7,  7,  0,  0,  7,  7,  7,  7,  6,  0,  0,  7,  7,  7,  7,  6,  0,  1,  7,  6,  7,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  7,  7,  7,  7,  4,  0,  0,  0,  0,  0,  0,
	};*/
	static const char PROGMEM raw_logo[] = {
	    0,  0,  0,  0,  0,  0,  0, 64,112,112,112,112,128,  0,  0,  0,  0,128,128,112,240,240,240, 32,  0,224,240,112,112,112,  0,192,240,240,176,176,128,  0,  0,128,176,176,176,176,  0,  0,224,240,240,240,240,112,112,112,112,112,112,  0,  0,240,240,240,240,240,112,112,112,112,112,112,  0,  0,112,  0,240,240,112,112,240,240,240,240,224,  0,  0,240,240,240,112,112,240,112,112,240,240,224,  0, 96,240,240,240,240,224, 80, 80, 48,112,112, 64,  0,112,112,112,112,240,240,240,240,128,112,112,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  0,224,222, 63,255,127, 31,159,255,252,124, 28,157,253,253,254,253, 61,  1,224,254,255,252,255, 15,  0,184,191,191,191,191, 15,  7, 60,188,191,127,255,255,  7,  0,124,254,254,255,255, 28, 28, 28, 28, 28, 28, 12,  0,  0,190,192,254,254,128,  0,  0,  0,  0,  0,  0,  0,  0,255,254,125,191,188, 28, 31,191,255,255,251,128,  0,255,255,255,230,242,113,114,102,255,255,255,248,  0, 15,191,191,127,254,252, 28, 28, 12, 28, 28, 24,  0,  0,  0,  0,  3, 63,223,223,223,216,128,  0,  0,  0,  0,  0,  0,  0,
	    0,  0,  0,  0,  7,  7,  7,  7,  7,  0,  0,  0,  0,  0,  0,  0,  7,  7,  7,  7,  3,  0,  0,  7,  7,  7,  7,  3,  0,  4,  7,  7,  7,  7,  1,  0,  0,  0,  7,  7,  0,  7,  7,  0,  0,  7,  0,  7,  7,  7,  7,  7,  7,  1,  6,  7,  7,  0,  0,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  0,  0,  7,  7,  0,  7,  7,  0,  0,  7,  7,  7,  7,  7,  0,  0,  7,  7,  7,  7,  6,  0,  0,  7,  7,  7,  7,  6,  0,  1,  7,  6,  7,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  7,  7,  7,  7,  4,  0,  0,  0,  0,  0,  0,
	};
  oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // QMK Logo and version information
    //render_qmk_logo();
	render_minecraft_logo();
	oled_set_cursor(0,3);

//  oled_write_P(PSTR("      te96 alpha ver\n"), false);
    oled_write_P(PSTR("      te96 ver0.1a\n"), false);

	// Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state))
    {
      OLED_MODE_KEYMAP_ALL();
      default:
        // Or use the write_ln shortcut over adding '\n' to the end of your string
        oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif
