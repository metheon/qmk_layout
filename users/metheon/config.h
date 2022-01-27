#pragma once

#define COMBO_TERM                  30

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD_PER_KEY
// Allow per key configuration for individual keys
#define TAPPING_TERM_PER_KEY

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN           4

#define ONESHOT_TIMEOUT             2000

// The Leader key allows to flexibly assign macros to key sequences.
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT              750
