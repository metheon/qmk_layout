#pragma once

// Encoder tap functions
#define BSE_E01             MO(_ADJUST)
#define BSE_E02             KC_NO
#define LWR_E01             KC_MUTE
#define LWR_E02             KC_NO
#define RSE_E01             KC_NO
#define RSE_E02             KC_NO
#define ADJ_E01             KC_TRNS
#define ADJ_E02             KC_TRNS
#define EXT_E01             KC_NO
#define EXT_E02             KC_MPLY

// Required for alt-tab function
void matrix_scan_fn(void);
