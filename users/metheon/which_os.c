#include "which_os.h"

bool is_mac(void) {
    return keymap_config.swap_lctl_lgui;
}

bool is_windows(void) {
    return !is_mac();
}
