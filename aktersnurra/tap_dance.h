#pragma once

#include QMK_KEYBOARD_H

typedef enum { _COLEMAK_DH, _LOWER, _RAISE } layers;

typedef enum { SINGLE_TAP, SINGLE_HOLD, DOUBLE_SINGLE_TAP } td_state_t;

typedef enum { M_ESC, TD_LOWER, TD_RAISE } tap_dances;

int cur_dance(qk_tap_dance_state_t *state);

void raise_finished(qk_tap_dance_state_t *state, void *user_data);
void raise_reset(qk_tap_dance_state_t *state, void *user_data);

void lower_finished(qk_tap_dance_state_t *state, void *user_data);
void lower_reset(qk_tap_dance_state_t *state, void *user_data);
