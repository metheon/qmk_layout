#pragma once

#include QMK_KEYBOARD_H
#include "encoders.h"
#include "process_records.h"
#include "window_tab.h"
#include "leader.h"

enum layers {
    _BASE,                  // Colemak-DH
    _LOWER,                 // Numpad and funpad layer
    _RAISE,                 // Primary symbols layer
    _SYMBOLS,               // Secondary symbols layer
    _EXTEND,                // Navigation cluster
    _ADJUST,                // Mainly RGB and media keys, activated when lower and raise is pressed at the same time
    _MAGNET,                // Shortcuts for Magnet software on mac
};

#define __NONE__            KC_NO
#define ________            _______

// Thumb keys from left to right, four on each side
#define MAGNET              OSL(_MAGNET)
#define SPC_EXT             LT(_EXTEND, KC_SPACE)
#define ENT_LWR             LT(_LOWER, KC_ENTER)

#define DEL_RSE             LT(_RAISE, KC_DEL)
#define BSPC_SYM            LT(_SYMBOLS, KC_BSPC)

#define SHIFT               OSM(MOD_LSFT)

// Home row mods, using Colemak ... arst <--> neio
#define HOME_A              LGUI_T(KC_A)
#define HOME_R              LALT_T(KC_R)
#define HOME_S              LSFT_T(KC_S)
#define HOME_T              LCTL_T(KC_T)
#define HOME_N              LCTL_T(KC_N)
#define HOME_E              LSFT_T(KC_E)
#define HOME_I              LALT_T(KC_I)
#define HOME_O              LGUI_T(KC_O)

// Home row mods, for the funpad and numpad... F5 F6 F7 F8 <--> 4 5 6 0
#define HOME_F5             LGUI_T(KC_F5)
#define HOME_F6             LALT_T(KC_F6)
#define HOME_F7             LSFT_T(KC_F7)
#define HOME_F8             LCTL_T(KC_F8)
#define HOME_4              LCTL_T(KC_4)
#define HOME_5              LSFT_T(KC_5)
#define HOME_6              LALT_T(KC_6)
#define HOME_0              LGUI_T(KC_0)

#define COPY_T              LCTL(KC_INSERT)
#define PASTE_T             LSFT(KC_INSERT)

#define KC_STAB             LSFT(KC_TAB)

#define NEXT_TAB            LCTL(KC_TAB)
#define PREV_TAB            LCTL(KC_STAB)

