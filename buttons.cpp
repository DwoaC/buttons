#include "Arduino.h"
#include "buttons.h"


Button::Button (int pin_, int sign_,
    GeneralFunction func_high_, GeneralFunction func_low_) {
  pin = pin_;
  sign = sign_;
  func_high = func_high_;
  func_low = func_low_;
  setup();
}


Button::Button (int pin_, int sign_,
    GeneralFunction func_high_){
  pin = pin_;
  sign = sign_;
  func_high = func_high_;
  setup();
}

Button::Button (int pin_, GeneralFunction func_high_) {
  pin = pin_;
  sign = LOW;
  func_high = func_high_;
  setup();
}

Button::Button (){
  pin = -1;
  sign = 0;
}

void Button::check() {
  if (digitalRead(pin) == sign) {
    func_high();
  }
}

void Button::setup() {
  pinMode(pin, INPUT_PULLUP);
}


void Buttons::add (Button _button){
  if (count < len) {
    buttons[count] = _button;
    count++;
  }
}

void Buttons::check() {
  for(int i=0; i<count; i++) {
    buttons[i].check();
  }
}
