#pragma once
#include <UTFT.h>
#include <TouchScreen.h>
#include <EEPROM.h>
#include "Name.h"

//Таблица рекордов
class Table {
public:
  //Отрисовка таблицы рекордов
  void draw(UTFT&, Name);
};
