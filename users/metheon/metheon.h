#include QMK_KEYBOARD_H
#include "encoders.h"
#include "process_records.h"
#include "leader.h"
#include "magnet.h"

enum layers {
    _BASE,                  // Colemak-DH
    _LOWER,                 // A funpad and a numpad
    _RAISE,                 // Symbols mostly
    _ADJUST,                // Mainly RGB and media keys, activated when lower and raise is pressed at the same time
    _EXTEND,                // Home row mods, navigation cluster
    _MAGNET,                // Layer https://magnet.crowdcafe.com/
};

#define __NONE__            KC_NO
#define ________            _______

#define DEL_LWR             LT(_LOWER, KC_DEL)
#define BSPC_RSE            LT(_RAISE, KC_BSPC)
#define SPC_EXT             LT(_EXTEND, KC_SPACE)
#define ENT_EXT             LT(_RAISE, KC_ENTER)
#define MAGNET              OSL(_MAGNET)

#define UNDO                LGUI(KC_Z)
#define CUT                 LGUI(KC_X)
#define COPY                LGUI(KC_C)
#define PASTE               LGUI(KC_V)
#define COPY_T              LCTL(KC_INSERT)
#define PASTE_T             LSFT(KC_INSERT)

#define KC_AA               RALT(KC_A)
#define KC_OE               RALT(KC_O)
#define KC_AE               RALT(KC_QUOT)
#define KC_PND              RALT(KC_3)
#define KC_EUR              LSFT(RALT(KC_4))
