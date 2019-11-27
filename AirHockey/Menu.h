#pragma once
#include <UTFT.h>
#include <TouchScreen.h>
#include "Name.h"
#include "Table.h"
#include "Set.h"

class Menu {
public:
  //Основная функция взаимодействия с loop()
  void push(const TSPoint, UTFT&, Name&, Table, Set&);

  //Отрисовка элементов меню
  void draw(UTFT&);
};
