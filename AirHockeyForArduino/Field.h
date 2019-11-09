#pragma once
#include <UTFT.h>

class Field {
public:
	//Change drawing of the field
	void push(UTFT&);

	//Visualization of the field
	void draw(UTFT&);
};
