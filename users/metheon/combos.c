#include "metheon.h"

enum combo_events {
    NE_BSPC,
    ST_DEL,
    FP_TAB,
    LU_STAB,
    RS_ESC,
    EI_ENTER,
    CD_MINS,
    XC_UNDS,
    HC_COLN,        // h comma
    CD_SCLN,        // comma dot
    COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM ne_bspc_combo[] = {HOME_N, HOME_E, COMBO_END};
const uint16_t PROGMEM st_del_combo[] = {HOME_S, HOME_T, COMBO_END};
const uint16_t PROGMEM fp_tab_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM lu_stab_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM rs_esc_combo[] = {HOME_R, HOME_S, COMBO_END};
const uint16_t PROGMEM ei_enter_combo[] = {HOME_E, HOME_I, COMBO_END};
const uint16_t PROGMEM cd_mins_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM xc_unds_combo[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM hc_coln_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM cd_scln_combo[] = {KC_COMMA, KC_DOT, COMBO_END};

combo_t key_combos[] = {
  [NE_BSPC] = COMBO(ne_bspc_combo, KC_BSPC),
  [ST_DEL] = COMBO(st_del_combo, KC_DEL),
  [FP_TAB] = COMBO(fp_tab_combo, KC_TAB),
  [LU_STAB] = COMBO(lu_stab_combo, KC_STAB),
  [RS_ESC] = COMBO(rs_esc_combo, KC_ESC),
  [EI_ENTER] = COMBO(ei_enter_combo, KC_ENTER),
  [CD_MINS] = COMBO(cd_mins_combo, KC_MINS),
  [XC_UNDS] = COMBO(xc_unds_combo, KC_UNDS),
  [HC_COLN] = COMBO(hc_coln_combo, KC_COLN),
  [CD_SCLN] = COMBO(cd_scln_combo, KC_SCLN),
};
