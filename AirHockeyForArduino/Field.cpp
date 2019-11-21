#include "Field.h"
#include <UTFT.h>
#include "Ball.h"

void Field::push(UTFT& myGLCD, Ball& ball) {
	this->draw(myGLCD);
  this->count(myGLCD, ball);
}

void Field::draw(UTFT& myGLCD) {
    myGLCD.fillRect(50, 0, 319, 4);
    myGLCD.fillRect(50, 5, 54, 75);
    myGLCD.fillRect(50, 160, 54, 235);
    myGLCD.fillRect(50, 236, 319, 240);
    myGLCD.fillRect(316, 5, 319, 75);
    myGLCD.fillRect(316, 160, 319, 235);
    myGLCD.fillRect(184, 5, 186, 235);
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(312, 76, 319, 159);
    myGLCD.fillRect(310, 5, 315, 234);
    myGLCD.setColor(255, 255, 255);
}

void Field::count(UTFT& myGLCD, Ball& ball) {
  if (ball.getEnemyPoint() == 1) {
    myGLCD.fillCircle(191, 230, 2);
  } else if (ball.getEnemyPoint() == 2) {
    myGLCD.fillCircle(191, 230, 2);
    myGLCD.fillCircle(201, 230, 2);
  } else if (ball.getEnemyPoint() == 3) {
    myGLCD.fillCircle(191, 230, 2);
    myGLCD.fillCircle(201, 230, 2);
    myGLCD.fillCircle(191, 220, 2); 
  } else if (ball.getEnemyPoint() == 4) {
    myGLCD.fillCircle(191, 230, 2);
    myGLCD.fillCircle(201, 230, 2);
    myGLCD.fillCircle(191, 220, 2);
    myGLCD.fillCircle(201, 220, 2);
  } else if (ball.getEnemyPoint() == 5) {
    myGLCD.fillCircle(191, 230, 2);
    myGLCD.fillCircle(201, 230, 2);
    myGLCD.fillCircle(191, 220, 2);
    myGLCD.fillCircle(201, 220, 2);
    myGLCD.fillCircle(191, 210, 2);
  } else if (ball.getEnemyPoint() == 6) {
    myGLCD.fillCircle(191, 230, 2);
    myGLCD.fillCircle(201, 230, 2);
    myGLCD.fillCircle(191, 220, 2);
    myGLCD.fillCircle(201, 220, 2);
    myGLCD.fillCircle(191, 210, 2);
    myGLCD.fillCircle(201, 210, 2);
  } else if (ball.getEnemyPoint() == 7) {
    this->theEnd(myGLCD, ball);
  }

  if (ball.getMyPoint() == 1) {
    myGLCD.fillCircle(179, 230, 2);
  } else if (ball.getMyPoint() == 2) {
    myGLCD.fillCircle(179, 230, 2);
    myGLCD.fillCircle(169, 230, 2);
  } else if (ball.getMyPoint() == 3) {
    myGLCD.fillCircle(179, 230, 2);
    myGLCD.fillCircle(169, 230, 2);
    myGLCD.fillCircle(179, 220, 2); 
  } else if (ball.getMyPoint() == 4) {
    myGLCD.fillCircle(179, 230, 2);
    myGLCD.fillCircle(169, 230, 2);
    myGLCD.fillCircle(179, 220, 2);
    myGLCD.fillCircle(169, 220, 2);
  } else if (ball.getMyPoint() == 5) {
    myGLCD.fillCircle(179, 230, 2);
    myGLCD.fillCircle(169, 230, 2);
    myGLCD.fillCircle(179, 220, 2);
    myGLCD.fillCircle(169, 220, 2);
    myGLCD.fillCircle(179, 210, 2);
  } else if (ball.getMyPoint() == 6) {
    myGLCD.fillCircle(179, 230, 2);
    myGLCD.fillCircle(169, 230, 2);
    myGLCD.fillCircle(179, 220, 2);
    myGLCD.fillCircle(169, 220, 2);
    myGLCD.fillCircle(179, 210, 2);
    myGLCD.fillCircle(169, 210, 2);
  } else if (ball.getMyPoint() == 7) {
    this->theEnd(myGLCD, ball);
  }
}

void Field::theEnd(UTFT& myGLCD, Ball& ball) {
  if (ball.getMyPoint() == 7) {
    myGLCD.setColor(0, 255, 0);
    myGLCD.fillRect(0, 0, 319, 240);
    myGLCD.setColor(255, 255, 255);
  } else {
    myGLCD.setColor(255, 0, 0);
    myGLCD.fillRect(0, 0, 319, 240);
    myGLCD.setColor(255, 255, 255);
  }
  delay(2000);
  ball.setMyPoint(0);
  ball.setEnemyPoint(0);
  myGLCD.clrScr();
}
