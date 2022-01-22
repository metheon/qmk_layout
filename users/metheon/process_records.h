#pragma once

#include QMK_KEYBOARD_H
#include "caps_word.h"

#undef TEXT
#define TEXT(name, text) name,

enum keycodes {
    CAPSWORD = SAFE_RANGE,  // CAPITALIZES next word
    SNK_CASE,               // snake_case
    SCRM_SNK,               // SCREAMING_SNAKE_CASE
    CPS_DSBL,               // Disables any caps word mode
    PREV_WIN,               // Gui + shift + tab
    NEXT_WIN,               // Gui + tab
#include "text.def"
};

