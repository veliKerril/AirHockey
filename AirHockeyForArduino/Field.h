#pragma once
#include <UTFT.h>
#include <TouchScreen.h>

class Field {
public:
	//Change drawing of the field
	void push();

	//Visualization of the field
	void draw(UTFT&);
};
