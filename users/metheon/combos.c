#include QMK_KEYBOARD_H

enum combos {
  W_F_Q,
  U_Y_QUOT,

};

const uint16_t PROGMEM w_f_q[] = { KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM u_y_quot[] = { KC_U, KC_Y, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [W_F_Q] = COMBO(w_f_q, KC_Q),
  [U_Y_QUOT] = COMBO(u_y_quot, KC_QUOT),
};
