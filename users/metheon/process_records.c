#include "process_records.h"
#include "which_os.h"
#include "window_tab.h"
#include "metheon.h"

#undef OSKEY
#define OSKEY(name, linux, mac)           \
    case name:                            \
        tap_os_key(linux, mac, pressed);  \
        break;

// call this function for plain tapping a keycode which differs on the OS'es
void tap_os_key(uint16_t lnx_keycode, uint16_t mac_keycode, bool pressed) {
    if (pressed) {
        tap_code16(is_linux() ? lnx_keycode : mac_keycode);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
        // all mod_tab cases
        case NEXT_WIN:
            mod_tab(record, false);
            break;
        case PREV_WIN:
            mod_tab(record, S(true));
            break;
        // include all keys that change between OS'es
#include "oskeys.def"
        default:
            return true;
    }
    return false;
};
