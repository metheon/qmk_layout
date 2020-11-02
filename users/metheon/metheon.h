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
#define SPC_EXT             LT(_EXTEND, KC_SPACE)
#define LWR_DEL             LT(_LOWER, KC_DEL)
#define RSE_BSP             LT(_RAISE, KC_BSPC)
#define ENT_SFT             LSFT_T(KC_ENTER)

// Home row mods, using Colemak ... arst <--> neio
// As I use a GUI/Super heavy UI for Linux I have decided to mirror the order from Apples keyboards: shift ctrl alt gui <--> gui alt ctrl shift
#define A_SFT               LSFT_T(KC_A)
#define R_CTL               LCTL_T(KC_R)
#define S_ALT               LALT_T(KC_S)
#define T_GUI               LGUI_T(KC_T)
#define N_GUI               LGUI_T(KC_N)
#define E_ALT               LALT_T(KC_E)
#define I_CTL               LCTL_T(KC_I)
#define O_SFT               LSFT_T(KC_O)

// Home row mods, for the numpad and funpad ... F6, F5, F4 <--> 4 5 6
#define F6_CTL              LCTL_T(KC_F6)
#define F5_ALT              LALT_T(KC_F5)
#define F4_GUI              LGUI_T(KC_F4)
#define _4_GUI              LGUI_T(KC_4)
#define _5_ALT              LALT_T(KC_5)
#define _6_CTL              LCTL_T(KC_6)

#define UNDO                LCTL(KC_Z)
#define REDO                LSFT(LCTL(KC_Z))
#define CUT                 LCTL(KC_X)
#define COPY                LCTL(KC_C)
#define PASTE               LCTL(KC_V)
#define COPY_T              LCTL(KC_INSERT)
#define PASTE_T             LSFT(KC_INSERT)

#define OSM_SFT             OSM(MOD_LSFT)

//#define SPACES              LGUI(KC_TAB)            // I think it's called Desktops in Windows actually
//#define LEFT_MON            LGUI(LSFT(KC_LEFT))     // Move window to left monitor
//#define RGHT_MON            LGUI(LSFT(KC_RGHT))     // Move window to right monitor
//#define LEFT_SPC            LGUI(LCTL(KC_LEFT))     // Move to left space
//#define RGHT_SPC            LGUI(LCTL(KC_RGHT))     // Move to right space
//#define WIN_MENU            LCTL(KC_ESC)            // Open the win menu
//#define DESKTOP             LGUI(KC_D)              // Expose the Desktop
//#define LFT_ALGN            LGUI(KC_LEFT)           // Align the window to the left half of the screen
//#define RGT_ALGN            LGUI(KC_RGHT)           // Align the window to the right half of the screen
//#define MAXIMIZE            LGUI(KC_UP)             // Maximize the window

//#define VID_OFF             LCTL(LSFT(KC_O))        // Turns off camera in Teams
//#define MIC_OFF             LCTL(LSFT(KC_M))        // Turns off microphone in Teams

//#define LOCK_PC             LGUI(KC_L)              // Lock the PC
//#define DEL_WRD             LCTL(KC_BSPC)           // Backwards delete a whole word
//#define FILES               LGUI(KC_E)              // Open File Explorer

// Key combinations used on Windows for the Danish language using US International keyboard layout
#define DK_EE               RALT(KC_E)
#define DK_AA               RALT(KC_W)
#define DK_AE               RALT(KC_Z)
#define DK_OE               RALT(KC_L)
#define DK_PND              RALT(LSFT(KC_4))
#define DK_EUR              RALT(KC_5)
