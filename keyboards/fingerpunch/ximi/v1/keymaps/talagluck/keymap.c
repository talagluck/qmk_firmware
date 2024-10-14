#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE,
    ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty todo : enable shift on raise and lower layers; remove click buzz
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  | Ctrl |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         |Mouse1|BckSpc|Delete|    |Tab   | Space| Enter|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         |NO_OP | NO_OP |NO_OP|    |Mouse1|Mouse3|Mouse2|    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_QWERTY] = LAYOUT_ximi(
  KC_ESC,       KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,         KC_Y,    KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
  KC_TAB,       LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LSFT_T(KC_F), HYPR_T(KC_G), HYPR_T(KC_H),    RSFT_T(KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_V,         KC_B,         KC_N,    KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RCTL,
                KC_MUTE,                    MO(_LOWER),     KC_BSPC,      HYPR_T(KC_DEL),      HYPR_T(KC_TAB), KC_SPC,       LT(_RAISE, KC_ENT),                      KC_MUTE,
                                            KC_NO,        KC_NO,        KC_NO,        KC_MS_BTN2, KC_MS_BTN3, KC_MS_BTN1
),

/* Colemak
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * |  Esc |   Q  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |   ;  |   \  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * |  Tab |   A  |   R  |   S  |   T  |   G  |           |   M  |   N  |   E  |   I  |   O  |   '  |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | Shft |   Z  |   X  |   C  |   D  |   V  |           |   K  |   H  |   ,  |   .  |   /  | Ctrl |
 * `--------------------+--------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER| Enter|   '  |    |BckSpc| Space| RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         |NO_OP | NO_OP |NO_OP|    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
 */

// Default config uses home row mods. So hold each of the keys on the home row to use ctrl, gui, alt, or shift
[_COLEMAK] = LAYOUT_ximi(
  KC_ESC,       KC_Q,         KC_W,         KC_F,         KC_P,         KC_B,         KC_J,    KC_L,         KC_U,         KC_Y,         KC_SCLN,      KC_BSLS,
  KC_TAB,       LCTL_T(KC_A), LGUI_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_G,         KC_M,    RSFT_T(KC_N), RALT_T(KC_E), RGUI_T(KC_I), RCTL_T(KC_O), KC_QUOT,
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_D,         KC_V,         KC_K,    KC_H,         KC_COMM,      KC_DOT,       KC_SLSH,      KC_RCTL,
                KC_MUTE,                    LOWER,        KC_ENT,       KC_QUOT,      KC_BSPC, KC_SPC,       RAISE,                      KC_MUTE,
                                            C(KC_Z),      C(S(KC_Z)),   C(KC_Y),      KC_VOLD, KC_MUTE,      KC_VOLU
),

/* Raise
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * | ____ |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ | Left | Down |  Up  | Right| Tab  |           |      |   -  |   =  |   [  |   ]  | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ |  Ctrl|   `  |  GUI |  Alt |      |           |      |      |      |   \  |   '  | ____ |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER|KC_DEL|      |    |      |      | RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
 */
[_RAISE] = LAYOUT_ximi(
  _______,      KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  _______,      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TAB,       _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
  _______,      KC_LCTL, KC_GRV,  KC_LGUI, KC_LALT, _______,      _______, _______, _______, KC_BSLS, KC_QUOT, _______,
                _______,          _______, _______,  _______,      _______, _______, _______,          _______,
                                  _______, _______, _______,      _______, _______, _______
),

/* Lower
 * 
 * ,-----------------------------------------.           ,-----------------------------------------.
 * | ____ |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ |  Esc |      |      |      |EECLR |           |      |   _  |   +  |   {  |   }  | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ |  Caps|   ~  |      |Reset |Btldr |           |      |      |      |   |  |   '  | ____ |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER|      |      |    |  Del |      | RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
 */
[_LOWER] = LAYOUT_ximi(
  _______,      KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______,      KC_ESC,  _______, _______, _______, EE_CLR,       _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  _______,      KC_CAPS, KC_TILD, _______, QK_RBT,  QK_BOOT,      _______, _______, _______, KC_PIPE,  KC_DQT, _______,
                _______,          _______, _______, _______,      KC_DEL,  _______, LT(_ADJUST, KC_ENT),          _______,
                                  _______, _______, _______,      _______, _______, _______
),

/* Adjust (Lower + Raise)
 *
 * ,-----------------------------------------.           ,-----------------------------------------.
 * | ____ | RGB_T| RGB_R| RGB_F|      |QWERTY|           |   F1 |  F2  |  F3  |  F4  |  F5  | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ | SPD_I| HUE_I| SAT_I| VAL_I|COLEMK|           |   F6 |  F7  |  F8  |  F9  |  F10 | ____ |
 * |------+------+------+------+------+------|           |------+------+------+------+------+------|
 * | ____ | SPD_D| HUE_D| SAT_D| VAL_D|      |           |  F11 |  F12 |      |Reset | Btldr| ____ |
 * `-----------------------------------------'           `-----------------------------------------'
 *        ,------.         ,--------------------.    ,--------------------.          ,------.
 *        | MUTE |         | LOWER|      |      |    |      |      | RAISE|          | MUTE |
 *        `------'         `--------------------'    `--------------------.          `------'
 *                         ,--------------------.    ,--------------------.
 *                         | Undo | Redo2| Redo |    | Vol- | Mute | Vol+ |    // 3 way thumb switch
 *                         `--------------------'    `--------------------.
 */
[_ADJUST] =  LAYOUT_ximi(
  _______,      RGB_TOG, RGB_RMOD, RGB_MOD, _______, TO(_QWERTY),       KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   _______,
  _______,      RGB_SPI, RGB_HUI,  RGB_SAI, RGB_VAI, TO(_COLEMAK),      KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  _______,
  _______,      RGB_SPD, RGB_HUD,  RGB_SAD, RGB_VAD, _______,           KC_F11,  KC_F12,  _______, QK_RBT,   QK_BOOT, _______,
                _______,           _______, _______, _______,           _______, _______, _______,          _______,
                                   _______, _______, _______,           _______, _______, _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
            break;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
            break;
        default:
            break;
    }

    return true;
}
