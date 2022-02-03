#include "process_records.h"
#include "window_tab.h"
#include "metheon.h"

#undef TEXT
#define TEXT(name, text)            \
    case name:                      \
        if(pressed) {               \
            SEND_STRING(text);      \
        }                           \
        break;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // caps word related processing
    if (!process_caps_word(keycode, record)) {
        return false;
    }

    const bool pressed = record->event.pressed;
    switch (keycode) {
        #include "text.def"
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
        // cmd+shift+tab
        case PREV_WIN:
            if (pressed) {
                mod_tab(record, 1);
            }
            break;
        // cmd+tab
        case NEXT_WIN:
            if (pressed) {
                mod_tab(record, 0);
            }
            break;
        // one shot shift w/ layer
        case SFT_NUM:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    set_oneshot_mods(MOD_LSFT);
                }
                return false;
            }
        default:
            // return true to keep processing the key
            return true;
    }
    // return false to ignore further processing of the key
    return false;
};
