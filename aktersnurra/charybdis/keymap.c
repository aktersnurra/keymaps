#include QMK_KEYBOARD_H
#include "../sftrp.c"

#define KC_HA GUI_T(KC_A)
#define KC_HR ALT_T(KC_R)
#define KC_HS CTL_T(KC_S)
#define KC_HT SFT_T(KC_T)

#define KC_HO GUI_T(KC_O)
#define KC_HI ALT_T(KC_I)
#define KC_HE CTL_T(KC_E)
#define KC_HN SFT_T(KC_N)

#define KC_SLBRC SFT_T(KC_LBRC)

#define KC_ALT_CTL LALT(KC_LCTL)

#define NAV LT(_NAV, KC_SPC)
#define SYM LT(_SYM, KC_BSPC)
#define NUM LT(_NUM, KC_TAB)
#define CHARYBDIS_AUTO_SNIPING_ON_LAYER _MOU

enum { _COLEMAK_DH, _NAV, _NUM, _SYM, _FUN, _MEDIA, } layers;
enum td_keycodes {
  SFT_RP,
};

tap_dance_action_t tap_dance_actions[] = {
    [SFT_RP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, sftrp_finished, sftrp_reset)};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK_DH] = LAYOUT( /* COLEMAK MOD DH */
    KC_Q,  KC_W,  KC_F,  KC_P,   KC_B,            KC_J, KC_L,  KC_U,    KC_Y,   KC_SCLN,
    KC_HA, KC_HR, KC_HS, KC_HT,  KC_G,            KC_M, KC_HN, KC_HE,   KC_HI,  KC_HO,
    KC_Z,  KC_X,  KC_C,  KC_D,   KC_V,            KC_K, KC_H,  KC_COMM, KC_DOT, KC_SLSH,
                  KC_ENT, NAV,   KC_ESC,          SYM,  NUM
  ),

  [_SYM] = LAYOUT( /* [> Symbol layer <] */
    KC_TRNS, KC_EXLM, KC_PERC, KC_DLR,     KC_AMPR,     KC_AT,  KC_ASTR,  KC_CIRC, KC_TRNS, KC_TRNS,
    KC_GRV,  KC_HASH,  KC_LPRN, TD(SFT_RP), KC_MINS,    KC_EQL,  KC_SLBRC, KC_RBRC, KC_QUOT, KC_PIPE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_BSLS,
                      KC_TRNS, KC_SPC,     KC_TRNS,     KC_TRNS, KC_TRNS
  ),

  [_NAV] = LAYOUT( /* [> Mouse/Nav layer <] */
    KC_TRNS, KC_TRNS, KC_WH_D, KC_WH_U, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS,        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS,        KC_BSPC, KC_TRNS
  ),

  [_NUM] = LAYOUT( /* [> Number layer <] */
    KC_TRNS, KC_4,    KC_5,    KC_6,        KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_1,    KC_2,    KC_3,        KC_0,            KC_TRNS, KC_7,    KC_8,    KC_9,    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      MO(_MEDIA),  MO(_FUN), KC_TRNS,        KC_TRNS, KC_TRNS
  ),

  [_MEDIA] = LAYOUT( /* [> Media layer <] */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS,        KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS
  ),

  [_FUN] = LAYOUT( /* [> Function layer <] */
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, EE_CLR, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_ALT_CTL, KC_TRNS,        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS,    KC_TRNS,        KC_TRNS, KC_TRNS
  ),
};
