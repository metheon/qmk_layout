#include "which_os.h"

bool     is_mod_tab_active = false;
uint16_t mod_tab_timer     = 0;

void register_mod(void) {
    if(is_windows()) {
        register_code(KC_LALT);
    } else if (is_mac()) {
        register_code(KC_LGUI);
    }
}

void unregister_mod(void) {
    if(is_windows()) {
        unregister_code(KC_LALT);
    } else if (is_mac()) {
        unregister_code(KC_LGUI);
    }
}

void matrix_scan_window_tab(void) {
    if (is_mod_tab_active) {
        if (timer_elapsed(mod_tab_timer) > 750) {
            unregister_mod();
            is_mod_tab_active = false;
        }
    }
}

bool mod_tab(keyrecord_t *record, bool shifted) {
    if(record->event.pressed) {
        if (!is_mod_tab_active) {
            is_mod_tab_active = true;
            register_mod();
        }
        mod_tab_timer = timer_read();
        if(shifted) {
            tap_code16(S(KC_TAB));
        } else {
            tap_code16(KC_TAB);
        }
        return true;
    }
    return false;
}