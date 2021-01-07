#include QMK_KEYBOARD_H
#include "encoders.h"
#include "process_records.h"
#include "leader.h"
#include "keymap_danish_osx.h"

enum layers {
    _BASE,                  // Colemak
    _LOWER,                 // A funpad and a numpad
    _RAISE,                 // Symbols
    _ADJUST,                // Mainly RGB, activated when lower and raise is pressed at the same time
    _EXTEND,                // Home row mods, navigation cluster
};

#define __NONE__            KC_NO

// Base layer thumb cluster from left side, left hand, to right side, right hand
#define TAB_LWR             LT(_LOWER, KC_TAB)
#define SPC_EXT             LT(_EXTEND, KC_SPACE)
#define ENT_RSE             LT(_RAISE, KC_ENTER)
#define DEL_RSE             LT(_RAISE, KC_DEL)
#define BSPC_EXT            LT(_EXTEND, KC_BSPC)
#define ESC_LWR             LT(_LOWER, KC_ESC)

// Home row mods, using Colemak ... arst <--> neio
#define HOME_A              LCTL_T(DK_A)
#define HOME_R              LALT_T(DK_R)
#define HOME_S              LSFT_T(DK_S)
#define HOME_T              LGUI_T(DK_T)
#define HOME_N              LGUI_T(DK_N)
#define HOME_E              LSFT_T(DK_E)
#define HOME_I              LALT_T(DK_I)
#define HOME_O              LCTL_T(DK_O)

// Home row mods, for the numpad and funpad ... ( F6, F5, F4 <--> 4 5 6 -
#define HOME_LP             LCTL_T(DK_LPRN)
#define HOME_F6             LALT_T(KC_F6)
#define HOME_F5             LSFT_T(KC_F5)
#define HOME_F4             LGUI_T(KC_F4)
#define HOME_4              LGUI_T(DK_4)
#define HOME_5              LSFT_T(DK_5)
#define HOME_6              LALT_T(DK_6)
#define HOME_MN             LCTL_T(DK_MINS)

#define UNDO                LGUI(DK_Z)
#define REDO                LSFT(LGUI(DK_Z))
#define CUT                 LGUI(DK_X)
#define COPY                LGUI(DK_C)
#define PASTE               LGUI(DK_V)
#define COPY_T              LCTL(KC_INSERT)
#define PASTE_T             LSFT(KC_INSERT)

#define OSM_SFT             OSM(MOD_LSFT)

#define DK_EE               KC_NO // placeholder
