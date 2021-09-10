#include "metheon.h"

#if defined(COMBO_ENABLE)
#include "g/keymap_combo.h" // to make combo def dictionary work
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
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
        case HOME_F5:
        case HOME_F6:
        case HOME_F7:
        case HOME_F8:
        case HOME_4:
        case HOME_5:
        case HOME_6:
        case HOME_0:
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
        case HOME_F5:
        case HOME_F6:
        case HOME_F7:
        case HOME_F8:
        case HOME_4:
        case HOME_5:
        case HOME_6:
        case HOME_0:
            return TAPPING_TERM - 100; // 400-100=300
        case SPC_EXT:
        case ENT_LWR:
        case BSPC_SFT:
        case DEL_RSE:
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
    [_BASE] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,    KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_QUOT ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         HOME_A  ,HOME_R  ,HOME_S  ,HOME_T  ,KC_G    ,    KC_M    ,HOME_N  ,HOME_E  ,HOME_I  ,HOME_O  ,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         KC_AE   ,KC_OE   ,KC_C    ,KC_D    ,KC_V    ,    KC_K    ,KC_H    ,KC_COMMA,KC_DOT  ,KC_AA   ,
    //  '--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                           BSE_E01 ,ENT_LWR ,SPC_EXT ,    BSPC_SFT,DEL_RSE ,BSE_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_LOWER] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,__NONE__,    KC_EQL  ,KC_7    ,KC_8    ,KC_9    ,KC_ASTR ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         HOME_F5 ,HOME_F6 ,HOME_F7 ,HOME_F8 ,__NONE__,    KC_PLUS ,HOME_4  ,HOME_5  ,HOME_6  ,HOME_0  ,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,__NONE__,    KC_MINS ,KC_1    ,KC_2    ,KC_3    ,KC_SLSH ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                           LWR_E01 ,________,________,    ________,________,LWR_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_RAISE] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         KC_GRV  ,KC_CIRC ,KC_HASH ,KC_TILD ,KC_LCBR ,    KC_RCBR ,KC_DLR  ,KC_EUR  ,KC_PND  ,KC_DQT  ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_AT   ,KC_SLSH ,KC_MINS ,KC_SCLN ,KC_LPRN ,    KC_RPRN ,KC_EQL  ,KC_EXLM ,KC_AMPR ,KC_PIPE ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_BSLS ,KC_QUES ,KC_UNDS ,KC_COLN ,KC_LBRC ,    KC_RBRC ,KC_PERC ,KC_LT   ,KC_GT   ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           RSE_E01 ,________,________,    ________,________,RSE_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_EXTEND] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         PREV_TAB,NEXT_TAB,PREV_WIN,NEXT_WIN,__NONE__,    LOCK    ,KC_STAB ,KC_UP   ,KC_TAB  ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_LCTRL,KC_LALT ,KC_LSFT ,KC_LGUI ,KC_LEAD ,    SEARCH  ,KC_LEFT ,KC_DOWN ,KC_RGHT ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         UNDO    ,CUT     ,COPY    ,PASTE   ,__NONE__,    SCRNSHT ,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           EXT_E01 ,________,________,    KC_DEL  ,________,EXT_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_ADJUST] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         RESET   ,__NONE__,__NONE__,__NONE__,__NONE__,    __NONE__,KC_FLASH,KC_MAKE ,KC_VRSN ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_MPRV ,KC_MPLY ,KC_MNXT ,__NONE__,    RGB_TOG ,RGB_MOD ,RGB_HUI ,RGB_SAI ,RGB_VAI ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_MUTE ,KC_VOLD ,KC_VOLU ,__NONE__,    __NONE__,RGB_RMOD,RGB_HUD ,RGB_SAD ,RGB_VAD ,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           ADJ_E01 ,________,________,    ________,________,ADJ_E02
    //                    '--------+--------+--------'   '--------+--------+--------'
    ),
    [_MAGNET] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         __NONE__,M_LT_3RD,M_MD_3RD,M_RT_3RD,__NONE__,    __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         M_UP_HF ,M_LT_HF ,M_FSCRN ,M_RT_HF ,__NONE__,    __NONE__,ZOOM_AUD,ZOOM_VID,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         M_BT_HF ,M_L2_3RD,HIDE_WIN,M_R2_3RD,__NONE__,    __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                           __NONE__,__NONE__,__NONE__,    __NONE__,__NONE__,__NONE__
    //                    '--------+--------+--------'   '--------+--------+--------'
    )
};
// clang-format on

