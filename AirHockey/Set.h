#pragma once
#include <UTFT.h>
#include <TouchScreen.h>
#include <EEPROM.h>

//Настройки скорости и масштаба
class Set {
public:
  //Отрисовка окна с настройками
  void draw(UTFT&);

  //Переменные из нестираемой памяти: скорость мяча,
  //вражеской платформы и размер мяча соответственно
  int speedOfBall = EEPROM.read(1);;
  int speedOfEnemyPlatform = EEPROM.read(2);;
  int sizeOfBall = EEPROM.read(3);;

  //Графическое поддверждения выбора той или иной настройки
  void picture1(UTFT&);
  void picture2(UTFT&);
  void picture3(UTFT&);
  void picture4(UTFT&);
  void picture5(UTFT&);
  void picture6(UTFT&);
};
