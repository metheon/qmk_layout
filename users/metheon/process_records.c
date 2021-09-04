#include "quantum.h"
#include "metheon.h"
#include "process_records.h"
#include "version.h"

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#include "secrets.h"
#else
// `PROGMEM const char secret[][x]` may work better, but it takes up more space in the firmware
// And I'm not familiar enough to know which is better or why...
// If the secret.h file is ever lost, simply create it again with this array being the only content
static const char * const secrets[] = {
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found"
};
#endif

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
        case KC_SEC_1 ... KC_SEC_5: // Secrets!  Externally defined strings, not stored in repo
            if (!record->event.pressed) {
                send_string(secrets[keycode - KC_SEC_1]);
            }
            break;
        return false;
    }
    return true;
};
