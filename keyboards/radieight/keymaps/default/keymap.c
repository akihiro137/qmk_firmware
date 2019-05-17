/* Copyright 2019 akihiro137
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

#define LAYER( \
  L00, L01, L02, L03, R00, R01, R02, R03, \
  L10, L11, L12, L13, R10, R11, R12, R13 ) \
  { \
    { L03, L02, L01, L00 }, \
    { L13, L12, L11, L10 }, \
    { R00, R01, R02, R03 }, \
    { R10, R11, R12, R13 }, \
  }

#define LAYER_BASE  0
#define LAYER_RGB   1
#define LAYER_ARROW 2
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYER(
      MO( LAYER_RGB ),   KC_7, KC_8, KC_9,   KC_1, KC_2, KC_3, KC_KP_PLUS,
      MO( LAYER_ARROW ), KC_4, KC_5, KC_6,   KC_0, KC_DOT, KC_KP_MINUS, KC_KP_ENTER
  ),
  [LAYER_RGB] = LAYER(
      _______, RGB_TOG, RGB_M_G, RGB_M_K,    RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI,
      _______, RGB_M_B, RGB_M_R, RGB_M_SW,   RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD
  ),
  [LAYER_ARROW] = LAYER(
      _______, _______, _______,   _______,    KC_HOME, KC_UP,   KC_END,   KC_PGUP,
      _______, _______, KC_BSPACE, KC_DELETE,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
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
