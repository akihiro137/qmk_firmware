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

enum custom_layers {
  LAYER_BASE,
  LAYER_RGB,
  LAYER_ARROW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
      MO( LAYER_RGB ),   KC_KP_7, KC_KP_8, KC_KP_9,    KC_KP_1, KC_KP_2,   KC_KP_3,    KC_KP_MINUS,
      MO( LAYER_ARROW ), KC_KP_4, KC_KP_5, KC_KP_6,    KC_KP_0, KC_KP_DOT, KC_KP_PLUS, KC_KP_ENTER
  ),
  [LAYER_RGB] = LAYOUT(
      _______, RGB_TOG, RGB_M_G, RGB_M_K,      RGB_MOD,  RGB_HUI, RGB_SAI, RGB_VAI,
      _______, RGB_M_B, RGB_M_R, RGB_M_SW,     RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD
  ),
  [LAYER_ARROW] = LAYOUT(
      _______, RCMD(KC_Z), KC_PGUP,    KC_PGDOWN,     KC_HOME, KC_UP,   KC_END,   KC_DELETE,
      _______, RCMD(KC_X), RCMD(KC_C), RCMD(KC_V),    KC_LEFT, KC_DOWN, KC_RIGHT, KC_BSPACE
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
