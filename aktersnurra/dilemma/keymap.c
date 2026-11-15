#include QMK_KEYBOARD_H

#define KC_HA GUI_T(KC_A)
#define KC_HR ALT_T(KC_R)
#define KC_HS CTL_T(KC_S)
#define KC_HT SFT_T(KC_T)

#define KC_HO GUI_T(KC_O)
#define KC_HI ALT_T(KC_I)
#define KC_HE CTL_T(KC_E)
#define KC_HN RSFT_T(KC_N)

#define KC_ALT_CTL LALT(KC_LCTL)

#define NAV LT(_NAV, KC_SPC)
#define SYM LT(_SYM, KC_BSPC)
#define NUM LT(_NUM, KC_TAB)

enum { _COLEMAK_DH, _NAV, _NUM, _SYM, _FUN, _MEDIA, } layers;

// Thumb layer keys get a shorter term so layers (and sniping) engage sooner.
// Everything else follows the global term, which DT_UP/DT_DOWN adjust live.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  if (IS_QK_LAYER_TAP(keycode)) {
    return 180;
  }
  return g_tapping_term;
}

// A mod-tap only becomes a hold when the next key is on the other hand.
// Thumb keys ('*') count as either hand, so home row mods combine with them
// (Gui+Enter, Ctrl+Esc) and thumb layer keys combine with anything.
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x5_3(
  'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R',
  'L', 'L', 'L', 'L', 'L',      'R', 'R', 'R', 'R', 'R',
            '*', '*', '*',      '*', '*', '*'
);

// While typing quickly, home row mods are always taps. Layer keys and
// Shift are exempt, so thumb layers and capitals mid-sentence still work.
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record,
                           uint16_t prev_keycode) {
  if (!IS_QK_MOD_TAP(keycode) || !is_flow_tap_key(prev_keycode)) {
    return 0;
  }
  switch (keycode) {
  case KC_HT:
  case KC_HN:
    return 0;
  default:
    return FLOW_TAP_TERM;
  }
}

// Slow, precise pointer while the Nav layer is held.
layer_state_t layer_state_set_user(layer_state_t state) {
  dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, _NAV));
  return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT_split_3x5_3( /* COLEMAK MOD DH */
    KC_Q,  KC_W,  KC_F,  KC_P,   KC_B,            KC_J, KC_L,  KC_U,    KC_Y,   KC_SCLN,
    KC_HA, KC_HR, KC_HS, KC_HT,  KC_G,            KC_M, KC_HN, KC_HE,   KC_HI,  KC_HO,
    KC_Z,  KC_X,  KC_C,  KC_D,   KC_V,            KC_K, KC_H,  KC_COMM, KC_DOT, KC_SLSH,
                  KC_ENT, NAV,   KC_ESC,          SYM,  NUM,   KC_LGUI
  ),

  [_SYM] = LAYOUT_split_3x5_3( /* [> Symbol layer <] */
    KC_TRNS, KC_EXLM, KC_PERC, KC_DLR,     KC_AMPR,     KC_AT,  KC_ASTR,  KC_CIRC, KC_TRNS, KC_TRNS,
    KC_GRV,  KC_HASH, KC_LPRN, KC_RPRN,    KC_MINS,     KC_EQL,  KC_LBRC,  KC_RBRC, KC_QUOT, KC_PIPE,
    KC_TILD, KC_TRNS, KC_LT,   KC_GT,      KC_UNDS,     KC_PLUS, KC_LCBR,  KC_RCBR, KC_DQUO, KC_BSLS,
                      KC_TRNS, KC_SPC,     KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS
  ),

  [_NAV] = LAYOUT_split_3x5_3( /* [> Mouse/Nav layer <] */
    KC_TRNS, KC_TRNS, KC_WH_D, KC_WH_U, KC_TRNS,        KC_HOME, KC_PGDN, KC_PGUP, KC_END,   KC_TRNS,
    KC_TRNS, KC_BTN3, KC_BTN2, KC_BTN1, KC_TRNS,        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS,        KC_BSPC, KC_DEL, KC_TRNS
  ),

  [_NUM] = LAYOUT_split_3x5_3( /* [> Number layer <] */
    KC_TRNS, KC_4,    KC_5,        KC_6,     KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_1,    KC_2,        KC_3,     KC_0,           KC_TRNS, KC_7,    KC_8,    KC_9,    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,  KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      MO(_MEDIA),  MO(_FUN), KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_MEDIA] = LAYOUT_split_3x5_3( /* [> Media layer <] */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS,        KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_FUN] = LAYOUT_split_3x5_3( /* [> Function layer <] */
    QK_BOOT, KC_TRNS, RM_TOGG, RM_PREV,    RM_NEXT,       KC_TRNS, KC_F4,   KC_F5,   KC_F6,   KC_F7,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_ALT_CTL, KC_TRNS,        KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F11,
    EE_CLR,  KC_TRNS, DT_DOWN, DT_UP,      DT_PRNT,        KC_TRNS, KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
                      KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS
  ),
};
