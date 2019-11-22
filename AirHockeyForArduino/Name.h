#pragma once
#include <UTFT.h>
#include <TouchScreen.h>
#include <EEPROM.h>

class Name {
private:
public:
  void draw(UTFT&);
  int nameOf = EEPROM.read(4);;
  void picture1(UTFT&);
  void picture2(UTFT&);
  void picture3(UTFT&);
};
