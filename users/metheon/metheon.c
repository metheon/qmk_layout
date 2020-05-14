#include QMK_KEYBOARD_H
#include "metheon.h"
#include "metheon_encoders.h"
#include "metheon_tap_dance.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HIBRNT:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LGUI(SS_TAP(X_X)) SS_TAP(X_U) SS_TAP(X_H), 200);
            }
            break;
        case SLEEP:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_LGUI(SS_TAP(X_X)) SS_TAP(X_U) SS_TAP(X_S), 200);
            }
            break;
    }
    return true;
};

// clang-format off
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
};
// clang-format on

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_metheon(
        KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_BSPC ,
        ESC_MEH ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_D    ,KC_H    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_QUOT ,
        KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_K    ,KC_M    ,KC_COMMA,KC_DOT  ,KC_SLSH ,KC_RSFT ,
        KC_NO   ,KC_NO   ,TD_ALT  ,TD_CTRL ,LOWER   ,SPACE_FN,ENTER_FN,RAISE   ,TD_CTRL ,TD_GUI  ,DM_PLY1 ,DM_PLY2 ,
        BSE_E01 ,BSE_E02
    ),
    [_LOWER] = LAYOUT_metheon(
        KC_TILD ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_DEL  ,
        XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,KC_UNDS ,KC_PLUS ,KC_LCBR ,KC_RCBR ,XXXXXXX ,
        XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_PIPE ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,_______ ,_______ ,_______ ,KC_ENTER,KC_ENTER,RAISE   ,_______ ,_______ ,XXXXXXX ,XXXXXXX ,
        LWR_E01 ,LWR_E02
    ),
    [_RAISE] = LAYOUT_metheon(
        KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_DEL  ,
        KC_CAPS ,DK_EE   ,DK_AE   ,DK_OE   ,DK_AA   ,DK_PND  ,DK_EUR  ,KC_MINS ,KC_EQL  ,KC_LBRC ,KC_RBRC ,XXXXXXX ,
        XXXXXXX ,UNDO    ,CUT     ,COPY    ,PASTE   ,REDO    ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_BSLS ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,_______ ,_______ ,_______ ,KC_SPACE,KC_SPACE,RAISE   ,_______ ,_______ ,XXXXXXX ,XXXXXXX ,
        RSE_E01 ,RSE_E02
    ),
    [_ADJUST] = LAYOUT_metheon(
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,RESET   ,
        HIBRNT  ,RGB_VAI ,RGB_SAI ,RGB_HUI ,RGB_MOD ,RGB_TOG ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        SLEEP   ,RGB_VAD ,RGB_SAD ,RGB_HUD ,RGB_RMOD,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,_______ ,_______ ,_______ ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,_______ ,XXXXXXX ,XXXXXXX ,
        ADJ_E01 ,ADJ_E02
    ),
    [_FUNPAD] = LAYOUT_metheon(
        XXXXXXX ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        XXXXXXX ,KC_F5   ,KC_F6   ,KC_F7   ,KC_F8   ,XXXXXXX ,XXXXXXX ,KC_LCTRL,KC_LSFT ,KC_LALT ,KC_LGUI ,_______ ,
        XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,XXXXXXX ,XXXXXXX ,
        FUN_E01 ,FUN_E02
    ),
    [_NUMPAD] = LAYOUT_metheon(
        KC_TAB  ,XXXXXXX ,XXXXXXX ,KC_LPRN ,KC_RPRN ,XXXXXXX ,XXXXXXX ,KC_7    ,KC_8    ,KC_9    ,XXXXXXX ,KC_BSPC ,
        _______ ,KC_SLSH ,KC_ASTR ,KC_MINS ,KC_PLUS ,XXXXXXX ,XXXXXXX ,KC_4    ,KC_5    ,KC_6    ,XXXXXXX ,XXXXXXX ,
        _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_EQL  ,XXXXXXX ,XXXXXXX ,KC_1    ,KC_2    ,KC_3    ,XXXXXXX ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,_______ ,_______ ,XXXXXXX ,ENTER_FN,ENTER_FN,KC_0    ,KC_COMMA,KC_DOT  ,XXXXXXX ,XXXXXXX ,
        NUM_E01 ,NUM_E02
    ),
    [_EXTEND] = LAYOUT_metheon(
        SPACES  ,LEFT_MON,RGHT_MON,LEFT_SPC,RGHT_SPC,XXXXXXX ,KC_PGUP ,KC_HOME ,KC_UP   ,KC_END  ,XXXXXXX ,DEL_WRD ,
        WIN_MENU,KC_LGUI ,KC_LALT ,KC_LSFT ,KC_LCTRL,DESKTOP ,KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RGHT ,XXXXXXX ,XXXXXXX ,
        KC_LSFT ,LFT_ALGN,RGT_ALGN,MAXIMIZE,VID_OFF ,XXXXXXX ,FILES   ,MIC_OFF ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        LOCK_PC ,DM_RSTP ,KC_MPRV ,KC_MPLY ,KC_MNXT ,_______ ,_______ ,KC_VOLU ,KC_VOLD ,KC_MUTE ,DM_REC1 ,DM_REC2 ,
        EXT_E01 ,EXT_E02
    )
};
// clang-format on

void matrix_scan_user(void) {
    matrix_scan_fn();
}
