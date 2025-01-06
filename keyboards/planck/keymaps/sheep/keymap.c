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

// Aliases for readability
#define CTL_ESC  LCTL_T(KC_ESC)
#define MOVE_TAB LT(_MOVE, KC_TAB)
#define MOVE_SPC LT(_MOVE, KC_SPC)
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: BASE
 *
 * ,-------------------------------------------------------------------------------------.
 * |MOVE/Tab|   B  |   É  |   P  |   O  |   È  |   ^  |   V  |   D  |   L  |   J  |   Z  |
 * |--------+------+------+------+------+------+------+------+------+------+------+------|
 * |Ctrl/Esc|   A  |   U  |   I  |   E  |   ;  |   C  |   T  |   S  |   R  |   N  |   M  |
 * |--------+------+------+------+------+------+------+------+------+------+------+------|
 * |    Ç   |   À  |   Y  |   X  |   :  |   K  |   ?  |   Q  |   G  |   H  |   F  |   W  |
 * |--------+------+------+------+------+------+------+------+------+------+------+------|
 * |SETTINGS|  FN  | SUPER| ALT  | Space|  NUM | MOVE | Enter| SHIFT|ALT Gr|  FN  | CTRL |
 * `-------------------------------------------------------------------------------------'
 */
    [_BASE] = LAYOUT_planck_grid(
     MOVE_TAB ,     KC_Q ,    KC_W,    KC_E,   KC_R,     KC_T,   KC_Y,   KC_U,    KC_I,       KC_O,          KC_P, KC_LBRC,
     CTL_ESC  ,     KC_A ,    KC_S,    KC_D,   KC_F,     KC_G,   KC_H,   KC_J,    KC_K,       KC_L,       KC_SCLN, KC_QUOT,
     KC_BSLS  ,     KC_Z ,    KC_X,    KC_C,   KC_V,     KC_B,   KC_N,   KC_M, KC_COMM,     KC_DOT,       KC_SLSH, KC_RBRC,
     DM_REC1  , TG(_MOVE), KC_LGUI, KC_LALT, MOVE_SPC, TT(_NUM), KC_ENT, KC_RSFT, KC_RALT, TT(_MOVE), TG(_SETTINGS), DM_PLY1
    ),

// DM_REC1, DM_REC2,     DM_PLY2  , DM_PLY1,


/*
 * Navigation Layer: MOVE
 *
 * ,---------------------------------------------------------------------------------------.
 * |        |      |      | PrtSc|      |      | PgUp | Home |   ↑  | End  | BkSpc| Insert |
 * |--------+------+------+------+------+------|------+------+------+------+------+--------|
 * |        | SUPER|  ALT | SHIFT| CTRL |CAPSLK| PgDn |  ←   |   ↓  |   →  |  Del |  KC_NO | // évite de taper M
 * |--------+------+------+------+------+------+------+------+------+------+------+--------| // par erreur
 * |        |      |      |      |      |      |      | prev | play | next |      |        |
 * |--------+------+------+------+------+------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |      |      |      |        |
 * `---------------------------------------------------------------------------------------'
 */
    [_MOVE] = LAYOUT_planck_grid(
      _______, _______, XXXXXXX, KC_PSCR, XXXXXXX, XXXXXXX, KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_BSPC, KC_INS,
      _______, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL ,XXXXXXX,
      _______, _______, _______, _______, _______, _______,  KC_APP, KC_MRWD, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

/*
 * Numbers Layer: NUM
 *
 * ,---------------------------------------------------------------------------------------.
 * |    $   |   "  |  «   |  »   |  (   |  )   |   @  |   +  |  -   |  /   |  *   |   =    |  <--.
 * |--------+------+------+------+------+------+------+------+------+------+------+--------|     |  test inversion
 * |        |      |      |      |      |      |   %  |      |      |      |      |        |  <--'
 * |--------+------+------+------+------+------+------+------+------+------+------+--------|
 * |  F12   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
 * |--------+------+------+------+------+------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |      |      |      |        |
 * `---------------------------------------------------------------------------------------'
 */
    [_NUM] = LAYOUT_planck_grid(
      KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,   KC_6,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL ,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,KC_MINS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_F12 ,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 , KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 ,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),


/*
 * Settings Layer: SETTINGS
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|      |AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
    [_SETTINGS] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  _______, _______, _______, _______, _______, _______, _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};
/* clang-format on */

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                print("mode just switched to qwerty and this is a huge string\n");
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
#ifdef BACKLIGHT_ENABLE
                backlight_step();
#endif
#ifdef KEYBOARD_planck_rev5
                writePinLow(E6);
#endif
            } else {
                unregister_code(KC_RSFT);
#ifdef KEYBOARD_planck_rev5
                writePinHigh(E6);
#endif
            }
            return false;
            break;
        case PLOVER:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                stop_all_notes();
                PLAY_SONG(plover_song);
#endif
                layer_off(_RAISE);
                layer_off(_LOWER);
                layer_off(_ADJUST);
                layer_on(_PLOVER);
                if (!eeconfig_is_enabled()) {
                    eeconfig_init();
                }
                keymap_config.raw  = eeconfig_read_keymap();
                keymap_config.nkro = 1;
                eeconfig_update_keymap(keymap_config.raw);
            }
            return false;
            break;
        case EXT_PLV:
            if (record->event.pressed) {
#ifdef AUDIO_ENABLE
                PLAY_SONG(plover_gb_song);
#endif
                layer_off(_PLOVER);
            }
            return false;
            break;
    }
    return true;
}
*/

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307



uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

/*
deferred_token tokens[8];

bool encoder_update_user(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    if (clockwise) {
        melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
        audio_play_melody(&melody[index], 2, false);
    } else {
        melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
        audio_play_melody(&melody[index], 2, false);
    }
    tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
    return false;
}
*/

/*
bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_song);
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                    PLAY_SONG(plover_gb_song);
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}
*/

#ifdef RGBLIGHT_ENABLE
const uint8_t blink_duration = 100;

/*
 * LED physical location index
 *     6 5 4 3
 *        0
 *     7 8 1 2
*/
/*
const rgblight_segment_t PROGMEM num_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM move_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 1, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM settings_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 1, HSV_GREEN}
);
const rgblight_segment_t PROGMEM dm_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7, 1, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    num_layer,
    move_layer,
    settings_layer,
    dm_layer
);
*/

//uint8_t hues[] = {118, 103, 98, 83, 68, 53, 38, 21, 8};
uint8_t hues[] = {248, 212, 176, 140, 100, 78, 52, 26, 0};

uint8_t sats[] = {240, 240, 240, 240, 240, 240, 240, 240, 240};
uint8_t val = 255;
uint8_t default_hues[] = {103, 103, 98, 83, 68, 53, 38, 21, 8};
//uint8_t default_sats[] = {0, 240, 240, 240, 240, 240, 240, 240, 240};
uint8_t default_sats[9] = {0};
//uint8_t default_val = 100;
uint8_t default_val = 0;

void keyboard_post_init_user(void) {
    // Enable the LED layers
    //rgblight_layers = my_rgb_layers;
    rgblight_sethsv_noeeprom(0, 0, default_val);
}

uint32_t callback_led_off(uint32_t trigger_time, void *cb_arg) {
    uint8_t h_prev = ((uint8_t *)cb_arg)[0];
    uint8_t s_prev = ((uint8_t *)cb_arg)[1];
    uint8_t v_prev = ((uint8_t *)cb_arg)[2];
    uint8_t idx = ((uint8_t *)cb_arg)[3];
    free(cb_arg);

    rgblight_sethsv_at(h_prev, s_prev, v_prev, idx);
    return 0;
}


/*
 * LED physical location index
 *     6 5 4 3
 *        0
 *     7 8 1 2
*/

// TODO :      _______, _______, _______, _______, _______, _______,  KC_APP, KC_MRWD, KC_MPLY, KC_MNXT, KC_VOLD, KC_VOLU,

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ENT:
            if (record->event.pressed) {
                uint8_t idx = 0;
                uint8_t *hsvi_prev = malloc(4 * sizeof(uint8_t));
                hsvi_prev[0] = default_hues[idx];
                hsvi_prev[1] = default_sats[idx];
                hsvi_prev[2] = default_val;
                hsvi_prev[3] = idx;

                rgblight_sethsv_at(HSV_RED, idx);
                defer_exec(blink_duration, callback_led_off, hsvi_prev);
            };
            break;
        case KC_G:
        case KC_H:
        case KC_B:
        case KC_N:
            if (record->event.pressed) {
                uint8_t idx = 0;
                uint8_t *hsvi_prev = malloc(4 * sizeof(uint8_t));
                hsvi_prev[0] = default_hues[idx];
                hsvi_prev[1] = default_sats[idx];
                hsvi_prev[2] = default_val;
                hsvi_prev[3] = idx;

                rgblight_sethsv_at(hues[idx], sats[idx], val, idx);
                defer_exec(blink_duration, callback_led_off, hsvi_prev);
            };
            break;
        case KC_TAB:
        case KC_Q:
        case KC_W:
        case KC_ESC:
        case KC_A:
        case KC_S:
        case KC_GRV:
        case KC_1:
        case KC_2:
            if (record->event.pressed) {
                uint8_t idx = 6;
                uint8_t *hsvi_prev = malloc(4 * sizeof(uint8_t));
                hsvi_prev[0] = default_hues[idx];
                hsvi_prev[1] = default_sats[idx];
                hsvi_prev[2] = default_val;
                hsvi_prev[3] = idx;

                rgblight_sethsv_at(hues[idx], sats[idx], val, idx);
                defer_exec(blink_duration, callback_led_off, hsvi_prev);
            };
            break;
        case KC_E:
        case KC_R:
        case KC_T:
        case KC_D:
        case KC_F:
        case KC_LSFT:
        case KC_LCTL:
        case KC_3:
        case KC_4:
        case KC_5:
            if (record->event.pressed) {
                uint8_t idx = 5;
                uint8_t *hsvi_prev = malloc(4 * sizeof(uint8_t));
                hsvi_prev[0] = default_hues[idx];
                hsvi_prev[1] = default_sats[idx];
                hsvi_prev[2] = default_val;
                hsvi_prev[3] = idx;

                rgblight_sethsv_at(hues[idx], sats[idx], val, idx);
                defer_exec(blink_duration, callback_led_off, hsvi_prev);
            };
            break;
        case KC_Y:
        case KC_U:
        case KC_I:
        case KC_J:
        case KC_K:
        case KC_LEFT:
        case KC_PGUP:
        case KC_HOME:
        case KC_UP:
        case KC_6:
        case KC_7:
        case KC_8:
        case KC_MINS:
            if (record->event.pressed) {
                uint8_t idx = 4;
                uint8_t *hsvi_prev = malloc(4 * sizeof(uint8_t));
                hsvi_prev[0] = default_hues[idx];
                hsvi_prev[1] = default_sats[idx];
                hsvi_prev[2] = default_val;
                hsvi_prev[3] = idx;

                rgblight_sethsv_at(hues[idx], sats[idx], val, idx);
                defer_exec(blink_duration, callback_led_off, hsvi_prev);
            };
            break;
        case KC_O:
        case KC_P:
        case KC_LBRC:
        case KC_L:
        case KC_SCLN:
        case KC_QUOT:
        case KC_RGHT:
        case KC_DEL:
        case KC_END:
        case KC_BSPC:
        case KC_INS:
        case KC_9:
        case KC_0:
        case KC_EQL:
            if (record->event.pressed) {
                uint8_t idx = 3;
                uint8_t *hsvi_prev = malloc(4 * sizeof(uint8_t));
                hsvi_prev[0] = default_hues[idx];
                hsvi_prev[1] = default_sats[idx];
                hsvi_prev[2] = default_val;
                hsvi_prev[3] = idx;

                rgblight_sethsv_at(hues[idx], sats[idx], val, idx);
                defer_exec(blink_duration, callback_led_off, hsvi_prev);
            };
            break;
        case KC_BSLS:
        case KC_Z:
        case KC_X:
        case KC_LGUI:
            if (record->event.pressed) {
                uint8_t idx = 7;
                uint8_t *hsvi_prev = malloc(4 * sizeof(uint8_t));
                hsvi_prev[0] = default_hues[idx];
                hsvi_prev[1] = default_sats[idx];
                hsvi_prev[2] = default_val;
                hsvi_prev[3] = idx;

                rgblight_sethsv_at(hues[idx], sats[idx], val, idx);
                defer_exec(blink_duration, callback_led_off, hsvi_prev);
            };
            break;
        case KC_C:
        case KC_V:
        case KC_LALT:
        case KC_SPC:
            if (record->event.pressed) {
                uint8_t idx = 8;
                uint8_t *hsvi_prev = malloc(4 * sizeof(uint8_t));
                hsvi_prev[0] = default_hues[idx];
                hsvi_prev[1] = default_sats[idx];
                hsvi_prev[2] = default_val;
                hsvi_prev[3] = idx;

                rgblight_sethsv_at(hues[idx], sats[idx], val, idx);
                defer_exec(blink_duration, callback_led_off, hsvi_prev);
            };
            break;
        case KC_M:
        case KC_COMM:
        case KC_RSFT:
        case KC_RALT:
        case KC_PGDN:
        case KC_DOWN:
            if (record->event.pressed) {
                uint8_t idx = 1;
                uint8_t *hsvi_prev = malloc(4 * sizeof(uint8_t));
                hsvi_prev[0] = default_hues[idx];
                hsvi_prev[1] = default_sats[idx];
                hsvi_prev[2] = default_val;
                hsvi_prev[3] = idx;

                rgblight_sethsv_at(hues[idx], sats[idx], val, idx);
                defer_exec(blink_duration, callback_led_off, hsvi_prev);
            };
            break;
        case KC_DOT:
        case KC_SLSH:
        case KC_RBRC:
            if (record->event.pressed) {
                uint8_t idx = 2;
                uint8_t *hsvi_prev = malloc(4 * sizeof(uint8_t));
                hsvi_prev[0] = default_hues[idx];
                hsvi_prev[1] = default_sats[idx];
                hsvi_prev[2] = default_val;
                hsvi_prev[3] = idx;

                rgblight_sethsv_at(hues[idx], sats[idx], val, idx);
                defer_exec(blink_duration, callback_led_off, hsvi_prev);
            };
            break;
    }
}

void dynamic_macro_record_start_user(int8_t direction) {
    // Triggered when you start recording a macro.
    uint8_t idx = 7;
    // HSV_RED
    rgblight_sethsv_at(HSV_RED, idx);
    //rgblight_set_layer_state(3, true);
    return;
}

void dynamic_macro_record_end_user(int8_t direction) {
    // Triggered when the macro recording is stopped.
    uint8_t idx = 7;
    rgblight_sethsv_at(default_hues[idx], default_sats[idx], default_val, idx);
    //rgblight_set_layer_state(3, false);
    return;
}

// #TODO : illuminer les touches quand le layers MOVE est activé et revoir la répartitions des touches pour faire clignoter les leds du bas un peu plus souvent


layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, _MOVE)) {
        uint8_t idx = 6;
        rgblight_sethsv_at(HSV_ORANGE, idx);
        //rgblight_sethsv_at(HSV_ORANGE, 6);
    } else {
        uint8_t idx = 6;
        rgblight_sethsv_at(default_hues[idx], default_sats[idx], default_val, idx);
        //rgblight_sethsv_at(hues[6], default_sat, default_val, 6);
    }

    if (layer_state_cmp(state, _NUM)) {
        uint8_t idx = 0;
        rgblight_sethsv_at(HSV_PURPLE, idx);
        //rgblight_sethsv_at(HSV_PURPLE, 0);
    } else {
        uint8_t idx = 0;
        rgblight_sethsv_at(default_hues[idx], default_sats[idx], default_val, idx);
        //rgblight_sethsv_at(hues[0], default_sat, default_val, 0);
    }

    if (layer_state_cmp(state, _SETTINGS)) {
        uint8_t idx = 2;
        rgblight_sethsv_at(HSV_GREEN, idx);
        //rgblight_sethsv_at(HSV_GREEN, 2);
    } else {
        uint8_t idx = 2;
        rgblight_sethsv_at(default_hues[idx], default_sats[idx], default_val, idx);
        //rgblight_sethsv_at(hues[2], default_sat, default_val, 2);
    }

    //rgblight_set_layer_state(0, layer_state_cmp(state, _NUM)); // num_layer rgb
    //rgblight_set_layer_state(1, layer_state_cmp(state, _MOVE)); // move_layer rgb
    //rgblight_set_layer_state(2, layer_state_cmp(state, _SETTINGS)); // settings_layer rgb
    return state;
}
#endif //RGBLIGHT_ENABLE
