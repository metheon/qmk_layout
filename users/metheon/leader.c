#include "leader.h"
#include "version.h"

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#include "secrets.h"
#else
// If the secret.h file is ever lost, simply create it again with this array being the only content
static const char * const secrets[] = {
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
  "no secrets to be found",
};
#endif

LEADER_EXTERNS();

void matrix_scan_leader(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // ////////////////////// //
        // Keyboard Related Stuff //
        // ////////////////////// //
        SEQ_TWO_KEYS(KC_Q, KC_M) {
            SEND_STRING("qmk compile -c -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER));
        }
        SEQ_TWO_KEYS(KC_Q, KC_F) {
            SEND_STRING("qmk flash -c -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER));
        }
        SEQ_TWO_KEYS(KC_Q, KC_V) {
            SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }

        // ////////////////////// //
        // Secrets (no passwords) //
        // ////////////////////// //

        SEQ_ONE_KEY(KC_N) {
            // send my name
            send_string(secrets[0]);
        }
        SEQ_TWO_KEYS(KC_S, KC_E) {
            // encrypt the secrets file
            send_string(secrets[1]);
        }
        SEQ_TWO_KEYS(KC_S, KC_R) {
            // rm the secrets file
            send_string(secrets[2]);
        }
        SEQ_TWO_KEYS(KC_S, KC_D) {
            // decrypt the secrets file
            send_string(secrets[3]);
        }
        SEQ_TWO_KEYS(KC_P, KC_E) {
            // send my private email
            send_string(secrets[4]);
        }
        SEQ_TWO_KEYS(KC_W, KC_E) {
            // send my work email
            send_string(secrets[5]);
        }
    }
}

