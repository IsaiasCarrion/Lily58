#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _NUMBERS,
    _SYMBOLS
};

enum custom_tap_dances {
    TD_DOT,
    TD_COMMA,
    TD_EQUAL
};

// Tap dance
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_DOT]   = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COLN),
    [TD_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_SCLN),
    [TD_EQUAL] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS)
};

// Home row mods
#define MT_A LCTL_T(KC_A)
#define MT_S LALT_T(KC_S)
#define MT_D LGUI_T(KC_D)
#define MT_F LSFT_T(KC_F)

#define MT_J RSFT_T(KC_J)
#define MT_K RGUI_T(KC_K)
#define MT_L RALT_T(KC_L)
#define MT_NTIL RCTL_T(KC_NTIL)

#define LOWER MO(_NUMBERS)
#define RAISE MO(_SYMBOLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * ┌────────────┐
 * │ Capa 0: _QWERTY (Shift y Control intercambiados)
 * └──────────────────────────────────────────────────────────────────────────────┐
 * ,----------------------------------.                ,----------------------------------.
 * | ESC  |  1 |  2 |  3 |  4 |  5 |   |                |   |  6 |  7 |  8 |  9 |  0 | BSPC |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * | TAB  |  Q |  W |  E |  R |  T |   |                |   |  Y |  U |  I |  O |  P |  -   |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * | SHFT | A |  S |  D |  F |  G |   |                |   |  H |  J |  K |  L |  Ñ |  '   |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * | CTRL |  Z |  X |  C |  V |  B |   |                |   |  N |  M |  , |  . |  = | RSFT |
 * `---------------------------+------+------+  +------+------+---------------------------'
 * |LOWER | LALT |  | ENT  | RALT | RAISE|
 * `-------------'  `-------------'
 */
[_QWERTY] = LAYOUT(
  KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,   MT_A,    MT_S,    MT_D,    MT_F,    KC_G,                   KC_H,    MT_J,    MT_K,    MT_L,    MT_NTIL, KC_QUOT,
  KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   KC_N,    KC_M,    TD_COMMA,TD_DOT,  TD_EQUAL,KC_RSFT,
                             LOWER, KC_LALT, KC_SPC,              KC_ENT, KC_RALT, RAISE
),

/*
 * ┌────────────┐
 * │ Capa 1: _NUMBERS (Enter añadido)
 * └──────────────────────────────────────────────────────────────────────────────┐
 * ,----------------------------------.                ,----------------------------------.
 * |      |  ! |  @ |  # |  $ |  % |   |                |   |  ^ |  & |  * | (  |  ) | DEL  |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * |      |  1 |  2 |  3 |  4 |  5 |   |                |   |  6 |  7 |  8 |  9 |  0 |  +   |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * |      |  = |  - |  / |  * |  \ |   |                | |  | < | > |  ? |  ! |  [  |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * |      |    |    |    |    |    |   |                |   |    |  . |  , |  ] | ENT  |
 * `---------------------------+------+------+  +------+------+---------------------------'
 * |      |      |  |      |      |      |
 * `-------------'  `-------------'
 */
[_NUMBERS] = LAYOUT(
  _______,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  _______,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PLUS,
  _______,   KC_EQL,  KC_MINS, KC_SLSH, KC_ASTR, KC_BSLS,                KC_PIPE, KC_LT,   KC_GT,   KC_QUES, KC_IEXCL,KC_LBRC,
  _______,   _______, _______, _______, _______, _______,                _______, _______, KC_DOT,  KC_COMM, KC_RBRC, KC_ENT,
                             _______, _______, _______,            _______, _______, _______
),

/*
 * ┌────────────┐
 * │ Capa 2: _SYMBOLS
 * └──────────────────────────────────────────────────────────────────────────────┐
 * ,----------------------------------.                ,----------------------------------.
 * |      | F1 | F2 | F3 | F4 | F5 |   |                |   | F6 | F7 | F8 | F9 |F10 | F11  |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * |      | {  | (  | [  | |  | `  |   |                | _  | ~  | End|PgUp|PgDn|Home|
 * |------+------+------+------+------+                +------+------+------+------+------|
 * |      | }  | )  | ]  | <  | >  |   |                | ←  | ↓  | ↑  | →  | :  | ;   |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * |      |    |    |    |    |    |   |                | .  | ,  | /  | * | =  |      |
 * `---------------------------+------+------+  +------+------+---------------------------'
 * |      |      |  |      |      |      |
 * `-------------'  `-------------'
 */
[_SYMBOLS] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______,   KC_LCBR, KC_LPRN, KC_LBRC, KC_PIPE, KC_GRV,                 KC_UNDS, KC_TILD, KC_END,  KC_PGUP, KC_PGDN, KC_HOME,
  _______,   KC_RCBR, KC_RPRN, KC_RBRC, KC_LABK, KC_RABK,                KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_COLN, KC_SCLN,
  _______,   _______, _______, _______, _______, _______,                KC_PDOT, KC_PCMM, KC_PSLS, KC_PAST, KC_PEQL, _______
                             _______, _______, _______,             _______, _______, _______
)
};
