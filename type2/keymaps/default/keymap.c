/* Copyright 2019 e3w2q
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

#define FN1_ESC     LT(1, KC_ESC)

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  SEND_00 = SAFE_RANGE,
  SEND_000
};

enum encoder_number {
    _1ST_ENC = 0,
    _2ND_ENC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Default Layer
   *  Master Side (USB Cable Connected Side)
   *  ,-------------------------------
   *  | NmLk  KP/  KP*  Tab MO(1)XXXX
   *  |  KP7  KP8  KP9  KP- Home XXXX
   *  |  KP4  KP5  KP6  KP+  End XXXX
   *  |  KP1  KP2  KP3 Entr PgUp XXXX
   *  |  KP0   00    .   Up PgDn XXXX
   *  |   BS  Del Left Down Rght XXXX
   *  `-------------------------------
   *  Slave Side (USB Cable Not Connected Side)
   *  ,-------------------------------
   *  | XXXX XXXX XXXX XXXX XXXX XXXX
   *  | XXXX XXXX XXXX XXXX XXXX XXXX
   *  | XXXX XXXX XXXX XXXX XXXX XXXX
   *  | XXXX XXXX XXXX XXXX XXXX XXXX
   *  | XXXX XXXX XXXX XXXX XXXX XXXX
   *  | XXXX XXXX XXXX XXXX XXXX XXXX
   *  `-------------------------------
   */

  //[0] = LAYOUT( /* Base */
  //  KC_NLCK,  KC_PSLS,  KC_PAST,  KC_TAB,   MO(1),    XXXXXXX,
  //  KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  KC_HOME,  XXXXXXX,
  //  KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  KC_END,   XXXXXXX,
  //  KC_P1,    KC_P2,    KC_P3,    KC_ENT,   KC_PGUP,  XXXXXXX,
  //  KC_P0,    SEND_00,  KC_PDOT,  KC_UP,    KC_PGDN,  XXXXXXX,
  //  KC_BSPC,  KC_DEL,   KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,

  [0] = LAYOUT( /* Base */
    FN1_ESC,  KC_PSLS,  KC_PAST,  KC_PMNS,  KC_BSPC,  XXXXXXX,
    KC_7,     KC_8,     KC_9,     KC_PPLS,  KC_HOME,  XXXXXXX,
    KC_4,     KC_5,     KC_6,     XXXXXXX,  KC_PGUP,  XXXXXXX,
    KC_1,     KC_2,     KC_3,     KC_ENT,   KC_PGDN,  XXXXXXX,
    KC_0,     XXXXXXX,  KC_PDOT,  XXXXXXX,  KC_END,   XXXXXXX,
    C(KC_Z),  C(KC_A),  C(KC_X),  C(KC_C),  C(KC_V),  XXXXXXX
  ),
    
  [1] = LAYOUT(
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_TOG,  RGB_MOD,  RGB_VAI,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_HUI,  RGB_SAI,  RGB_VAD,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    RGB_HUD,  RGB_SAD,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  EE_CLR,   XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  QK_BOOT,  XXXXXXX
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SEND_00:
      if (record->event.pressed) {
        // when keycode SEND_00 is pressed
        SEND_STRING("00");
      } else {
        // when keycode SEND_00 is released
      }
      break;
    case SEND_000:
      if (record->event.pressed) {
        // when keycode SEND_000 is pressed
        //SEND_STRING("000" SS_TAP(X_ENTER));
        SEND_STRING("000");
      } else {
        // when keycode SEND_000 is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
      case _1ST_ENC:
        if (clockwise) {
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
        break;
      case _2ND_ENC:
        if (clockwise) {
          tap_code(KC_PGDN);
        } else {
          tap_code(KC_PGUP);
        }
        break;
    }
    return false;
}

