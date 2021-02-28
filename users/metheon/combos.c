#include "metheon.h"

enum combo_events {
    FP_DEL,
    LU_BSPC,
    CD_ESC,
    HCOMMA_ENTER,
    COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM fp_del_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM lu_bspc_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM cd_esc_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM hcomma_enter_combo[] = {KC_H, KC_COMMA, COMBO_END};

combo_t key_combos[] = {
  [FP_DEL] = COMBO(fp_del_combo, KC_DEL),
  [LU_BSPC] = COMBO(lu_bspc_combo, KC_BSPC),
  [CD_ESC] = COMBO(cd_esc_combo, KC_ESC),
  [HCOMMA_ENTER] = COMBO(hcomma_enter_combo, KC_ENTER),
};
