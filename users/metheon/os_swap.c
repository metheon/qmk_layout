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

#define WIN_CUT     LCTL(KC_X)
#define MAC_CUT     LGUI(KC_X)

enum preonic_keycodes {
    EPRM = SAFE_RANGE,
    TG_OS,                      // Toggle between windows and mac
    CUT,
    ...
};

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
        case CUT:
            return tap_for_mac_and_tap_for_win(WIN_CUT, MAC_CUT, record);
    }
    return true;
}
