// Copyright 2023 Kostas Pagratis (@kpagratis)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,  KC_8,    KC_9,   KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,  KC_I,    KC_O,   KC_P,    KC_BSLS,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                          KC_LCTL, KC_LALT,                                     KC_MINS, KC_EQL,
                                        KC_LCTL, KC_SPC,  LOWER,   RAISE,   KC_SPC, KC_ENT,
                                        KC_LALT, KC_BSPC, KC_LBRC, KC_RBRC, KC_DEL, KC_LGUI
    ),

    [_RAISE] = LAYOUT(
        KC_GRV ,      _______, _______,    _______,    KC_END,     _______,        _______,    _______, _______, _______, KC_HOME ,   _______,
        LALT(KC_TAB), _______, _______,    _______,    _______,    KC_TRNS,        LCTL(KC_V), _______, KC_INS,  _______, LCTL(KC_C), KC_VOLU,
        _______,      _______, _______,    KC_DEL,     KC_PGDN,    KC_TRNS,        KC_LEFT,    KC_DOWN, KC_UP,   KC_RGHT, KC_MUTE,    KC_VOLD,
        KC_TRNS,      _______, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_PGUP,        _______,    _______, _______, _______, KC_MPLY,    KC_TRNS,
                               _______,    _______,                                                     _______, _______,
                                                 _______, _______,_______,        _______, _______, _______,
                                                 _______, _______,_______,        _______, _______, _______
    ),
    [_LOWER] = LAYOUT(
        KC_F12,       KC_F1,   KC_F2,      KC_F3 ,     KC_F4,      KC_F5,          KC_F6,   KC_F7 ,  KC_F8,   KC_F9,   KC_F10 , KC_F11,
        LALT(KC_TAB), _______, _______,    _______,    _______,    KC_LBRC,        KC_RBRC, KC_P7,   KC_P8,   KC_P9,   KC_PSCR, KC_VOLU,
        _______,      KC_SCRL, KC_INS,     KC_PAUS,    KC_PSCR,    KC_LPRN,        KC_RPRN, KC_P4,   KC_P5,   KC_P6,   KC_MUTE, KC_VOLD,
        KC_TRNS,      _______, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______,        _______, KC_P1,   KC_P2,   KC_P3,   KC_MPLY, KC_TRNS,
                               _______, _______,                                            KC_P0,   KC_PDOT,
                                                 _______, _______,_______, _______, _______, _______,
                                                 _______, _______,_______, _______, _______, _______

    )
};

// Shift + Backspace = Delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);
// Shift + Delete = Backspace
const key_override_t backspace_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DEL, KC_BSPC);

// Shift + esc = ~
const key_override_t tilde_esc_override = ko_make_basic(MOD_MASK_SHIFT, KC_ESC, S(KC_GRV));
// GUI + esc = `
const key_override_t grave_esc_override = ko_make_basic(MOD_MASK_CTRL, KC_ESC, KC_GRV);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&delete_key_override,
    &backspace_key_override,
    &tilde_esc_override,
    &grave_esc_override
};
