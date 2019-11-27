#pragma once
#include "Plat.h"
#include <UTFT.h>
#include <TouchScreen.h>

//Моя платформа
class MyPlat : public Plat {
public:
  MyPlat();

  //Основная функция взаимодействия с loop()
	void push(const TSPoint p, UTFT& myGLCD);
};
