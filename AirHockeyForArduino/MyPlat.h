#pragma once
#include "Plat.h"
#include <UTFT.h>
#include <TouchScreen.h>

class MyPlat : public Plat {
public:
	void push(const TSPoint p, UTFT& myGLCD);
};
