#include "metheon.h"
#include "key_overrides.c"

#if defined(COMBO_ENABLE)
#include "g/keymap_combo.h" // to make combo def dictionary work
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _NUM, _SYS);
    return state;
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
          case SPC_NAV:
               return true;
          default:
               // allow key repeat on tap and hold
               return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
          // layer keys, main
          case SFT_NUM:
          case SPC_NAV:
          // layer keys, alternative
          case ZERO_NAV:
          case BSPC_NUM:
          case DEL_SYM:
               return 200;
          default:
               return 300;
    }
}

void matrix_scan_user(void) {
    matrix_scan_encoders();
    matrix_scan_leader();
    matrix_scan_window_tab();
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BSE] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         KC_J    ,KC_W    ,KC_H    ,KC_P    ,KC_B    ,    KC_QUES ,KC_M    ,KC_U    ,KC_A    ,KC_AT   ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         HOME_C  ,HOME_S  ,HOME_N  ,HOME_T  ,KC_G    ,    KC_QUOT ,HOME_R  ,HOME_E  ,HOME_O  ,HOME_I  ,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         KC_X    ,KC_F    ,KC_L    ,KC_D    ,KC_V    ,    KC_GRV  ,KC_K    ,KC_COMMA,KC_DOT  ,KC_Y    ,
    //  '--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                           BSE_E01 ,SYM     ,SPC_NAV ,    SFT_NUM ,SYM     ,BSE_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_NAV] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         PRV_DSKT,NXT_DSKT,PREV_WIN,NEXT_WIN,KC_LEAD ,    MAC_PGUP,KC_STAB ,KC_UP   ,KC_TAB  ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_LCTL ,KC_LALT ,KC_LSFT ,KC_LGUI ,KC_ESC  ,    MAC_PGDN,KC_LEFT ,KC_DOWN ,KC_RGHT ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         UNDO    ,CUT     ,COPY    ,PASTE   ,LOCK    ,    SCRNSHT ,CAPSWORD,SCRM_SNK,SNK_CASE,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           NAV_E01 ,__NONE__,________,    BSPC_NUM,DEL_SYM ,NAV_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_NUM] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         KC_LPRN ,KC_7    ,KC_8    ,KC_9    ,KC_RPRN ,    __NONE__,KC_PERC ,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_MINS ,KC_4    ,KC_5    ,KC_6    ,KC_PLUS ,    __NONE__,KC_LGUI ,KC_LSFT ,KC_LALT ,KC_LCTL ,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         KC_SLSH ,KC_1    ,KC_2    ,KC_3    ,KC_ASTR ,    __NONE__,KC_EQL  ,KC_COMMA,KC_DOT  ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                           NUM_E01 ,__NONE__,ZERO_NAV,    ________,__NONE__,NUM_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_SYM] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         __NONE__,KC_CIRC ,KC_DLR  ,KC_EUR  ,KC_PND  ,    __NONE__,KC_MINS ,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_LT   ,KC_LCBR ,KC_LBRC ,KC_LPRN ,__NONE__,    __NONE__,KC_EQL  ,KC_AMPR ,KC_PIPE,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_GT   ,KC_RCBR ,KC_RBRC ,KC_RPRN ,__NONE__,    __NONE__,KC_SLSH ,KC_BSLS ,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           __NONE__,________,KC_UNDS ,    __NONE__,________,__NONE__
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_SYS] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         RESET   ,KC_MUTE ,KC_VOLD ,KC_VOLU ,__NONE__,    M_UL_QD ,M_L2_3RD,M_UP_HF ,M_R2_3RD,M_UR_QD ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_MPRV ,KC_MPLY ,KC_MNXT ,__NONE__,    M_FSCRN ,M_LT_HF ,M_BT_HF ,M_RT_HF ,HIDE_WIN,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,    M_BL_QD ,M_LT_3RD,M_MD_3RD,M_RT_3RD,M_BR_QD ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           __NONE__,__NONE__,________,    ________,__NONE__,__NONE__
    //                    '--------+--------+--------'   '--------+--------+--------'
    )
};
// clang-format on
