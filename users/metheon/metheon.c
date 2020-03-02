#include QMK_KEYBOARD_H

#define UNDO        LCTL(KC_Z)
#define REDO        LSFT(LCTL(KC_Z))
#define CUT         LCTL(KC_X)
#define COPY        LCTL(KC_C)
#define PASTE       LCTL(KC_V)

// EurKey key combinations used on Windows for the Danish language
#define DK_EE       RALT(KC_G)
#define DK_AA       RALT(KC_W)
#define DK_AE       RALT(KC_Q)
#define DK_OE       RALT(KC_L)
#define DK_PND      RALT(KC_4)
#define DK_EUR      RALT(KC_5)

// OSM Mods
#define OSM_SFT     OSM(MOD_LSFT)
#define OSM_ALT     OSM(MOD_LALT)
#define OSM_WIN     OSM(MOD_LGUI)
#define OSM_CTL     OSM(MOD_LCTL)
#define OSM_HYP     OSM(MOD_HYPR)
#define OSM_MEH     OSM(MOD_MEH)

// Layers
#define SPACE_FN    LT(_EXTEND, KC_SPACE)
#define ENTER_FN    LT(_EXTEND, KC_ENTER)
#define LOWER       MO(_LOWER)
#define RAISE       MO(_RAISE)

// Utility
#define SPACES      LGUI(KC_TAB)        // I think it's called Desktops in Windows actually
#define LEFT_MON    LGUI(LSFT(KC_LEFT)) // Move window to left monitor
#define RGHT_MON    LGUI(LSFT(KC_RGHT)) // Move window to right monitor
#define LEFT_SPC    LGUI(LCTL(KC_LEFT)) // Move to left space
#define RGHT_SPC    LGUI(LCTL(KC_RGHT)) // Move to right space
#define WIN_MENU    LCTL(KC_ESC)        // Open the win menu
#define DESKTOP     LGUI(KC_D)          // Expose the Desktop
#define LFT_ALGN    LGUI(KC_LEFT)       // Align the window to the left half of the screen
#define RGT_ALGN    LGUI(KC_RGHT)       // Align the window to the right half of the screen
#define MAXIMIZE    LGUI(KC_UP)         // Maximize the window
#define VID_OFF     LCTL(LSFT(KC_O))    // Turns off camera in Teams
#define MIC_OFF     LCTL(LSFT(KC_M))    // Turns off microphone in Teams
#define LOCK_PC     LGUI(KC_L)          // Lock the PC
#define DEL_WRD     LCTL(KC_BSPC)       // Backwards delete a whole word
#define FILES       LGUI(KC_E)          // Open File Explorer

// Colors
#define ORANGE      {17,255,255}
#define YELLOW      {27,255,255}
#define BLUE        {172,255,255}
#define RED         {0,255,255}
#define PURPLE      {215,255,128}
#define GREEN       {86,255,128}

enum layers {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _EXTEND,
};

enum keycodes {
    WALLY = SAFE_RANGE,
    HIBRNT,
    SLEEP,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case WALLY:
        if (record->event.pressed) {
            SEND_STRING_DELAY(SS_LCTL(SS_TAP(X_ESCAPE)) SS_TAP(X_W) SS_TAP(X_A) SS_TAP(X_L) SS_TAP(X_ENTER), 200);
        }
        break;
    case HIBRNT:
        if (record->event.pressed) {
            SEND_STRING_DELAY(SS_LGUI(SS_TAP(X_X)) SS_TAP(X_U) SS_TAP(X_H), 200);
        }
        break;
    case SLEEP:
        if (record->event.pressed) {
            SEND_STRING_DELAY(SS_LGUI(SS_TAP(X_X)) SS_TAP(X_U) SS_TAP(X_S), 200);
        }
        break;
  }
  return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_metheon(
        KC_TAB  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_G    ,KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_BSPC ,
        KC_ESC  ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_D    ,KC_H    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_QUOT ,
        KC_LSFT ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,KC_K    ,KC_M    ,KC_COMMA,KC_DOT  ,KC_SLSH ,KC_RSFT ,
        OSM_MEH ,KC_NO   ,KC_LALT ,KC_LCTL ,LOWER   ,SPACE_FN,ENTER_FN,RAISE   ,KC_LCTL ,KC_LWIN ,DM_PLY1 ,DM_PLY2
    ),
    [_LOWER] = LAYOUT_metheon(
        KC_TILD ,KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,KC_DEL  ,
        XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,KC_F6   ,KC_UNDS ,KC_PLUS ,KC_LCBR ,KC_RCBR ,XXXXXXX ,
        XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,KC_F12  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_PIPE ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,LOWER   ,KC_ENTER,KC_ENTER,RAISE   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
    ),
    [_RAISE] = LAYOUT_metheon(
        KC_GRV  ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_DEL  ,
        KC_CAPS ,DK_EE   ,DK_AE   ,DK_OE   ,DK_AA   ,DK_PND  ,DK_EUR  ,KC_MINS ,KC_EQL  ,KC_LBRC ,KC_RBRC ,XXXXXXX ,
        XXXXXXX ,UNDO    ,CUT     ,COPY    ,PASTE   ,REDO    ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_BSLS ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,LOWER   ,KC_SPACE,KC_SPACE,RAISE   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
    ),
    [_ADJUST] = LAYOUT_metheon(
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        HIBRNT  ,RGB_VAI ,RGB_SAI ,RGB_HUI ,RGB_MOD ,RGB_TOG ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        SLEEP   ,RGB_VAD ,RGB_SAD ,RGB_HUD ,RGB_RMOD,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,RESET   ,RESET   ,KC_NO   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
    ),
    [_EXTEND] = LAYOUT_metheon(
        SPACES  ,LEFT_MON,RGHT_MON,LEFT_SPC,RGHT_SPC,XXXXXXX ,KC_PGUP ,KC_HOME ,KC_UP   ,KC_END  ,XXXXXXX ,DEL_WRD ,
        WIN_MENU,KC_LGUI ,KC_LALT ,KC_LSFT ,KC_LCTRL,DESKTOP ,KC_PGDN ,KC_LEFT ,KC_DOWN ,KC_RGHT ,XXXXXXX ,XXXXXXX ,
        KC_LSFT ,LFT_ALGN,RGT_ALGN,MAXIMIZE,VID_OFF ,XXXXXXX ,FILES   ,MIC_OFF ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
        LOCK_PC ,DM_RSTP ,KC_MPRV ,KC_MPLY ,KC_MNXT ,XXXXXXX ,XXXXXXX ,KC_VOLU ,KC_VOLD ,KC_MUTE ,DM_REC1 ,DM_REC2
    )
};
