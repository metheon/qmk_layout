#pragma once

// clang-format off
#define LAYOUT_metheon( \
        L00   ,L01   ,L02   ,L03   ,L04   ,R04   ,R03   ,R02   ,R01   ,R00   , \
        L10   ,L11   ,L12   ,L13   ,L14   ,R14   ,R13   ,R12   ,R11   ,R10   , \
        L20   ,L21   ,L22   ,L23   ,L24   ,R24   ,R23   ,R22   ,R21   ,R20   , \
                      ENC01 ,L30   ,L31   ,R31   ,R30   ,ENC02                 \
    ) \
    LAYOUT( \
        KC_NO ,L00   ,L01   ,L02   ,L03   ,L04                               ,R04   ,R03   ,R02   ,R01   ,R00   ,KC_NO , \
        KC_NO ,L10   ,L11   ,L12   ,L13   ,L14                               ,R14   ,R13   ,R12   ,R11   ,R10   ,KC_NO , \
        KC_NO ,L20   ,L21   ,L22   ,L23   ,L24   ,KC_NO ,KC_NO ,KC_NO ,KC_NO ,R24   ,R23   ,R22   ,R21   ,R20   ,KC_NO , \
                             ENC01 ,KC_NO ,L30   ,L31   ,KC_NO ,KC_NO ,R31   ,R30   ,KC_NO ,ENC02                        \
    )
// clang-format on

#ifdef RGBLIGHT_ENABLE
//  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_EFFECT_BREATHING
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
