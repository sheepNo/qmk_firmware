#include QMK_KEYBOARD_H

// Layer declaration
enum {
  DEFAULT = 0,
  RAISE = 1,
  NUM = 2,
  ARROWS = 3, 
  NOTAP = 4,
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

// Define a type for as many tap dance states as you need
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP
};

enum {
    RAISE_OR_NUM, // Our custom tap dance key; add any other tap dance keys to this enum 
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
uint8_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(qk_tap_dance_state_t *state, void *user_data);
void ql_reset(qk_tap_dance_state_t *state, void *user_data);

// ------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[DEFAULT] = LAYOUT(
      KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_DEL, 
      LT(1,KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
      LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, TD(RAISE_OR_NUM),
      KC_LGUI, KC_LALT, KC_SPC, KC_RALT, TG(NOTAP)),
	[RAISE] = LAYOUT(
      KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_BSLS, KC_DEL,
      KC_TRNS, KC_Q, KC_W, KC_PGUP, KC_PGDN, KC_T, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_BSPC, KC_INS, KC_RBRC, KC_BSPC,
      KC_ESC, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_G, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_PSCR, KC_ENT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, KC_VOLU, KC_VOLD, KC_MPLY, KC_MNXT, KC_RSFT, KC_TRNS,
      KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_TRNS),
	[NUM] = LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_P7, KC_P8, KC_P9, KC_LBRC, KC_RBRC, KC_BSPC,
      KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_P4, KC_P5, KC_P6, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_P1, KC_P2, KC_P3, KC_RSFT, KC_TRNS,
      KC_LGUI, KC_LALT, KC_SPC, KC_P0, KC_TRNS),
	[ARROWS] = LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_UP, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
      KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_LEFT, KC_DOWN, KC_RIGHT, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_TRNS,
      KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_TRNS),
	[NOTAP] = LAYOUT(
      KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,
      KC_O, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSPC,
      KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_TRNS,
      KC_LGUI, KC_LALT, KC_SPC, KC_RALT, KC_TRNS)
};

// Determine the current tap dance state
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) return DOUBLE_TAP;
    else return 8;
}

// Initialize tap structure associated with example tap dance key
static tap ql_tap_state = {
    .is_press_action = true,
    .state = 0
};

// Functions that control what our tap dance key does
void ql_finished(qk_tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case SINGLE_TAP:
            if (layer_state_is(NUM)) {
                // If already set, then switch it off
                layer_off(NUM);
            } else {
                if (layer_state_is(ARROWS)) {
                    layer_off(ARROWS);
                }
                // If not already set, then switch the layer on
                layer_on(NUM);
            }
            break;
        case SINGLE_HOLD:
            layer_on(RAISE);
            break;
        case DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(ARROWS)) {
                // If already set, then switch it off
                layer_off(ARROWS);
            } else {
                if (layer_state_is(NUM)) {
                    layer_off(NUM);
                }
                // If not already set, then switch the layer on
                layer_on(ARROWS);
            }
            break;
    }
}

void ql_reset(qk_tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == SINGLE_HOLD) {
        layer_off(RAISE);
    }
    ql_tap_state.state = 0;
}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
    //[RAISE_OR_NUM] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, ql_finished, ql_reset, 275)
    [RAISE_OR_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
};
