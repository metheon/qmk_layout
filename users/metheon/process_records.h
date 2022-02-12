#pragma once

#include QMK_KEYBOARD_H
#include "caps_word.h"

enum keycodes {
    CAPSWORD = SAFE_RANGE,  // CAPITALIZES next word
    SNK_CASE,               // snake_case
    SCRM_SNK,               // SCREAMING_SNAKE_CASE
    CPS_DSBL,               // Disables any caps word mode
    CTRL,                   // One Shot Control
    ALT,                    // One Shot Alt
    SHIFT,                  // One Shot Shift
    GUI,                    // One Shot Command
};

