#include "metheon.h"
#include "key_overrides.c"

#if defined(COMBO_ENABLE)
#include "g/keymap_combo.h" // to make combo def dictionary work
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _NUM, _SYM);
    return state;
};


void matrix_scan_user(void) {
    matrix_scan_encoders();
    matrix_scan_leader();
    matrix_scan_window_tab();
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BSE] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         KC_J    ,KC_W    ,KC_H    ,KC_P    ,KC_B    ,    KC_SLSH ,KC_M    ,KC_U    ,KC_A    ,KC_AT   ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_C    ,KC_S    ,KC_N    ,KC_T    ,KC_G    ,    KC_MINS ,KC_R    ,KC_E    ,KC_O    ,KC_I    ,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         KC_QUOT ,KC_F    ,KC_L    ,KC_D    ,KC_V    ,    KC_GRV  ,KC_K    ,KC_COMMA,KC_DOT  ,KC_Y    ,
    //  '--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                           BSE_E01 ,NAV     ,KC_SPACE,    OSM_LSFT,NUM     ,BSE_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_NAV] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         KC_ESC  ,KC_MPRV ,KC_MPLY ,KC_MNXT ,KC_VOLU ,    __NONE__,KC_STAB ,KC_UP   ,KC_TAB  ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         CTRL    ,ALT     ,SHIFT   ,GUI     ,KC_VOLD ,    __NONE__,KC_LEFT ,KC_DOWN ,KC_RGHT ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         UNDO    ,CUT     ,COPY    ,PASTE   ,KC_MUTE ,    __NONE__,KC_BSPC ,CAPSWORD,KC_DEL  ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           NAV_E01 ,________,__NONE__,    KC_ENTER,________,NAV_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_NUM] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         __NONE__,KC_7    ,KC_8    ,KC_9    ,__NONE__,    __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_4    ,KC_5    ,KC_6    ,__NONE__,    __NONE__,GUI     ,SHIFT   ,ALT     ,CTRL    ,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         __NONE__,KC_1    ,KC_2    ,KC_3    ,__NONE__,    __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                           NUM_E01 ,________,KC_0    ,    __NONE__,________,NUM_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_SYM] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         KC_PERC ,KC_CIRC ,KC_DLR  ,KC_EUR  ,KC_PND  ,    __NONE__,M_L2_3RD,HIDE_WIN,M_R2_3RD,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_SLSH ,KC_ASTR ,KC_MINS ,KC_PLUS ,KC_BSLS ,    __NONE__,M_LT_HF ,M_FSCRN ,M_RT_HF ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_PIPE ,KC_AMPR ,KC_EXLM ,KC_EQL  ,DEGREE  ,    __NONE__,M_LT_3RD,M_MD_3RD,M_RT_3RD,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           __NONE__,________,__NONE__,    __NONE__,________,__NONE__
    //                    '--------+--------+--------'   '--------+--------+--------'
    )
};
// clang-format on
