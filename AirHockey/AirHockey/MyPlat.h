#pragma once
#include "Plat.h"

class MyPlat : public Plat {
public:
	//Start my platform's parameters
	MyPlat();

	//Responsible for moving my platform
	void Move() override;

	//Change drawing of the platform
	void push(const TSPoint p, UTFT& myGLCD) override;

};