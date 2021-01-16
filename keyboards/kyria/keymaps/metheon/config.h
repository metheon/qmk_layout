#pragma once

// clang-format off
#define LAYOUT_metheon( \
        L11  ,L12  ,L13  ,L14  ,L15  ,R11  ,R12  ,R13  ,R14  ,R15  , \
        L21  ,L22  ,L23  ,L24  ,L25  ,R21  ,R22  ,R23  ,R24  ,R25  , \
        L31  ,L32  ,L33  ,L34  ,L35  ,R31  ,R32  ,R33  ,R34  ,R35  , \
                    L41  ,L42  ,L43  ,R41  ,R42  ,R43                \
    ) \
    LAYOUT( \
        KC_NO,L11  ,L12  ,L13  ,L14  ,L15                          ,R11  ,R12  ,R13  ,R14  ,R15  ,KC_NO, \
        KC_NO,L21  ,L22  ,L23  ,L24  ,L25                          ,R21  ,R22  ,R23  ,R24  ,R25  ,KC_NO, \
        KC_NO,L31  ,L32  ,L33  ,L34  ,L35  ,KC_NO,KC_NO,KC_NO,KC_NO,R31  ,R32  ,R33  ,R34  ,R35  ,KC_NO, \
                          L41  ,KC_NO,KC_NO,L42  ,L43  ,R41  ,R42  ,KC_NO,KC_NO,R43                      \
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
