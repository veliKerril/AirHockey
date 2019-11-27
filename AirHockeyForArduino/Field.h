#pragma once
#include <UTFT.h>
#include "Ball.h"
#include "Name.h"

//Игровое поле
class Field {
private:
  //Отрисовка игрового поля
  void draw(UTFT&, Name);

  //Обработка конца партии
  void theEnd(UTFT&, Ball&, Name);

  //Обработка игрового счета
  void count(UTFT&, Ball&, Name);
  
public:
  //Основная функция взаимодействия с loop()
	void push(UTFT&, Ball&, Name);
};
