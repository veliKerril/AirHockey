#include "Ball.h"
#include <UTFT.h>
#include <TouchScreen.h>

Ball::Ball() {
	this->startMy();
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

void Ball::push(UTFT& myGLCD) {
	this->draw(myGLCD);
}

void Ball::draw(UTFT& myGLCD) {
	myGLCD.fillCircle(this->x, this->y, 8);
}


void Ball::tr() {
	/*Define new x and y*/
}

void Ball::startMy() {
	this->x = 50;
  this->y = 120;
}

void Ball::startEn() {
  this->x = 280;
  this->y = 120;	
}
