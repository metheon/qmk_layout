#include "encoders.h"

// For the alt tab macro (rotary encoder)
bool     is_alt_tab_active = false;
uint16_t alt_tab_timer     = 0;

void matrix_scan_encoders(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 2000) {
            unregister_code(KC_LGUI);
            is_alt_tab_active = false;
        }
    }
}

void volume_control(bool clockwise) {
    if (clockwise) {
        tap_code16(KC_VOLU);
    } else {
        tap_code16(KC_VOLD);
    }
}

void media_control(bool clockwise) {
    if (clockwise) {
        tap_code16(KC_MNXT);
    } else {
        tap_code16(KC_MPRV);
    }
}

void scrolling(bool clockwise) {
    if (clockwise) {
        tap_code16(KC_PGDN);
    } else {
        tap_code16(KC_PGUP);
    }
}

void zoom(bool clockwise) {
    if (clockwise) {
        tap_code16(G(KC_MINS));
    } else {
        tap_code16(G(KC_PLUS));
    }
}

void gui_tab(bool clockwise) {
    if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LGUI);
    }
    alt_tab_timer = timer_read();
    if (clockwise) {
        tap_code16(KC_TAB);
    } else {
        tap_code16(S(KC_TAB));
    }
}

void tabbing(bool clockwise) {
    if (clockwise) {
        tap_code16(KC_TAB);
    } else {
        tap_code16(S(KC_TAB));
    }
}

void ctrl_tab(bool clockwise) {
    if (clockwise) {
        tap_code16(C(KC_TAB));
    } else {
        tap_code16(S(C(KC_TAB)));
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {  // Left encoder
        switch (biton32(layer_state)) {
            case _BASE:
                gui_tab(clockwise);
                break;
            case _NAV:
                ctrl_tab(clockwise);
                break;
            default:
                // Do nothing
                break;
        }
    } else if (index == 1) {  // Right encoder
        switch (biton32(layer_state)) {
            case _BASE:
                volume_control(clockwise);
                break;
            case _NUM:
                scrolling(clockwise);
                break;
            default:
                // Do nothing
                break;
        }
    }
    return true;
}
