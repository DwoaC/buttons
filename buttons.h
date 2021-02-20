#ifndef Buttons_h
#define Buttons_h

#include "Arduino.h"

typedef void (*GeneralFunction) ();

class Button {
  public:
    int pin;
    Button();
    Button(int, GeneralFunction);
    Button(int, GeneralFunction, GeneralFunction);

    GeneralFunction func_high;
    GeneralFunction func_low;
    virtual void check() {};
    virtual void setup() {};
};

class ButtonPin : public Button {
  public:
    ButtonPin(int, GeneralFunction);
    ButtonPin(int, GeneralFunction, GeneralFunction);
    void check();
    void setup();
};

class ButtonIR : public Button {
  public:
    ButtonIR(int, GeneralFunction);
    // ButtButtonIRon(int, GeneralFunction, GeneralFunction) ;
    void check(){};
    void setup(){};
};


class Buttons {
  public:
    static const int len = 10;
    int count = 0;
    Button* buttons[len];
    void add(Button);
    void check();
};

#endif
