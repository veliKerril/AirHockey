#include "EnemyPlat.h"
#include <UTFT.h>
#include <TouchScreen.h>

EnemyPlat::EnemyPlat() {
  this->setX(300);
  this->setY(120);  
}

void EnemyPlat::Move() {  
  if ((y > 200) || (y < 40)) {
    right = (right + 1) % 2;
  }
  
  if (right) {
    y += 10;
  }
  else {
    y -= 10;
  }
  
}

void EnemyPlat::push(UTFT& myGLCD) {
  this->Move();
  this->draw(myGLCD);
}
