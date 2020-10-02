#include QMK_KEYBOARD_H
#include "encoders.h"
#include "tap_dance.h"
#include "process_records.h"
#include "leader.h"

enum layers {
    _BASE,                  // Colemak
    _LOWER,                 // Shifted characters, mostly
    _RAISE,                 // Unshifted characters, mostly
    _ADJUST,                // Mainly RGB, activated when lower and raise is pressed at the same time
    _EXTEND,                // Home row mods, navigation cluster, window management, shortcuts
    _FUNPAD,                // F1 - F12
    _NUMPAD,                // A numpad
};

// Layer keys
#define SPACE_FN            LT(_EXTEND, KC_SPACE)
#define ENTER_FN            LT(_EXTEND, KC_ENTER)
#define LOWER               MO(_LOWER)
#define RAISE               MO(_RAISE)
#define LWR_DEL             LT(_LOWER, KC_DEL)
#define RSE_BSP             LT(_RAISE, KC_BSPC)
#define NUM_Z               LT(_NUMPAD, KC_Z)
#define FUN_SLSH            LT(_FUNPAD, KC_SLSH)

#define UNDO                LCTL(KC_Z)
#define REDO                LSFT(LCTL(KC_Z))
#define CUT                 LCTL(KC_X)
#define COPY                LCTL(KC_C)
#define PASTE               LCTL(KC_V)
#define COPY_T              LCTL(KC_INSERT)
#define PASTE_T             LSFT(KC_INSERT)

#define SPACES              LGUI(KC_TAB)            // I think it's called Desktops in Windows actually
#define LEFT_MON            LGUI(LSFT(KC_LEFT))     // Move window to left monitor
#define RGHT_MON            LGUI(LSFT(KC_RGHT))     // Move window to right monitor
#define LEFT_SPC            LGUI(LCTL(KC_LEFT))     // Move to left space
#define RGHT_SPC            LGUI(LCTL(KC_RGHT))     // Move to right space
#define WIN_MENU            LCTL(KC_ESC)            // Open the win menu
#define DESKTOP             LGUI(KC_D)              // Expose the Desktop
#define LFT_ALGN            LGUI(KC_LEFT)           // Align the window to the left half of the screen
#define RGT_ALGN            LGUI(KC_RGHT)           // Align the window to the right half of the screen
#define MAXIMIZE            LGUI(KC_UP)             // Maximize the window

#define VID_OFF             LCTL(LSFT(KC_O))        // Turns off camera in Teams
#define MIC_OFF             LCTL(LSFT(KC_M))        // Turns off microphone in Teams

#define LOCK_PC             LGUI(KC_L)              // Lock the PC
#define DEL_WRD             LCTL(KC_BSPC)           // Backwards delete a whole word
#define FILES               LGUI(KC_E)              // Open File Explorer

// Key combinations used on Windows for the Danish language using US International keyboard layout
#define DK_EE               RALT(KC_E)
#define DK_AA               RALT(KC_W)
#define DK_AE               RALT(KC_Z)
#define DK_OE               RALT(KC_L)
#define DK_PND              RALT(LSFT(KC_4))
#define DK_EUR              RALT(KC_5)
