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
    //  .--------------------------------------------.                    .--------------------------------------------.
         KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B                         ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_QUOT ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         HOME_A  ,HOME_R  ,HOME_S ,HOME_T   ,KC_G                         ,M_MAG   ,HOME_N  ,HOME_E  ,HOME_I  ,HOME_O  ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V                         ,KC_K    ,KC_H    ,KC_COMMA,KC_DOT  ,KC_SLSH ,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   TAB_LWR ,SPC_EXT  ,ENT_RSE    ,DEL_RSE ,BSPC_MSE,ESC_LWR ,
    //                            '--------+---------+--------+  +--------+--------+--------'
    //  Encoders
    //  .--------+-------.
         BSE_E01 ,BSE_E02
    //  '--------+-------'
    ),
    [_LOWER] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         KC_RPRN ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12                       ,KC_ASTR ,KC_7    ,KC_8    ,KC_9    ,KC_SLSH ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         HOME_ENT,HOME_F5 ,HOME_F6,HOME_F7  ,KC_F8                        ,KC_PLUS ,HOME_4  ,HOME_5  ,HOME_6  ,HOME_MN ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_LPRN ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4                        ,KC_0    ,KC_1    ,KC_2    ,KC_3    ,KC_EQL  ,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   _______ ,_______  ,_______    ,_______ ,_______ ,_______ ,
    //                            '--------+---------+--------+  +--------+--------+--------'
    //  Encoders
    //  .--------+-------.
         LWR_E01 ,LWR_E02
    //  '--------+-------'
    ),
    [_RAISE] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         KC_GRV  ,KC_CIRC ,KC_HASH ,KC_TILD ,KC_LCBR                      ,KC_RCBR ,KC_DLR  ,KC_EUR  ,__NONE__,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_AT   ,KC_AE   ,KC_OE   ,KC_AA   ,KC_LPRN                      ,KC_RPRN ,KC_EQL  ,KC_EXLM ,KC_AMPR ,KC_PIPE ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         __NONE__,__NONE__,KC_UNDS ,KC_MINS ,KC_LBRC                      ,KC_RBRC ,KC_SCLN ,KC_COLN ,KC_PERC ,KC_BSLS ,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   _______ ,_______  ,_______    ,_______ ,_______ ,_______ ,
    //                            '--------+---------+--------+  +--------+--------+--------'
    //  Encoders
    //  .--------+-------.
         RSE_E01 ,RSE_E02
    //  '--------+-------'
    ),
    [_EXTEND] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__                     ,KC_PGUP ,KC_HOME ,KC_UP   ,KC_END  ,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_LCTRL,KC_LALT ,KC_LSFT ,KC_LGUI,KC_LEAD                       ,KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RGHT ,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         UNDO    ,CUT     ,COPY    ,PASTE   ,WIN_MAC                      ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   _______ ,_______  ,_______    ,_______ ,_______ ,_______ ,
    //                            '--------+---------+--------+  +--------+--------+--------'
    //  Encoders
    //  .--------+-------.
         EXT_E01 ,EXT_E02
    //  '--------+-------'
    ),
    [_MOUSE] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         __NONE__,KC_WH_L ,KC_MS_U ,KC_WH_R ,KC_WH_U                      ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         __NONE__,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D                      ,__NONE__,KC_LGUI ,KC_LSFT ,KC_LALT ,KC_LCTRL,
    //  |--------------------------------------------|                    |--------------------------------------------|
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__                     ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   KC_BTN1 ,KC_BTN2  ,KC_BTN3    ,_______ ,_______ ,_______ ,
    //                            '--------+---------+--------+  +--------+--------+--------'
    //  Encoders
    //  .--------+-------.
         MSE_E01 ,MSE_E02
    //  '--------+-------'
    ),
    [_ADJUST] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         __NONE__,__NONE__,__NONE__,__NONE__,__NONE__                     ,__NONE__,KC_FLASH,KC_MAKE ,KC_VRSN ,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         KC_CAPS ,KC_MPRV ,KC_MPLY ,KC_MNXT ,__NONE__                     ,RGB_TOG ,RGB_MOD ,RGB_HUI ,RGB_SAI ,RGB_VAI ,
    //  |--------------------------------------------|                    |--------------------------------------------|
         __NONE__,KC_MUTE ,KC_VOLD ,KC_VOLU ,USE_MAC                      ,USE_WIN ,RGB_RMOD,RGB_HUD ,RGB_SAD ,RGB_VAD ,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   _______ ,RESET    ,_______    ,_______ ,RESET   ,_______ ,
    //                            '--------+---------+--------+  +--------+--------+--------'
    //  Encoders
    //  .--------+-------.
         ADJ_E01 ,ADJ_E02
    //  '--------+-------'
    ),
    [_MAGNET] = LAYOUT_metheon(
    //  .--------------------------------------------.                    .--------------------------------------------.
         __NONE__,__NONE__,MG_UL_QD,MG_UP_HF,MG_UR_QD                     ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         MG_L2_TD,MG_R2_TD,MG_LF_HF,MG_FSCR ,MG_RT_HF                     ,_______ ,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------------------------------------------|                    |--------------------------------------------|
         __NONE__,__NONE__,MG_BL_QD,MG_BT_HF,MG_BR_QD                     ,__NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  '-------------------------+--------+---------+--------+  +--------+--------+--------+--------------------------'
                                   MG_LF_TD,MG_MD_TD ,MG_RT_TD   ,_______ ,_______ ,_______ ,
    //                            '--------+---------+--------+  +--------+--------+--------'
    //  Encoders
    //  .--------+-------.
         MAG_E01 ,MAG_E02
    //  '--------+-------'
    )
};
// clang-format on
