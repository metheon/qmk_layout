#pragma once

#include QMK_KEYBOARD_H
#include "caps_word.h"

#undef OSKEY
#define OSKEY(name, linux, mac) name,

enum keycodes {
    KC_MAKE = SAFE_RANGE,   // make keyboard:user
    KC_FLASH,               // make keyboard:user:bootloader
    KC_VRSN,                // prints the version
    NEXT_WIN,               // Next window (alt tab / gui tab)
    PREV_WIN,               // Previous window (like above but shifted)
    CAPSWORD,               // CAPITALIZES next word
    SNK_CASE,               // snake_case
    SCRM_SNK,               // SCREAMING_SNAKE_CASE
    CPS_DSBL,               // Disables any caps word mode
#include "oskeys.def"       // include all keys that change between OS'es
};

