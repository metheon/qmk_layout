#include "quantum.h"
#include "metheon.h"
#include "tap_dance.h"

// Advanced tap dance functions
void ctrl_ctrlshift_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LCTL);
    } else {
        register_code(KC_LCTL);
        register_code(KC_LSFT);
    }
}

void ctrl_ctrlshift_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_LCTL);
    } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
    }
}

// Add tap dance functions to tap dance array
// clang-format off
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CONTROL_CTRLSHIFT]  =   ACTION_TAP_DANCE_FN_ADVANCED    (NULL, ctrl_ctrlshift_finished, ctrl_ctrlshift_reset),
    [TD_ALT_GUI]            =   ACTION_TAP_DANCE_DOUBLE         (KC_LALT, KC_LGUI),
    [TD_GUI_ALT]            =   ACTION_TAP_DANCE_DOUBLE         (KC_LGUI, KC_LALT)
};
// clang-format on
