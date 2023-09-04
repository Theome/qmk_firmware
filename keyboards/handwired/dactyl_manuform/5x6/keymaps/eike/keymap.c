/* A standard layout for the Dactyl Manuform 5x6 Keyboard */

#include QMK_KEYBOARD_H

#define GRAVE_ESC_ALT_OVERRIDE
#define GRAVE_ESC_CTRL_OVERRIDE

#define _QWERTY 0
#define _LOWER 1
#define _NAVLAY 2
#define _RGBLAY 3

#define LOWER TT(_LOWER)
#define NAVLAY TT(_NAVLAY)
#define RGBLAY MO(_RGBLAY)

enum {
    TAPDANCE_1 = 0,
    TAPDANCE_2 = 1
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TAPDANCE_1] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_PDOT), 
    [TAPDANCE_2] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_ESC) 
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_GRV , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  ,                         KC_6  , KC_7  , KC_8  , KC_9  , KC_0   ,LT(RGBLAY,KC_MINS),
     KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R  , KC_T  ,                         KC_Y  , KC_U  , KC_I  , KC_O  , KC_P   , KC_LBRC ,
     KC_LSFT , KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                         KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN ,KC_QUOT,
     KC_LCTL, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,                         KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH ,KC_RCTL,
                      KC_LGUI,KC_LALT,                                                       KC_RALT, KC_RGUI,
                                       KC_SPC,KC_LSFT,                        TD(TAPDANCE_2) ,KC_ENT,
                                       LOWER,NAVLAY,                          NAVLAY, LOWER,
                                       KC_LALT, KC_BSPC ,                     KC_DEL , KC_LGUI
  ),

  [_LOWER] = LAYOUT_5x6(

     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6 , KC_F7 , KC_F8 , KC_F9         , KC_F10  , KC_F11 ,
     KC_PSLS ,KC_EXLM, RALT(KC_7) ,RALT(KC_0),KC_DLR ,RALT(KC_RBRC),				 KC_NLCK       , KC_P7 , KC_P8 , KC_P9 , KC_PAST , KC_PPLS,
     RALT(KC_MINS) , RALT(KC_Q),LSFT(KC_8),LSFT(KC_9),LSFT(KC_EQL),KC_EQL,	 KC_NUHS , KC_P4 , KC_P5 , KC_P6 , KC_PSLS , KC_PMNS,
     _______,RALT(KC_NUBS),RALT(KC_8) ,RALT(KC_9),LSFT(KC_2),LSFT(KC_NUHS),  KC_PEQL  ,KC_P1 , KC_P2 , KC_P3 , TD(TAPDANCE_1) ,  _______,
                     KC_NUBS, LSFT(KC_NUBS) ,																									      KC_P0, _______,
                                             _______,_______,           _______,_______,
                                            _______ , _______ ,				  _______,_______,
																						_______ , _______,					  _______,_______

  ),
  [_NAVLAY] = LAYOUT_5x6(

     KC_NO   , KC_NO , KC_NO   , KC_WH_U , KC_NO   , KC_NO ,                  KC_PSCR , KC_SLCK , KC_PAUS , KC_NLCK , KC_NO   , KC_MUTE ,
     KC_NO   , KC_NO , KC_NO   , KC_MS_U , KC_BTN3 , KC_NO , 								  KC_HOME , KC_PGDN , KC_PGUP , KC_END  , KC_NO   , KC_VOLU ,
     KC_CAPS , KC_NO , KC_MS_L , KC_MS_D , KC_MS_R , KC_NO ,                  KC_LEFT , KC_DOWN , KC_UP   , KC_RGHT , KC_MINS , KC_VOLD ,
     _______ , KC_NO , KC_WH_L , KC_WH_D , KC_WH_R , KC_NO ,                  KC_MPRV , KC_MPLY , KC_MNXT , KC_NO   , KC_NO   , KC_NO ,
                       _______ , _______ ,																						 						_______,_______,
                                             KC_BTN1,KC_BTN2,            KC_BTN1,KC_BTN2,
                                             _______,_______,            _______,_______,
                                             _______,_______,            _______,_______

  ),
  [_RGBLAY] = LAYOUT_5x6(

     RGB_MODE_RAINBOW,RGB_MODE_SWIRL, RGB_MODE_SNAKE ,RGB_MODE_KNIGHT,RGB_MODE_XMAS ,RGB_MODE_GRADIENT,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     RGB_MODE_PLAIN, KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                        KC_NO, KC_NO ,  KC_NO  ,  KC_NO  ,  KC_NO  ,RGB_VAI,
     KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO ,                         KC_NO ,  KC_NO  ,  KC_NO  ,  KC_NO  ,KC_MINS,RGB_VAD,
     KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO ,                  KC_NO   , KC_NO , KC_NO   , KC_NO   , KC_NO   , KC_NO ,
										_______,RGB_TOG,																															  KC_NO  , KC_NO,
                                             KC_NO  ,  KC_NO  ,              KC_NO  ,  KC_NO  ,
                                             KC_NO  ,  KC_NO  ,              KC_NO  ,  KC_NO  ,
                                             KC_NO  ,  KC_NO  ,              KC_NO  ,  KC_NO  

  )

};


const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {14, 2, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 2, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 24, HSV_RED}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 24, HSV_CYAN}
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 24, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_layer1_layer,
    my_layer2_layer,
    my_layer3_layer,
    my_numlock_layer,
    my_capslock_layer
);

void keyboard_post_init_user(void) {
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(169, 200, 100);
  rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(3, led_state.num_lock);
    rgblight_set_layer_state(4, led_state.caps_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(1, layer_state_cmp(state, _NAVLAY));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RGBLAY));
    return state;
}
