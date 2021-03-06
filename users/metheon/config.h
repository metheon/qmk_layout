#pragma once
#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define TAPPING_TERM                400

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD_PER_KEY
#define TAPPING_TERM_PER_KEY

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN           4

#define ONESHOT_TIMEOUT             2000
#define ONESHOT_TAP_TOGGLE          5

// The Leader key allows to flexibly assign macros to key sequences.
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT              750

