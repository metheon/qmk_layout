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
        case HOME_A:
        case HOME_R:
        case HOME_S:
        case HOME_T:
        case HOME_N:
        case HOME_E:
        case HOME_I:
        case HOME_O:
             return true;
        case TAB_SYM:
        case SPC_NAV:
        case BSPC_NUM:
        case DEL_SYM:
            return true;
        default:
            return false;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
        case HOME_R:
        case HOME_S:
        case HOME_T:
        case HOME_N:
        case HOME_E:
        case HOME_I:
        case HOME_O:
            return TAPPING_TERM - 100; // 400-100=300
        case TAB_SYM:
        case SPC_NAV:
        case BSPC_NUM:
        case DEL_SYM:
            return TAPPING_TERM - 225; // 400-225=175
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
    [_COLDH] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         KC_AE   ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,    KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_QUOT ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         HOME_A  ,HOME_R  ,HOME_S  ,HOME_T  ,KC_G    ,    KC_M    ,HOME_N  ,HOME_E  ,HOME_I  ,HOME_O  ,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         KC_AA   ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,    KC_K    ,KC_H    ,KC_COMMA,KC_DOT  ,KC_OE   ,
    //  '--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                           CHD_E01 ,TAB_SYM ,SPC_NAV ,    BSPC_NUM,DEL_SYM ,CHD_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_NAV] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         PREV_TAB,NEXT_TAB,PRV_DSKT,NXT_DSKT,LOCK    ,    __NONE__,KC_BSPC ,KC_UP   ,KC_DEL  ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_LCTRL,KC_LALT ,KC_LSFT ,KC_LGUI ,SEARCH  ,    __NONE__,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_ENTER,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         UNDO    ,CUT     ,COPY    ,PASTE   ,SCRNSHT ,    __NONE__,CAPSWORD,SCRM_SNK,SNK_CASE,CPS_DSBL,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           NAV_E01 ,________,________,    ________,________,NAV_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_NUM] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         __NONE__,KC_7    ,KC_8    ,KC_9    ,__NONE__,    __NONE__,KC_EQL  ,KC_LPRN ,KC_RPRN ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_4    ,KC_5    ,KC_6    ,__NONE__,    __NONE__,KC_LGUI ,KC_LGUI ,KC_LALT ,KC_LCTL ,
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
         RESET   ,__NONE__,__NONE__,__NONE__,__NONE__,    __NONE__,M_L2_3RD,M_UP_HF ,M_R2_3RD,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_MPRV ,KC_MPLY ,KC_MNXT ,__NONE__,    M_FSCRN ,M_LT_HF ,M_BT_HF ,M_RT_HF ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_MUTE ,KC_VOLD ,KC_VOLU ,__NONE__,    __NONE__,M_LT_3RD,M_MD_3RD,M_RT_3RD,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           __NONE__,________,________,    ________,________,__NONE__
    //                    '--------+--------+--------'   '--------+--------+--------'
    )
};
// clang-format on

