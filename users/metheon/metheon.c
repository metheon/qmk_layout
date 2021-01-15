#include "metheon.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
};

void matrix_scan_user(void) {
    matrix_scan_encoders();
    matrix_scan_leader();
}

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_BSPC ,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_ESC  ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_QUOT ,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,KC_K    ,KC_H    ,KC_COMMA,KC_DOT  ,KC_SLSH ,KC_RSFT ,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_LEAD ,MAGNET  ,KC_LALT ,KC_LGUI ,LOWER   ,SPC_EXT ,ENT_EXT ,RAISE   ,KC_LGUI ,KC_LCTL ,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
         BSE_E01 ,BSE_E02
    //  '--------+--------'
    ),
    [_LOWER] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         ________,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,KC_RPRN ,KC_ASTR ,KC_7    ,KC_8    ,KC_9    ,KC_EQL  ,KC_DEL  ,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         ________,KC_F5   ,KC_F6   ,KC_F7   ,KC_F8   ,KC_LPRN ,KC_PLUS ,KC_4    ,KC_5    ,KC_6    ,KC_MINS ,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         ________,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_PERC ,KC_0    ,KC_1    ,KC_2    ,KC_3    ,KC_SLSH ,________,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,________,________,LOWER   ,KC_ENTER,KC_ENTER,RAISE   ,________,________,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
         LWR_E01 ,LWR_E02
    //  '--------+--------'
    ),
    [_RAISE] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         ________,KC_CIRC ,KC_AT   ,KC_HASH ,KC_TILD ,KC_LCBR ,KC_RCBR ,KC_DLR  ,KC_EUR  ,KC_PND  ,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         ________,KC_PIPE ,KC_AMPR ,KC_EXLM ,KC_EQL  ,KC_LPRN ,KC_RPRN ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         ________,KC_BSLS ,KC_GRV  ,KC_UNDS ,KC_MINS ,KC_LBRC ,KC_RBRC ,__NONE__,__NONE__,__NONE__,__NONE__,________,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,________,________,LOWER   ,KC_SPACE,KC_SPACE,RAISE   ,________,________,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
         RSE_E01 ,RSE_E02
    //  '--------+--------'
    ),
    [_EXTEND] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,KC_PGUP ,KC_HOME ,KC_UP   ,KC_END  ,KC_AE   ,KC_OE   ,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,KC_LCTRL,KC_LALT ,KC_LSFT ,KC_LGUI ,__NONE__,KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RGHT ,__NONE__,KC_AA   ,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         ________,UNDO    ,CUT     ,COPY    ,PASTE   ,__NONE__,__NONE__,PASTE_T ,COPY_T  ,__NONE__,__NONE__,________,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,________,________,LOWER   ,________,________,RAISE   ,________,________,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
         EXT_E01 ,EXT_E02
    //  '--------+--------'
    ),
    [_ADJUST] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,KC_FLASH,KC_MAKE ,KC_VRSN ,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         KC_CAPS ,__NONE__,KC_MPRV ,KC_MPLY ,KC_MNXT ,__NONE__,RGB_TOG ,RGB_MOD ,RGB_HUI ,RGB_SAI ,RGB_VAI ,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,KC_MUTE ,KC_VOLD ,KC_VOLU ,__NONE__,__NONE__,RGB_RMOD,RGB_HUD ,RGB_SAD ,RGB_VAD ,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,________,________,LOWER   ,RESET   ,RESET   ,RAISE   ,________,________,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
         ADJ_E01 ,ADJ_E02
    //  '--------+--------'
    ),
    [_MAGNET] = LAYOUT_metheon(
//  .--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------.
         __NONE__,__NONE__,MG_UL_QD,MG_UP_HF,MG_UR_QD,MG_RT_TD,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         MG_L2_TD,MG_R2_TD,MG_LF_HF,MG_FSCR ,MG_RT_HF,MG_MD_TD,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,MG_BL_QD,MG_BT_HF,MG_BR_QD,MG_LF_TD,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------'
         MAG_E01 ,MAG_E02
    //  '--------+--------'
    )
};
// clang-format on
