// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "tap_dance.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

#define KC_HA GUI_T(KC_A)
#define KC_HR ALT_T(KC_R)
#define KC_HS CTL_T(KC_S)
#define KC_HT SFT_T(KC_T)

#define KC_HO GUI_T(KC_O)
#define KC_HI ALT_T(KC_I)
#define KC_HE CTL_T(KC_E)
#define KC_HN SFT_T(KC_N)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT( /* COLEMAK MOD DH */
    KC_Q,  KC_W,  KC_F,  KC_P,   KC_B,                  KC_J,         KC_L,   KC_U,    KC_Y,   KC_SCLN,
    KC_HA, KC_HR, KC_HS, KC_HT,  KC_G,                  TD(M_ESC),    KC_HN,  KC_HE,   KC_HI,  KC_HO,
    KC_Z,  KC_X,  KC_C,  KC_D,   KC_V,                  KC_K,         KC_H,   KC_COMM, KC_DOT, KC_SLSH,
                         KC_ENT, TD(TD_LOWER),          TD(TD_RAISE), KC_TAB
  ),

  [_LOWER] = LAYOUT( /* [> LOWER <] */
    KC_GRV,  KC_EXLM, KC_PERC, KC_DLR,  KC_AT,          KC_PIPE, KC_HASH, KC_ASTR, KC_AMPR, KC_CIRC,
    KC_TRNS, KC_LBRC, KC_LPRN, KC_TRNS, KC_QUOT,        KC_DQT,  KC_TRNS, KC_EQL,  KC_MINS, KC_BSLS,
    KC_TRNS, KC_RBRC, KC_RPRN, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                               KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
  ),

  [_RAISE] = LAYOUT( /* [> RAISE <] */
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,           KC_6,    KC_7,    KC_8,    KC_9,     KC_0,
    KC_TRNS, KC_MUTE, KC_VOLU, KC_VOLD, KC_MPLY,        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS,
    KC_LCTL, KC_LALT, KC_TRNS, KC_TRNS, KC_MPRV,        KC_MNXT, KC_TRNS, KC_F1,   KC_F2,    KC_F3,
                               KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
  )
};
