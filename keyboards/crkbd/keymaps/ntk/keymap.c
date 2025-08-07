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
#include "keymap_japanese.h"
#include "keymap_ctl.h"
#include "keymap_alt.h"
#include "keymap_gui.h"

enum layer_number {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _FUNCTION,
    _LEFT_TOOL,
    _LEFT_TOOL_LOWER,
    _LEFT_TOOL_RAISE,
    _EXTRA,
};

#define DL_BAS DF(_BASE)
#define DL_LTL DF(_LEFT_TOOL)
#define ML_FNC MO(_FUNCTION)
#define ML_EXT MO(_EXTRA)

#define LW_MHN LT(_LOWER, JP_MHEN)
#define RS_HKN LT(_RAISE, JP_HENK)
#define LRS_SP LT(_LEFT_TOOL_RAISE, KC_SPC)

#define RSFT_BSL RSFT_T(JP_BSLS)

#define INS_CPY RCTL(KC_INSERT)
#define INS_PST RSFT(KC_INSERT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,                         JP_Y,    JP_U,    JP_I,    JP_O,    JP_P, JP_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    JP_A,    JP_S,    JP_D,    JP_F,    JP_G,                         JP_H,    JP_J,    JP_K,    JP_L, JP_SCLN, JP_COLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,                         JP_N,    JP_M, JP_COMM,  JP_DOT, JP_SLSH,RSFT_BSL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  LW_MHN,  KC_SPC,     KC_ENT,  RS_HKN, KC_RGUI
                                      //`--------------------------'  `--------------------------'

  ),

    [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, JP_EXLM, JP_DQUO, JP_HASH,  JP_DLR, JP_PERC,                      JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_CIRC, JP_TILD,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    JP_1,    JP_2,    JP_3,    JP_4,    JP_5,                         JP_6,    JP_7,    JP_8,    JP_9,    JP_0, JP_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      JP_UNDS,    JP_0,    JP_9,    JP_8,    JP_7,    JP_6,                        JP_AT, JP_LCBR, JP_LBRC, JP_RBRC, JP_RCBR,  JP_GRV,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______,  KC_SPC,    ALT_ENT,  ML_FNC, KC_RGUI
                                      //`--------------------------'  `--------------------------'
  ),

    [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       CT_TAB,    CT_Q,    CT_W,    CT_E,    CT_R,    CT_T,                      KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  CT_BSP,  CT_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    CT_A,    CT_S,    CT_D,    CT_F,    CT_G,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_BSPC,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    CT_Z,    CT_X, INS_CPY, INS_PST,    CT_B,                        RG_LT,   RG_DN,   RG_UP,   RG_RT,CLS_WNDW, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  ML_FNC,  ALT_SP,     KC_ENT, _______, KC_RGUI
                                      //`--------------------------'  `--------------------------'
  ),

    [_FUNCTION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       CS_TAB, XXXXXXX, XXXXXXX, XXXXXXX,CLS_WNDW,    CS_T,                       DL_LTL, XXXXXXX, XXXXXXX, XXXXXXX,  KC_INS,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAPS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX,    CS_V, XXXXXXX,                       CG_LFT,   RG_DN,   RG_UP,  CG_RGT, XXXXXXX, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______, XXXXXXX,    XXXXXXX, _______, KC_RGUI
                                      //`--------------------------'  `--------------------------'
  ),

    [_LEFT_TOOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,CLS_WNDW,    CT_W,  AS_TAB, ALT_TAB,    CT_T,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    CT_A,  A_BACK, KC_HOME,  KC_END,  A_FWRD,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    CT_Z,    CT_X,    CT_C,    CT_V, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT,  LRS_SP,  KC_ENT,     DL_BAS, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [_LEFT_TOOL_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,  KC_ESC,    JP_Q,    JP_W,    JP_E,    JP_T,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LCTL,    JP_A,  A_BACK,  A_FWRD,    JP_F,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LALT, _______,  KC_ENT,     DL_BAS, _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
  [3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT), ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(KC_RGHT, KC_LEFT), },
};
#endif
