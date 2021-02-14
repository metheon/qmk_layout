#pragma once

#include QMK_KEYBOARD_H
#include "process_records.h"

// tap dance declarations
enum {
    TD_SCLN_AE,
    TD_MINS_OE,
    TD_QUOT_AA,
};

// tap dance defines (to be used in keymap)
#define TD_SCLN     TD(TD_SCLN_AE)
#define TD_MINS     TD(TD_MINS_OE)
#define TD_QUOT     TD(TD_QUOT_AA)

