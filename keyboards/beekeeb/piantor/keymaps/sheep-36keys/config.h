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
//#include "gpio.h"

// mod-tap :
// Lets you roll mod-tap keys
//#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD // mod if another key is pressed and released before the tapping term while the mod-tap key is pressed
//#define HOLD_ON_OTHER_KEY_PRESS // hold if another key is pressed whateve the tapping term
#define TAPPING_TERM 150
#define QUICK_TAP_TERM 0 // disable double tap to hold

#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */
#define COMBO_TERM 10  /* Time (in ms) for combos */

// dyn macros
// #define DYNAMIC_MACRO_SIZE 48
//#define DYNAMIC_MACRO_USER_CALL
#define DYNAMIC_MACRO_NO_NESTING

// size reduction
#define DISABLE_LEADER
// #define NO_ACTION_ONESHOT
// Disabled -> incompatible with LTO
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
