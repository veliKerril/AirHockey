
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

void Ball::setMyPoint(int myPoint) {
  this->myPoint = myPoint;
}

void Ball::setEnemyPoint(int enemyPoint) {
  this->enemyPoint = enemyPoint;
}

void Ball::push(UTFT& myGLCD, const MyPlat& myPlat, const EnemyPlat& enemyPlat) {
  this->tr(myPlat, enemyPlat);
	this->draw(myGLCD);
}




void Ball::tr(const MyPlat& myPlat, const EnemyPlat& enemyPlat) {
	if (   (((x - 15) <=  (myPlat.getX() + 2)) && ((x + 15) >=  (myPlat.getX() - 2)) && (y <=  myPlat.getY() + 20) && (y >=  myPlat.getY() - 20)) // от моей платформы
	    || (((x - 5) <= 55) && ((y >= 160)||(y <= 75))) // от моего дна
	    || ((x + 15) >=  (enemyPlat.getX() - 2) && ((x - 15) <=  (enemyPlat.getX() + 2)) && (y <= enemyPlat.getY() + 20) && (y >= enemyPlat.getY() - 20)) // от вражеской платформы
	    || (((x + 5) >= 315) && ((y >= 160)||(y <= 75)))) { //от вражеского дна
    up = (up + 1) % 2;
	} 

  if (((y) <=  10) || ((y) >= 230)) {
    right = (right + 1) % 2;
  } 
  
  
  if (up) {
    x += 5;
  } else {
    x -= 5;
  }

  if (right) {
    y += 5;
  } else {
    y -= 5;
  }

  if (((x - 5) < 50) && (y > 75) && (y < 160)) {
    enemyPoint += 1;
    this->startMy();
    up += 1;
    delay(1000);
  }

  if (((x + 5) > 320) && (y > 75) && (y < 160)) {
    myPoint += 1;
    this->startEn();
    up -= 1;
    delay(1000);
  }
}

void Ball::startMy() {
	x = 100;
  y = 120;
}

void Ball::startEn() {
  x = 280;
  y = 120;
}

void Ball::draw(UTFT& myGLCD) {
  myGLCD.fillCircle(x, y, 5);
  delay(10);
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillCircle(x, y, 6);
  myGLCD.setColor(255, 255, 255);
}

int Ball::getMyPoint() const {
  return myPoint;  
}

int Ball::getEnemyPoint() const {
  return enemyPoint;
}









/*Serial.println(myPlat.getX() + 2);
  Serial.println(x + 5);
  Serial.println(enemyPlat.getX() - 2);
  Serial.println(up);
  delay(500);
  Serial.println(' ');*/
