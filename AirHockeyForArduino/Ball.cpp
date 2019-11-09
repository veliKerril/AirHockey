
#include "Ball.h"
#include "MyPlat.h"
#include "EnemyPlat.h"
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

void Ball::push(UTFT& myGLCD, const MyPlat& myPlat, const EnemyPlat& enemyPlat) {
  this->tr(myPlat, enemyPlat);
	this->draw(myGLCD);
}

void Ball::draw(UTFT& myGLCD) {
	myGLCD.fillCircle(this->x, this->y, 5);
  myGLCD.setColor(0, 0, 0);
  delay(20);
  myGLCD.fillCircle(this->x, this->y, 5);
  myGLCD.setColor(255, 255, 255);
}


void Ball::tr(const MyPlat& myPlat, const EnemyPlat& enemyPlat) {
	if ((this->x - 5) <=  (myPlat.getX() + 2)){
    this->x += 2;
	} else if ((this->x + 5) >=  (enemyPlat.getX() - 2)) {
    this->x -= 2;
	}
}

void Ball::startMy() {
	this->x = 50;
  this->y = 120;
}

void Ball::startEn() {
  this->x = 280;
  this->y = 120;	
}
