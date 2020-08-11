#include QMK_KEYBOARD_H

#include "kb.h"

#define _MCRO 0
#define _GAME 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_MCRO] = LAYOUT(
		TG(1), KC_PSLS, KC_P7, KC_P8, KC_P9, 
		KC_SLEP, KC_PAST, KC_P4, KC_P5, KC_P6, 
		KC_WHOM, KC_PMNS, KC_P1, KC_P2, KC_P3, 
		LSFT(LALT(KC_F)), KC_PPLS, KC_PEQL, KC_P0, KC_NLCK),

	[_GAME] = LAYOUT(
		TG(1), KC_H, KC_U, KC_Y, KC_T, 
		KC_B, KC_Q, KC_W, KC_E, KC_R, 
		KC_LSFT, KC_A, KC_S, KC_D, KC_F, 
		KC_LCTL, KC_Z, KC_X, KC_G, KC_SPC)
};


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}
azer
static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();

    // Host Keyboard Layer Status
    // oled_write_P(PSTR("Layer: "), false);
    // switch (get_highest_layer(layer_state)) {
    //     case _MCRO:
    //         oled_write_P(PSTR("Macropad\n"), false);
    //         break;
    //     case _GAME:
    //         oled_write_P(PSTR("Gamepad\n"), false);
    //         break;
    //     default:
    //         oled_write_P(PSTR("Undefined\n"), false);
    // }

    // Host Keyboard LED Status
    // uint8_t led_usb_state = host_keyboard_leds();
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    // oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
  }
}
#endif



void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
