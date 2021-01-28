#pragma once

#include QMK_KEYBOARD_H

enum keycodes {
    KC_MAKE = SAFE_RANGE,   // make keyboard:user
    KC_FLASH,               // make keyboard:user:bootloader
    KC_VRSN,                // prints the version
    WHICH_OS,               // Prints which OS the keyboard is set to
    KC_AE,                  // Æ
    KC_OE,                  // Ø
    KC_AA,                  // Å
    KC_EUR,                 // €
    KC_PND,                 // £
    UNDO,
    CUT,
    COPY,
    PASTE,
    NEXT_WRD,               // Next word
    PREV_WRD,               // Previous word
    NEXT_WIN,               // Next window (alt tab / gui tab)
    PREV_WIN,               // Previous window (like above but shifted)
    TEXT_MOD,               // The mod used when moving around text, ctrl on windows, alt on mac
    LOCK,
    IJ_RNAME,
    IJ_TERM,
};
