enum layers {
    _BASE,                  // Colemak
    _LOWER,                 // Shifted characters, mostly
    _RAISE,                 // Unshifted characters, mostly
    _ADJUST,                // Mainly RGB, activated when lower and raise is pressed at the same time
    _EXTEND,                // Home row mods, navigation cluster, window management
};

enum keycodes {
    HIBRNT = SAFE_RANGE,    // Hibernate the computer
    SLEEP,                  // Sleep the computer
};

// Layer keys
#define SPACE_FN            LT(_EXTEND, KC_SPACE)
#define ENTER_FN            LT(_EXTEND, KC_ENTER)
#define LOWER               MO(_LOWER)
#define RAISE               MO(_RAISE)
