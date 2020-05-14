#pragma once

enum tap_dance_functions {
    TD_CONTROL_CTRLSHIFT = 0,   // Once: Ctrl. Twice: ctrl+shift
    TD_ALT_NUMPAD,              // Once: Alt. Twice: Toggle numpad layer
    TD_GUI_FUNPAD,              // Once: Gui. Twice: Toggle funpad layer
};

#define TD_CTRL     TD(TD_CONTROL_CTRLSHIFT)
#define TD_ALT      TD(TD_ALT_NUMPAD)
#define TD_GUI      TD(TD_GUI_FUNPAD)
