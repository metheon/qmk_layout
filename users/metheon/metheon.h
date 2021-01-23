#pragma once

#include QMK_KEYBOARD_H
#include "encoders.h"
#include "process_records.h"
#include "leader.h"
#include "magnet.h"
#include "window_tab.h"

enum layers {
    _BASE,                  // Colemak-DH
    _NUMPAD,
    _SYMBOLS,
    _EXTEND,                // Navigation cluster
    _FUNPAD,                // Left hand funpad (F1 - F12)
    _ADJUST,                // Mainly RGB and media keys, activated when lower and raise is pressed at the same time
    _MAGNET,                // Layer https://magnet.crowdcafe.com/
};

#define __NONE__            KC_NO
#define ________            _______

// Base layer thumb cluster from left side, left hand, to right side, right hand
#define SPC_EXT             LT(_EXTEND, KC_SPACE)   // Left hand, left thumb
#define ENT_NUM             LT(_NUMPAD, KC_ENTER)   // Left hand, right thumb
#define DEL_FUN             LT(_FUNPAD, KC_DEL)     // Right hand, left thumb
#define BSPC_SYM            LT(_SYMBOLS, KC_BSPC)   // Right hand, right thumb

#define TAB_SYM             LT(_SYMBOLS, KC_TAB)     // Left hand, left thumb
#define ESC_FUN             LT(_FUNPAD, KC_ESC)     // Left hand, right thumb

// Home row mods, using Colemak ... arst <--> neio
#define HOME_A              LGUI_T(KC_A)
#define HOME_R              LALT_T(KC_R)
#define HOME_S              LSFT_T(KC_S)
#define HOME_T              LCTL_T(KC_T)
#define HOME_N              LCTL_T(KC_N)
#define HOME_E              LSFT_T(KC_E)
#define HOME_I              LALT_T(KC_I)
#define HOME_O              LGUI_T(KC_O)

// Home row mods, for the numpad and funpad ... ( F6, F5, F4 <--> 4 5 6 -
#define HOME_ENT            LCTL_T(KC_ENTER)
#define HOME_F5             LALT_T(KC_F5)
#define HOME_F6             LSFT_T(KC_F6)
#define HOME_F7             LGUI_T(KC_F7)
#define HOME_4              LGUI_T(KC_4)
#define HOME_5              LSFT_T(KC_5)
#define HOME_6              LALT_T(KC_6)
#define HOME_MN             LCTL_T(KC_MINS)

#define COPY_T              LCTL(KC_INSERT)
#define PASTE_T             LSFT(KC_INSERT)

#define OSM_SFT             OSM(MOD_LSFT)

#define KC_STAB             LSFT(KC_TAB)

#define NEXT_TAB            LCTL(KC_TAB)
#define PREV_TAB            LCTL(KC_STAB)
