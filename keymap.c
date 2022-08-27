#include QMK_KEYBOARD_H

enum layers {
  _BASE,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAME,
  _NAV,
};

// Readability keycodes
#define LOWER    MO(_LOWER)
#define RAISE    MO(_RAISE)
#define LOW_ENT  LT(_LOWER, KC_ENT)
#define RAI_ENT  LT(_RAISE, KC_ENT)
#define LSFT_LB  MT(MOD_LSFT, KC_LBRC)
#define RSFT_RB  MT(MOD_RSFT,KC_RBRC)
#define NAV      MO(_NAV)
#define CTL_SPC  MT(MOD_LCTL, KC_SPC)
#define SCR_SHT  LGUI(LSFT(KC_5))
#define GAME     TG(_GAME)
#define COLEMAK  DF(1)
#define QUERTY   DF(0)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    LSFT_LB, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_RB,
    NAV,     KC_LCTL, KC_LALT, KC_LGUI, LOW_ENT, CTL_SPC, CTL_SPC, RAI_ENT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  [_COLEMAK] = LAYOUT_ortho_4x12(
    _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______,
    _______, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    _______,
    _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_LOWER] = LAYOUT_ortho_4x12(
    _______, _______, KC_MUTE, KC_VOLU, KC_VOLD, _______, _______, _______, _______, KC_UNDS, KC_PLUS, _______,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
    _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, _______, _______, _______, _______, _______,
    SCR_SHT, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
  ),

  [_RAISE] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  _______,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    GAME,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_ortho_4x12(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_DEL,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, COLEMAK, _______, QUERTY,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_GAME] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT,
    _______, _______, _______, _______, _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______, _______
  ),

  [_NAV] = LAYOUT_ortho_4x12(
    _______, _______, _______, KC_WH_U, KC_WH_D, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,
    _______, _______, _______, KC_BTN1, KC_BTN2, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

};


uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
