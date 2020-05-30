enum layers {
    _BASE,                  // Colemak
    _LOWER,                 // Shifted characters, mostly
    _RAISE,                 // Unshifted characters, mostly
    _ADJUST,                // Mainly RGB, activated when lower and raise is pressed at the same time
    _FUNPAD,                // F1 - F12
    _NUMPAD,                // A numpad
    _EXTEND,                // Home row mods, navigation cluster, window management
    _BL3_BSE,               // Base layer for Borderlands 3
    _BL3_UPR,               // Upper layer for Borderlands 3
};

// Layer keys
#define SPACE_FN            LT(_EXTEND, KC_SPACE)
#define ENTER_FN            LT(_EXTEND, KC_ENTER)
#define LOWER               MO(_LOWER)
#define RAISE               MO(_RAISE)
#define NUM_Z               LT(_NUMPAD, KC_Z)
#define FUN_SLSH            LT(_FUNPAD, KC_SLSH)

#define UNDO                LCTL(KC_Z)
#define REDO                LSFT(LCTL(KC_Z))
#define CUT                 LCTL(KC_X)
#define COPY                LCTL(KC_C)
#define PASTE               LCTL(KC_V)

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
#define ESC_MEH             MEH_T(KC_ESC)           // Esc on tap, meh on hold (I use that for virtual box)

// EurKey key combinations used on Windows for the Danish language
#define DK_EE               RALT(KC_G)
#define DK_AA               RALT(KC_W)
#define DK_AE               RALT(KC_Q)
#define DK_OE               RALT(KC_L)
#define DK_PND              RALT(KC_4)
#define DK_EUR              RALT(KC_5)

// All keys related to Borderlands 3
#define TO_BL3              TO(_BL3_BSE)
#define TO_BASE             TO(_BASE)
#define BL3_SPC             LT(_BL3_UPR, KC_SPACE)
#define BL3_W               LSFT(KC_W)              // BL3: Hold shift while pressing W to run instead of walking
