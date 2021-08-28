/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _LOWER 1
#define _NAVLAY 2
#define _RGBLAY 3

#define LOWER MO(_LOWER)
#define NAVLAY TT(_NAVLAY)
#define RGBLAY MO(_RGBLAY)

/*
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
  //debug_mouse=true;
//   xprintf("testtttt")

  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  rgblight_sethsv_noeeprom(180, 255, 255); // sets the color to teal/cyan without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 2); // sets mode to Fast breathing
}
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_ESC , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,LT(RGBLAY,KC_BSPC),
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  , KC_LBRC ,
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RCTL,
                      KC_LGUI,KC_LALT,                                                       KC_RALT, KC_RGUI,
                                       KC_SPC,KC_BSPC,                        KC_ESC,KC_ENT,
                                       LOWER,NAVLAY,                         NAVLAY,  LOWER,
                                      _______, _______,                        KC_LGUI, KC_LALT
  ),

  [_LOWER] = LAYOUT_5x6(

     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                         KC_P7 , KC_P8 , KC_P9 ,KC_LPRN,KC_RPRN,,KC_PLUS,
     KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,_______,                         KC_P4 , KC_P5 , KC_P6 ,KC_LBRC,KC_RBRC,KC_MINS,
     _______,_______,_______,_______,_______,_______,                         KC_P1 , KC_P2 , KC_P3 ,KC_LT ,KC_RT,_______,
                     _______, KC_PSCR ,																									      KC_P0, _______,
                                             _______,_______,           _______,_______,
                                            _______ , _______ ,				  _______,_______,
																						_______ ,_______,					  _______,_______

  ),
  [_NAVLAY] = LAYOUT_5x6(

     KC_NO	,KC_NO	, KC_NO ,KC_WH_U,KC_NO	,KC_NO,                        KC_NO,KC_NO,KC_NO,KC_NO,KC_NO,KC_MUTE,
     _______,_______,_______,KC_MS_U,_______,KC_NO,                        KC_HOME,KC_PGUP,KC_PGDN,KC_END,_______,KC_VOLU,
     _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,KC_NO,                        KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,KC_MINS,KC_VOLD,
     _______,_______,KC_WH_L,KC_WH_D,KC_WH_R,_______,                        KC_MPRV,KC_MPLY,KC_MNXT,_______ ,_______,_______ ,
                      _______,_______,																						 						_______,_______,
                                             KC_BTN1,KC_BTN2,            KC_BTN1,KC_BTN2,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),
  [_RGBLAY] = LAYOUT_5x6(

     RGB_MODE_RAINBOW,RGB_MODE_SWIRL, RGB_MODE_SNAKE ,RGB_MODE_KNIGHT,RGB_MODE_XMAS ,RGB_MODE_GRADIENT,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,_______,RGB_VAI,
     _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,RGB_VAD,
     _______,_______,_______,_______,_______,_______,                        _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL ,_______,
                                             _______,RGB_TOG,            _______, KC_P0,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),

};




// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 2, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 2, HSV_PURPLE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {13, 2, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _QWERTY));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _NAVLAY));
    return state;
}

