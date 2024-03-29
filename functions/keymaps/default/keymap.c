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

#define FN1_F12     LT(1, KC_F12)
#define FN2_F11     LT(2, KC_F11)

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

  [0] = LAYOUT( /* Base */
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    XXXXXXX,
    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   XXXXXXX,
    FN2_F11,  FN1_F12,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_A,     KC_B,     XXXXXXX
  ),
  
  [1] = LAYOUT(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,    XXXXXXX,
    KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    XXXXXXX,
    FN2_F11,  _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  [2] = LAYOUT(
    XXXXXXX,  XXXXXXX,  XXXXXXX,  EE_CLR,   XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  QK_RBT,   XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

};

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
          tap_code(KC_VOLU);
        } else {
          tap_code(KC_VOLD);
        }
        break;
    }
    return false;
}
