#include "Ball.h"

//Что мне нужно в конструкторе мяча?
Ball::Ball() {

}

double Ball::getX() const {
	return this->x;
}

 double Ball::getY() const {
	return this->y;
}

void Ball::setX(double x) {
	this->x = x;
}

void Ball::setY(double y) {
	this->x = y;
}

//Как я буду изменять рисовку мяча?
void Ball::Push() {

}

//Как я буду отрисовывать мяч?
void Ball::Draw() {

}

//Как я буду считать траекторию мяча при соприкосновении со мной?
void Ball::tr() {

}

//Начальное положение мяча при проигрыше или при начале игры
void Ball::startMy() {

}

//Начальное положение мяча при выигрыше
void Ball::startEn() {

}