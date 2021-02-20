#include "Arduino.h"
#include "buttons.h"

Button::Button() {
  pin = -1;
  func_high = -1;
  func_low = -1;
}

Button::Button(int _pin, GeneralFunction _func_high) {
  pin = _pin;
  func_high = _func_high;
  setup();
}

Button::Button(int _pin, GeneralFunction _func_high, GeneralFunction _func_low) {
  pin = _pin;
  func_high = _func_high;
  func_low = func_low;
  setup();
}

ButtonPin::ButtonPin(
  int _pin, GeneralFunction _func_high
) : Button(
  _pin, _func_high
) {}

ButtonPin::ButtonPin(
  int _pin, GeneralFunction _func_high, GeneralFunction _func_low
) : Button(
  _pin, _func_high, _func_low
) {}

ButtonIR::ButtonIR(
  int _pin, GeneralFunction _func_high
) : Button(
  _pin, _func_high
) {}


void ButtonPin::check() {
  if (pin == -1) {
    return;
  }
  if (digitalRead(pin) == LOW) {
    if (func_high != -1) {
      func_high();
    }
  } else {
    if (func_low != -1 ) {
      func_low();
    }
  }
}

void ButtonPin::setup() {
  pinMode(pin, INPUT_PULLUP);
}

void Buttons::add (Button _button){
  if (count < len) {
    buttons[count] = &_button;
    count++;
  }
}

void Buttons::check() {
  for(int i=0; i<count; i++) {
    buttons[i]->check();
  }
}
