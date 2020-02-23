#pragma once

#ifndef METHEON
#define METHEON

#include "quantum.h"

// -- Windows --
#define WIN_UNDO    LCTL(KC_Z)
#define WIN_REDO    LSFT(LCTL(KC_Z))
#define WIN_CUT     LCTL(KC_X)
#define WIN_COPY    LCTL(KC_C)
#define WIN_PSTE    LCTL(KC_V)
// EurKey key combinations used on Windows, right alt will be applied later
#define WIN_EE      KC_G
#define WIN_AA      KC_W
#define WIN_AE      KC_Q
#define WIN_OE      KC_L
#define WIN_PND     KC_4
#define WIN_EUR     KC_5

// -- MacOS --
#define MAC_UNDO    LGUI(KC_Z)
#define MAC_REDO    LSFT(LGUI(KC_Z))
#define MAC_CUT     LGUI(KC_X)
#define MAC_COPY    LGUI(KC_C)
#define MAC_PSTE    LGUI(KC_V)
// Mac key combinations to mirror EurKey
// #define MAC_EE --> see DK_EE (this is special on mac)
#define MAC_AA      LALT(KC_A)
#define MAC_AE      LALT(KC_QUOTE)
#define MAC_OE      LALT(KC_O)
#define MAC_PND     LALT(KC_3)
#define MAC_EUR     LSFT(LALT(KC_2))

#define MAC_PGUP    LGUI(KC_UP)
#define MAC_PGDN    LGUI(KC_DOWN)
#define MAC_HOME    LGUI(KC_LEFT)
#define MAC_END     LGUI(KC_RIGHT)

// Layers
#define LOWER       MO(_LOWER)
#define RAISE       MO(_RAISE)
#define BASE        TO(_BASE)
#define NUMPAD      TO(_NUMPAD)
#define SPACE_FN    LT(_MOVE, KC_SPACE)

enum metheon_layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOVE,
    _NUMPAD,
};

enum metheon_keycodes {
    EPRM = SAFE_RANGE,
    TG_OS,                      // Toggle between windows and mac
    ALT_GUI,                    // Alt on windows, Gui on mac
    GUI_ALT,                    // Gui on windows, Alt on mac
    REDO,
    UNDO,
    CUT,
    COPY,
    PASTE,
    DK_EE,
    DK_AE,
    DK_OE,
    DK_AA,
    MY_PND,
    MY_EUR,
    MY_PGUP,
    MY_PGDN,
    MY_HOME,
    MY_END,
};

#define LAYOUT_preonic_grid_wrapper(...)   LAYOUT_preonic_grid(__VA_ARGS__)
#define LAYOUT_planck_grid_wrapper(...)   LAYOUT_planck_grid(__VA_ARGS__)

/**
 * A note on the 2U key (space key) which is defined twice on all layouts (2 x 1U keys).
 * On the preonic it seems that it is the right position which counts and on the planck it is the left.
 * As a result I've defined them both to the same and that seems to work fine, as the other remain unused.
 */

#define _______NONE____________     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______



#define _______BASE_1__________     KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_BSPC
#define _______BASE_2__________     KC_ESC  ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_D    ,KC_H    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_QUOT
#define _______BASE_3__________     KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_K    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_RSFT
#define _______BASE_4__________     NUMPAD  ,KC_LCTL ,GUI_ALT ,ALT_GUI ,LOWER   ,SPACE_FN,SPACE_FN,RAISE   ,ALT_GUI ,GUI_ALT ,KC_LCTL ,KC_MEH



#define _______LOWER_1_________     KC_TILD ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_DEL
#define _______LOWER_2_________     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,KC_UNDS ,KC_PLUS ,KC_LCBR ,KC_RCBR ,KC_PIPE
#define _______LOWER_3_________     _______ ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,_______ ,_______ ,_______ ,_______ ,_______
#define _______LOWER_4_________     _______ ,_______ ,_______ ,_______ ,LOWER   ,KC_ENT  ,KC_ENT  ,RAISE   ,_______ ,_______ ,_______ ,_______



#define _______RAISE_1_________     KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_DEL
#define _______RAISE_2_________     KC_CAPS ,DK_EE   ,DK_AE   ,DK_OE   ,DK_AA   ,MY_PND  ,MY_EUR  ,KC_MINS ,KC_EQL  ,KC_LBRC ,KC_RBRC ,KC_BSLS
#define _______RAISE_3_________     _______ ,UNDO    ,CUT     ,COPY    ,PASTE   ,REDO    ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
#define _______RAISE_4_________     _______ ,_______ ,_______ ,_______ ,LOWER   ,KC_ENT  ,KC_ENT  ,RAISE   ,_______ ,_______ ,_______ ,_______



#define _______ADJUST_1________     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
#define _______ADJUST_2________     _______ ,_______ ,KC_MPRV ,KC_MPLY ,KC_MNXT ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
#define _______ADJUST_3________     _______ ,_______ ,KC_MUTE ,KC_VOLD ,KC_VOLU ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
#define _______ADJUST_4________     _______ ,_______ ,_______ ,_______ ,LOWER   ,RESET   ,RESET   ,RAISE   ,_______ ,_______ ,_______ ,TG_OS


#define _______MOVE_1__________     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,MY_PGUP ,MY_HOME ,KC_UP   ,MY_END  ,_______ ,_______
#define _______MOVE_2__________     _______ ,KC_LSFT ,KC_LCTL ,GUI_ALT ,ALT_GUI ,_______ ,MY_PGDN ,KC_LEFT ,KC_DOWN ,KC_RGHT ,_______ ,_______
#define _______MOVE_3__________     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______
#define _______MOVE_4__________     _______ ,_______ ,_______ ,_______ ,_______ ,SPACE_FN,SPACE_FN,_______ ,_______ ,_______ ,_______ ,_______



#define _______NUMPAD_1________     _______ ,_______ ,KC_HASH ,KC_LPRN ,KC_RPRN ,_______ ,_______ ,KC_7    ,KC_8    ,KC_9    ,_______ ,_______
#define _______NUMPAD_2________     _______ ,KC_SLSH ,KC_ASTR ,KC_MINS ,KC_PLUS ,_______ ,_______ ,KC_4    ,KC_5    ,KC_6    ,_______ ,_______
#define _______NUMPAD_3________     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_1    ,KC_2    ,KC_3    ,_______ ,_______
#define _______NUMPAD_4________     BASE    ,_______ ,_______ ,_______ ,KC_EQUAL,KC_ENT  ,KC_ENT  ,KC_0    ,KC_COMM ,KC_DOT  ,_______ ,_______


#endif
