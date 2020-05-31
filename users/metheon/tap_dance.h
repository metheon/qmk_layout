#pragma once

enum tap_dance_functions {
    TD_CONTROL_CTRLSHIFT = 0,   // Once: Ctrl. Twice: ctrl+shift
    TD_ALT_GUI,                 // Once: Alt. Twice: Toggle numpad layer
    TD_GUI_ALT,                 // Once: Gui. Twice: Toggle funpad layer
};

#define TD_CTRL      TD(TD_CONTROL_CTRLSHIFT)
#define ALT_GUI      TD(TD_ALT_GUI)
#define GUI_ALT      TD(TD_GUI_ALT)
