// clang-format off
#define LAYOUT_metheon( \
        L11, L12, L13, L14, L15, L16, R11, R12, R13, R14, R15, R16, \
        L21, L22, L23, L24, L25, L26, R21, R22, R23, R24, R25, R26, \
        L31, L32, L33, L34, L35, L36, R31, R32, R33, R34, R35, R36, \
        L41, L42, L43, L44, L45, L46, R41, R42, R43, R44, R45, R46  \
    ) \
    LAYOUT_planck_1x2uC( \
        L11, L12, L13, L14, L15, L16, R11, R12, R13, R14, R15, R16, \
        L21, L22, L23, L24, L25, L26, R21, R22, R23, R24, R25, R26, \
        L31, L32, L33, L34, L35, L36, R31, R32, R33, R34, R35, R36, \
        L41, L42, L43, L44, L45, L46,      R42, R43, R44, R45, R46  \
    )
// clang-format on

#include "metheon.c"
#include "eeprom.h"

extern bool         g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) { rgb_matrix_enable(); }

// clang-format off
const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [_LOWER] = {BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE, BLUE},

    [_RAISE] = {RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED, RED},

    [_ADJUST] = {PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE, PURPLE},

    [_EXTEND] = {GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN, GREEN}
};
// clang-format on

void set_layer_color(int layer) {
    for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color(i, 0, 0, 0);
        } else {
            RGB   rgb = hsv_to_rgb(hsv);
            float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
        }
    }
}

void rgb_matrix_indicators_user(void) {
    if (g_suspend_state || keyboard_config.disable_layer_led) {
        return;
    }
    switch (biton32(layer_state)) {
        case 1:
            set_layer_color(1);
            break;
        case 2:
            set_layer_color(2);
            break;
        case 3:
            set_layer_color(3);
            break;
        case 4:
            set_layer_color(4);
            break;
        case 5:
            set_layer_color(5);
            break;
        case 7:
            set_layer_color(7);
            break;
        case 8:
            set_layer_color(8);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}
