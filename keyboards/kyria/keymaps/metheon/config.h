#pragma once

#define LAYOUT_metheon( \
        L11, L12, L13, L14, L15, L16, R11, R12, R13, R14, R15, R16, \
        L21, L22, L23, L24, L25, L26, R21, R22, R23, R24, R25, R26, \
        L31, L32, L33, L34, L35, L36, R31, R32, R33, R34, R35, R36, \
        L41, L42, L43, L44, L45, L46, R41, R42, R43, R44, R45, R46, \
        E01, E02                                                    \
    ) \
    LAYOUT( \
      L11, L12, L13, L14, L15, L16,                       R11, R12, R13, R14, R15, R16, \
      L21, L22, L23, L24, L25, L26,                       R21, R22, R23, R24, R25, R26, \
      L31, L32, L33, L34, L35, L36, L41, L42,   R45, R46, R31, R32, R33, R34, R35, R36, \
                     E01, L43, L44, L46, L45,   R42, R41, R43, R44, E02                 \
    )
// clang-format on

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  #define RGBLIGHT_SLEEP
  #define RGBLIGHT_SPLIT
#endif

// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.
#define ENCODER_RESOLUTION 2

// Allows to use either side as the master. Look at the documentation for info:
// https://docs.qmk.fm/#/config_options?id=setting-handedness
#define EE_HANDS

// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 10

// Reverse encoder directionality
#define ENCODER_DIRECTION_FLIP
