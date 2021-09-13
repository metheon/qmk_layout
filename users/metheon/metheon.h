#pragma once

#include QMK_KEYBOARD_H
#include "encoders.h"
#include "process_records.h"
#include "window_tab.h"
#include "leader.h"

enum layers {
    _BASE,                  // Colemak-DH
    _COLHD,                 // Colemak and Hands Down hybrid
    _LOWER,                 // Numpad and funpad layer
    _RAISE,                 // Primary symbols layer
    _EXTEND,                // Navigation cluster
    _ADJUST,                // Mainly RGB and media keys, activated when lower and raise is pressed at the same time
    _MAGNET,                // Shortcuts for Magnet software on mac
};

#define __NONE__            KC_NO
#define ________            _______

#define MAGNET              OSL(_MAGNET)
#define SHIFT               OSM(MOD_LSFT)

#define SPC_EXT             LT(_EXTEND, KC_SPACE)
#define ENT_LWR             LT(_LOWER, KC_ENTER)
#define BSPC_SFT            LSFT_T(KC_BSPC)
#define DEL_RSE             LT(_RAISE, KC_DEL)

// Home row mods, using Colemak ... arst <--> neio
#define HOME_A              LCTL_T(KC_A)
#define HOME_R              LALT_T(KC_R)
#define HOME_S              LSFT_T(KC_S)
#define HOME_T              LGUI_T(KC_T)
#define HOME_N              LGUI_T(KC_N)
#define HOME_E              LSFT_T(KC_E)
#define HOME_I              LALT_T(KC_I)
#define HOME_O              LCTL_T(KC_O)
#define BASE                DF(_BASE)

// Home row mods, using colemak hands down hybrid
#define HRM_R               LCTL_T(KC_R)
#define HRM_S               LALT_T(KC_S)
#define HRM_N               LSFT_T(KC_N)
#define HRM_T               LGUI_T(KC_T)
#define HRM_A               LGUI_T(KC_A)
#define HRM_E               LSFT_T(KC_E)
#define HRM_I               LALT_T(KC_I)
#define HRM_O               LCTL_T(KC_O)
#define COLHD               DF(_COLHD)

// Home row mods, for the funpad and numpad... F5 F6 F7 F8 <--> 4 5 6 0
#define HOME_F5             LCTL_T(KC_F5)
#define HOME_F6             LALT_T(KC_F6)
#define HOME_F7             LSFT_T(KC_F7)
#define HOME_F8             LGUI_T(KC_F8)
#define HOME_4              LGUI_T(KC_4)
#define HOME_5              LSFT_T(KC_5)
#define HOME_6              LALT_T(KC_6)
#define HOME_0              LCTL_T(KC_0)

#define COPY_T              LCTL(KC_INSERT)
#define PASTE_T             LSFT(KC_INSERT)

#define KC_STAB             LSFT(KC_TAB)

#define NEXT_TAB            LCTL(KC_TAB)
#define PREV_TAB            LCTL(KC_STAB)

#define SCRNSHT             LGUI(LSFT(KC_5))

#define KC_AE               RALT(KC_QUOT)       // Æ
#define KC_OE               RALT(KC_O)          // Ø
#define KC_AA               RALT(KC_A)          // Å

// other symbols
#define KC_EUR              LSFT(RALT(KC_2))    // €
#define KC_PND              RALT(KC_3)          // £

// clipboard
#define UNDO                LGUI(KC_Z)          // Undo
#define CUT                 LGUI(KC_X)          // Cut
#define COPY                LGUI(KC_C)          // Copy
#define PASTE               LGUI(KC_V)          // Paste

// utilities
#define LOCK                LCTL(LGUI(KC_Q))    // Lock computer      
#define SEARCH              LGUI(KC_SPACE)      // Search 
#define NXT_DSKT            LCTL(KC_RIGHT)      // Next Desktop
#define PRV_DSKT            LCTL(KC_LEFT)       // Previous Desktop
#define DEL_WRD             LALT(KC_BSPC)       // Delete word
#define ZOOM_AUD            LGUI(LSFT(KC_A))    // Zoom Audio Off/On
#define ZOOM_VID            LGUI(LSFT(KC_V))    // Zoom Video Off/On
#define HIDE_WIN            LGUI(KC_H)          // Hide a Window
