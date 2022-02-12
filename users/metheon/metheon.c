#include "metheon.h"
#include "features/key_overrides.c"
#include "features/oneshot.h"

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
                                    NAV     ,KC_SPACE,    OSM_LSFT,NUM
    //                             '--------+--------'   '--------+--------'
    ),
    [_NAV] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         KC_ESC  ,KC_MPRV ,KC_MPLY ,KC_MNXT ,KC_VOLU ,    __NONE__,KC_STAB ,KC_UP   ,KC_TAB  ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         OS_CTRL ,OS_ALT  ,OS_SHFT ,OS_CMD  ,KC_VOLD ,    __NONE__,KC_LEFT ,KC_DOWN ,KC_RGHT ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         UNDO    ,CUT     ,COPY    ,PASTE   ,KC_MUTE ,    __NONE__,KC_BSPC ,KC_CAPS ,KC_DEL  ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                                    ________,__NONE__,    KC_ENTER,________
    //                             '--------+--------'   '--------+--------'
    ),
    [_NUM] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         __NONE__,KC_7    ,KC_8    ,KC_9    ,__NONE__,    __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         __NONE__,KC_4    ,KC_5    ,KC_6    ,__NONE__,    __NONE__,OS_CMD  ,OS_SHFT ,OS_ALT  ,OS_CTRL ,
    //  |--------+--------+--------+--------+--------|   |--------+--------|--------+--------+--------|
         __NONE__,KC_1    ,KC_2    ,KC_3    ,__NONE__,    __NONE__,__NONE__,__NONE__,__NONE__,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------'
                                    ________,KC_0    ,    __NONE__,________
    //                             '--------+--------'   '--------+--------'
    ),
    [_SYM] = LAYOUT_metheon(
    //  .--------+--------+--------+--------+--------.   .--------+--------+--------+--------+--------.
         KC_PERC ,KC_CIRC ,KC_DLR  ,KC_EUR  ,KC_PND  ,    __NONE__,M_L2_3RD,HIDE_WIN,M_R2_3RD,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_SLSH ,KC_ASTR ,KC_MINS ,KC_PLUS ,KC_BSLS ,    __NONE__,M_LT_HF ,M_FSCRN ,M_RT_HF ,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
         KC_PIPE ,KC_AMPR ,KC_EXLM ,KC_EQL  ,DEGREE  ,    __NONE__,M_LT_3RD,M_MD_3RD,M_RT_3RD,__NONE__,
    //  |--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------|
                                    ________,__NONE__,    __NONE__,________
    //                             '--------+--------'   '--------+--------'
    )
};
// clang-format on

#if defined(COMBO_ENABLE)
#include "g/keymap_combo.h" // to make combo def dictionary work
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NAV, _NUM, _SYM);
};

bool is_oneshot_cancel_key(uint16_t keycode) {
     switch (keycode) {
          case NUM:
          case NAV:
               return true;
          default:
               return false;
     }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
     switch (keycode) {
          case NUM:
          case NAV:
          case OSM_LSFT:
          case OS_SHFT:
          case OS_CTRL:
          case OS_ALT:
          case OS_CMD:
               return true;
          default:
               return false;
     }
}

bool sw_win_active = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(
        &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
        keycode, record
    );
    update_swapper(
        &sw_lang_active, KC_LCTL, KC_SPC, SW_LANG,
        keycode, record
    );

    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LCMD, OS_CMD,
        keycode, record
    );

    return true;
}
