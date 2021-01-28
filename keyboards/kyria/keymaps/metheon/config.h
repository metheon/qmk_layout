#pragma once

// The Kyria maps 1:1 to Kyria but we need the name change (LAYOUT_metheon instead of LAYOUT)
// clang-format off
#define LAYOUT_metheon( \
        L00   ,L01   ,L02   ,L03   ,L04   ,L05                                    ,R05   ,R04   ,R03   ,R02   ,R01   ,R00   , \
        L10   ,L11   ,L12   ,L13   ,L14   ,L15                                    ,R15   ,R14   ,R13   ,R12   ,R11   ,R10   , \
        L20   ,L21   ,L22   ,L23   ,L24   ,L25   ,L26   ,L27        ,R27   ,R26   ,R25   ,R24   ,R23   ,R22   ,R21   ,R20   , \
                             L30   ,L31   ,L32   ,L33   ,L34        ,R34   ,R33   ,R32   ,R31   ,R30                          \
    ) \
    LAYOUT( \
        L00   ,L01   ,L02   ,L03   ,L04   ,L05                                    ,R05   ,R04   ,R03   ,R02   ,R01   ,R00   , \
        L10   ,L11   ,L12   ,L13   ,L14   ,L15                                    ,R15   ,R14   ,R13   ,R12   ,R11   ,R10   , \
        L20   ,L21   ,L22   ,L23   ,L24   ,L25   ,L26   ,L27        ,R27   ,R26   ,R25   ,R24   ,R23   ,R22   ,R21   ,R20   , \
                             L30   ,L31   ,L32   ,L33   ,L34        ,R34   ,R33   ,R32   ,R31   ,R30                          \
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
