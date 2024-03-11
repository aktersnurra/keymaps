typedef enum {
  TD_NONE,
  TD_UNKNOWN,
  TD_SINGLE_TAP,
  TD_SINGLE_HOLD,
  TD_DOUBLE_SINGLE_TAP
} td_state_t;

static td_state_t td_state;

td_state_t cur_dance(tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->interrupted || !state->pressed)
      return TD_SINGLE_TAP;
    else
      return TD_SINGLE_HOLD;
  }
  if (state->count == 2)
    return TD_DOUBLE_SINGLE_TAP;
  else
    return TD_UNKNOWN;
}

void sftrp_finished(tap_dance_state_t *state, void *user_data) {
  td_state = cur_dance(state);
  switch (td_state) {
  case TD_SINGLE_TAP:
    register_code16(KC_RPRN);
    break;
  case TD_SINGLE_HOLD:
    register_mods(MOD_BIT(
        KC_LSFT));
    break;
  case TD_DOUBLE_SINGLE_TAP:
    tap_code16(KC_RPRN);
    register_code16(KC_RPRN);
    break;
  default:
    break;
  }
}

void sftrp_reset(tap_dance_state_t *state, void *user_data) {
  switch (td_state) {
  case TD_SINGLE_TAP:
    unregister_code16(KC_RPRN);
    break;
  case TD_SINGLE_HOLD:
    unregister_mods(MOD_BIT(
        KC_LSFT));
    break;
  case TD_DOUBLE_SINGLE_TAP:
    unregister_code16(KC_RPRN);
    break;
  default:
    break;
  }
}
