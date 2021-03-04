#include QMK_KEYBOARD_H
#include <stdbool.h>

// This particular implementation is by @dnaq at splitkb.com discord.
// Idea originally from @iaap, also at splitkb.com discord.
// Modified by @sevanteri

static bool caps_word_enabled = false;
void caps_word_enable(void) {
    caps_word_enabled = true;
    if (!host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

void caps_word_disable(void) {
    caps_word_enabled = false;
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

void caps_word_toggle(void) {
    if (caps_word_enabled) {
        caps_word_disable();
    } else {
        caps_word_enable();
    }
}

static bool process_caps_word(uint16_t keycode, keyrecord_t *record) {
    /* Return value determines if processing the keycode should continue to core code.
     * This allows more customizability. */

    if (caps_word_enabled) {
        // first strip of the mod taps and layer taps if needed
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                if (record->tap.count == 0)
                    return true;
                keycode = keycode & 0xFF;
        }
        // we end caps word on one of the following keypresses
        switch (keycode) {
            case KC_ESC:
            case KC_ENT:
            case KC_TAB:
            case KC_DOT:
            case KC_COMM:
                if (record->event.pressed) {
                    caps_word_disable();
                }
                return true;
            case KC_SPC:
                // _ on space
                if (record->event.pressed) {
                    register_code16(KC_UNDS);
                } else {
                    unregister_code16(KC_UNDS);
                }
                return false;
        }
    }

    return true;
}

