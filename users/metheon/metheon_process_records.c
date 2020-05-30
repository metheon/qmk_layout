#include "quantum.h"
#include "metheon.h"
#include "metheon_process_records.h"
#include "version.h"

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
                SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP SS_TAP(X_ENTER));
            }
            break;
        case KC_FLASH:
            if (!record->event.pressed) {
                SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP ":flash" SS_TAP(X_ENTER));
                reset_keyboard();
            }
            break;
        case KC_VRSN:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            }
            break;
    }
    return true;
};
