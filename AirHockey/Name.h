#pragma once
#include <UTFT.h>
#include <TouchScreen.h>
#include <EEPROM.h>

//Ввод никнейма пользователи
class Name {
public:
  //Массив символов, хранящий введенное имя игрока
  char* nameOf = new char[4] {EEPROM.read(5), EEPROM.read(6), EEPROM.read(7)};

  //Отрисовка блока с вводом имени
  void draw(UTFT&);
};
