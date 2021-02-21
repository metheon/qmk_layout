#include "process_records.h"
#include "version.h"
#include "which_os.h"
#include "window_tab.h"

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

#define MAC_LOCK             LCTL(LGUI(KC_Q))
#define MAC_IJ_RNAME         LSFT(KC_F6)
#define MAC_IJ_TERM          LALT(KC_F12)
#define MAC_SEARCH           LGUI(KC_SPACE)
#define MAC_NXT_DSKT         LCTL(KC_RIGHT)
#define MAC_PRV_DSKT         LCTL(KC_LEFT)
#define MAC_OVERVIEW         KC_NO // unknown, check later

#define MAC_DEL_WRD         LALT(KC_BSPC)

// Linux uses EurKey
#define LNX_AE               RALT(KC_Q)
#define LNX_OE               RALT(KC_L)
#define LNX_AA               RALT(KC_W)
#define LNX_EUR              RALT(KC_5)
#define LNX_PND              RALT(KC_4)

#define LNX_UNDO             LCTL(KC_Z)
#define LNX_CUT              LCTL(KC_X)
#define LNX_COPY             LCTL(KC_C)
#define LNX_PSTE             LCTL(KC_V)

#define LNX_NEXT_WRD         LCTL(KC_RIGHT)
#define LNX_PREV_WRD         LCTL(KC_LEFT)

#define LNX_LOCK             LGUI(KC_ESC)
#define LNX_IJ_RNAME         LSFT(KC_F6)
#define LNX_IJ_TERM          LALT(KC_F12)
#define LNX_SEARCH           LGUI(KC_SLSH)
#define LNX_NXT_DSKT         LGUI(LCTL(KC_DOWN))
#define LNX_PRV_DSKT         LGUI(LCTL(KC_UP))
#define LNX_OVERVIEW         KC_LGUI

#define LNX_DEL_WRD         LCTL(KC_BSPC)

// call this function for plain tapping a keycode which differs on the OS'es
bool tap_os_key(uint16_t lnx_keycode, uint16_t mac_keycode, bool key_down) {
    if (is_mac()) {
        if (key_down) {
            register_code16(mac_keycode);
        } else {
            unregister_code16(mac_keycode);
        }
        return true;
    } else if (is_linux()) {
        if (key_down) {
            register_code16(lnx_keycode);
        } else {
            unregister_code16(lnx_keycode);
        }
        return true;
    }
    return false;
}

bool tap_kc_ae(bool key_down) {
    return tap_os_key(LNX_AE, MAC_AE, key_down);
}

bool tap_kc_oe(bool key_down) {
    return tap_os_key(LNX_OE, MAC_OE, key_down);
}

bool tap_kc_aa(bool key_down) {
    return tap_os_key(LNX_AA, MAC_AA, key_down);
}

bool make(keyrecord_t *record) {
    if (!record->event.pressed) {
        SEND_STRING("make clean && make -j 8 " QMK_KEYBOARD ":" QMK_KEYMAP SS_TAP(X_ENTER));
        return false;
    }
    return true;
}

bool flash(keyrecord_t *record) {
    if (!record->event.pressed) {
        SEND_STRING("make clean && make -j 8 " QMK_KEYBOARD ":" QMK_KEYMAP ":flash" SS_TAP(X_ENTER));
        return false;
    }
    return true;
}

bool version(keyrecord_t *record) {
    if (!record->event.pressed) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
    }
    return true;
}

bool which_os(keyrecord_t *record) {
    if (record->event.pressed) {
        if(is_linux()) {
            SEND_STRING("LINUX");
            return true;
        } else if(is_mac()) {
            SEND_STRING("MAC");
            return true;
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MAKE:
            return make(record);
        case KC_FLASH:
            return flash(record);
        case KC_VRSN:
             return version(record);
        case WHICH_OS:
            return which_os(record);
        case TEXT_MOD:
            return tap_os_key(KC_LCTL, KC_LALT, record->event.pressed);
        case KC_AE:
            return tap_kc_ae(record->event.pressed);
        case KC_OE:
            return tap_kc_oe(record->event.pressed);
        case KC_AA:
            return tap_kc_aa(record->event.pressed);
        case KC_EUR:
            return tap_os_key(LNX_EUR, MAC_EUR, record->event.pressed);
        case KC_PND:
            return tap_os_key(LNX_PND, MAC_PND, record->event.pressed);
        case UNDO:
            return tap_os_key(LNX_UNDO, MAC_UNDO, record->event.pressed);
        case CUT:
            return tap_os_key(LNX_CUT, MAC_CUT, record->event.pressed);
        case COPY:
            return tap_os_key(LNX_COPY, MAC_COPY, record->event.pressed);
        case PASTE:
            return tap_os_key(LNX_PSTE, MAC_PSTE, record->event.pressed);
        case NEXT_WRD:
            return tap_os_key(LNX_NEXT_WRD, MAC_NEXT_WRD, record->event.pressed);
        case PREV_WRD:
            return tap_os_key(LNX_PREV_WRD, MAC_PREV_WRD, record->event.pressed);
        case NEXT_WIN:
            return mod_tab(record, false);
        case PREV_WIN:
            return mod_tab(record, S(true));
        case LOCK:
            return tap_os_key(LNX_LOCK, MAC_LOCK, record->event.pressed);
        case SEARCH:
            return tap_os_key(LNX_SEARCH, MAC_SEARCH, record->event.pressed);
         case IJ_RNAME:
            return tap_os_key(LNX_IJ_RNAME, MAC_IJ_RNAME, record->event.pressed);
        case IJ_TERM:
            return tap_os_key(LNX_IJ_TERM, MAC_IJ_TERM, record->event.pressed);
        case PRV_DSKT:
            return tap_os_key(LNX_PRV_DSKT, MAC_PRV_DSKT, record->event.pressed);
        case NXT_DSKT:
            return tap_os_key(LNX_NXT_DSKT, MAC_NXT_DSKT, record->event.pressed);
        case OVERVIEW:
            return tap_os_key(LNX_OVERVIEW, MAC_OVERVIEW, record->event.pressed);
        case DEL_WRD:
            return tap_os_key(LNX_DEL_WRD, MAC_DEL_WRD, record->event.pressed);
    }
    return true;
};
