#include "process_records.h"
#include "which_os.h"
#include "window_tab.h"
#include "metheon.h"

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

#define MAC_DEL_WRD          LALT(KC_BSPC)

#define MAC_KC_AC_A          KC_NO
#define MAC_KC_AC_E          KC_NO
#define MAC_KC_AC_I          KC_NO
#define MAC_KC_AC_O          KC_NO
#define MAC_KC_AC_U          KC_NO
#define MAC_KC_DI_U          KC_NO
#define MAC_KC_TI_N          KC_NO
#define MAC_INV_EXCL         KC_NO
#define MAC_INV_QUES         KC_NO

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

#define LNX_DEL_WRD          LCTL(KC_BSPC)

#define LNX_KC_AC_A          RALT(KC_X)
#define LNX_KC_AC_E          RALT(KC_G)
#define LNX_KC_AC_I          RALT(KC_B)
#define LNX_KC_AC_O          RALT(KC_DOT)
#define LNX_KC_AC_U          RALT(KC_J)
#define LNX_KC_DI_U          RALT(KC_U)
#define LNX_KC_TI_N          RALT(KC_N)
#define LNX_INV_EXCL         RALT(KC_1)
#define LNX_INV_QUES         RALT(KC_SLSH)

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
        // all tap_os_key cases
        case TEXT_MOD:
            tap_os_key(KC_LCTL, KC_LALT, pressed); 
            break;
        case KC_AE:
            tap_os_key(LNX_AE ,MAC_AE, pressed);
            break;
        case KC_OE:
            tap_os_key(LNX_OE ,MAC_OE, pressed);
            break;
        case KC_AA:
            tap_os_key(LNX_AA ,MAC_AA, pressed);
            break;
        case KC_AC_A:
            tap_os_key(LNX_KC_AC_A,MAC_KC_AC_A, pressed);
            break;
        case KC_AC_E:
            tap_os_key(LNX_KC_AC_E,MAC_KC_AC_E, pressed);
            break;
        case KC_AC_I:
            tap_os_key(LNX_KC_AC_I,MAC_KC_AC_I, pressed);
            break;
        case KC_AC_O:
            tap_os_key(LNX_KC_AC_O,MAC_KC_AC_O, pressed);
            break;
        case KC_AC_U:
            tap_os_key(LNX_KC_AC_U,MAC_KC_AC_U, pressed);
            break;
        case KC_DI_U:
            tap_os_key(LNX_KC_DI_U,MAC_KC_DI_U, pressed);
            break;
        case KC_TI_N:
            tap_os_key(LNX_KC_TI_N,MAC_KC_TI_N, pressed);
            break;
        case INV_EXCL:
            tap_os_key(LNX_INV_EXCL,MAC_INV_EXCL, pressed);
            break;
        case INV_QUES:
            tap_os_key(LNX_INV_QUES,MAC_INV_QUES, pressed);
            break;
        case KC_EUR:
            tap_os_key(LNX_EUR, MAC_EUR, pressed);
            break;
        case KC_PND:
            tap_os_key(LNX_PND, MAC_PND, pressed);
            break;
        case UNDO:
            tap_os_key(LNX_UNDO, MAC_UNDO, pressed);
            break;
        case CUT:
            tap_os_key(LNX_CUT, MAC_CUT, pressed);
            break;
        case COPY:
            tap_os_key(LNX_COPY, MAC_COPY, pressed);
            break;
        case PASTE:
            tap_os_key(LNX_PSTE, MAC_PSTE, pressed);
            break;
        case NEXT_WRD:
            tap_os_key(LNX_NEXT_WRD, MAC_NEXT_WRD, pressed);
            break;
        case PREV_WRD:
            tap_os_key(LNX_PREV_WRD, MAC_PREV_WRD, pressed);
            break;
        case LOCK:
            tap_os_key(LNX_LOCK, MAC_LOCK, pressed);
            break;
        case SEARCH:
            tap_os_key(LNX_SEARCH, MAC_SEARCH, pressed);
            break;
         case IJ_RNAME:
            tap_os_key(LNX_IJ_RNAME, MAC_IJ_RNAME, pressed);
            break;
        case IJ_TERM:
            tap_os_key(LNX_IJ_TERM, MAC_IJ_TERM, pressed);
            break;
        case PRV_DSKT:
            tap_os_key(LNX_PRV_DSKT, MAC_PRV_DSKT, pressed);
            break;
        case NXT_DSKT:
            tap_os_key(LNX_NXT_DSKT, MAC_NXT_DSKT, pressed);
            break;
        case OVERVIEW:
            tap_os_key(LNX_OVERVIEW, MAC_OVERVIEW, pressed);
            break;
        case DEL_WRD:
            tap_os_key(LNX_DEL_WRD, MAC_DEL_WRD, pressed);
            break;
        // all mod_tab cases
        case NEXT_WIN:
            mod_tab(record, false);
            break;
        case PREV_WIN:
            mod_tab(record, S(true));
            break;
        default:
            return true;
    }
    return false;
};
