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
};
#endif

LEADER_EXTERNS();

void matrix_scan_leader(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        // /////////////////////// //
        // Application Invocations //
        // /////////////////////// //
        SEQ_ONE_KEY(KC_P) { // Invoke Password Manager
            SEND_STRING(SS_LCTL( SS_LALT( SS_LSFT("p") ) ) );
        }

        // ////////////////////// //
        // Keyboard Related Stuff //
        // ////////////////////// //
        SEQ_TWO_KEYS(KC_Q, KC_M) {
            SEND_STRING("make clean && make -j 8 " QMK_KEYBOARD ":" QMK_KEYMAP SS_TAP(X_ENTER));
        }
        SEQ_TWO_KEYS(KC_Q, KC_F) {
            SEND_STRING("make clean && make -j 8 " QMK_KEYBOARD ":" QMK_KEYMAP ":flash" SS_TAP(X_ENTER));
        }
        SEQ_TWO_KEYS(KC_Q, KC_V) {
            SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }

        // /////// //
        // Secrets //
        // /////// //

        // 0 not in use
        SEQ_ONE_KEY(KC_P) {
            send_string(secrets[1]);
        }
        SEQ_THREE_KEYS(KC_P, KC_N, KC_I) {
            send_string(secrets[2]);
        }
        SEQ_ONE_KEY(KC_N) {
            send_string(secrets[3]);
        }
        SEQ_TWO_KEYS(KC_P, KC_N) {
            send_string(secrets[4]);
        }
        // 5 not in use
        // 6 not in use
        SEQ_TWO_KEYS(KC_S, KC_E) {
            send_string(secrets[7]);
        }
        SEQ_TWO_KEYS(KC_S, KC_R) {
            send_string(secrets[8]);
        }
        SEQ_TWO_KEYS(KC_S, KC_D) {
            send_string(secrets[9]);
        }
        // 10 not in use
        SEQ_TWO_KEYS(KC_P, KC_G) {
            send_string(secrets[11]);
        }
        SEQ_TWO_KEYS(KC_P, KC_D) {
            send_string(secrets[12]);
        }
        SEQ_TWO_KEYS(KC_P, KC_L) {
            send_string(secrets[13]);
        }
        SEQ_TWO_KEYS(KC_P, KC_E) {
            send_string(secrets[14]);
        }
        SEQ_TWO_KEYS(KC_W, KC_E) {
            send_string(secrets[15]);
        }
        SEQ_TWO_KEYS(KC_W, KC_L) {
            send_string(secrets[16]);
        }
        SEQ_TWO_KEYS(KC_W, KC_G) {
            send_string(secrets[17]);
        }
        SEQ_THREE_KEYS(KC_W, KC_S, KC_P) {
            send_string(secrets[18]);
        }
        SEQ_THREE_KEYS(KC_W, KC_S, KC_T) {
            send_string(secrets[19]);
        }
    }
}

