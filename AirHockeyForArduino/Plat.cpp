#include "Plat.h"
#include <UTFT.h>
#include <TouchScreen.h>

Plat::Plat() {}

double Plat::getX() const{
	return this->x;
}

double Plat::getY() const {
	return this->y;
}

void Plat::setX(const TSPoint p) {
	this->x = p.x + 100;
}
void Plat::setY(const TSPoint p) {
	/*Check deadline*/
	this->y = -p.y;
}

//Draw the rect for plat
void Plat::draw(UTFT& myGLCD) {
	myGLCD.fillRect(x - 2, y - 20, x + 2, y + 20);
  delay(20);
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(x - 2, y - 20, x + 2, y + 20);
  myGLCD.setColor(255, 255, 255);
}
