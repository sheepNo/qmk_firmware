/* Copyright 2015-2023 Jack Humbert
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

enum layers {
    _BASE = 0,
    _MOVE = 1,
    _NUM = 2,
    _SETTINGS = 3,
};


// const uint16_t PROGMEM en_combo[] = {OSM(MOD_LSFT), OSM(MOD_LCTL), COMBO_END};
// const uint16_t PROGMEM sn_combo[] = {OSM(MOD_LALT), OSM(MOD_LCTL), COMBO_END};
// const uint16_t PROGMEM se_combo[] = {OSM(MOD_LALT), OSM(MOD_LSFT), COMBO_END};
// const uint16_t PROGMEM sen_combo[] = {OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM ti_combo[] = {KC_K, KC_L, COMBO_END};

combo_t key_combos[] = {
   // COMBO(en_combo, OSM(MOD_LSFT | MOD_LCTL)),
   // COMBO(sn_combo, OSM(MOD_LALT | MOD_LCTL)),
   // COMBO(se_combo, OSM(MOD_LSFT | MOD_LALT)),
   // COMBO(sen_combo, OSM(MOD_LSFT | MOD_LCTL | MOD_LALT)),
   COMBO(ti_combo, C(KC_TAB)),
   COMBO(rt_combo, C(S(KC_TAB)))
};

// Aliases for readability
#define CTL_ESC  LCTL_T(KC_ESC)
#define MOVE_TAB LT(_MOVE, KC_TAB)
#define NUM_TAB LT(_NUM, KC_TAB)
#define NUM_ESC LT(_NUM, KC_ESC)
#define MOVE_ESC LT(_MOVE, KC_ESC)
#define MOVE_SPC LT(_MOVE, KC_SPC)
#define MOVE_TAB LT(_MOVE, KC_TAB)
#define GR_ESC MT(MOD_RALT, KC_ESC)
#define MOVE_ENT LT(_MOVE, KC_ENT)

// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: BASE
 *
 * ,--------------------------                 .---------------------.
 * | Q | C | O |    P    | W |                 |  J |  M | D | ! | Y |
 * |---+---+---+---------+---+                 +----+----+---+---+---|
 * | A | S | E |    N    | F | user            |  L |  R | T | I | U |
 * |---+---+---+---------+---+ key             +----+----+---+---+---|
 * | Z | X | ? |    V    | B |                 |  : |  H | G | F | K |
 * |---+---+---+---------+---+-----------------+----+----+---+---+---|
 *             | LWR/TAB | _ | RSE/ESC |         CR | ST | GR/ESC |
 *             `--------------------------------------------------'
 */
    [_BASE] = LAYOUT_split_3x5_3(
     KC_Q ,  KC_W,  KC_E,     KC_R,   KC_T,           KC_Y,   KC_U,    KC_I,   KC_O,    KC_P,
     KC_A ,  KC_S,  KC_D,     KC_F,   KC_G,           KC_H,   KC_J,    KC_K,   KC_L, KC_SCLN,
     KC_Z ,  KC_X,  KC_C,     KC_V,   KC_B,           KC_N,   KC_M, KC_COMM, KC_DOT, KC_SLSH,
                 KC_ESC, MOVE_SPC, NUM_TAB,           MOVE_ENT, KC_LSFT, GR_ESC
    ),

// DM_REC1, DM_REC2,     DM_PLY2  , DM_PLY1, 


/*
 * Navigation Layer: MOVE
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |      | PrtSc|      |      |      |      | PgUp | Home |   ↑  | End  | BkSpc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SUPER|  ALT | SHIFT| CTRL |CAPSLK|      |      | PgDn |  ←   |   ↓  |   →  |  Del | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | prev | play | next | vol- | vol+ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | TAB  |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_MOVE] = LAYOUT_split_3x5_3(
                        _______, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX,    KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_BSPC,
      KC_LGUI, OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_CAPS,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL ,
                        _______, _______, _______, _______, _______,    KC_MRWD, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU,
                                          _______, _______,  KC_TAB,    _______, _______, _______
    ),

/*
 * Numbers Layer: NUM
 *
 * o
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |      |      |  6   |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------| 
 * |  F11 | F12  |      |      |  DFU |      |      |      |      |      |      |      | 
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |      |      | F6   |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_NUM] = LAYOUT_split_3x5_3(
      KC_1  ,   KC_2,   KC_3 ,   KC_4 ,   KC_5 ,      KC_6,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0,
      KC_F11, KC_F12, XXXXXXX, XXXXXXX, QK_BOOT,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_F1 ,  KC_F2,  KC_F3 ,  KC_F4 ,  KC_F5 ,      KC_F6,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 ,
                      _______, _______, _______,      _______, _______, _______
    )

};
/* clang-format on */

/*
//layer_state_t layer_state_set_user(layer_state_t state) {
bool led_update_user(led_t led_state) {
    //writePin(GP25, (layer_state_cmp(state, _MOVE)));
    writePin(GP25, 0);
    return true;
}
*/


