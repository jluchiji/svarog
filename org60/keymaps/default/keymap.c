#include "svarog.h"


/**
 * Keypress handler assignments
 */
enum function_id {
    SHIFT_ESC,
};
const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_FUNCTION(SHIFT_ESC),
};
  

/**
 * Keyboard layout and key assignments
 */
 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    /**
    * Base layer
    */
    KEYMAP(
        F(0),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_NO,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,           KC_BSLS,
        MO(1),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NO,             KC_ENT,
        KC_LSFT, KC_NO,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,    MO(1),
        KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                                      KC_RALT, KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT),
    
    /**
    * Fn + Key
    */
    KEYMAP(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,   KC_DEL,   KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,            KC_GRV,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT,KC_TRNS, KC_GRV,   BL_DEC,             KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  RGB_TOG,  KC_PGUP,  KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                                     KC_TRNS, KC_TRNS,  KC_HOME,  KC_PGDN,  KC_END),
    
};


/**
 * Shift + Esc prints a '~' character
 */
void shift_esc(keyrecord_t * record, uint8_t isShiftPressed) {
    uint16_t keycode = isShiftPressed ? KC_GRV : KC_ESC;
    if (record->event.pressed) {
        add_key(keycode);
    } else {
        del_key(keycode);
    }
    send_keyboard_report();
}


/**
 * Action handler resolver
 */
void action_function(keyrecord_t * record, uint8_t actionId, uint8_t options) {
    uint8_t isShiftPressed = get_mods() & (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT));
  
    switch (actionId) {
    case SHIFT_ESC:
        shift_esc(record, isShiftPressed);
        break;
    } 
}
