#include QMK_KEYBOARD_H

#include "metheon.h"

#define __BASE_ROW_1___     __RAISE_L1________, __RAISE_R1________
#define __BASE_ROW_2___     __BASE_L1_________, __BASE_R1_________
#define __BASE_ROW_3___     __BASE_L2_________, __BASE_R2_________
#define __BASE_ROW_4___     __BASE_L3_________, __BASE_R3_________
#define __BASE_ROW_5___     __BASE_L4_________, __BASE_L4_MID_____, __BASE_R4_MID_____, __BASE_R4_________

#define __LOWER_ROW_1__     __TRNS_12_COLUMN__
#define __LOWER_ROW_2__     __LOWER_L1________, __LOWER_R1________
#define __LOWER_ROW_3__     __LOWER_L2________, __LOWER_R2________
#define __LOWER_ROW_4__     __LOWER_L3________, __LOWER_R3________
#define __LOWER_ROW_5__     __LOWER_L4________, __LOWER_L4_MID____, __LOWER_R4_MID____, __LOWER_R4________

#define __RAISE_ROW_1__     __TRNS_12_COLUMN__
#define __RAISE_ROW_2__     __RAISE_L1________, __RAISE_R1________
#define __RAISE_ROW_3__     __RAISE_L2________, __RAISE_R2________
#define __RAISE_ROW_4__     __RAISE_L3________, __RAISE_R3________
#define __RAISE_ROW_5__     __RAISE_L4________, __RAISE_L4_MID____, __RAISE_R4_MID____, __RAISE_R4________

#define __ADJUST_ROW_1_     __TRNS_12_COLUMN__
#define __ADJUST_ROW_2_     __ADJUST_L1_______, __ADJUST_R1_______
#define __ADJUST_ROW_3_     __ADJUST_L2_______, __ADJUST_R2_______
#define __ADJUST_ROW_4_     __ADJUST_L3_______, __ADJUST_R3_______
#define __ADJUST_ROW_5_     __ADJUST_L4_______, __ADJUST_L4_MID___, __ADJUST_R4_MID___, __ADJUST_R4_______

#define __MOVE_ROW_1___     __TRNS_12_COLUMN__
#define __MOVE_ROW_2___     __MOVE_L1_________, __MOVE_R1_________
#define __MOVE_ROW_3___     __MOVE_L2_________, __MOVE_R2_________
#define __MOVE_ROW_4___     __MOVE_L3_________, __MOVE_R3_________
#define __MOVE_ROW_5___     __MOVE_L4_________, __MOVE_L4_MID_____, __MOVE_R4_MID_____, __MOVE_R4_________

#define __NUMPAD_ROW_1_     __TRNS_12_COLUMN__
#define __NUMPAD_ROW_2_     __NUMPAD_L1_______, __NUMPAD_R1_______
#define __NUMPAD_ROW_3_     __NUMPAD_L2_______, __NUMPAD_R2_______
#define __NUMPAD_ROW_4_     __NUMPAD_L3_______, __NUMPAD_R3_______
#define __NUMPAD_ROW_5_     __NUMPAD_L4_______, __NUMPAD_L4_MID___, __NUMPAD_R4_MID___, __NUMPAD_R4_______

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_preonic_grid_wrapper(
        __BASE_ROW_1___,
        __BASE_ROW_2___,
        __BASE_ROW_3___,
        __BASE_ROW_4___,
        __BASE_ROW_5___
        ),

    [_LOWER] = LAYOUT_preonic_grid_wrapper(
        __LOWER_ROW_1__,
        __LOWER_ROW_2__,
        __LOWER_ROW_3__,
        __LOWER_ROW_4__,
        __LOWER_ROW_5__
        ),

    [_RAISE] = LAYOUT_preonic_grid_wrapper(
        __RAISE_ROW_1__,
        __RAISE_ROW_2__,
        __RAISE_ROW_3__,
        __RAISE_ROW_4__,
        __RAISE_ROW_5__
        ),

    [_ADJUST] = LAYOUT_preonic_grid_wrapper(
        __ADJUST_ROW_1_,
        __ADJUST_ROW_2_,
        __ADJUST_ROW_3_,
        __ADJUST_ROW_4_,
        __ADJUST_ROW_5_
        ),

    [_MOVE] = LAYOUT_preonic_grid_wrapper(
        __MOVE_ROW_1___,
        __MOVE_ROW_2___,
        __MOVE_ROW_3___,
        __MOVE_ROW_4___,
        __MOVE_ROW_5___
        ),

    [_NUMPAD] = LAYOUT_preonic_grid_wrapper(
        __NUMPAD_ROW_1_,
        __NUMPAD_ROW_2_,
        __NUMPAD_ROW_3_,
        __NUMPAD_ROW_4_,
        __NUMPAD_ROW_5_
        ),
};

