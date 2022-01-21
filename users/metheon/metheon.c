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
          // hands down
          case HOME_I:
          case HOME_E:
          case HOME_A:
          case HOME_U:
          case HOME_P:
          case HOME_T:
          case HOME_N:
          case HOME_S:
               return true;
          // thumb keys
          case ENT_SYM:
          case SPC_NAV:
          case R_NUM:
          case BSPC_SYM:
          case DEL_SYM:
          case BSPC_NUM:
          case ZERO_NAV:
               return true;
          default:
               return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
          // hands down
          case HOME_I:
          case HOME_E:
          case HOME_A:
          case HOME_U:
          case HOME_P:
          case HOME_T:
          case HOME_N:
          case HOME_S:
               return TAPPING_TERM - 100; // 400-100=300
          // thumb keys
          case ENT_SYM:
          case SPC_NAV:
          case R_NUM:
          case BSPC_SYM:
          case DEL_SYM:
          case BSPC_NUM:
          case ZERO_NAV:
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
    [_BASE] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         KC_J    ,KC_W    ,KC_M    ,HOME_P  ,KC_B    ,    KC_GRV  ,HOME_U  ,KC_O    ,KC_Y    ,KC_AT   ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_C    ,HOME_S  ,HOME_N  ,HOME_T  ,KC_G    ,    KC_SLSH ,HOME_A  ,HOME_E  ,HOME_I  ,KC_H    ,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         KC_X    ,KC_F    ,KC_L    ,KC_D    ,KC_V    ,    KC_MINS ,KC_QUOT ,KC_COMMA,KC_DOT  ,KC_K    ,
    //  '--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                           CHD_E01 ,ENT_SYM ,SPC_NAV ,    R_NUM   ,BSPC_SYM,CHD_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_NAV] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         __NONE__,__NONE__,__NONE__,KC_LCTL ,LOCK    ,    __NONE__,KC_STAB ,KC_UP   ,KC_TAB  ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_LALT ,KC_LSFT ,KC_LGUI ,KC_ESC  ,    KC_ENTER,KC_LEFT ,KC_DOWN ,KC_RGHT ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         UNDO    ,CUT     ,COPY    ,PASTE   ,SEARCH  ,    SCRNSHT ,CAPSWORD,SCRM_SNK,SNK_CASE,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           NAV_E01 ,__NONE__,________,    BSPC_NUM,DEL_SYM ,NAV_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_NUM] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         __NONE__,KC_7    ,KC_8    ,KC_9    ,__NONE__,    __NONE__,KC_LCTL ,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         DEGREE  ,KC_4    ,KC_5    ,KC_6    ,__NONE__,    __NONE__,KC_LGUI ,KC_LSFT ,KC_LALT ,FUN     ,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         __NONE__,KC_1    ,KC_2    ,KC_3    ,__NONE__,    __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                           NUM_E01 ,________,ZERO_NAV,    ________,________,NUM_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_FUN] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         __NONE__,KC_F7   ,KC_F8   ,KC_F9   ,__NONE__,    __NONE__,KC_LCTL ,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_F12  ,KC_F4   ,KC_F5   ,KC_F6   ,KC_F11  ,    __NONE__,KC_LGUI ,KC_LSFT ,KC_LALT ,________,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         __NONE__,KC_F1   ,KC_F2   ,KC_F3   ,__NONE__,    __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                           NUM_E01 ,________,KC_F10  ,    ________,________,NUM_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_SYM] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         __NONE__,KC_PERC ,KC_CIRC ,KC_LCBR ,__NONE__,    __NONE__,KC_RCBR ,KC_DLR  ,KC_EUR  ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_QUES ,KC_EXLM ,KC_LPRN ,KC_LT   ,    KC_GT   ,KC_RPRN ,KC_EQL  ,KC_AMPR ,KC_PIPE ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,KC_LBRC ,__NONE__,    __NONE__,KC_RBRC ,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           __NONE__,________,KC_UNDS ,    __NONE__,________,__NONE__
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_SYS] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         RESET   ,KC_MUTE ,KC_VOLD ,KC_VOLU ,__NONE__,    M_UL_QD ,M_L2_3RD,M_UP_HF ,M_R2_3RD,M_UR_QD ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_MPRV ,KC_MPLY ,KC_MNXT ,__NONE__,    M_FSCRN ,M_LT_HF ,M_BT_HF ,M_RT_HF ,M_FSCRN ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,    M_BL_QD ,M_LT_3RD,M_MD_3RD,M_RT_3RD,M_BR_QD ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           __NONE__,__NONE__,________,    ________,__NONE__,__NONE__
    //                    '--------+--------+--------'   '--------+--------+--------'
    )
};
// clang-format on
