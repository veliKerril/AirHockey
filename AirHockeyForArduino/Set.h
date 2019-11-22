#pragma once
#include <UTFT.h>
#include <TouchScreen.h>
#include <EEPROM.h>

class Set {
public:
  void draw(UTFT&);
  int speedOfBall = EEPROM.read(1);;
  int speedOfEnemyPlatform = EEPROM.read(2);;
  int sizeOfBall = EEPROM.read(3);;
  void picture1(UTFT&);
  void picture2(UTFT&);
  void picture3(UTFT&);
  void picture4(UTFT&);
  void picture5(UTFT&);
  void picture6(UTFT&);
};
