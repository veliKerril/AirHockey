#pragma once
#include "Plat.h"
#include <UTFT.h>
#include <TouchScreen.h>

class EnemyPlat : public Plat {
private:
  int right = 1;
public:
	EnemyPlat();
	void Move();
	void push(UTFT& myGLCD);

};
