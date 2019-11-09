#pragma once
#include "Plat.h"
#include <UTFT.h>
#include <TouchScreen.h>

class EnemyPlat : public Plat {
public:
	//Start enemy platform's parameters
	EnemyPlat();

	//Responsible for moving enemy platform
	void Move();

	//Change drawing of the platform
	void push(UTFT& myGLCD);

};
