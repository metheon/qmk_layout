#include QMK_KEYBOARD_H

#include "metheon.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_preonic_grid_wrapper(
        _______RAISE_1_________,
        _______BASE_1__________,
        _______BASE_2__________,
        _______BASE_3__________,
        _______BASE_4__________
        ),

    [_LOWER] = LAYOUT_preonic_grid_wrapper(
        _______NONE____________,
        _______LOWER_1_________,
        _______LOWER_2_________,
        _______LOWER_3_________,
        _______LOWER_4_________
        ),

    [_RAISE] = LAYOUT_preonic_grid_wrapper(
        _______NONE____________,
        _______RAISE_1_________,
        _______RAISE_2_________,
        _______RAISE_3_________,
        _______RAISE_4_________
        ),

    [_ADJUST] = LAYOUT_preonic_grid_wrapper(
        _______NONE____________,
        _______ADJUST_1________,
        _______ADJUST_2________,
        _______ADJUST_3________,
        _______ADJUST_4________
        ),

    [_MOVE] = LAYOUT_preonic_grid_wrapper(
        _______NONE____________,
        _______MOVE_1__________,
        _______MOVE_2__________,
        _______MOVE_3__________,
        _______MOVE_4__________
        ),

    [_NUMPAD] = LAYOUT_preonic_grid_wrapper(
        _______NONE____________,
        _______NUMPAD_1________,
        _______NUMPAD_2________,
        _______NUMPAD_3________,
        _______NUMPAD_4________
        ),
};

