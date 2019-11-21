#include "Field.h"
#include <UTFT.h>

void Field::push(UTFT& myGLCD) {
	this->draw(myGLCD);
}

void Field::draw(UTFT& myGLCD) {
    myGLCD.fillRect(50, 0, 319, 4);
    myGLCD.fillRect(50, 5, 54, 75);
    myGLCD.fillRect(50, 160, 54, 235);
    myGLCD.fillRect(50, 236, 319, 240);
    myGLCD.fillRect(316, 5, 319, 75);
    myGLCD.fillRect(316, 160, 319, 235);
    myGLCD.fillRect(184, 5, 186, 235);
}
