#include "leader.h"
#include "version.h"

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#include "secrets.h"
#else
// If the secret.h file is ever lost, simply create it again with this array being the only content
static const char * const secrets[] = {
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

        // [F]lash [S]weep
        SEQ_TWO_KEYS(KC_F, KC_S) {
            // send make command to flash the Sweep
            send_string("make ferris/sweep:metheon:dfu-split-left");
        }
        // [F]lash [S]weep [R]ight
        SEQ_THREE_KEYS(KC_F, KC_S, KC_R) {
            // send make command to flash the Sweep, right side
            send_string("make ferris/sweep:metheon:dfu-split-right");
        }
        // [F]lash [K]yria
        SEQ_TWO_KEYS(KC_F, KC_K) {
            // send make command to flash the Kyria
            send_string("make splitkb/kyria:metheon");
        }
        // [F]lash [P]lanck
        SEQ_TWO_KEYS(KC_F, KC_P) {
            // send make command to flash the Planck
            send_string("make planck/ez:metheon");
        }

        // ////////////////////// //
        // Secrets (no passwords) //
        // ////////////////////// //

        // [N]ame
        SEQ_ONE_KEY(KC_N) {
            // send my name
            send_string(secrets[0]);
        }
        // [E]mail
        SEQ_ONE_KEY(KC_E) {
            // send my email
            send_string(secrets[1]);
        }
    }
}

