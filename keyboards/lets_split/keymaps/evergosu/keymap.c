#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

enum td_keycodes {
  SPC_L,
  ENT_R,
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state);
void spc_lower_finished(tap_dance_state_t *state, void *user_data);
void spc_lower_reset(tap_dance_state_t *state, void *user_data);
void ent_raise_finished(tap_dance_state_t *state, void *user_data);
void ent_raise_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* COMPOSED KEYMAPS.
   * ,-----------------------------------------------.        ,-----------------------------------------------.
   * |   1   |   2   |   3   |   4   |   5   |   6   |        |   7   |   8   |   9   |   0   |   -   |   =   |
   * |   `   |   Q   |   W   |   E   |   R   |   T   |        |   Y   |   U   |   I   |   O   |   P   |   x   |
   * |   !   |   @   |   #   |   $   |   %   |   ^   |        |   &   |   *   |   (   |   )   |   _   |   +   |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |   `   |       |       |       |       |       |        |  Left |  Down |   Up  | Right |       |   |   |
   * |  Esc  |   A   |   S   |   D   |   F   |   G   |        |   H   |   J   |   K   |   L   |   ;   |   "   |
   * |   ~   |       |       |       |       |       |        |   [   |   ]   |   {   |   }   |       |  \ ё  |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |        |       |       |       |       |       |  Boot |
   * | Shift |   Z   |   X   |   C   |   V   |   B   |        |   N   |   M   |   ,   |   .   |   /   | Shift |
   * | Boot  |       |       |       |       |       |        |       |   ъ   |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |        |       |       |       | BriUp |       | VolUp |
   * |  Fn   |       |  CMD  |  Ctl  |  Tab  | Spc-L |        | Ent-R |  Bsp  |  Alt  | Sleep | Next  | Play  |
   * |       |       |       |       |       |       |        |       |  Del  |       | BriDn |       | VolDn |
   * `-----------------------------------------------'        `-----------------------------------------------'
   */
  /* QWERTY LAYER.
   * ,-----------------------------------------------.        ,-----------------------------------------------.
   * |   `   |   Q   |   W   |   E   |   R   |   T   |        |   Y   |   U   |   I   |   O   |   P   |   x   |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |  Esc  |   A   |   S   |   D   |   F   |   G   |        |   H   |   J   |   K   |   L   |   ;   |   "   |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * | Shift |   Z   |   X   |   C   |   V   |   B   |        |   N   |   M   |   ,   |   .   |   /   | Shift |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |  Fn   |       |  CMD  |  Ctl  |  Tab  | Spc-L |        | Ent-R |  Bsp  |  Alt  | Sleep | Next  | Play  |
   * `-----------------------------------------------'        `-----------------------------------------------'
   */
  [_QWERTY] = LAYOUT_ortho_4x12(
    KC_GRV,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,      KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,    KC_LBRC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,      KC_G,      KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,      KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
    AP_FN,   _______, KC_LGUI, KC_LCTL, KC_TAB, TD(SPC_L), TD(ENT_R), KC_BSPC, KC_LALT,  KC_SLEP, KC_MNXT, KC_MPLY
  ),

  /* LOWER LAYER.
   * ,-----------------------------------------------.        ,-----------------------------------------------.
   * |   !   |   @   |   #   |   $   |   %   |   ^   |        |   &   |   *   |   (   |   )   |   _   |   +   |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |   ~   |       |       |       |       |       |        |   [   |   ]   |   {   |   }   |       |  \ ё  |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * | Boot  |       |       |       |       |       |        |       |   ъ   |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |        |       |  Del  |       | BriDn |       | VolDn |
   * `-----------------------------------------------'        `-----------------------------------------------'
   */
  [_LOWER] = LAYOUT_ortho_4x12(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC,     KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, KC_PLUS,
    KC_TILD, _______, _______, _______, _______, _______,     KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______, KC_BSLS,
    QK_BOOT, _______, _______, _______, _______, _______,     _______, KC_RBRC, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,     _______, KC_DEL,  _______, KC_BRID, _______, KC_VOLD
  ),

  /* RAISE LAYER.
   * ,-----------------------------------------------.        ,-----------------------------------------------.
   * |   1   |   2   |   3   |   4   |   5   |   6   |        |   7   |   8   |   9   |   0   |   -   |   =   |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |   `   |       |       |       |       |       |        |  Left |  Down |   Up  | Right |       |   |   |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |        |       |       |       |       |       |  Boot |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |        |       |       |       | BriUp |       | VolUp |
   * `-----------------------------------------------'        `-----------------------------------------------'
   */
  [_RAISE] = LAYOUT_ortho_4x12(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,        KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
    KC_GRV,  _______, _______, _______, _______, _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_PIPE,
    _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, QK_BOOT,
    _______, _______, _______, _______, _______, _______,     _______, _______, _______, KC_BRIU, _______, KC_VOLU
  ),

  /* ADJUST LAYER (LOWER + RAISE).
   * ,-----------------------------------------------.        ,-----------------------------------------------.
   * |  F-1  |  F-2  |  F-3  |  F-4  |  F-5  |  F-6  |        |  F-7  |  F-8  |  F-9  |  F10  |  F11  |  F12  |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       | AudOn | AuOff |       |        |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |        |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------|        |-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |        |       |       |       |       |       |       |
   * `-----------------------------------------------'        `-----------------------------------------------'
   */
  [_ADJUST] = LAYOUT_ortho_4x12(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, _______, _______, AU_ON,   AU_OFF,  _______,     _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

td_state_t cur_dance(tap_dance_state_t *state) {
  switch (state->count) {
    case 1:
      if (!state->pressed) {
        return TD_SINGLE_TAP;
      } else {
        return TD_SINGLE_HOLD;
      }
    default:
      return TD_UNKNOWN;
  }
}

// SPACE on single tap, LOWER on single hold.
static td_tap_t spc_lower_tap_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void spc_lower_finished(tap_dance_state_t *state, void *user_data) {
  spc_lower_tap_state.state = cur_dance(state);
  switch (spc_lower_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_SPC);
      break;
    case TD_SINGLE_HOLD:
      layer_on(_LOWER);
      break;
    default:
      break;
  }
}

void spc_lower_reset(tap_dance_state_t *state, void *user_data) {
  if (spc_lower_tap_state.state == TD_SINGLE_HOLD) {
    layer_off(_LOWER);
  }
  spc_lower_tap_state.state = TD_NONE;
}

// ENTER on single tap, RAISE on single hold.
static td_tap_t ent_raise_tap_state = {
  .is_press_action = true,
  .state = TD_NONE
};

void ent_raise_finished(tap_dance_state_t *state, void *user_data) {
  ent_raise_tap_state.state = cur_dance(state);
  switch (ent_raise_tap_state.state) {
    case TD_SINGLE_TAP:
      tap_code(KC_ENT);
      break;
    case TD_SINGLE_HOLD:
      layer_on(_RAISE);
      break;
    default:
      break;
  }
}

void ent_raise_reset(tap_dance_state_t *state, void *user_data) {
  if (ent_raise_tap_state.state == TD_SINGLE_HOLD) {
    layer_off(_RAISE);
  }
  ent_raise_tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [SPC_L] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, spc_lower_finished, spc_lower_reset),
    [ENT_R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ent_raise_finished, ent_raise_reset),
};
