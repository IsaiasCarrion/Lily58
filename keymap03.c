#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _SYMBOLS,
    _NUMBERS
};

enum custom_tap_dances {
    TD_DOT,
    TD_COMMA
};

// Tap dance
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_DOT]   = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COLN),
    [TD_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_SCLN)
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

#define LOWER MO(_SYMBOLS)
#define RAISE MO(_NUMBERS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * ┌────────────┐
 * │ Capa 0: _QWERTY
 * └──────────────────────────────────────────────────────────────────────────────┐
 * ,----------------------------------.                ,----------------------------------.
 * | ESC  |  1 |  2 |  3 |  4 |  5 |   |                |   |  6 |  7 |  8 |  9 |  0 | BSPC |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * | TAB  |  Q |  W |  E |  R |  T |   |                |   |  Y |  U |  I |  O |  P |  -   |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * | SHFT | A |  S |  D |  F |  G |   |                |   |  H |  J |  K |  L |  Ñ |  '   |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * | CTRL |  Z |  X |  C |  V |  B |   |                |   |  N |  M | TD_COMMA,TD_DOT,  = | RSFT |
 * `---------------------------+------+------+  +------+------+---------------------------'
 * |LOWER | LALT |  | ENT  | RALT | RAISE|
 * `-------------'  `-------------'
 */
[_QWERTY] = LAYOUT(
  KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,   MT_A,    MT_S,    MT_D,    MT_F,    KC_G,                   KC_H,    MT_J,    MT_K,    MT_L,    MT_NTIL, KC_QUOT,
  KC_LCTL,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   KC_N,    KC_M,    TD_COMMA,TD_DOT,  KC_EQL,  KC_RSFT,
                             LOWER, KC_LALT, KC_SPC,              KC_ENT, KC_RALT, RAISE
),

/*
 * ┌────────────┐
 * │ Capa 1: _SYMBOLS (Modificada)
 * └──────────────────────────────────────────────────────────────────────────────┐
 * ,----------------------------------.                ,----------------------------------.
 * |      | F1 | F2 | F3 | F4 | F5 |   |                |   | F6 | F7 | F8 | F9 |F10 | F11  |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * |      | [  | ]  |   |   |   |   |                |   | |  | `  | ~  | ^  | |      |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * |      | {  |  } |   |    |   |                | _  | -  | +  | =  | :  | ;  |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * |      |< | >|    |    |    |   |                | ,  | .  | '  | "  | ¿  | ¡  |
 * `---------------------------+------+------+  +------+------+---------------------------'
 * |      |      |  |      |      |      |
 * `-------------'  `-------------'
 */
[_SYMBOLS] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______,   KC_LBRC, KC_RBRC, _______, _______, _______,                _______, KC_PIPE, KC_GRV,  KC_TILD, KC_CIRC, _______,
  _______,   KC_LCBR, KC_RCBR, _______, _______, _______,                KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  _______, _______,
  _______,   KC_LABK, KC_RABK, _______, _______, _______,                KC_COMM, KC_DOT,  KC_QUOT, KC_DQUO, KC_QUES, KC_EXLM
                             _______, _______, _______,             _______, _______, _______
),

/*
 * ┌────────────┐
 * │ Capa 2: _NUMBERS
 * └──────────────────────────────────────────────────────────────────────────────┐
 * ,----------------------------------.                ,----------------------------------.
 * | ESC  |      |      |      |      |      |   |        |   |      |      |      |      | BSPC  |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * | TAB  | Home | Up   | End |      |      |        | 7  | 8  | 9  | -  |   |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * | SHFT | Left | Down | Right|      |      |        | 4 | 5  | 6  | + | * |
 * |------+------+------+------+------+                +------+------+------+------+------|
 * |      | Pgup |      | PgDn |      |      |        | 1  | 2  | 3  | 0  | .  | ENT  |
 * `---------------------------+------+------+  +------+------+---------------------------'
 * |      |      |  |      |      |      |
 * `-------------'  `-------------'
 */
[_NUMBERS] = LAYOUT(
  KC_ESC,    _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, KC_BSPC,
  KC_TAB,    KC_HOME, KC_UP,   KC_END,  _______, _______,                KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______, _______,
  KC_LSFT,   KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,                KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAST, _______,
  _______,   KC_PGUP, _______, KC_PGDN, _______, _______,                KC_P1,   KC_P2,   KC_P3,   KC_P0,   KC_PDOT, KC_PEQL
)
};
