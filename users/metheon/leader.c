#include "leader.h"

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

        // ////// //
        // MAGNET //
        // ////// //
        SEQ_TWO_KEYS(KC_M, KC_W) {
            tap_code16(MAGNET_UPPER_LEFT_QUADRANT);
        }
        SEQ_TWO_KEYS(KC_M, KC_F) {
            tap_code16(MAGNET_UPPER_HALF);
        }
        SEQ_TWO_KEYS(KC_M, KC_P) {
            tap_code16(MAGNET_UPPER_RIGHT_QUADRANT);
        }
        SEQ_TWO_KEYS(KC_M, KC_R) {
            tap_code16(MAGNET_LEFT_HALF);
        }
        SEQ_TWO_KEYS(KC_M, KC_S) {
            tap_code16(MAGNET_FULLSCREEN);
        }
        SEQ_TWO_KEYS(KC_M, KC_T) {
            tap_code16(MAGNET_RIGHT_HALF);
        }
        SEQ_TWO_KEYS(KC_M, KC_X) {
            tap_code16(MAGNET_BOTTOM_LEFT_QUADRANT);
        }
        SEQ_TWO_KEYS(KC_M, KC_C) {
            tap_code16(MAGNET_BOTTOM_HALF);
        }
        SEQ_TWO_KEYS(KC_M, KC_D) {
            tap_code16(MAGNET_BOTTOM_RIGHT_QUADRANT);
        }
        SEQ_TWO_KEYS(KC_M, KC_N) {
            tap_code16(MAGNET_LEFT_THIRD);
        }
        SEQ_TWO_KEYS(KC_M, KC_E) {
            tap_code16(MAGNET_MIDDLE_THIRD);
        }
        SEQ_TWO_KEYS(KC_M, KC_I) {
            tap_code16(MAGNET_RIGHT_THIRD);
        }
        SEQ_TWO_KEYS(KC_M, KC_L) {
            tap_code16(MAGNET_LEFT_TWO_THIRDS);
        }
        SEQ_TWO_KEYS(KC_M, KC_U) {
            tap_code16(MAGNET_RIGHT_TWO_THIRDS);
        }

        // /////// //
        // Secrets //
        // /////// //
        SEQ_ONE_KEY(KC_P) {
            send_string(secrets[0]);
        }
        // 1 not in use
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

