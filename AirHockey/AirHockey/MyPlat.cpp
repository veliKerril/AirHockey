#include "MyPlat.h"

//Какие начальные данные у моей платформы?
MyPlat::MyPlat() {

}

//Как обработать движение платформы?
void MyPlat::Move() {

}

//Как отрисовать это?
void MyPlat::push(const TSPoint p, UTFT& myGLCD) {
	this->setX(p);
	this->setY(p);
	this->draw(myGLCD);
}