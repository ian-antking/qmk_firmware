#include QMK_KEYBOARD_H

#define FN1_BSPC    LT(1, KC_BSPC)
#define FN2_SPC     LT(2, KC_SPC)
#define FN3_TAB     LT(3, KC_TAB)
#define FN3_DEL     LT(3, KC_DEL)
#define LALT_C      LALT_T(KC_C)
#define LGUI_V      LGUI_T(KC_V)
#define RGUI_B      RGUI_T(KC_B)
#define SFT_Z       LSFT_T(KC_Z)
#define CTL_X       CTL_T(KC_X)
#define RALT_N      RALT_T(KC_N)
#define CTL_M       RCTL_T(KC_M)
#define SFT_ENT     RSFT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [0] = LAYOUT_ortho_3x10(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ESC,
    SFT_Z,   CTL_X,   LALT_C,  LGUI_V,  FN2_SPC,FN1_BSPC, RGUI_B,  RALT_N,  CTL_M,   SFT_ENT
  ),

  [1] = LAYOUT_ortho_3x10(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    _______, _______, _______, KC_GRV,  KC_QUOT, KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
    _______, _______, _______, _______, FN3_TAB, _______, KC_SCLN, KC_COMM, KC_DOT,  KC_SLSH
  ),

  [2] = LAYOUT_ortho_3x10(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    _______, _______, _______, _______, _______, KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
    _______, _______, _______, _______, _______, FN3_DEL, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
  ),

  [3] = LAYOUT_ortho_3x10(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_F11,  KC_F12,  _______, _______, _______, KC_COMM, KC_DOT,  KC_SLSH, KC_SCLN, KC_QUOT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}
