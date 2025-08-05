// Copyright 2022 Tommy Oldfield (@oldfieldtc)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// 1. ENUM REORDENADO
enum layers {
    _QWERTY,
    _NUMBERS, // Ahora es la capa 1
    _SYMBOLS  // Ahora es la capa 2
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

// 2. DEFINES ACTUALIZADOS
#define LOWER MO(_NUMBERS) // LOWER ahora va a la capa _NUMBERS
#define RAISE MO(_SYMBOLS) // RAISE ahora va a la capa _SYMBOLS

// Define un alias para las teclas transparentes.
#define _______ KC_TRNS

// 3. KEYMAPS REORDENADOS
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* _QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |SHIFT |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  Ñ   |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |CTRL  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,(TD)| .(TD)|  /  |SHIFT |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOWER | ALT |      | /Space /       \Enter \  |       | ALT  | RAISE |
 *                   |      |      |      |/       /        \      \ |      |      |        |
 *                   `----------------------------'           '------''--------------------'
 */
[_QWERTY] = LAYOUT(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_NTIL, KC_QUOT,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LBRC,   KC_RBRC,   KC_N,    KC_M,    TD(TD_COMMA), TD(TD_DOT), KC_SLSH, KC_RSFT,
                      LOWER,   KC_LALT, KC_NO,   KC_SPC,                       KC_ENT,  KC_NO,   KC_RALT, RAISE
),

/* _NUMBERS (Ahora activada con LOWER)
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | ESC   |  !  |  @  |  #  |  $  |  %  |                    |  ^  |  &  |  * |  (  |  )  |  DEL  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | TAB   | Home| Up  | End |TRNS |TRNS |                    |  7  |  8  |  9  |  -  |TRNS |TRNS |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | SHFT  | Left| Down|Right|TRNS |TRNS |-------.      .-------|  4  |  5  |  6  |  +  |  * |TRNS |
 * |------+------+------+------+------+--|   {   |      |  }  |------+------+------+------+------+------|
 * | TRNS  | PgUp|TRNS |PgDn |TRNS |TRNS |-------|      |-------|  1  |  2  |  3  |  0  |  .  | ENT   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LOWER | ALT |      | /Space /       \Enter \  |       | ALT  | RAISE |
 *                   |      |      |      |/       /        \      \ |      |      |        |
 *                   `----------------------------'           '------''--------------------'
 */
[_NUMBERS] = LAYOUT(
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
    KC_TAB,  KC_HOME, KC_UP,   KC_END,  _______, _______,                      KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______, _______,
    KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,  KC_LCBR,   KC_RCBR,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PAST, _______,
    _______, KC_PGUP, _______, KC_PGDN, _______, _______,                      KC_P1,   KC_P2,   KC_P3,   KC_P0,   KC_PDOT, KC_PENT,
                      _______, _______, _______, _______,                      _______, _______, _______, _______
),

/* _SYMBOLS (Ahora activada con RAISE)
 * ,-----------------------------------------.                ,-----------------------------------------.
 * | TRNS  | F1  | F2  | F3  | F4  | F5  |                    | F6  | F7  | F8  | F9  |F10  | F11   |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | TRNS  | TRNS| TRNS| TRNS| TRNS| TRNS|                    |  |  |  `  |  ~  |  ^  | TRNS  | TRNS  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | TRNS  | TRNS| TRNS| TRNS| TRNS| TRNS|-------.      .-------|  _  |  -  |  +  |  =  |  :  |  ;    |
 * |------+------+------+------+---+-----+   <   |      |   >   |-----+------+------+------+------+------|
 * | TRNS  |     |    | TRNS| TRNS| TRNS|-------|      |-------|  ,  |  .  |  '  |  "  |  ¿  |  ¡    |
 * `-----------------------------------------/      /     \      \-----------------------------------------'
 *                   | LOWER | ALT |      | /Space /       \Enter \  |       | ALT  | RAISE |
 *                   |      |      |      |/       /        \      \ |      |      |        |
 *                   `----------------------------'           '------''--------------------'
 */
[_SYMBOLS] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______,                      KC_PIPE, KC_GRV,  KC_TILD, KC_CIRC, _______, _______,
    _______, _______, _______, _______, _______, _______,                      KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  KC_COLN, KC_SCLN,
    _______, _______, _______, _______, _______, _______,  KC_LABK,   KC_RABK,   KC_COMM, KC_DOT,  KC_QUOT, KC_DQUO, KC_IQUS, KC_IEXL,
                      _______, _______, _______, _______,                      _______, _______, _______, _______
)

};
