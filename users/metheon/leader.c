#include "quantum.h"

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
            register_code(KC_LCTL);
            register_code(KC_LALT);
            register_code(KC_LSFT);
            register_code(KC_P);
            unregister_code(KC_P);
            unregister_code(KC_LSFT);
            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
        }

        // //////// //
        // Markdown //
        // //////// //
        SEQ_THREE_KEYS(KC_M, KC_C, KC_I) { // Markdown Inline Code
            SEND_STRING("`` " SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        SEQ_THREE_KEYS(KC_M, KC_C, KC_B) { // Markdown code block
            SEND_STRING("```c" SS_LSFT("\n\n") "``` " SS_TAP(X_UP));
        }
        SEQ_TWO_KEYS(KC_M, KC_U) { // Markdown url
            SEND_STRING("[]()" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }
        SEQ_TWO_KEYS(KC_M, KC_B) { // Markdown bold
            SEND_STRING("**" SS_TAP(X_LEFT));
        }
        SEQ_TWO_KEYS(KC_M, KC_I) { // Markdown italic
            SEND_STRING("__" SS_TAP(X_LEFT));
        }
        SEQ_TWO_KEYS(KC_M, KC_S) { // Markdown strikethrough
            SEND_STRING("~~~~" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
        }

        // /// //
        // QMK //
        // /// //
        SEQ_TWO_KEYS(KC_Q, KC_D) { // QMK Docs
            SEND_STRING("https://docs.qmk.fm/#/");
        }
        SEQ_TWO_KEYS(KC_Q, KC_U) { // QMK User space
            SEND_STRING("https://github.com/metheon/qmk_firmware/tree/metheon/users/metheon");
        }
        SEQ_THREE_KEYS(KC_Q, KC_U, KC_R) { // QMK User space, readme
            SEND_STRING("https://github.com/metheon/qmk_firmware/blob/metheon/users/metheon/readme.md");
        }

        // /////////////// //
        // Keyboards I own //
        // /////////////// //
        SEQ_TWO_KEYS(KC_K, KC_K) {
            SEND_STRING("https://blog.splitkb.com/blog/introducing-the-kyria");
        }
        SEQ_TWO_KEYS(KC_K, KC_P) {
            SEND_STRING("https://ergodox-ez.com/pages/planck");
        }

        // ////// //
        // Emojis //
        // ////// //
        SEQ_TWO_KEYS(KC_E, KC_T) {
            SEND_STRING(":thinking:");
        }
        SEQ_TWO_KEYS(KC_E, KC_P) {
            SEND_STRING(":poop:");
        }
        SEQ_TWO_KEYS(KC_E, KC_M) {
            SEND_STRING(":money_with_wings:");
        }
        SEQ_THREE_KEYS(KC_E, KC_M, KC_S) {
            SEND_STRING(":man_shrugging:");
        }
        SEQ_THREE_KEYS(KC_E, KC_F, KC_P) {
            SEND_STRING(":man_facepalming:");
        }

        // /////// //
        // Secrets //
        // /////// //
        SEQ_TWO_KEYS(KC_P, KC_N) {
            send_string(secrets[0]);
        }
        SEQ_TWO_KEYS(KC_P, KC_E) {
            send_string(secrets[1]);
        }
        SEQ_TWO_KEYS(KC_P, KC_P) {
            send_string(secrets[2]);
        }
        SEQ_TWO_KEYS(KC_P, KC_U) {
            send_string(secrets[3]);
        }
        SEQ_THREE_KEYS(KC_P, KC_P, KC_N) {
            send_string(secrets[4]);
        }
        SEQ_TWO_KEYS(KC_P, KC_N) {
            send_string(secrets[5]);
        }
        SEQ_THREE_KEYS(KC_P, KC_E, KC_M) {
            send_string(secrets[6]);
        }
        SEQ_TWO_KEYS(KC_W, KC_E) {
            send_string(secrets[7]);
        }
        SEQ_TWO_KEYS(KC_W, KC_P) {
            send_string(secrets[8]);
        }
        SEQ_TWO_KEYS(KC_W, KC_U) {
            send_string(secrets[9]);
        }
        SEQ_THREE_KEYS(KC_W, KC_E, KC_I) {
            send_string(secrets[10]);
        }
    }
}
