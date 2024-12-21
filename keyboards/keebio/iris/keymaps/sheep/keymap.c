#include QMK_KEYBOARD_H

// Layer declaration
enum {
	DEFAULT = 0,
	RAISE = 1,
	NUM = 2,
	NOTAP = 3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[DEFAULT] = LAYOUT(
//
	KC_GRV		  , KC_1, KC_2, KC_3, KC_4, KC_5,					KC_6, KC_7, KC_8   , KC_9  , KC_0   , KC_BSLS, 
//
	LT(1,KC_TAB)  , KC_Q, KC_W, KC_E, KC_R, KC_T,					KC_Y, KC_U, KC_I   , KC_O  , KC_P   , KC_LBRC, 
//	
	LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G,					KC_H, KC_J, KC_K   , KC_L  , KC_SCLN, KC_QUOT,
//	
	KC_MUTE		  , KC_Z, KC_X, KC_C, KC_V, KC_B, TG(3) ,	 TG(2), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RBRC,
//	
								KC_LGUI, KC_LALT, KC_SPC,	KC_ENT, KC_RSFT, KC_RALT),
// ---------------------------------------------------------------
	[RAISE] = LAYOUT(
//		
	KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                       KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, 
//
	KC_TRNS, RGB_TOG, KC_TRNS, KC_PSCR, KC_TRNS, KC_TRNS,         	KC_MINS, KC_HOME, KC_UP, KC_END, KC_PGUP, KC_BSPC,
//	
	KC_TRNS, RGB_MOD, KC_LALT, KC_LSFT, KC_LCTL, KC_TRNS,            KC_EQL, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_DEL,
//	  
	KC_TRNS, RGB_RMOD, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS, KC_TRNS,     	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_MNXT, KC_TRNS, 
//	
                            	KC_TRNS, KC_TRNS, KC_TRNS,                   	KC_TRNS, KC_TRNS, KC_TRNS),
// ---------------------------------------------------------------
	[NUM] = LAYOUT(
//	
	KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, 
	KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
//	
	KC_TAB, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN,
	KC_Y, KC_P7, KC_P8, KC_P9, KC_P, KC_LBRC, 
//	
	KC_LCTL, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, RGB_TOG,
	KC_EQL, KC_P4, KC_P5, KC_P6, KC_SCLN, KC_QUOT,
//	
	KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS,
	KC_TRNS, KC_PDOT, KC_P1, KC_P2, KC_P3, KC_SLSH, KC_RBRC, 		
//
	KC_LGUI, KC_LALT, KC_SPC,
	KC_ENT, KC_RSFT, KC_P0),
//	 ---------------------------------------------------------------
	[NOTAP] = LAYOUT(
//		
	KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5,
  KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
//	
	KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
	KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
//	
	KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G,
	KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
//	
	KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS,
	KC_TRNS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RBRC,
//	
	KC_LGUI, KC_LALT, KC_SPC, 
	KC_ENT, KC_RSFT, KC_RALT),
};



uint32_t layer_state_set_user(uint32_t state) {
	switch(biton32(state)) {
	case RAISE:
		rgblight_sethsv_noeeprom(HSV_TEAL);
		break;
	case NUM:
		rgblight_sethsv_noeeprom(HSV_CHARTREUSE);
		break;
	case NOTAP:
		rgblight_sethsv_noeeprom(HSV_YELLOW);
		break;
	case DEFAULT:
		rgblight_sethsv_noeeprom(HSV_RED);
		break;
	};
	return state;
};

/* The encoder_update_user is a function.
 * It'll be called by QMK every time you turn the encoder.
 *
 * The index parameter tells you which encoder was turned. If you only have
 * one encoder, the index will always be zero.
 *
 * The clockwise parameter tells you the direction of the encoder. It'll be
 * true when you turned the encoder clockwise, and false otherwise.
 */
void encoder_update_user(uint8_t index, bool clockwise) {
  /* With an if statement we can check which encoder was turned. */
// if (index == 0) { /* First encoder */
    /* And with another if statement we can check the direction. */
    if (clockwise) {
      /* This is where the actual magic happens: this bit of code taps on the
         Page Down key. You can do anything QMK allows you to do here.
         You'll want to replace these lines with the things you want your
         encoders to do. */
      tap_code(KC_VOLD);
    } else {
      /* And likewise for the other direction, this time Page Down is pressed. */
      tap_code(KC_VOLU);
    }
  /* You can copy the code and change the index for every encoder you have. Most
     keyboards will only have two, so this piece of code will suffice. */
// } else if (index == 1) { /* Second encoder */
//    if (clockwise) {
//      tap_code(KC_UP);
//    } else {
//      tap_code(KC_DOWN);
//    }
//  }
}
