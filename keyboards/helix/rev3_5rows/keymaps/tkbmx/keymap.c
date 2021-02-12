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
#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

// Defines names for use in layer keycodes and the keymap
enum layer_names {
//  _QWERTY = 0,
  _BASE = 0,
  _QWERTY_L,
  _BEPO_L,
  _SHIFT_OVERLAY,
  _FN,
  _LOWER,
  _RAISE,
  _KEYBOARD
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  //EISU = SAFE_RANGE,
  ADJUST = SAFE_RANGE,
  RGBRST
};

#define FN MO(_FN)
#define TG_LOW TG(_LOWER)
#define TG_RAIS TG(_RAISE)
#define TG_KEYB TG(_KEYBOARD)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define L0 TO(_BASE)
#define L1 TO(_BASE)
#define L2 TO(_BASE)
#define LSHIFT LM(_SHIFT_OVERLAY, MOD_LSFT)
#define CTRL_A C(KC_A)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |   0  |   -  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |   [  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   =  | Bksp |   N  |   M  |   ,  |   .  |   /  |   ]  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |  Fn  | lower| raise| Alt  | GUI  | Space|  Esc | Enter| Space| AltGr| Ctrl |      |   \  |      |
   * `-------------------------------------------------------------------------------------------------'
   */
    [_BASE] = LAYOUT( \
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
      LSHIFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_EQL,   KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC, \
      FN,      LOWER,   KC_LGUI, KC_LALT, RAISE,   KC_SPC, KC_ESC,   KC_ENT,  KC_SPC,  KC_RALT, KC_RCTL, XXXXXXX, KC_BSLS, XXXXXXX  \
    ),
  /* QWERTY
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |   [  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |   Z  |   X  |   C  |   V  |   B  |   =  |      |   N  |   M  |   ,  |   .  |   /  |   ]  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |   \  |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_QWERTY_L] = LAYOUT( \
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
      _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
      _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______  \
    ),
  /* bépo
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   $  |   "  |   «  |   »  |  (   |  )   |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   b  |   é  |   p  |   o  |   è  |             |   Y  |   U  |   I  |   O  |   P  |   [  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |   a  |   u  |   i  |   e  |   ,  |             |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |   à  |   y  |   x  |   .  |   k  |   %  |      |   N  |   M  |   ,  |   .  |   /  |   ]  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |   \  |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_BEPO_L] = LAYOUT( \
      _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
      _______, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, \
      _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
      _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______, _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RBRC, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______  \
    ),
  /*J Fn
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Mute |      |PrtScr| Sleep|      |TgKeyb|             |      |      |   :  |   /  |   *  |   -  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Vol+ |brigh+|      |      |      |      |             |   E  |   F  |   7  |   8  |   9  |   +  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Vol- |brigh-|      |      |      |      |             |   C  |   D  |   4  |   5  |   6  |   +  |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |  ««  | >/|| |  »»  |  x   |      |      |      |  Ins |   A  |   B  |   1  |   2  |   3  | Enter|
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |TgLow |TgRais|      |      |      |      |      |      |      |   0  |   .  |PageDn|PageUp|
   * `-------------------------------------------------------------------------------------------------'
   */
  [_FN] =  LAYOUT( \
      KC_MUTE, XXXXXXX, KC_PSCR, KC_SLEP, XXXXXXX, TG_KEYB,                   XXXXXXX, XXXXXXX, KC_COLN, KC_PSLS, KC_PAST, KC_PMNS, \
      KC_VOLU, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_E,    KC_F,    KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, \
      KC_VOLD, KC_BRID, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_D,    KC_C,    KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS, \
      KC_MRWD, KC_MPLY, KC_MFFD, KC_MSTP, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  KC_A,    KC_B,    KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT, \
      _______, TG_LOW,  TG_RAIS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_KP_0, KC_PDOT, KC_PGDN, KC_PGUP  \
    ),
  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |  F7  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |  F12 |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT( \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
   
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, \
      _______, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17, KC_F18,   KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_F12, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
      ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      | Home |  Up  |  End |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |Ctrl-A|      |      |      |      |             |      | Left | Down | Right|      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      | PgUp |PgDown|      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT( \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, KC_HOME, KC_UP,   KC_END,  _______, _______, \
      _______,  CTRL_A, _______, _______, _______, _______,                   _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_PGDN, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
      ),
  /* Shift overlay
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |  ins |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_SHIFT_OVERLAY] = LAYOUT( \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, KC_INS,  _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
      ),
  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | Reset|RGBRST|EEPRST|      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      | Mac  |             | Win  |      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------+------|
   * |  L0  |  L1  |  L2  |      |      |      |      |      |      |      | MODE | HUE- | SAT- | VAL- |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_KEYBOARD] =  LAYOUT( \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, RESET,   RGBRST,  EEP_RST, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, AG_NORM,                   AG_SWAP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
      L0,      L1,      L2,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD \
      )

};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Left side encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) { /* Right side encoder */
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u," \
            "interrupt: %b, count: %u\n",
            keycode, record->event.key.col, record->event.key.row,
            record->event.pressed, record->event.time,
            record->tap.interrupted, record->tap.count);
#endif
#if 0
    static uint16_t key_timer;
    key_timer = timer_read();

    if (timer_elapsed(key_timer) < 100) {
      // do something if less than 100ms have passed
    } else {
      // do something if 100ms or more have passed
    }
#endif
  switch (keycode) {
//    case EISU:
//      if (record->event.pressed) {
//        if (is_mac_mode()) {
//          register_code(KC_LANG2);
//        }else{
//          tap_code16(LALT(KC_GRAVE));
//        }
//      } else {
//        unregister_code(KC_LANG2);
//      }
//      return false;
//      break;
//    case KANA:
//      if (record->event.pressed) {
//        if (is_mac_mode()) {
//          register_code(KC_LANG1);
//        }else{
//          tap_code16(LALT(KC_GRAVE));
//        }
//      } else {
//        unregister_code(KC_LANG1);
//      }
//      return false;
//      break;
//    case ADJUST:
//      if (record->event.pressed) {
//        layer_on(_LOWER);
//        layer_on(_RAISE);
//      } else {
//        layer_off(_LOWER);
//        layer_off(_RAISE);
//      }
//      break;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }
      #endif
      break;
  }
  return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable=true;
    debug_matrix=true;
#endif
}
