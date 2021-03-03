#pragma once

#include QMK_KEYBOARD_H
#include "encoders.h"
#include "process_records.h"
#include "magnet.h"
#include "window_tab.h"
#include "tap_dances.h"

enum layers {
    _BASE,                  // Colemak-DH
    _LOWER,
    _RAISE,
    _EXTEND,                // Navigation cluster
    _FUNPAD,                // Left hand funpad (F1 - F12)
    _ADJUST,                // Mainly RGB and media keys, activated when lower and raise is pressed at the same time
    _MAGNET,                // Layer https://magnet.crowdcafe.com/
    _SECRETS,               // Dedicated layer for all the secrets
    _BL3_BSE,               // Base layer for Borderlands 3
    _BL3_UPR,               // Upper layer for Borderlands 3
};

#define __NONE__            KC_NO
#define ________            _______

#define FUN_TAB             LT(_FUNPAD, KC_TAB)     // Left hand, thumb one
#define EXT_SPC             LT(_EXTEND, KC_SPACE)   // Left hand, thumb two
#define LWR_ENT             LT(_LOWER, KC_ENTER)    // Left hand, thumb three
#define RSE_DEL             LT(_RAISE, KC_DEL)      // Right hand, thumb three
#define SFT_BSP             LSFT_T(KC_BSPC)   // Right hand, thumb two
#define MAG_ESC             LT(_MAGNET, KC_ESC)     // Right hand, thumb one

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

// All keys related to Borderlands 3
#define TO_BL3              TO(_BL3_BSE)
#define TO_BASE             TO(_BASE)
#define BL3_SPC             LT(_BL3_UPR, KC_SPACE)
#define BL3_W               LSFT(KC_W)              // BL3: Hold shift while pressing W to run instead of walking
#define BL3_A               LSFT(KC_A)              // BL3: Hold shift while pressing A to run instead of walking
#define BL3_S               LSFT(KC_S)              // BL3: Hold shift while pressing S to run instead of walking
#define BL3_D               LSFT(KC_D)              // BL3: Hold shift while pressing D to run instead of walking

