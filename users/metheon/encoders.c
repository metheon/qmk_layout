#include "encoders.h"

// For the alt tab macro (rotary encoder)
bool     is_alt_tab_active = false;
uint16_t alt_tab_timer     = 0;

void matrix_scan_encoders(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 750) {
            unregister_code(KC_LALT);
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
        tap_code16(KC_WH_D);
    } else {
        tap_code16(KC_WH_U);
    }
}

void zoom(bool clockwise) {
    if (clockwise) {
        tap_code16(C(KC_MINS));
    } else {
        tap_code16(C(KC_PLUS));
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

void ctrl_tab(bool clockwise) {
    if (clockwise) {
        tap_code16(C(KC_TAB));
    } else {
        tap_code16(S(C(KC_TAB)));
    }
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {  // Left encoder
        switch (biton32(layer_state)) {
            case _BASE:
                gui_tab(clockwise);
                break;
            case _SYMBOLS:
                ctrl_tab(clockwise);
                break;
            case _EXTEND:
                media_control(clockwise);
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
            case _NUMPAD:
                scrolling(clockwise);
                break;
            case _EXTEND:
                volume_control(clockwise);
                break;
            default:
                // Do nothing
                break;
        }
    }
}
