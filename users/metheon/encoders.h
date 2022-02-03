#include "metheon.h"

// Encoder tap functions
#define BSE_E01             KC_NO
#define BSE_E02             KC_MUTE

#define NAV_E01             KC_NO
#define NAV_E02             KC_NO

#define NUM_E01             LGUI(KC_W) // close tab
#define NUM_E02             KC_NO

// Required for cmd-tab function
void matrix_scan_encoders(void);
