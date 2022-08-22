/* Copyright 2020 yushakobo
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "bootloader.h"
#include "keymap_jp.h"
#include "keymap_ctrl.h"
#include "keymap_alt.h"
#include "keymap_gui.h"

#ifdef PROTOCOL_LUFA
#include "lufa.h"
#include "split_util.h"
#endif
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _EXTRA,
    _ANOTHER,
    _ADJUST
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT
};

//Macros
#define LW_MHN LT(_LOWER, JP_MHEN)
#define RS_HKN LT(_RAISE, JP_HENK)
#define SFT_BSL RSFT_T(JP_BSLS)
#define SFT_UND RSFT_T(JP_UNDS)
#define I_COPY RCTL(KC_INSERT)
#define I_PASTE RSFT(KC_INSERT)
#define SFT_CTL RSFT(KC_RCTL)
#define SFT_ALT RSFT(KC_RALT)
#define CTL_ALT RCTL(KC_RALT)

// Layer Mode aliases
#define DL_BAS DF(_BASE)
#define ML_LOW MO(_LOWER)
#define ML_RAI MO(_RAISE)
#define ML_EXT MO(_EXTRA)
#define ML_ATH MO(_ANOTHER)
#define ML_ADJ MO(_ADJUST)

#if MATRIX_ROWS == 10 // HELIX_ROWS == 5
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Esc  |  1   |  2   |  3   |  4   |  5   |             |  6   |  7   |  8   |  9   |  0   | Bsp  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |  Q   |  W   |  E   |  R   |  T   |             |  Y   |  U   |  I   |  O   |  P   |  -   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctl  |  A   |  S   |  D   |  F   |  G   |             |  H   |  J   |  K   |  L   |  ;   |  :   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Sft  |  Z   |  X   |  C   |  V   |  B   | Del  | Bsp  |  N   |  M   |  ,   |  .   |  /   | Sft\ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |CtlSft|CtlAlt|AltSft| Gui  | Alt  | LMHN | Spc  | Ent  | RHKN | Gui  | Left | Down |  Up  | Right|
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT(
      KC_ESC,  JP_1,    JP_2,    JP_3,    JP_4,    JP_5,                      JP_6,    JP_7,    JP_8,    JP_9,    JP_0,    KC_BSPC,
      KC_TAB,  JP_Q,    JP_W,    JP_E,    JP_R,    JP_T,                      JP_Y,    JP_U,    JP_I,    JP_O,    JP_P,    JP_MINS,
      KC_LCTL, JP_A,    JP_S,    JP_D,    JP_F,    JP_G,                      JP_H,    JP_J,    JP_K,    JP_L,    JP_SCLN, JP_COLN,
      KC_LSFT, JP_Z,    JP_X,    JP_C,    JP_V,    JP_B,    KC_DEL,  KC_BSPC, JP_N,    JP_M,    JP_COMM, JP_DOT,  JP_SLSH, SFT_BSL,
      SFT_CTL, CTL_ALT, SFT_ALT, KC_RGUI, KC_LALT, LW_MHN,  KC_SPC,  KC_ENT,  RS_HKN,  KC_RGUI, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
      ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Esc  |  !   |  "   |  #   |  $   |  %   |             |  &   |  '   |  (   |  )   |  ^   |  ~   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctl  |  1   |  2   |  3   |  4   |  5   |             |  6   |  7   |  8   |  9   |  0   |  |   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |  _   |  0   |  9   |  8   |  7   |  6   | Del  | Bsp  |  @   |  {   |  [   |  ]   |  }   |  `   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      | Alt  | Lower| Spc  | AEnt | Anth | Gui  | Home | Pgdn | Pgup | End  |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
      KC_ESC,  JP_EXLM, JP_DQUO, JP_HASH, JP_DLR,  JP_PERC,                   JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_CIRC, JP_TILD,
      KC_LCTL, JP_1,    JP_2,    JP_3,    JP_4,    JP_5,                      JP_6,    JP_7,    JP_8,    JP_9,    JP_0,    JP_PIPE,
      JP_UNDS, JP_0,    JP_9,    JP_8,    JP_7,    JP_6,    KC_DEL,  KC_BSPC, JP_AT,   JP_LCBR, JP_LBRC, JP_RBRC, JP_RCBR, JP_GRV,
      _______, _______, _______, _______, KC_LALT, _______, KC_SPC,  ALT_ENT,  ML_EXT,  KC_RGUI, KC_HOME, KC_PGDN, KC_PGUP,  KC_END
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | CEsc | CtF1 | CtF2 | CtF3 | CtF4 | CtF5 |             | CtF6 | CtF7 | CtF8 | CtF9 | CtF10|      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | CTab | CtlQ | CtlW | CtlE | CtlR | CtlT |             | Home | Pgdn | Pgup | End  |      | Del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Caps | CtlA | CtlS | CtlD | CtlF | CtlG |             | Left | Down |  Up  | Right|      | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Sft  | CtlZ | CtlX | Copy | Paste| CtlB |      |      | GuiL | GuiD | GuiU | GuiR |      | Sft  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      | Alt  | Anth | ASpc | Ent  |      | Gui  |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT(
      _______, CT_F1,   CT_F2,   CT_F3,   CT_F4,   CT_F5,                     CT_F6,   CT_F7,   CT_F8,   CT_F9,   CT_F10,  _______,
      CT_TAB,  CT_Q,    CT_W,    CT_E,    CT_R,    CT_T,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, KC_DEL,
      KC_LCTL, CT_A,    CT_S,    CT_D,    CT_F,    CT_G,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,_______, KC_BSPC,
      KC_LSFT, CT_Z,    CT_X,    I_COPY,  I_PASTE, CT_B,    _______, _______, RG_LT,   RG_DN,   RG_UP,   RG_RT,   _______, KC_RSFT,
      _______, _______, _______, _______, KC_LALT, ML_ATH,  ALT_SP,  KC_ENT,  _______, KC_RGUI, _______, _______, _______, _______
      ),

  /* Another (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ANOTHER] =  LAYOUT(
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      ALT_TAB, _______, _______, _______, ALT_F4,  _______,                   CT_HOME, CT_PGDN, CT_PGUP, CT_END,  KC_INS,  KC_F12,
      KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      KC_LSFT, _______, _______, _______, RG_V,    _______, _______, _______, RG_LT,   RG_DN,   RG_UP,   RG_RT,   _______, KC_RSFT,
      _______, _______, _______, _______, KC_LALT, _______, _______, _______, _______, KC_RGUI, _______, _______, _______, _______
      ),

  /* Extra
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |  Del |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_EXTRA] =  LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL,
      _______, KC_E, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |  Del |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_ADJUST] =  LAYOUT(
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_DEL,
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
      )
};

#else
#error "undefined keymaps"
#endif


#ifdef AUDIO_ENABLE

float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_plover[][2]     = SONG(PLOVER_SOUND);
float tone_plover_gb[][2]  = SONG(PLOVER_GOODBYE_SOUND);
float music_scale[][2]     = SONG(MUSIC_SCALE_SOUND);
#endif

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    #ifdef RGBLIGHT_ENABLE
      //rgblight_mode(RGB_current_mode);
    #endif
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
          //not sure how to have keyboard check mode and set it to a variable, so my work around
          //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(RGBLIGHT_MODE_SNAKE + 1);
          #endif
        }
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);   // revert RGB to initial mode prior to RGB mode change
        #endif
        TOG_STATUS = false;
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        //not sure how to have keyboard check mode and set it to a variable, so my work around
        //uses another variable that would be set to true after the first time a reactive key is pressed.
        if (TOG_STATUS) { //TOG_STATUS checks is another reactive key currently pressed, only changes RGB mode if returns false
        } else {
          TOG_STATUS = !TOG_STATUS;
          #ifdef RGBLIGHT_ENABLE
            //rgblight_mode(RGBLIGHT_MODE_SNAKE);
          #endif
        }
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      } else {
        #ifdef RGBLIGHT_ENABLE
          //rgblight_mode(RGB_current_mode);  // revert RGB to initial mode prior to RGB mode change
        #endif
        layer_off(_RAISE);
        TOG_STATUS = false;
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
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
      //led operations - RGB mode change now updates the RGB_current_mode to allow the right RGB mode to be set after reactive keys are released
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_get_mode();
        }
      #endif
      return false;
      break;
  }
  return true;
}

#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_get_mode();
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}


#ifdef AUDIO_ENABLE

void startup_user()
{
    _delay_ms(20); // gets rid of tick
}

void shutdown_user()
{
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void)
{
    music_scale_user();
}

void music_scale_user(void)
{
    PLAY_SONG(music_scale);
}

#endif
