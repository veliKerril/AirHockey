#include "Field.h"
#include <UTFT.h>

void Field::push(UTFT& myGLCD) {
	this->draw(myGLCD);
}

void Field::draw(UTFT& myGLCD) {
	myGLCD.fillRect(0, 0, 319, 5);
  myGLCD.fillRect(0, 6, 5, 75);
  myGLCD.fillRect(0, 160, 5, 234);
  myGLCD.fillRect(0, 235, 319, 240);
  myGLCD.fillRect(315, 6, 319, 75);
  myGLCD.fillRect(315, 160, 319, 234);
}
