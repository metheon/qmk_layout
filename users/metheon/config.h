#pragma once

#ifdef TAPPING_TERM
#	undef TAPPING_TERM
#endif
#define TAPPING_TERM        200

#define ONESHOT_TIMEOUT     2500
#define ONESHOT_TAP_TOGGLE  3

// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.
#define ENCODER_RESOLUTION  2

#define PERMISSIVE_HOLD
