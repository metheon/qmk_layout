#include "metheon.h"
#include "eeprom.h"

// eeprom config
typedef union {
    uint32_t raw;
    struct {
        // win is false, mac is true
        bool os_win_mac : 1;
    };
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) {
    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();
}

// called when EEPROM is getting reset!
void eeconfig_init_user(void) {
    user_config.raw        = 0;
    // default to mac
    user_config.os_win_mac = true;
    // Write default value to EEPROM now
    eeconfig_update_user(user_config.raw);
}

void toggle_os(keyrecord_t *record) {
    // Toggle within event.pressed to ensure this is called only once
    if (record->event.pressed) {
        user_config.os_win_mac = !user_config.os_win_mac;
        eeconfig_update_user(user_config.raw);
    }
}

bool tap_mac_ee(keyrecord_t *record) {
    if (record ->event.pressed) {
            // Get the current shift modifier
            uint8_t temp = keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
            // Turn the modifier off
            unregister_mods(temp);

            register_mods(MOD_BIT(KC_LALT));
            // first e to get the accent
            tap_code16(KC_E);

            unregister_mods(MOD_BIT(KC_LALT));

            // Turn the shift modifier back on
            register_mods(temp);

            // second e to get the e, shift should be reapplied
            tap_code16(KC_E);
    }
    return false;
}

bool tap_eurkey(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        register_code16(KC_RALT);
        register_code16(keycode);
    } else {
        unregister_code16(keycode);
        unregister_code16(KC_RALT);
    }
    return false;
}

bool tap_dk_ee(keyrecord_t *record) {
    if (user_config.os_win_mac) {  // true == mac
        return tap_mac_ee(record);
    } else {  // false == win
        return tap_eurkey(WIN_EE, record);
    }
}

// for mac it taps the keycode, for win it applies RALT (for EurKey)
bool tap_for_mac_and_eurkey_for_win(uint16_t win_keycode, uint16_t mac_keycode, keyrecord_t *record) {
    if (user_config.os_win_mac) { // true == mac
        if (record->event.pressed) {
            register_code16(mac_keycode);
        } else {
            unregister_code16(mac_keycode);
        }
    } else { // false == win
        tap_eurkey(win_keycode, record);
    }
    return false;
}

// call this function for plain tapping a keycode which differs on on the OS'es
bool tap_for_mac_and_tap_for_win(uint16_t win_keycode, uint16_t mac_keycode, keyrecord_t *record) {
    if (user_config.os_win_mac) { // true == mac
        if (record->event.pressed) {
            register_code16(mac_keycode);
        } else {
            unregister_code16(mac_keycode);
        }
    } else { // false == win
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
        // toggle os (win or mac)
        case TG_OS:
            toggle_os(record);
            return false;
        // all cases with just standard os specific keycodes with normal tapping
        case REDO:
            return tap_for_mac_and_tap_for_win(WIN_REDO, MAC_REDO, record);
        case UNDO:
            return tap_for_mac_and_tap_for_win(WIN_UNDO, MAC_UNDO, record);
        case CUT:
            return tap_for_mac_and_tap_for_win(WIN_CUT, MAC_CUT, record);
        case COPY:
            return tap_for_mac_and_tap_for_win(WIN_COPY, MAC_COPY, record);
        case PASTE:
            return tap_for_mac_and_tap_for_win(WIN_PSTE, MAC_PSTE, record);
        // navigation but otherwise standard tapping
        case MY_PGUP:
            return tap_for_mac_and_tap_for_win(KC_PGUP, MAC_PGUP, record);
        case MY_PGDN:
            return tap_for_mac_and_tap_for_win(KC_PGDN, MAC_PGDN, record);
        case MY_HOME:
            return tap_for_mac_and_tap_for_win(KC_HOME, MAC_HOME, record);
        case MY_END:
            return tap_for_mac_and_tap_for_win(KC_END, MAC_END, record);
        // alt on windows, gui on mac, otherwise standard tapping
        case ALT_GUI:
            return tap_for_mac_and_tap_for_win(KC_LALT, KC_LGUI, record);
        // gui on windows, alt on mac, otherwise standard tapping
        case GUI_ALT:
            return tap_for_mac_and_tap_for_win(KC_LGUI, KC_LALT, record);
        // the danish character ee (é, É) which is special on mac (two key combo) and eurkey on windows
        case DK_EE:
            return tap_dk_ee(record);
        // other danish characters which requires eurkey on windows
        case DK_AE:
            return tap_for_mac_and_eurkey_for_win(WIN_AE, MAC_AE, record);
        case DK_OE:
            return tap_for_mac_and_eurkey_for_win(WIN_OE, MAC_OE, record);
        case DK_AA:
            return tap_for_mac_and_eurkey_for_win(WIN_AA, MAC_AA, record);
        // pound (£) which requires eurkey on windows
        case MY_PND:
            return tap_for_mac_and_eurkey_for_win(WIN_PND, MAC_PND, record);
        // euro (€) which requires eurkey on windows
        case MY_EUR:
            return tap_for_mac_and_eurkey_for_win(WIN_EUR, MAC_EUR, record);
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
