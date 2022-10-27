#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Del           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Home
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 End
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgUp
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       PgDn
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right

    // Windows Layout
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(2),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Mac Layout
    [1] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_END,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGUP,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_PGDN,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RALT, MO(2),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    // Function Layer
    [2] = LAYOUT(
        RGB_TOG, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, DEBUG,            _______,
        _______, TO(0),   TO(1),   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    )
};

// RGB LED layout

// led index number, function of the key

//  67, Side led 01    0, ESC      6, F1       12, F2       18, F3       23, F4       28, F5       34, F6       39, F7       44, F8       50, F9       56, F10      61, F11      66, F12      69, Prt       Rotary(Mute)   68, Side led 12
//  70, Side led 02    1, ~        7, 1        13, 2        19, 3        24, 4        29, 5        35, 6        40, 7        45, 8        51, 9        57, 0        62, -_       78, (=+)     85, BackSpc   72, Del        71, Side led 13
//  73, Side led 03    2, Tab      8, Q        14, W        20. E        25, R        30, T        36, Y        41, U        46, I        52, O        58, P        63, [{       89, ]}       93, \|        75, PgUp       74, Side led 14
//  76, Side led 04    3, Caps     9, A        15, S        21, D        26, F        31, G        37, H        42, J        47, K        53, L        59, ;:       64, '"                    96, Enter     86, PgDn       77, Side led 15
//  80, Side led 05    4, Sh_L     10, Z       16, X        22, C        27, V        32, B        38, N        43, M        48, ,<       54, .<       60, /?                    90, Sh_R     94, Up        82, End        81, Side led 16
//  83, Side led 06    5, Ct_L     11,Win_L    17, Alt_L                              33, SPACE                              49, Alt_R    55, FN                    65, Ct_R     95, Left     97, Down      79, Right      84, Side led 17
//  87, Side led 07                                                                                                                                                                                                        88, Side led 18
//  91, Side led 08        

uint8_t thisHue = 0;
uint8_t thisSat = 255;
uint8_t thisVal = 255;
const int SIZE = 8;
int leftSideLEDs[] = { 67, 70, 73, 76, 80, 83, 87, 91 };
int rightSideLEDs[] = { 68, 71, 74, 77, 81, 84, 88, 92 };

bool sideLEDsActive = false;

#if defined(ENCODER_ENABLE) && !defined(ENCODER_DEFAULTACTIONS_ENABLE)    

void encoder_action_hsv_change(bool clockwise, uint8_t hueChange, uint8_t satChange, uint8_t valChange) {
    if (clockwise) {
        thisHue += hueChange;
        thisSat += satChange;
        thisVal += valChange;
    } else {
        thisHue -= hueChange;
        thisSat -= satChange;
        thisVal -= valChange;
    }            
}

void invert_sideLEDsActive(bool sideLEDsBoolean){
    if(sideLEDsBoolean) {
        sideLEDsActive = false;
    } else {
        sideLEDsActive = true;
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t mods_state = get_mods();

    if (mods_state & MOD_BIT(KC_LCTL)) {
        encoder_action_hsv_change(clockwise, 2, 0, 0); // Hue change
    } else if (mods_state & MOD_BIT(KC_LSFT)) {
        encoder_action_hsv_change(clockwise, 0, 2, 0); // Saturation change
    } else if (mods_state & MOD_BIT(KC_LALT)) {  
        encoder_action_hsv_change(clockwise, 0, 0, 2); // Value/Brightness change
    } 
    else {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }   
    return true;
}

#endif // endif ENCODER

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color_all(RGB_WHITE);
    } else {
        HSV hsv = {thisHue, thisSat, thisVal};
        RGB rgb = hsv_to_rgb(hsv);
        
        HSV currentMatrix_hsv = rgb_matrix_get_hsv();
        RGB currentMatrix_rgb = hsv_to_rgb(currentMatrix_hsv);

        if(sideLEDsActive) {
            for (int i = 0; i < SIZE; i++) {
                rgb_matrix_set_color(leftSideLEDs[i], rgb.r, rgb.g, rgb.b);
                rgb_matrix_set_color(rightSideLEDs[i], rgb.r, rgb.g, rgb.b);
            }
        }        

        if (get_highest_layer(layer_state) > 0) {
            uint8_t layer = get_highest_layer(layer_state);

            switch (layer) {
            case 2:
                // Turn off all lights
                // rgb_matrix_set_color_all(0, 0, 0);

                // Set Media control colors
                rgb_matrix_set_color(50, RGB_BLUE); // F9. "Prev Track"
                rgb_matrix_set_color(56, RGB_BLUE); // F10 "Next track"
                rgb_matrix_set_color(61, RGB_GREEN); //F11 "Play"
                rgb_matrix_set_color(66, RGB_RED); // F12 "Stop"

                // Set Windows/Mac Keyboard Toggle colors
                rgb_matrix_set_color(7, RGB_BLUE); // 1 "Windows Layout"
                rgb_matrix_set_color(13, RGB_RED); // 2 "Mac Layout"

                // Set Hue, Saturation, and Value keys
                rgb_matrix_set_color(8, RGB_PURPLE); // Q. "Hue Increase"
                rgb_matrix_set_color(9, RGB_CYAN); // A "Hue Decrease"
                rgb_matrix_set_color(14, RGB_GREEN); //W "Saturation Increase"
                rgb_matrix_set_color(15, RGB_WHITE); // S "Saturation Decrease"
                rgb_matrix_set_color(20, RGB_BLUE); // E. "Value Increase"
                rgb_matrix_set_color(21, RGB_TURQUOISE); // D "Value Decrease"

                rgb_matrix_set_color(33, currentMatrix_rgb.r, currentMatrix_rgb.g, currentMatrix_rgb.b); // Space.  Color indicator
                
                break;

            default:
                for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
                    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                        uint8_t index = g_led_config.matrix_co[row][col];                        

                        if (index >= led_min && index <= led_max && index != NO_LED &&
                        keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                            // rgb_matrix_set_color(index, currentMatrix_rgb.r, currentMatrix_rgb.g, currentMatrix_rgb.b);
                        }
                    }
                }
                break;
            }            
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_MUTE:
        if (record->event.pressed) {
            if (get_mods() & MOD_MASK_CTRL){
                invert_sideLEDsActive(sideLEDsActive);
                return false;
            }
            return true;            
        }
    default:
      return true; // Process all other keycodes normally
  }
}