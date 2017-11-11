#include "svarog.h"
#include "led.h"

/**
 * Firmware initialization
 */
void matrix_init_kb(void) {
  matrix_init_user();
};


/**
 * Key polling
 */
void matrix_scan_kb(void) {
  matrix_scan_user();
};


/**
 * OS interfacing with keyboard LED indicators
 */
void led_set_kb(uint8_t usb_led) {
  led_set_user(usb_led);
}
