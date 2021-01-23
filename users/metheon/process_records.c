#include "metheon.h"
#include "version.h"

// OS dependant key codes
// Mac uses standard US ANSI keyboard
#define MAC_AE               RALT(KC_QUOT)
#define MAC_OE               RALT(KC_O)
#define MAC_AA               RALT(KC_A)
#define MAC_EUR              LSFT(RALT(KC_2))
#define MAC_PND              RALT(KC_3)

#define MAC_UNDO             LGUI(KC_Z)
#define MAC_CUT              LGUI(KC_X)
#define MAC_COPY             LGUI(KC_C)
#define MAC_PSTE             LGUI(KC_V)

#define MAC_NEXT_WRD         LALT(KC_RIGHT)
#define MAC_PREV_WRD         LALT(KC_LEFT)

#define MAC_NEXT_WIN         LGUI(KC_TAB)
#define MAC_PREV_WIN         LGUI(KC_STAB)

// Windows uses EurKey
#define WIN_AE               RALT(KC_Q)
#define WIN_OE               RALT(KC_L)
#define WIN_AA               RALT(KC_W)
#define WIN_EUR              RALT(KC_5)
#define WIN_PND              RALT(KC_4)

#define WIN_UNDO             LCTL(KC_Z)
#define WIN_CUT              LCTL(KC_X)
#define WIN_COPY             LCTL(KC_C)
#define WIN_PSTE             LCTL(KC_V)

#define WIN_NEXT_WRD         LCTL(KC_RIGHT)
#define WIN_PREV_WRD         LCTL(KC_LEFT)
#define WIN_NEXT_WIN         LALT(KC_TAB)
#define WIN_PREV_WIN         LALT(KC_STAB)

bool is_mac(void) {
    return keymap_config.swap_lctl_lgui;
}

bool is_windows(void) {
    return !is_mac();
}

// call this function for plain tapping a keycode which differs on on the OS'es
bool tab_os_key(uint16_t win_keycode, uint16_t mac_keycode, keyrecord_t *record) {
    if (is_mac()) {
        if (record->event.pressed) {
            register_code16(mac_keycode);
        } else {
            unregister_code16(mac_keycode);
        }
        return true;
    } else if (is_windows()) {
        if (record->event.pressed) {
            register_code16(win_keycode);
        } else {
            unregister_code16(win_keycode);
        }
        return true;
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
        case WHICH_OS:
            if (record->event.pressed) {
                if(is_windows()) {
                    SEND_STRING("WIN");
                    return true;
                } else if(is_mac()) {
                    SEND_STRING("MAC");
                    return true;
                }
            }
            break;
        case KC_AE:
            return tab_os_key(WIN_AE, MAC_AE, record);
        case KC_OE:
            return tab_os_key(WIN_OE, MAC_OE, record);
        case KC_AA:
            return tab_os_key(WIN_AA, MAC_AA, record);
        case KC_EUR:
            return tab_os_key(WIN_EUR, MAC_EUR, record);
        case KC_PND:
            return tab_os_key(WIN_PND, MAC_PND, record);
        case UNDO:
            return tab_os_key(WIN_UNDO, MAC_UNDO, record);
        case CUT:
            return tab_os_key(WIN_CUT, MAC_CUT, record);
        case COPY:
            return tab_os_key(WIN_COPY, MAC_COPY, record);
        case PASTE:
            return tab_os_key(WIN_PSTE, MAC_PSTE, record);
        case NEXT_WRD:
            return tab_os_key(WIN_NEXT_WRD, MAC_NEXT_WRD, record);
        case PREV_WRD:
            return tab_os_key(WIN_PREV_WRD, MAC_PREV_WRD, record);
        case NEXT_WIN:
            return tab_os_key(WIN_NEXT_WIN, MAC_NEXT_WIN, record);
        case PREV_WIN:
            return tab_os_key(WIN_PREV_WIN, MAC_PREV_WIN, record);
        return false;
    }
    return true;
};
