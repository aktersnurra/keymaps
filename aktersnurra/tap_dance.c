#include "tap_dance.h"

static td_state_t td_state;

int cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed) {
      return SINGLE_TAP;
    } else {
      return SINGLE_HOLD;
    }
  }
  if (state->count == 2) {
    return DOUBLE_SINGLE_TAP;
  } else {
    return 3;
  }
}

void raise_finished(qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
  case SINGLE_TAP:
    register_code16(KC_BSPC);
    break;
  case SINGLE_HOLD:
    layer_on(_RAISE);
    break;
  case DOUBLE_SINGLE_TAP:
    tap_code16(KC_BSPC);
    register_code16(KC_BSPC);
  }
}

void raise_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
  case SINGLE_TAP:
    unregister_code16(KC_BSPC);
    break;
  case SINGLE_HOLD:
    layer_off(_RAISE);
    break;
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_BSPC);
  }
}

void lower_finished(qk_tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
  case SINGLE_TAP:
    register_code16(KC_SPC);
    break;
  case SINGLE_HOLD:
    layer_on(_LOWER);
    break;
  case DOUBLE_SINGLE_TAP:
    tap_code16(KC_SPC);
    register_code16(KC_SPC);
  }
}

void lower_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
  case SINGLE_TAP:
    unregister_code16(KC_SPC);
    break;
  case SINGLE_HOLD:
    layer_off(_LOWER);
    break;
  case DOUBLE_SINGLE_TAP:
    unregister_code16(KC_SPC);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [M_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_ESC),
    [TD_RAISE] =
        ACTION_TAP_DANCE_FN_ADVANCED(NULL, raise_finished, raise_reset),
    [TD_LOWER] =
        ACTION_TAP_DANCE_FN_ADVANCED(NULL, lower_finished, lower_reset)};
