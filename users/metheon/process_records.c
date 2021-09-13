#include "process_records.h"
#include "window_tab.h"
#include "metheon.h"

#undef VIM
#define VIM(name, command)              \
    case name:                          \
        if(pressed) {                   \
            SEND_STRING(command);       \
        }                               \
        break;

#undef BIGRAM
#define BIGRAM(name, bigram)            \
    case name:                          \
        if(pressed) {                   \
            SEND_STRING(bigram);        \
        }                               \
        break;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // caps word related processing
    if (!process_caps_word(keycode, record)) {
        return false;
    }

    const bool pressed = record->event.pressed;
    switch (keycode) {
        // caps word related cases (start and stop modes)
        case CPS_DSBL:
            if(pressed) {
                disable_all();
            }
            break;
        case SCRM_SNK:
            if(pressed) {
                toggle_screaming_snake_case();
            }
            break;
        case SNK_CASE:
            if (pressed) {
                toggle_snake_case();
            }
            break;
        case CAPSWORD:
            if (pressed) {
                toggle_caps_word();
            }
            break;
#include "vim.def"
#include "bigram.def"
        default:
            return true;
    }
    return false;
};
