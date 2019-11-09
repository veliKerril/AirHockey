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

void Plat::setX(double x) {
	this->x = x;
}

void Plat::setY(double y) {
	this->x = y;
}

//Как изменять рисовку платформы?
void Plat::Push() {
	/*В этой функции всегда вызываем Draw и запускаем ее каждую иттерацию*/
}

//Как я буду отрисовывать платформу?
void Plat::Draw() {

}