#include QMK_KEYBOARD_H
#include "eurkey_danish.h"
#include "shortcuts.h"

// For the alt tab macro (rotary encoder)
bool     is_alt_tab_active = false;
uint16_t alt_tab_timer     = 0;

// clang-format off
// OSM Mods
#define OSM_SFT             OSM(MOD_LSFT)
#define OSM_ALT             OSM(MOD_LALT)
#define OSM_WIN             OSM(MOD_LGUI)
#define OSM_CTL             OSM(MOD_LCTL)
#define OSM_HYP             OSM(MOD_HYPR)
#define OSM_MEH             OSM(MOD_MEH)

// Layers
#define SPACE_FN            LT(_EXTEND, KC_SPACE)
#define ENTER_FN            LT(_EXTEND, KC_ENTER)
#define LOWER               MO(_LOWER)
#define RAISE               MO(_RAISE)

// Encoder click functions
#define BSE_E01             MO(_ADJUST)
#define BSE_E02             KC_NO
#define LWR_E01             KC_MUTE
#define LWR_E02             KC_NO
#define RSE_E01             KC_NO
#define RSE_E02             KC_NO
#define ADJ_E01             KC_TRNS
#define ADJ_E02             KC_TRNS
#define EXT_E01             KC_NO
#define EXT_E02             KC_MPLY

enum layers {
    _BASE,                                          // Colemak
    _LOWER,                                         // Shifted characters, mostly
    _RAISE,                                         // Unshifted characters, mostly
    _ADJUST,                                        // Mainly RGB, activated when lower and raise is pressed at the same time
    _EXTEND,                                        // Home row mods, navigation cluster, window management
};

enum keycodes {
    HIBRNT = SAFE_RANGE,                            // Hibernate the computer
    SLEEP,                                          // Sleep the computer
};

enum tap_dances {
    TD_CONTROL_CTRLSHIFT = 0,                       // Ctrl on single tap, ctrl+shift on double tap
};
// clang-format on

#define TD_C_CS TD(TD_CONTROL_CTRLSHIFT)

void ctrl_ctrlshift_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_LCTL);
    } else {
        register_code(KC_LCTL);
        register_code(KC_LSFT);
    }
}

void ctrl_ctrlshift_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_LCTL);
    } else {
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
    }
}

// Tap Dance Definitions
// clang-format off
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CONTROL_CTRLSHIFT]      =   ACTION_TAP_DANCE_FN_ADVANCED    (NULL, ctrl_ctrlshift_finished, ctrl_ctrlshift_reset)
};
// clang-format on

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

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_metheon(
        KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_BSPC ,
        ESC_MEH ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_D    ,KC_H    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_QUOT ,
        KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_K    ,KC_M    ,KC_COMMA,KC_DOT  ,KC_SLSH ,KC_RSFT ,
        KC_NO   ,KC_NO   ,KC_LALT ,TD_C_CS ,LOWER   ,SPACE_FN,ENTER_FN,RAISE   ,TD_C_CS ,KC_LWIN ,DM_PLY1 ,DM_PLY2 ,
        BSE_E01 ,BSE_E02
    ),
    [_LOWER] = LAYOUT_metheon(
        KC_TILD ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_DEL  ,
        XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,KC_UNDS ,KC_PLUS ,KC_LCBR ,KC_RCBR ,XXXXXXX ,
        XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_PIPE ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,LOWER   ,KC_ENTER,KC_ENTER,RAISE   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        LWR_E01 ,LWR_E02
    ),
    [_RAISE] = LAYOUT_metheon(
        KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_DEL  ,
        KC_CAPS ,DK_EE   ,DK_AE   ,DK_OE   ,DK_AA   ,DK_PND  ,DK_EUR  ,KC_MINS ,KC_EQL  ,KC_LBRC ,KC_RBRC ,XXXXXXX ,
        XXXXXXX ,UNDO    ,CUT     ,COPY    ,PASTE   ,REDO    ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_BSLS ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,LOWER   ,KC_SPACE,KC_SPACE,RAISE   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        RSE_E01 ,RSE_E02
    ),
    [_ADJUST] = LAYOUT_metheon(
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        HIBRNT  ,RGB_VAI ,RGB_SAI ,RGB_HUI ,RGB_MOD ,RGB_TOG ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        SLEEP   ,RGB_VAD ,RGB_SAD ,RGB_HUD ,RGB_RMOD,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,RESET   ,RESET   ,KC_NO   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        ADJ_E01 ,ADJ_E02
    ),
    [_EXTEND] = LAYOUT_metheon(
        SPACES  ,LEFT_MON,RGHT_MON,LEFT_SPC,RGHT_SPC,XXXXXXX ,KC_PGUP ,KC_HOME ,KC_UP   ,KC_END  ,XXXXXXX ,DEL_WRD ,
        WIN_MENU,KC_LGUI ,KC_LALT ,KC_LSFT ,KC_LCTRL,DESKTOP ,KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RGHT ,XXXXXXX ,XXXXXXX ,
        KC_LSFT ,LFT_ALGN,RGT_ALGN,MAXIMIZE,VID_OFF ,XXXXXXX ,FILES   ,MIC_OFF ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        LOCK_PC ,DM_RSTP ,KC_MPRV ,KC_MPLY ,KC_MNXT ,XXXXXXX ,XXXXXXX ,KC_VOLU ,KC_VOLD ,KC_MUTE ,DM_REC1 ,DM_REC2 ,
        EXT_E01 ,EXT_E02
    )
};
// clang-format on

void matrix_scan_user(void) {
#ifdef ENCODER_ENABLE
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1250) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
#endif
}

void volume_control(bool clockwise) {
    if (clockwise) {
        tap_code16(KC_VOLU);
    } else {
        tap_code16(KC_VOLD);
    }
}

void media_control(bool clockwise) {
    if (clockwise) {
        tap_code16(KC_MNXT);
    } else {
        tap_code16(KC_MPRV);
    }
}

void page_turning(bool clockwise) {
    if (clockwise) {
        tap_code16(KC_PGDN);
    } else {
        tap_code16(KC_PGUP);
    }
}

void zoom(bool clockwise) {
    if (clockwise) {
        tap_code16(C(KC_WH_D));
    } else {
        tap_code16(C(KC_WH_U));
    }
}

void alt_tab(bool clockwise) {
    if (clockwise) {
        if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(KC_TAB);
    } else {
        tap_code16(S(KC_TAB));
    }
}

void ctrl_tab(bool clockwise) {
    if (clockwise) {
        tap_code16(C(KC_TAB));
    } else {
        tap_code16(S(C(KC_TAB)));
    }
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {  // Left encoder
        switch (biton32(layer_state)) {
            case _BASE:
                alt_tab(clockwise);
                break;
            case _LOWER:
                // unused as lower is activated on the left
                break;
            case _RAISE:
                zoom(clockwise);
                break;
            case _ADJUST:
                ctrl_tab(clockwise);
                break;
            case _EXTEND:
                break;
            default:
                // Do nothing
                break;
        }
    } else if (index == 1) {  // Right encoder
        switch (biton32(layer_state)) {
            case _BASE:
                page_turning(clockwise);
                break;
            case _LOWER:
                volume_control(clockwise);
                break;
            case _RAISE:
                // unused as raise is activated on the right
                break;
            case _ADJUST:
                // currently unused
                break;
            case _EXTEND:
                media_control(clockwise);
                break;
            default:
                // Do nothing
                break;
        }
    }
}
#endif
