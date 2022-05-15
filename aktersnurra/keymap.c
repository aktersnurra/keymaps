// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _COLEMAK_DH,
  _LOWER,
  _RAISE
};

enum ferris_tap_dances {
  TD_Q_ESC,
  TD_M_ESC
};

#define KC_HOME_A GUI_T(KC_A)
#define KC_HOME_R ALT_T(KC_R)
#define KC_HOME_S CTL_T(KC_S)
#define KC_HOME_T SFT_T(KC_T)

#define KC_HOME_O GUI_T(KC_O)
#define KC_HOME_I ALT_T(KC_I)
#define KC_HOME_E CTL_T(KC_E)
#define KC_HOME_N SFT_T(KC_N)

#define LOWER LT(_LOWER, KC_ENT)
#define RAISE LT(_RAISE, KC_TAB)

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_M_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_ESC)
    [TD_G_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_G, KC_ESC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT( /* QWERTY */
    TD(TD_Q_ESC), KC_W,      KC_F,      KC_P,      KC_B,            KC_J,         KC_L,      KC_U,      KC_Y,      KC_SCLN,
    KC_HOME_A,    KC_HOME_R, KC_HOME_S, KC_HOME_T, TD(TD_G_ESC),    TD(TD_M_ESC), KC_HOME_N, KC_HOME_E, KC_HOME_I, KC_HOME_O,
    KC_Z,         KC_X,      KC_C,      KC_D,      KC_V,            KC_K,         KC_H,      KC_COMM,   KC_DOT,    KC_SLSH,
                                        LOWER,     KC_SPC,          KC_BSPC,      RAISE
  ),

  [_LOWER] = LAYOUT( /* [> LOWER <] */
    KC_GRV,  KC_EXLM, KC_PERC, KC_DLR,   KC_AT,         KC_PIPE, KC_HASH,  KC_ASTR,  KC_AMPR,  KC_CIRC,
    KC_TRNS, KC_LBRC, KC_LPRN, KC_TRANS, KC_COMM,       KC_DOT,  KC_TRANS, KC_QUOT,  KC_DQT,   KC_TRNS,
    KC_TRNS, KC_RBRC, KC_RPRN, KC_TRANS, KC_TRANS,      KC_BSLS, KC_TRANS, KC_TRANS, KC_TRANS, KC_TRANS,
                               KC_TRNS,  KC_TRNS,       KC_TRNS, KC_TRNS
  ),

  [_RAISE] = LAYOUT( /* [> RAISE <] */
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
    KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY,        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV,        KC_MPXT, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                               KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
  )
};
