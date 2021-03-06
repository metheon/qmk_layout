#pragma once

#include QMK_KEYBOARD_H
#include "encoders.h"
#include "process_records.h"
#include "window_tab.h"
#include "leader.h"

enum layers {
    _BASE,                  // Colemak-DH
    _LOWER,
    _RAISE,
    _EXTEND,                // Navigation cluster
    _FUNPAD,                // Left hand funpad (F1 - F12)
    _ADJUST,                // Mainly RGB and media keys, activated when lower and raise is pressed at the same time
    _SECRETS,               // Dedicated layer for all the secrets
    _BL3_BSE,               // Base layer for Borderlands 3
    _BL3_UPR,               // Upper layer for Borderlands 3
};

#define __NONE__            KC_NO
#define ________            _______

#define SHIFT               OSM(MOD_LSFT)
#define THMB_L1             MO(_FUNPAD)
#define THMB_L2             LT(_EXTEND, KC_SPACE)
#define THMB_L3             LT(_LOWER, KC_ENTER)
#define THMB_R3             LT(_RAISE, KC_BSPC)
#define THMB_R2             SHIFT
#define THMB_R1             __NONE__

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

#define KC_STAB             LSFT(KC_TAB)

#define NEXT_TAB            LCTL(KC_TAB)
#define PREV_TAB            LCTL(KC_STAB)

