
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




void Ball::tr(const MyPlat& myPlat, const EnemyPlat& enemyPlat) {
	if (((x - 15) <=  (myPlat.getX() + 2)) || ((x + 15) >=  (enemyPlat.getX() - 2)) || (((x - 5) <= 55) && ((y >= 160)||(y <= 75)))) {
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
    MyPoint += 1;
    this->startMy();
    up += 1;
  }

  if (((x + 5) > 320) && (y > 75) && (y < 160)) {
    EnemyPoint += 1;
    this->startEn();
    up -= 1;
  }
}

void Ball::startMy() {
	x = 100;
  y = 120;
  if (MyPoint > 6) {
    MyPoint = 0;
    EnemyPoint = 0;
  }
}

void Ball::startEn() {
  x = 280;
  y = 120;
  if (EnemyPoint > 6) {
    MyPoint = 0;
    EnemyPoint = 0;
  }
}

void Ball::draw(UTFT& myGLCD) {
  myGLCD.fillCircle(x, y, 5);
  delay(10);
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillCircle(x, y, 6);
  myGLCD.setColor(255, 255, 255);
}
/*Serial.println(myPlat.getX() + 2);
  Serial.println(x + 5);
  Serial.println(enemyPlat.getX() - 2);
  Serial.println(up);
  delay(500);
  Serial.println(' ');*/
