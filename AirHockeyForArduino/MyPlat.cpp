#include "MyPlat.h"
#include <UTFT.h>
#include <TouchScreen.h>

void MyPlat::push(const TSPoint p, UTFT& myGLCD) {
  this->setX(p);
  this->setY(p);
	this->draw(myGLCD);
}
