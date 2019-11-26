#pragma once
#include <UTFT.h>
#include <TouchScreen.h>
#include <EEPROM.h>

class Name {
private:
public:
  char* nameOf = new char[4] {EEPROM.read(5), EEPROM.read(6), EEPROM.read(7)};
  void draw(UTFT&);
};
