#include "Plat.h"

//Начальные значения платформы
Plat::Plat() {}

//Как реализовать обработку входящих данных о движении?
void Plat::Move() {

}

double Plat::getX() const{
	return this->x;
}

double Plat::getY() const {
	return this->y;
}

//Считываю координаты прикосания и назначаю их текущим координатам
void Plat::setX(const TSPoint p) {
	this->x = p.x;
}
void Plat::setY(const TSPoint p) {
	/*добавить условие выхода*/
	this->x = p.y;
}

//Реализация в другом файле
void Plat::push(const TSPoint p, UTFT& myGLCD) {}

//Draw the rect for plat
void Plat::draw(UTFT& myGLCD) {
	myGLCD.drawRect(x - 5, y - 2, x + 5, y + 2);
}