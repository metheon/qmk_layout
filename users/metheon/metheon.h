#include QMK_KEYBOARD_H
#include "encoders.h"
#include "process_records.h"
#include "leader.h"
#include "magnet.h"

enum layers {
    _BASE,                  // Colemak
    _LOWER,                 // A funpad and a numpad
    _RAISE,                 // Symbols
    _ADJUST,                // Mainly RGB, activated when lower and raise is pressed at the same time
    _EXTEND,                // Home row mods, navigation cluster
    _MOUSE,                 // Layer for mouse
    _MAGNET,                // Layer https://magnet.crowdcafe.com/
};

#define __NONE__            KC_NO

// Base layer thumb cluster from left side, left hand, to right side, right hand
#define TAB_LWR             LT(_LOWER, KC_TAB)
#define SPC_EXT             LT(_EXTEND, KC_SPACE)
#define ENT_RSE             LT(_RAISE, KC_ENTER)
#define DEL_RSE             LT(_RAISE, KC_DEL)
#define BSPC_MSE            LT(_MOUSE, KC_BSPC)
#define ESC_LWR             LT(_LOWER, KC_ESC)
#define M_MAG               LT(_MAGNET, KC_M)

// Home row mods, using Colemak ... arst <--> neio
#define HOME_A              LCTL_T(KC_A)
#define HOME_R              LALT_T(KC_R)
#define HOME_S              LSFT_T(KC_S)
#define HOME_T              LGUI_T(KC_T)
#define HOME_N              LGUI_T(KC_N)
#define HOME_E              LSFT_T(KC_E)
#define HOME_I              LALT_T(KC_I)
#define HOME_O              LCTL_T(KC_O)

// Home row mods, for the numpad and funpad ... ( F6, F5, F4 <--> 4 5 6 -
#define HOME_ENT            LCTL_T(KC_ENTER)
#define HOME_F5             LALT_T(KC_F5)
#define HOME_F6             LSFT_T(KC_F6)
#define HOME_F7             LGUI_T(KC_F7)
#define HOME_4              LGUI_T(KC_4)
#define HOME_5              LSFT_T(KC_5)
#define HOME_6              LALT_T(KC_6)
#define HOME_MN             LCTL_T(KC_MINS)

#define UNDO                LGUI(KC_Z)
#define CUT                 LGUI(KC_X)
#define COPY                LGUI(KC_C)
#define PASTE               LGUI(KC_V)
#define COPY_T              LCTL(KC_INSERT)
#define PASTE_T             LSFT(KC_INSERT)

#define OSM_SFT             OSM(MOD_LSFT)

#define KC_AA               RALT(KC_A)
#define KC_OE               RALT(KC_O)
#define KC_AE               RALT(KC_QUOT)
#define KC_EUR              LSFT(KC_4)
