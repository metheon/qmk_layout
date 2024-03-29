#pragma once

#include QMK_KEYBOARD_H

#include "features/magnet.h"
#include "features/swapper.h"

enum layers {
    _CDH,                   // Modified Colemak DH
    _NAV,                   // Navigation cluster plus media
    _NUM,                   // Numpad, magnet shortcuts
    _SYM,                   // Symbols
    _GAME_0,                // Game layer 0
    _GAME_1,                // Game layer 1
    _GAME_2,                // Game layer 2
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_CMD,

    SW_WIN,  // Switch to next window         (cmd-tab)
    SW_LANG, // Switch to next input language (ctl-spc)

    CDE_BLCK, // markdown code block
};

#define SPC_G1              LT(_GAME_1, KC_SPACE)
#define ESC_G2              LT(_GAME_2, KC_ESC)

#define __NONE__            KC_NO               // Alias to make it eight wide
#define ________            _______             // Alias to make it eight wide

#define NUM                 MO(_NUM)            // Numpad layer
#define NAV                 MO(_NAV)            // Navigation layer

#define OSM_LSFT            OSM(MOD_LSFT)       // Regular one shot shift key
#define KC_STAB             LSFT(KC_TAB)        // Shift+Tab

#define NEXT_TAB            LCTL(KC_TAB)        // Next tab (in browser etc)
#define PREV_TAB            LCTL(KC_STAB)       // Previous tab (in browser etc)

#define SCRNSHT             LGUI(LSFT(KC_5))    // Start the screenshot app

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
#define EMOJI               LGUI(LCTL(KC_SPC))  // Emoji keyboard shortcut

// utilities
#define LOCK                LCTL(LGUI(KC_Q))    // Lock computer      
#define SEARCH              LGUI(KC_SPACE)      // Search 
#define MUSIC               LGUI(LSFT(KC_S))    // Music
#define NXT_DSKT            LCTL(KC_RIGHT)      // Next Desktop
#define PRV_DSKT            LCTL(KC_LEFT)       // Previous Desktop
#define BSPC_WRD            LALT(KC_BSPC)       // Backspace a word
#define DEL_WRD             LALT(KC_DEL)        // Delete a word
#define ZOOM_AUD            LGUI(LSFT(KC_A))    // Zoom Audio Off/On
#define ZOOM_VID            LGUI(LSFT(KC_V))    // Zoom Video Off/On
#define HIDE_WIN            LGUI(KC_H)          // Hide a Window
#define SAVE                LGUI(KC_S)          // Save document
#define SELECT_ALL          LGUI(KC_A)          // Select all
#define FWD                 LGUI(KC_RBRC)       // Forward in the browser
#define BACK                LGUI(KC_LBRC)       // Backward in the browser

#define DEGREE              LALT(KC_K)          // ˚

#define MAC_PGUP            LALT(KC_UP)         // Page Up
#define MAC_PGDN            LALT(KC_DOWN)       // Page Down
#define MAC_HOME            LGUI(KC_LEFT)       // Home
#define MAC_END             LGUI(KC_RGHT)       // End
