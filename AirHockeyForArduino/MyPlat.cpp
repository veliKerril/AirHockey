#include "MyPlat.h"
#include <UTFT.h>
#include <TouchScreen.h>

MyPlat::MyPlat() {
  this->setX(20);
  this->setY(120);
}

void MyPlat::Move() {

}

void MyPlat::push(const TSPoint p, UTFT& myGLCD) {
	this->setX(p);
	this->setY(p);
	this->draw(myGLCD);
}
