#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"

typedef void (*GeneralFunction) ();

class Button {
  public:
    int pin;
    int sign;
    GeneralFunction func_high;
    GeneralFunction func_low;
    Button(int, int, GeneralFunction, GeneralFunction);
    Button(int, int, GeneralFunction);
    Button(int, GeneralFunction);
    Button();
    void check();
  private:
    void setup();
};


class Buttons {
  public:
    static const int len = 10;
    int count = 0;
    Button buttons[len];
    void add(Button);
    void check();
};

#endif
