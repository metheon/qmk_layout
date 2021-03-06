#pragma once

#include QMK_KEYBOARD_H
#include "caps_word.h"

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
    DEL_WRD,                // Delete a word, i.e., ctrl+backspace on Linux and alt+backspace on mac
    LOCK,
    SEARCH,
    NXT_DSKT,               // Next Desktop
    PRV_DSKT,               // Previous Desktop
    OVERVIEW,               // See all windows on a desktop
    IJ_RNAME,
    IJ_TERM,
    CAPSWORD,               // CAPITALIZES next word
    SNK_CASE,               // snake_case
    SCRM_SNK,               // SCREAMING_SNAKE_CASE
    CPS_DSBL,               // Disables any caps word mode
    // SECRETS
    SECRET00,
    SECRET01,
    SECRET02,
    SECRET03,
    SECRET04,
    SECRET05,
    SECRET06,
    SECRET07,
    SECRET08,
    SECRET09,
    SECRET10,
    SECRET11,
    SECRET12,
    SECRET13,
    SECRET14,
    SECRET15,
    SECRET16,
    SECRET17,
    SECRET18,
    SECRET19,
};

bool tap_kc_ae(bool key_down);
bool tap_kc_oe(bool key_down);
bool tap_kc_aa(bool key_down);

