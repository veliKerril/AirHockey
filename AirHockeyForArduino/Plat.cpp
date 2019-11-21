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
	this->x = p.x - 100;
}
void Plat::setY(const TSPoint p) {
	this->y = -p.y + 600;
}

void Plat::setX(double x) {
  this->x = x;
}
void Plat::setY(double y) {
  this->y = y;
}

void Plat::setXplus() {
  this->x += 15;
}

void Plat::setXminus() {
  this->x -= 15;
}

void Plat::setYplus() {
  this->y += 15;
}

void Plat::setYminus() {
  this->y -= 15;
}


void Plat::draw(UTFT& myGLCD) {
	myGLCD.fillRect(x - 2, y - 20, x + 2, y + 20);
  delay(10);
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(x - 2, y - 20, x + 2, y + 20);
  myGLCD.setColor(225, 225, 225);
  
}
