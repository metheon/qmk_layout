#include "process_records.h"
#include "metheon.h"
#include "oneshot.h"

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case NUM:
    case NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case NUM:
    case NAV:
    case CTRL:
    case ALT:
    case SHIFT:
    case GUI:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, SHIFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LGUI, GUI,
        keycode, record
    );

    // caps word related processing
    if (!process_caps_word(keycode, record)) {
        return false;
    }

    const bool pressed = record->event.pressed;
    switch (keycode) {
        // caps word related cases (start and stop modes)
        case CPS_DSBL:
            if(pressed) {
                disable_all();
            }
            break;
        case SCRM_SNK:
            if(pressed) {
                toggle_screaming_snake_case();
            }
            break;
        case SNK_CASE:
            if (pressed) {
                toggle_snake_case();
            }
            break;
        case CAPSWORD:
            if (pressed) {
                toggle_caps_word();
            }
            break;
        default:
            // return true to keep processing the key
            return true;
    }
    // return false to ignore further processing of the key
    return false;
};
