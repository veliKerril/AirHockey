#include "MyPlat.h"
#include <UTFT.h>
#include <TouchScreen.h>

MyPlat::MyPlat() {
  prevX = 70;
  prevY = 50;
  x = prevX;
  y = prevY;
}

void MyPlat::push(const TSPoint p, UTFT& myGLCD) {
  prevX = x;
  this->setX(p);
  
  prevY = y;
  this->setY(p);
  
	this->draw(myGLCD);
}
