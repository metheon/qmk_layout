#include "tap_dances.h"

// /////// //
// SCLN AE //
// /////// //
void td_scln_ae_finished(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 1) {
        register_code16(KC_SCLN);
    } else {
        tap_kc_ae(true);
    }
}

void td_scln_ae_reset(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 1) {
        unregister_code16(KC_SCLN);
    } else {
        tap_kc_ae(false);
    }
}

// /////// //
// SCLN OE //
// /////// //
void td_mins_oe_finished(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 1) {
        register_code16(KC_MINS);
    } else {
        tap_kc_oe(true);
    }
}

void td_mins_oe_reset(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 1) {
        unregister_code16(KC_MINS);
    } else {
        tap_kc_oe(false);
    }
}

// /////// //
// SCLN AA //
// /////// //
void td_quot_aa_finished(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 1) {
        register_code16(KC_QUOT);
    } else {
        tap_kc_aa(true);
    }
}

void td_quot_aa_reset(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 1) {
        unregister_code16(KC_QUOT);
    } else {
        tap_kc_aa(false);
    }
}

// ///////////////////// //
// TAP DANCE DEFINITIONS //
// ///////////////////// //
qk_tap_dance_action_t tap_dance_actions[] = {
    // tap once for semicolon, twice for ae
    [TD_SCLN_AE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_scln_ae_finished, td_scln_ae_reset),
    [TD_MINS_OE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_mins_oe_finished, td_mins_oe_reset),
    [TD_QUOT_AA] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_quot_aa_finished, td_quot_aa_reset),
};

