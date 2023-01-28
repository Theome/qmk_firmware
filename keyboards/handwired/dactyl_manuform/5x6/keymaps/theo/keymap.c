/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H


#define _QWERTY 0
#define _FN 1
#define _MAC 2


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6_T(
     KC_EQL , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0  ,KC_MINS,
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P  ,KC_BSLASH,
     KC_ESC , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
     KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
     MO(_FN), KC_GRV,KC_NUBS,KC_LEFT, KC_RGHT,                                        KC_UP, KC_DOWN, KC_LBRC,  KC_RBRC, RGB_TOG,
                                      KC_LGUI, TG(_FN) ,                          MO(_MAC), KC_LGUI,
                                            KC_LALT,                          KC_RALT,
                                KC_BSPC,KC_DEL, KC_LCTRL,                     KC_RCTRL, KC_ENT, KC_SPC
  ),

  [_FN] = LAYOUT_5x6_T(
       KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
       _______,_______,_______,_______,_______,_______,                        _______,KC_P7,KC_P8,KC_P9,_______,_______,
       TG(_FN),_______,_______,_______,_______,_______,                        _______,KC_P4,KC_P5,KC_P6,_______,_______,
       KC_CAPS,_______,_______,_______,_______,_______,                        _______,KC_P1,KC_P2,KC_P3,_______,_______,
       _______,_______,_______,_______,_______,                                         _______ , _______ , _______ ,_______,_______,
                                               _______,_______,            _______ ,_______,
                                                       _______,            _______,
                                       _______,_______,_______,            _______,_______,KC_P0
  ),


// NB: KC_BRMD and KC_BRMU are aliases for KC_F14 and KC_F15. On a MacBook, these control the screen brightness by default.
// When using an external display, assign brightness control to F14 and F15 manually in the system settings.
    [_MAC] = LAYOUT_5x6_T(
       XXXXXXX,XXXXXXX , XXXXXXX , KC_MPRV , KC_MPLY , KC_MNXT,                        KC_MUTE, KC_VOLD, KC_VOLU, KC_BRMD ,KC_BRMU ,XXXXXXX,
       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
       XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                                         XXXXXXX , XXXXXXX , XXXXXXX ,XXXXXXX,XXXXXXX,
                                               _______,_______,            _______ ,_______,
                                                       _______,            _______,
                                       _______,_______,_______,            _______,_______,_______
  ),
};

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {5, 3, HSV_RED},
//     {13, 3, HSV_RED}
    {0, 24, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 24, HSV_CYAN}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 24, HSV_RED}
);
//
// const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//     {0, 24, HSV_GREEN}
// );

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer//,    // Overrides other layers
//     my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(21, 100, 100);
  rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _FN));
    rgblight_set_layer_state(2, layer_state_cmp(state, _MAC));
//     rgblight_set_layer_state(3, layer_state_cmp(state, _MAC));
    return state;
}
