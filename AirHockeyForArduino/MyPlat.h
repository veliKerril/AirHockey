#pragma once
#include "Plat.h"
#include <UTFT.h>
#include <TouchScreen.h>

class MyPlat : public Plat {
private:
  double prevX = 70;
  double prevY = 120;
  
public:
	MyPlat();
	void Move();
	void push(const TSPoint p, UTFT& myGLCD);

};
