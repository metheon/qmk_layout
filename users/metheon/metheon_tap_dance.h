#pragma once

enum tap_dance_functions {
    TD_CONTROL_CTRLSHIFT = 0,   // Once: Ctrl. Twice: ctrl+shift
};

#define TD_C_CS TD(TD_CONTROL_CTRLSHIFT)
