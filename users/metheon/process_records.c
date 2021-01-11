#include "metheon.h"
#include "version.h"

bool is_mac(void) {
    return keymap_config.swap_lctl_lgui;
}

bool is_windows(void) {
    return !is_mac();
}

#define WIN_CUT     LCTL(KC_X)
#define MAC_CUT     LGUI(KC_X)

// call this function for plain tapping a keycode which differs on on the OS'es
bool tap_for_mac_and_tap_for_win(uint16_t win_keycode, uint16_t mac_keycode, keyrecord_t *record) {
    if (is_mac()) {
        if (record->event.pressed) {
            register_code16(mac_keycode);
        } else {
            unregister_code16(mac_keycode);
        }
    } else if (is_windows()) {
        if (record->event.pressed) {
            register_code16(win_keycode);
        } else {
            unregister_code16(win_keycode);
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HIBRNT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LGUI(SS_TAP(X_X)) SS_TAP(X_U) SS_TAP(X_D), 200);
            }
            break;
        case SLEEP:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LGUI(SS_TAP(X_X)) SS_TAP(X_U) SS_TAP(X_U), 200);
            }
            break;
        case KC_MAKE:
            if (!record->event.pressed) {
                SEND_STRING("make -j 4 " QMK_KEYBOARD ":" QMK_KEYMAP SS_TAP(X_ENTER));
            }
            break;
        case KC_FLASH:
            if (!record->event.pressed) {
                SEND_STRING("make -j 4 " QMK_KEYBOARD ":" QMK_KEYMAP ":flash" SS_TAP(X_ENTER));
            }
            break;
        case KC_VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            break;
        case CUT:
            return tap_for_mac_and_tap_for_win(WIN_CUT, MAC_CUT, record);
        case WIN_MAC:
            return tap_for_mac_and_tap_for_win(KC_W, KC_M, record);
        return false;
    }
    return true;
};
