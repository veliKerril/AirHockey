#include "Ball.h"
#include "MyPlat.h"
#include "EnemyPlat.h"
#include "Set.h"
#include "Name.h"
#include <UTFT.h>
#include <TouchScreen.h>

Ball::Ball() {
	this->startMy();
}

void Ball::setMyPoint(int myPoint) {
  this->myPoint = myPoint;
}

void Ball::setEnemyPoint(int enemyPoint) {
  this->enemyPoint = enemyPoint;
}

void Ball::push(UTFT& myGLCD, const MyPlat& myPlat, const EnemyPlat& enemyPlat, Set set, Name name) {
  this->tr(myGLCD, myPlat, enemyPlat, set, name);
	this->draw(myGLCD, set);
}




void Ball::tr(UTFT& myGLCD, const MyPlat& myPlat, const EnemyPlat& enemyPlat, Set set, Name name) {
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
    prevX = x;
    x += set.speedOfBall;
  } else {
    prevX = x;
    x -= set.speedOfBall;
  }

  if (right) {
    prevY = y;
    y += set.speedOfBall;
  } else {
    prevY = y;
    y -= set.speedOfBall;
  }

  if (((x - 5) < 50) && (y > 75) && (y < 160)) {
    enemyPoint += 1;
    this->startMy();
    up += 1;
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(305, 76, 319, 159);
    myGLCD.fillRect(310, 5, 315, 234);
    myGLCD.drawLine(0, 0, 0, 240);
    myGLCD.fillRect(187, 5, 295, 55);
    myGLCD.fillRect(55, 5, 183, 55);
    myGLCD.fillRect(21, 0, 49, 55);
    myGLCD.fillRect(50, 76, 69, 159);
    myGLCD.setColor(255, 255, 255);
    myGLCD.print(name.nameOf, 20, 4, 90);
    delay(1000);
  }

  if (((x + 5) > 320) && (y > 75) && (y < 160)) {
    myPoint += 1;
    this->startEn();
    up -= 1;
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(305, 76, 319, 159);
    myGLCD.fillRect(310, 5, 315, 234);
    myGLCD.drawLine(0, 0, 0, 240);
    myGLCD.fillRect(187, 5, 295, 55);
    myGLCD.fillRect(55, 5, 183, 55);
    myGLCD.fillRect(21, 0, 49, 55);
    myGLCD.fillRect(50, 76, 69, 159);
    myGLCD.setColor(255, 255, 255);
    myGLCD.print(name.nameOf, 20, 4, 90);
    delay(1000);
  }
}

void Ball::startMy() {
	prevX = 100;
  prevY = 120;
	x = prevX;
  y = prevY;
}

void Ball::startEn() {
  prevX = 280;
  prevY = 120;
  x = prevX;
  y = prevY;
}

void Ball::draw(UTFT& myGLCD, Set set) {
  myGLCD.fillCircle(x, y, set.sizeOfBall);
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillCircle(prevX, prevY, 6);
  myGLCD.setColor(255, 255, 255);
  delay(10);
  
}

int Ball::getMyPoint() const {
  return myPoint;  
}

int Ball::getEnemyPoint() const {
  return enemyPoint;
}
