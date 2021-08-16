/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

// #include QMK_KEYBOARD_H
#include "5x6_t.h"


#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MAC 3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define MAC MO(_MAC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_EQL , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLASH,
     KC_ESC , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
     RGB_TOG, KC_GRV,KC_NUBS,KC_LEFT, KC_RGHT,                                        KC_UP, KC_DOWN, KC_LBRC,  KC_RBRC, RGB_TOG,
                                      KC_LGUI,MAC,                          LOWER, KC_RGUI,
                                            KC_LALT,                          KC_RALT,
                                KC_BSPC,KC_DEL, KC_LCTRL,                     KC_RCTRL, KC_ENT, KC_SPC
  ),

  [_LOWER] = LAYOUT_5x6(
     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,KC_PLUS,
     _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,KC_PIPE,
     _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
     _______,_______,_______,_______,_______,                                         KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                             _______,KC_PSCR,            _______, KC_P0,
                                                     _______,            _______,
                                     _______,_______,_______,            _______,_______,_______

  ),

  [_RAISE] = LAYOUT_5x6(
       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,KC_MUTE,
       _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
       _______,_______,_______,_______,_______,                                         KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                               _______,_______,            KC_EQL ,_______,
                                                       _______,            _______,
                                       _______,_______,_______,            _______,_______,_______
  ),

    [_MAC] = LAYOUT_5x6(
       _______,KC_BRID , KC_BRIU , KC_MUTE , KC_VOLD , KC_VOLU,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,KC_MUTE,
       _______,KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                        KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,_______,KC_VOLU,
       _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,KC_VOLD,
       _______,_______,_______,_______,_______,                                         KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,KC_UNDS,
                                               _______,_______,            KC_EQL ,_______,
                                                       _______,            _______,
                                       _______,_______,_______,            _______,_______,_______
  ),
};


void update_led(void) {
  // Capslock priority
  if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
    rgblight_setrgb(RGB_WHITE);
  } else {
    // look layer...
    switch (biton32(layer_state)) {
      case 1:
        rgblight_sethsv_noeeprom(0, 255, 255);
//         rgblight_setrgb(RGB_RED);
        break;
      case 2:
        rgblight_sethsv_noeeprom(100, 255, 255);
//         rgblight_setrgb(RGB_BLUE);
        break;
      case 3:
              rgblight_sethsv_noeeprom(150, 255, 255);
//         rgblight_setrgb(RGB_GREEN);
        break;
      default:
//         rgblight_setrgb(RGB_YELLOW);
        rgblight_sethsv_noeeprom(200, 255, 255);
        break;
    }
  }
}


layer_state_t layer_state_set_user(layer_state_t state) {
//     update_led();
            rgblight_sethsv_noeeprom(0, 255, 10);

    return state;
}

void keyboard_post_init_user(void) {
  rgblight_enable(); // Enable RGB by default
//   rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2);
  rgblight_enable_noeeprom();
//   rgblight_layers = my_rgb_layers;
            rgblight_sethsv_noeeprom(0, 255, 10);

}

/*
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _MAC));
    return state;
}

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {0, 10, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_PURPLE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 10, HSV_GREEN}
);
// etc..

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
//   rgblight_enable(); // Enable RGB by default
  // rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2);
//   rgblight_enable_noeeprom();
  rgblight_layers = my_rgb_layers;
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
  // use the non noeeprom versions, to write these values to EEPROM too
  rgblight_enable(); // Enable RGB by default
  rgblight_sethsv_white();  // Set it to white by default
  rgblight_mode(RGBLIGHT_MODE_BREATHING); // set to breathing by default
}
*/
