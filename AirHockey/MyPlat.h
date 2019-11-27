#pragma once
#include "Plat.h"
#include <UTFT.h>
#include <TouchScreen.h>

//Пользовательская платформа
class MyPlat : public Plat {
public:
  MyPlat();

  //Основной метод взаимодействия с loop()
	void push(const TSPoint p, UTFT& myGLCD);
};
