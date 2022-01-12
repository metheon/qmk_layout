#include "metheon.h"

#if defined(COMBO_ENABLE)
#include "g/keymap_combo.h" // to make combo def dictionary work
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _NUM, _SYS);
    return state;
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
          // hands down
          case HDT_M_I:
          case HDT_M_E:
          case HDT_M_A:
          case HDT_M_U:
          case HDT_M_D:
          case HDT_M_T:
          case HDT_M_N:
          case HDT_M_S:
          // thumb keys
          case TAB_SYM:
          case SPC_NAV:
          case R_NUM:
          case BSPC_SYM:
               return true;
          default:
               return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
          // hands down
          case HDT_M_I:
          case HDT_M_E:
          case HDT_M_A:
          case HDT_M_U:
          case HDT_M_D:
          case HDT_M_T:
          case HDT_M_N:
          case HDT_M_S:
               return TAPPING_TERM - 100; // 400-100=300
          // thumb keys
          case TAB_SYM:
          case SPC_NAV:
          case R_NUM:
          case BSPC_SYM:
               return TAPPING_TERM - 100; // 400-100=300
          default:
               return TAPPING_TERM;       // 400
    }
}

void matrix_scan_user(void) {
    matrix_scan_encoders();
    matrix_scan_leader();
    matrix_scan_window_tab();
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_HDT] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         KC_X    ,KC_G    ,KC_M    ,KC_P    ,KC_B    ,    KC_SCLN ,KC_DOT  ,KC_SLSH ,KC_DQT  ,KC_QUOT ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         C_SYM   ,HDT_M_S ,HDT_M_N ,HDT_M_T ,KC_W    ,    KC_COMMA,HDT_M_A ,HDT_M_E ,HDT_M_I ,H_SYM   ,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         KC_J    ,KC_F    ,KC_L    ,HDT_M_D ,KC_V    ,    KC_MINS ,HDT_M_U ,KC_O    ,KC_Y    ,KC_K    ,
    //  '--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                           CHD_E01 ,TAB_SYM ,SPC_NAV ,    R_NUM   ,BSPC_SYM,CHD_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_NAV] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         UNDO    ,CUT     ,COPY    ,PASTE   ,LOCK    ,    SNK_CASE,KC_STAB ,KC_UP   ,KC_TAB  ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_LCTL ,KC_LALT ,KC_LSFT ,KC_LGUI ,KC_ESC  ,    CAPSWORD,KC_LEFT ,KC_DOWN ,KC_RGHT ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         PREV_TAB,NEXT_TAB,PRV_DSKT,NXT_DSKT,SCRNSHT ,    SCRM_SNK,KC_ENTER,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           NAV_E01 ,________,________,    ________,DEL_SYM ,NAV_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_NUM] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         __NONE__,KC_7    ,KC_8    ,KC_9    ,__NONE__,    __NONE__,KC_EQL  ,KC_LPRN ,KC_RPRN ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_4    ,KC_5    ,KC_6    ,__NONE__,    __NONE__,KC_LGUI ,KC_LSFT ,KC_LALT ,KC_LCTL ,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         __NONE__,KC_1    ,KC_2    ,KC_3    ,__NONE__,    __NONE__,KC_PLUS ,KC_MINS ,KC_ASTR ,KC_SLSH ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                           NUM_E01 ,________,ZERO_NAV,    ________,________,NUM_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_SYM] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         KC_GRV  ,KC_CIRC ,KC_HASH ,KC_TILD ,KC_LCBR ,    KC_RCBR ,KC_DLR  ,KC_EUR  ,KC_PND  ,KC_DQT  ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_AT   ,KC_SLSH ,KC_MINS ,KC_SCLN ,KC_LPRN ,    KC_RPRN ,KC_EQL  ,KC_EXLM ,KC_AMPR ,KC_PIPE ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_BSLS ,KC_QUES ,KC_UNDS ,KC_COLN ,KC_LBRC ,    KC_RBRC ,KC_PERC ,KC_LT   ,KC_GT   ,KC_SLSH ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           __NONE__,________,________,    ________,________,__NONE__
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_SYS] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         RESET   ,KC_MUTE ,KC_VOLD ,KC_VOLU ,__NONE__,    __NONE__,M_L2_3RD,M_UP_HF ,M_R2_3RD,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_MPRV ,KC_MPLY ,KC_MNXT ,__NONE__,    M_FSCRN ,M_LT_HF ,M_BT_HF ,M_RT_HF ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,    __NONE__,M_LT_3RD,M_MD_3RD,M_RT_3RD,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           __NONE__,________,________,    ________,________,__NONE__
    //                    '--------+--------+--------'   '--------+--------+--------'
    )
};
// clang-format on

