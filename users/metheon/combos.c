#include QMK_KEYBOARD_H

enum combos {
  W_F_TAB,
  U_Y_QUOT,
  L_U_ESC,
};

const uint16_t PROGMEM w_f_tab[] = { KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM u_y_quot[] = { KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM l_u_esc[] = { KC_L, KC_U, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [W_F_TAB] = COMBO(w_f_tab, KC_TAB),
  [U_Y_QUOT] = COMBO(u_y_quot, KC_QUOT),
  [L_U_ESC] = COMBO(l_u_esc, KC_ESC),
};
