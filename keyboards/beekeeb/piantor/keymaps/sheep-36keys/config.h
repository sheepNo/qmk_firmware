/* Copyright 2015-2021 Jack Humbert
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

#pragma once

#ifdef AUDIO_ENABLE
// #    define STARTUP_SONG SONG(PLANCK_SOUND)
#    define STARTUP_SONG SONG(NO_SOUND)
// #    define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

/*
 * MIDI options
 */

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4


#ifdef RGBLIGHT_ENABLE
//#    define RGBLIGHT_LAYERS
//#    define RGBLIGHT_LAYER_BLINK
//#    define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13} // circle
//#    define RBGLIGHT_LED_MAP {9,8,6,7,5,3,2,4,1,0,10,12,13,11,14,16,17,15,18,19} // horizontal
#    undef RGBLIGHT_ANIMATIONS
//#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_BREATHING
//#    define RGBLIGHT_EFFECT_CHRISTMAS
//#    define RGBLIGHT_EFFECT_KNIGHT 	
//#    define RGBLIGHT_EFFECT_RAINBOW_MOOD 
//#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL 
//#    define RGBLIGHT_EFFECT_RGB_TEST 	
//#    define RGBLIGHT_EFFECT_SNAKE 	
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT 
//#    define RGBLIGHT_EFFECT_TWINKLE 
#    define RGBLIGHT_SLEEP
#endif

// mod-tap :
// Lets you roll mod-tap keys
//#define IGNORE_MOD_TAP_INTERRUPT
// #define PERMISSIVE_HOLD // mod if another key is pressed and released before the tapping term while the mod-tap key is pressed
#define HOLD_ON_OTHER_KEY_PRESS
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 0

#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */
#define COMBO_TERM 40  /* Time (in ms) for combos */

// dyn macros
#define DYNAMIC_MACRO_SIZE 48
//#define DYNAMIC_MACRO_USER_CALL
#define DYNAMIC_MACRO_NO_NESTING

// size reduction
#define DISABLE_LEADER
// #define NO_ACTION_ONESHOT
// Disabled -> incompatible with LTO
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
