#include "metheon.h"
#include "key_overrides.c"

#if defined(COMBO_ENABLE)
#include "g/keymap_combo.h" // to make combo def dictionary work
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _NUM, _FUN);
    return state;
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
          // mod tab keys
          case HOME_C:
          case HOME_S:
          case HOME_N:
          case HOME_T:
          case HOME_A:
          case HOME_E:
          case HOME_I:
          case HOME_H:
               return true;
          // layer keys
          case SFT_SYS:
          case SFT_SYM:
          case SPC_NAV:
          case R_NUM:
               return false;
          default:
               return true;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
          // mod tab keys
          case HOME_C:
          case HOME_S:
          case HOME_N:
          case HOME_T:
          case HOME_A:
          case HOME_E:
          case HOME_I:
          case HOME_H:
               return 300;
          // layer keys
          case SFT_SYS:
          case SPC_NAV:
          case R_NUM:
          case SFT_SYM:
               return 300;
          default:
               return 400;
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
         KC_J    ,KC_M    ,KC_K    ,KC_P    ,KC_B    ,    KC_GRV  ,KC_U    ,KC_O    ,KC_Y    ,KC_AT   ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         HOME_C  ,HOME_S  ,HOME_N  ,HOME_T  ,KC_G    ,    KC_MINS ,HOME_A  ,HOME_E  ,HOME_I  ,HOME_H  ,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         KC_W    ,KC_F    ,KC_L    ,KC_D    ,KC_V    ,    KC_QUES ,KC_QUOT ,KC_COMMA,KC_DOT  ,KC_SLSH ,
    //  '--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                           CHD_E01 ,SFT_SYS ,SPC_NAV ,    R_NUM   ,SFT_SYM ,CHD_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_SYS] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         __NONE__,KC_MUTE ,KC_VOLD ,KC_VOLU ,__NONE__,    M_UL_QD ,M_L2_3RD,M_UP_HF ,M_R2_3RD,M_UR_QD ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_MPRV ,KC_MPLY ,KC_MNXT ,__NONE__,    M_FSCRN ,M_LT_HF ,M_BT_HF ,M_RT_HF ,HIDE_WIN,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,SNK_CASE,SCRM_SNK,CAPSWORD,__NONE__,    M_BL_QD ,M_LT_3RD,M_MD_3RD,M_RT_3RD,M_BR_QD ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           __NONE__,________,__NONE__,    M_FSCRN ,HIDE_WIN,__NONE__
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_NAV] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         LOCK    ,SCRNSHT ,PREV_WIN,NEXT_WIN,KC_LEAD ,    MAC_PGUP,KC_STAB ,KC_UP   ,KC_TAB  ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_LCTL ,KC_LALT ,KC_LSFT ,KC_LGUI ,KC_ESC  ,    MAC_PGDN,KC_LEFT ,KC_DOWN ,KC_RGHT ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         UNDO    ,CUT     ,COPY    ,PASTE   ,__NONE__,    __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           NAV_E01 ,__NONE__,________,    BSPC_NUM,KC_DEL  ,NAV_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_NUM] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         __NONE__,KC_7    ,KC_8    ,KC_9    ,__NONE__,    __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_4    ,KC_5    ,KC_6    ,__NONE__,    KC_ENTER,KC_LGUI ,KC_LSFT ,KC_LALT ,KC_LCTL ,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         __NONE__,KC_1    ,KC_2    ,KC_3    ,__NONE__,    __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                           NUM_E01 ,__NONE__,ZERO_NAV,    ________,__NONE__,NUM_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_SYM] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         __NONE__,KC_CIRC ,KC_DLR  ,KC_EQL  ,__NONE__,    __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_LT   ,KC_LCBR ,KC_LBRC ,KC_LPRN ,__NONE__,    __NONE__,KC_LGUI ,KC_LSFT ,KC_LALT ,KC_LCTL ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,__NONE__,KC_PIPE ,KC_AMPR ,__NONE__,    __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           __NONE__,__NONE__,KC_UNDS ,    __NONE__,________,__NONE__
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_FUN] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         RESET   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F12  ,    __NONE__,__NONE__,__NONE__,__NONE__,RESET   ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_F4   ,KC_F5   ,KC_F6   ,KC_F11  ,    __NONE__,KC_LGUI ,KC_LSFT ,KC_LALT ,KC_LCTL ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_F1   ,KC_F2   ,KC_F3   ,KC_F10  ,    __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           __NONE__,__NONE__,________,    ________,__NONE__,__NONE__
    //                    '--------+--------+--------'   '--------+--------+--------'
    )
};
// clang-format on
