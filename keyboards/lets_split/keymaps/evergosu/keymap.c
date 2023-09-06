#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define ESC_CTL MT(MOD_LCTL, KC_ESC)
#define TAB_CTL MT(MOD_LCTL, KC_TAB)
#define BSP_ALT MT(MOD_LALT, KC_BSPC)
#define SPC_L LT(_LOWER, KC_SPC)
#define ENT_R LT(_RAISE, KC_ENT)
#define LOCK C(G(KC_Q))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* COMPOSED KEYMAPS.
   * ,-----------------------------------------------.        ,-----------------------------------------------.
   * |   1   |   2   |   3   |   4   |   5   |   6   |        |   &   |   *   |   (   |   )   |   _   |   +   |
   * |   `   |   Q   |   W   |   E   |   R   |   T   |        |   Y   |   U   |   I   |   O   |   P   |   x   |
   * |   !   |   @   |   #   |   $   |   %   |   ^   |        |   7   |   8   |   9   |   0   |   -   |   =   |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |   `   |       |       |       |       |       |        |   {   |   [   |   ]   |   }   |       |   |   |
   * |Esc-CTL|   A   |   S   |   D   |   F   |   G   |        |   H   |   J   |   K   |   L   |   ;   |   "   |
   * |   ~   |  Left |  Down |   Up  | Right |       |        |  Left |  Down |   Up  | Right |       |  \ ё  |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |        |  Boot |       |       |       |       |       |
   * | SHIFT |   Z   |   X   |   C   |   V   |   B   |        |   N   |   M   |   ,   |   .   |   /   | SHIFT |
   * |       |       |       |       |       |  Boot |        |       |   ъ   |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |        |       |       |       | BriUp |       | VolUp |
   * |  Fn   |  RGB  | LOCK  |  CMD  |Tab-CTL| Spc-L |        | Ent-R |Bsp-ALT|  Fn   | Sleep | Next  | Play  |
   * |       |       |       |       |       |       |        |       |  Del  |       | BriDn |       | VolDn |
   * `-----------------------------------------------'        `-----------------------------------------------'
   */
  /* QWERTY LAYER.
   * ,-----------------------------------------------.        ,-----------------------------------------------.
   * |   `   |   Q   |   W   |   E   |   R   |   T   |        |   Y   |   U   |   I   |   O   |   P   |   x   |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |Esc-CTL|   A   |   S   |   D   |   F   |   G   |        |   H   |   J   |   K   |   L   |   ;   |   "   |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * | SHIFT |   Z   |   X   |   C   |   V   |   B   |        |   N   |   M   |   ,   |   .   |   /   | SHIFT |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |  Fn   |  RGB  | LOCK  |  CMD  |Tab-CTL| Spc-L |        | Ent-R |Bsp-ALT|  Fn   | Sleep | Next  | Play  |
   * `-----------------------------------------------'        `-----------------------------------------------'
   */
  [_QWERTY] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,         KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,    KC_LBRC,
    ESC_CTL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,         KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,         KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
    AP_FN,   RGB_TOG, LOCK,    KC_LGUI, TAB_CTL,SPC_L,        ENT_R,  BSP_ALT, AP_FN,    KC_SLEP, KC_MNXT, KC_MPLY
  ),
  /* LOWER LAYER.
   * ,-----------------------------------------------.        ,-----------------------------------------------.
   * |   !   |   @   |   #   |   $   |   %   |   ^   |        |   7   |   8   |   9   |   0   |   -   |   =   |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |   ~   |  Left |  Down |   Up  | Right |       |        |  Left |  Down |   Up  | Right |       |  \ ё  |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |  Boot |        |       |   ъ   |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |        |       |  Del  |       | BriDn |       | VolDn |
   * `-----------------------------------------------'        `-----------------------------------------------'
   */
  [_LOWER] = LAYOUT_ortho_4x12(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,     KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
    KC_TILD, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_BSLS,
    _______, _______, _______, _______, _______, QK_BOOT,     _______, KC_RBRC, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,     _______, KC_DEL,  _______, KC_BRID, _______, KC_VOLD
  ),

  /* RAISE LAYER.
   * ,-----------------------------------------------.        ,-----------------------------------------------.
   * |   1   |   2   |   3   |   4   |   5   |   6   |        |   &   |   *   |   (   |   )   |   _   |   +   |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |   `   |       |       |       |       |       |        |   {   |   [   |   ]   |   }   |       |   |   |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |        |  Boot |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |        |       |       |       | BriUp |       | VolUp |
   * `-----------------------------------------------'        `-----------------------------------------------'
   */
  [_RAISE] = LAYOUT_ortho_4x12(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,        KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
    KC_GRV,  _______, _______, _______, _______, _______,     KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, _______, KC_PIPE,
    _______, _______, _______, _______, _______, _______,     QK_BOOT, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_BRIU, _______, KC_VOLU
  ),

  /* ADJUST LAYER (LOWER + RAISE).
   * ,-----------------------------------------------.        ,-----------------------------------------------.
   * |  F-1  |  F-2  |  F-3  |  F-4  |  F-5  |  F-6  |        |  F-7  |  F-8  |  F-9  |  F10  |  F11  |  F12  |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |  SAT  |       |       |       |        |  HUE  | PG_DN | PG_UP |       |       |       |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |  VAL  |       |        |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |        |       |       |       |       |       |       |
   * `-----------------------------------------------'        `-----------------------------------------------'
   */
  [_ADJUST] = LAYOUT_ortho_4x12(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, RGB_SAI, _______, _______, _______,     RGB_HUI, KC_PGDN, KC_PGUP, _______, _______, _______,
    _______, _______, _______, _______, RGB_VAI, _______,     _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
