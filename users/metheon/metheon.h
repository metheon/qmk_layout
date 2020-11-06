#include QMK_KEYBOARD_H
#include "encoders.h"
#include "process_records.h"
#include "leader.h"

enum layers {
    _BASE,                  // Colemak-DH (formerly DHm)
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
#define HOME_A              LGUI_T(KC_A)
#define HOME_R              LALT_T(KC_R)
#define HOME_S              LSFT_T(KC_S)
#define HOME_T              LCTL_T(KC_T)
#define HOME_N              LCTL_T(KC_N)
#define HOME_E              LSFT_T(KC_E)
#define HOME_I              LALT_T(KC_I)
#define HOME_O              LGUI_T(KC_O)

// Home row mods, for the numpad and funpad ... ( F6, F5, F4 <--> 4 5 6 -
#define HOME_LP             LGUI_T(KC_LPRN)
#define HOME_F6             LALT_T(KC_F6)
#define HOME_F5             LSFT_T(KC_F5)
#define HOME_F4             LCTL_T(KC_F4)
#define HOME_4              LCTL_T(KC_4)
#define HOME_5              LSFT_T(KC_5)
#define HOME_6              LALT_T(KC_6)
#define HOME_MN             LGUI_T(KC_MINS)

#define UNDO                LCTL(KC_Z)
#define REDO                LSFT(LCTL(KC_Z))
#define CUT                 LCTL(KC_X)
#define COPY                LCTL(KC_C)
#define PASTE               LCTL(KC_V)
#define COPY_T              LCTL(KC_INSERT)
#define PASTE_T             LSFT(KC_INSERT)

#define OSM_SFT             OSM(MOD_LSFT)

// Key combinations used on Windows for the Danish language using US International keyboard layout
#define DK_EE               RALT(KC_E)
#define DK_AA               RALT(KC_W)
#define DK_AE               RALT(KC_Z)
#define DK_OE               RALT(KC_L)
#define DK_PND              RALT(LSFT(KC_4))
#define DK_EUR              RALT(KC_5)
