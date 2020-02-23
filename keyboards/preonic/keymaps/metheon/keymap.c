#include QMK_KEYBOARD_H
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

// -- Windows --
#define WIN_UNDO    LCTL(KC_Z)
#define WIN_REDO    LSFT(LCTL(KC_Z))
#define WIN_CUT     LCTL(KC_X)
#define WIN_COPY    LCTL(KC_C)
#define WIN_PSTE    LCTL(KC_V)
// EurKey key combinations used on Windows, right alt will be applied later
#define WIN_EE      KC_G
#define WIN_AA      KC_W
#define WIN_AE      KC_Q
#define WIN_OE      KC_L
#define WIN_PND     KC_4
#define WIN_EUR     KC_5

// -- MacOS --
#define MAC_UNDO    LGUI(KC_Z)
#define MAC_REDO    LSFT(LGUI(KC_Z))
#define MAC_CUT     LGUI(KC_X)
#define MAC_COPY    LGUI(KC_C)
#define MAC_PSTE    LGUI(KC_V)
// Mac key combinations to mirror EurKey
// #define MAC_EE --> see DK_EE (this is special on mac)
#define MAC_AA      LALT(KC_A)
#define MAC_AE      LALT(KC_QUOTE)
#define MAC_OE      LALT(KC_O)
#define MAC_PND     LALT(KC_3)
#define MAC_EUR     LSFT(LALT(KC_2))

#define MAC_PGUP    LGUI(KC_UP)
#define MAC_PGDN    LGUI(KC_DOWN)
#define MAC_HOME    LGUI(KC_LEFT)
#define MAC_END     LGUI(KC_RIGHT)

enum preonic_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOVE,
    _NUMPAD,
};

enum preonic_keycodes {
    EPRM = SAFE_RANGE,
    TG_OS,                      // Toggle between windows and mac
    ALT_GUI,                    // Alt on windows, Gui on mac
    GUI_ALT,                    // Gui on windows, Alt on mac
    REDO,
    UNDO,
    CUT,
    COPY,
    PASTE,
    DK_EE,
    DK_AE,
    DK_OE,
    DK_AA,
    MY_PND,
    MY_EUR,
    MY_PGUP,
    MY_PGDN,
    MY_HOME,
    MY_END,
};

// Layers
#define LOWER       MO(_LOWER)
#define RAISE       MO(_RAISE)
#define BASE        TO(_BASE)
#define NUMPAD      TO(_NUMPAD)
#define SPACE_FN    LT(_MOVE, KC_SPACE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_preonic_grid(
        KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_DEL  ,
        KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_BSPC ,
        KC_ESC  ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_D    ,KC_H    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_QUOT ,
        KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_K    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT ,
        KC_MEH  ,KC_LCTL ,GUI_ALT ,ALT_GUI ,LOWER   ,SPACE_FN,KC_NO   ,RAISE   ,ALT_GUI ,GUI_ALT ,KC_LCTL ,KC_MEH
        ),

    [_LOWER] = LAYOUT_preonic_grid(
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        KC_TILD ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_DEL  ,
        _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,KC_UNDS ,KC_PLUS ,KC_LCBR ,KC_RCBR ,KC_PIPE ,
        _______ ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,_______ ,_______ ,LOWER   ,KC_ENT  ,KC_NO   ,RAISE   ,_______ ,_______ ,_______ ,_______
        ),

    [_RAISE] = LAYOUT_preonic_grid(
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_DEL  ,
        KC_CAPS ,DK_EE   ,DK_AE   ,DK_OE   ,DK_AA   ,MY_PND  ,MY_EUR  ,KC_MINS ,KC_EQL  ,KC_LBRC ,KC_RBRC ,KC_BSLS ,
        _______ ,UNDO    ,CUT     ,COPY    ,PASTE   ,REDO    ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,_______ ,_______ ,LOWER   ,KC_ENT  ,KC_NO   ,RAISE   ,_______ ,_______ ,_______ ,_______
        ),

    [_ADJUST] = LAYOUT_preonic_grid(
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,KC_MPRV ,KC_MPLY ,KC_MNXT ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,KC_MUTE ,KC_VOLD ,KC_VOLU ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        NUMPAD  ,_______ ,_______ ,_______ ,LOWER   ,RESET   ,KC_NO   ,RAISE   ,_______ ,_______ ,_______ ,TG_OS
        ),

    [_MOVE] = LAYOUT_preonic_grid(
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,KC_WH_L ,KC_MS_U ,KC_WH_R ,KC_WH_U ,MY_PGUP ,MY_HOME ,KC_UP   ,MY_END  ,_______ ,_______ ,
        _______ ,_______ ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,MY_PGDN ,KC_LEFT ,KC_DOWN ,KC_RGHT ,_______ ,_______ ,
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_BTN1 ,KC_BTN2 ,_______ ,_______ ,_______ ,
        _______ ,_______ ,_______ ,_______ ,_______ ,SPACE_FN,KC_NO   ,_______ ,_______ ,_______ ,_______ ,_______
        ),

    [_NUMPAD] = LAYOUT_preonic_grid(
        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
        _______ ,_______ ,_______ ,KC_LPRN ,KC_RPRN ,_______ ,_______ ,KC_7    ,KC_8    ,KC_9    ,_______ ,_______ ,
        _______ ,_______ ,KC_HASH ,KC_MINS ,KC_PLUS ,_______ ,_______ ,KC_4    ,KC_5    ,KC_6    ,_______ ,_______ ,
        _______ ,_______ ,_______ ,KC_SLSH ,KC_ASTR ,_______ ,_______ ,KC_1    ,KC_2    ,KC_3    ,_______ ,_______ ,
        BASE    ,_______ ,_______ ,KC_EQUAL,KC_ENT  ,KC_SPACE,KC_NO   ,KC_0    ,KC_COMM ,KC_DOT  ,_______ ,_______
        ),
};

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
