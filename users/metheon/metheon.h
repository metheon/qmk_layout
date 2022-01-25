#pragma once

#include QMK_KEYBOARD_H
#include "encoders.h"
#include "process_records.h"
#include "window_tab.h"
#include "leader.h"
#include "magnet.h"
#include "desk_control.h"

enum layers {
    _HDT,                   // Hands Down Titanium (neu-rx)
    _NAV,                   // Navigation cluster layer
    _NUM,                   // Numpad layer
    _SYM,                   // Symbols, both hands
    _SYS,                   // Window navigation and media keys
};

#define __NONE__            KC_NO
#define ________            _______

// Main thumb keys
#define ENT_SYM             LT(_SYM, KC_ENTER)
#define SPC_NAV             LT(_NAV, KC_SPC)
#define R_NUM               LT(_NUM, KC_R)
#define BSPC_SYM            LT(_SYM, KC_BSPC)

// Alternative thumb keys
#define BSPC_NUM            LT(_NUM, KC_BSPC)
#define DEL_SYM             LT(_SYM, KC_DEL)
#define ZERO_NAV            LT(_NAV, KC_0)

// layer changes
#define NAV                 MO(_NAV)
#define NUM                 MO(_NUM)
#define SYM                 MO(_SYM)

// Other
#define SHIFT               OSM(MOD_LSFT)

// Home row mods, using Hands Down Titanium ... snt/p <--> u/aei
// Pinkies not used, instead ctrl is put over cmd
#define HOME_C              LCTL_T(KC_C)
#define HOME_S              LALT_T(KC_S)
#define HOME_N              LSFT_T(KC_N)
#define HOME_T              LGUI_T(KC_T)
#define HOME_A              LGUI_T(KC_A)
#define HOME_E              LSFT_T(KC_E)
#define HOME_I              LALT_T(KC_I)
#define HOME_H              LCTL_T(KC_H)

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
#define BSPC_WRD            LALT(KC_BSPC)       // Backspace a word
#define DEL_WRD             LALT(KC_DEL)        // Delete a word
#define ZOOM_AUD            LGUI(LSFT(KC_A))    // Zoom Audio Off/On
#define ZOOM_VID            LGUI(LSFT(KC_V))    // Zoom Video Off/On
#define HIDE_WIN            LGUI(KC_H)          // Hide a Window

#define DEGREE              LALT(KC_K)          // ˚

#define MAC_PGUP            LALT(KC_UP)         // Page Up
#define MAC_PGDN            LALT(KC_DOWN)       // Page Down
#define MAC_HOME            LGUI(KC_LEFT)       // Home
#define MAC_END             LGUI(KC_RGHT)       // End