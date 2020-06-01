#include "quantum.h"

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

LEADER_EXTERNS();

void matrix_scan_leader(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_P) { // Invoke Password Manager
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_P);
            unregister_code(KC_P);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
        }
        SEQ_TWO_KEYS(KC_D, KC_C) { // Discord Inline Code
            SEND_STRING("`` " SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        SEQ_TWO_KEYS(KC_D, KC_B) { // Discord code block
            SEND_STRING("```c" SS_LSFT("\n\n") "``` " SS_TAP(X_UP));
        }
        SEQ_TWO_KEYS(KC_M, KC_N) {
            send_string(secrets[0]);
        }
        SEQ_TWO_KEYS(KC_H, KC_E) {
            send_string(secrets[1]);
        }
        SEQ_TWO_KEYS(KC_H, KC_P) {
            send_string(secrets[2]);
        }
        SEQ_TWO_KEYS(KC_W, KC_E) {
            send_string(secrets[3]);
        }
        SEQ_TWO_KEYS(KC_W, KC_P) {
            send_string(secrets[4]);
        }
    }
}
