#include "MyPlat.h"
#include <UTFT.h>
#include <TouchScreen.h>

MyPlat::MyPlat() {

}

void MyPlat::Move() {

}

void MyPlat::push(const TSPoint p, UTFT& myGLCD) {
	this->setX(p.x);
	this->setY(p.y);
	this->draw(myGLCD);
}
