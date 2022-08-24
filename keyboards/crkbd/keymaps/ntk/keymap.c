/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "keymap_jp.h"
#include "keymap_ctrl.h"
#include "keymap_alt.h"
#include "keymap_gui.h"

#define DELAY_TIME  150

enum layer_number {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _EXTRA,
    _FROGGY
};

#define DL_BAS DF(_BASE)
#define DL_FRG DF(_FROGGY)
#define ML_LOW MO(_LOWER)
#define ML_RAI MO(_RAISE)
#define ML_FNC MO(_FUNCTION)
#define ML_EXT MO(_EXTRA)

#define LW_MHN LT(_LOWER, JP_MHEN)
#define RS_HKN LT(_RAISE, JP_HENK)

#define LT14_SP LT(14, KC_SPC)
#define L_NUM MO(15)

#define RSFT_BSL RSFT_T(JP_BSLS)

#define I_COPY RCTL(KC_INSERT)
#define I_PASTE RSFT(KC_INSERT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x6_3(
// ,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
    KC_TAB,  JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,                         JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,    JP_MINS,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL, JP_A,    JP_S,    JP_D,    JP_F,    JP_G,                         JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN, JP_COLN,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT, JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,                         JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH, RSFT_BSL,
// `--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------'
                                        KC_LALT, LW_MHN,  KC_SPC,     KC_ENT,  RS_HKN,  KC_RGUI
//                                     `--------+--------+--------'  `--------+--------+--------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
// ,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
    KC_ESC,  JP_EXLM, JP_DQUO, JP_HASH, JP_DLR,  JP_PERC,                      JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_CIRC, JP_TILD,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL, JP_1,    JP_2,    JP_3,    JP_4,    JP_5,                         JP_6,    JP_7,    JP_8,    JP_9,    JP_0,    JP_PIPE,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    JP_UNDS, JP_0,    JP_9,    JP_8,    JP_7,    JP_6,                         JP_AT,   JP_LCBR, JP_LBRC, JP_RBRC, JP_RCBR, JP_GRV,
// `--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------'
                                        KC_LALT, _______, KC_SPC,     ALT_ENT, ML_FNC,  KC_RGUI
//                                     `--------+--------+--------'  `--------+--------+--------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
// ,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
    CT_TAB,  CT_Q,    CT_W,    CT_E,    CT_R,    CT_T,                         KC_HOME, KC_PGDN, KC_PGUP, KC_END,  CT_BSP,  CT_DEL,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL, CT_A,    CT_S,    CT_D,    CT_F,    CT_G,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, KC_DEL,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT, CT_Z,    CT_X,    I_COPY,  I_PASTE, CT_B,                         RG_LT,   RG_DN,   RG_UP,   RG_RT,   XXXXXXX, KC_RSFT,
// `--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------'
                                        KC_LALT, ML_FNC,  ALT_SP,     KC_ENT,  _______, KC_RGUI
//                                     `--------+--------+--------'  `--------+--------+--------'
  ),

  [_FUNCTION] = LAYOUT_split_3x6_3(
// ,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
    CS_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, ALT_F4,  XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  KC_F12,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, RG_V,    XXXXXXX,                      RG_LT,   RG_DN,   RG_UP,   RG_RT,   XXXXXXX, KC_RSFT,
// `--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------'
                                        KC_LALT, _______, XXXXXXX,    DL_FRG,  _______, KC_RGUI
//                                     `--------+--------+--------'  `--------+--------+--------'
  ),

  [_EXTRA] = LAYOUT_split_3x6_3(
// ,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
    KC_ESC,  JP_EXLM, JP_DQUO, JP_HASH, JP_DLR,  JP_PERC,                      JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_AT,   JP_GRV,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LCTL, JP_1,    JP_2,    JP_3,    JP_4,    JP_5,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, JP_PLUS, JP_ASTR,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT, JP_0,    JP_9,    JP_8,    JP_7,    JP_6,                         JP_PIPE, JP_LCBR, JP_LABK, JP_RABK, JP_QUES, JP_UNDS,
// `--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------'
                                        KC_LALT, ML_LOW,  _______,    KC_ENT,  ML_RAI,  KC_RGUI
//                                     `--------+--------+--------'  `--------+--------+--------'
  ),

  [_FROGGY] = LAYOUT_split_3x6_3(
// ,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
    JP_HENK, JP_P,    JP_K,    JP_R,    JP_A,    JP_F,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_BSPC, JP_D,    JP_T,    JP_H,    JP_E,    JP_O,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT, JP_Y,    JP_S,    JP_N,    JP_I,    JP_U,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// `--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------'
                                        L_NUM,   LT14_SP, KC_ENT,     DL_BAS,  _______, XXXXXXX
//                                     `--------+--------+--------'  `--------+--------+--------'
  ),

  [14] = LAYOUT_split_3x6_3(
// ,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
    JP_MHEN, JP_J,    JP_M,    JP_B,    JP_QUOT, KC_TAB,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    JP_DOT,  JP_V,    JP_C,    JP_L,    JP_Z,    JP_Q,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RGB_MOD, JP_X,    JP_G,    JP_W,    JP_MINS, KC_DEL,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// `--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------'
                                        KC_LGUI, _______, KC_ENT,     XXXXXXX, _______, XXXXXXX
//                                     `--------+--------+--------'  `--------+--------+--------'
  ),

  [15] = LAYOUT_split_3x6_3(
// ,--------+--------+--------+--------+--------+--------.                    ,--------+--------+--------+--------+--------+--------.
    KC_ESC,  JP_ASTR, JP_7,    JP_8,    JP_9,    JP_MINS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    JP_DOT,  JP_SLSH, JP_4,    JP_5,    JP_6,    JP_PLUS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// |--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    RGB_MOD, JP_0,    JP_1,    JP_2,    JP_3,    JP_U,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
// `--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------'
                                        _______, KC_SPC,  KC_ENT,     XXXXXXX, _______, XXXXXXX
//                                     `--------+--------+--------'  `--------+--------+--------'
  )
};
