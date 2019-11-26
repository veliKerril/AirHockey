#include "EnemyPlat.h"
#include "Set.h"
#include <UTFT.h>
#include <TouchScreen.h>

EnemyPlat::EnemyPlat() {
  prevX = 300;
  prevY = 120;
  x = prevX;
  y = prevY;
}

void EnemyPlat::Move(Set set) {  
  if ((y > 200) || (y < 40)) {
    right = (right + 1) % 2;
  }

  if (right) {
    prevY = y;
    y += set.speedOfEnemyPlatform;
  }
  else {
    prevY = y;
    y -= set.speedOfEnemyPlatform;
  }
  
}

void EnemyPlat::push(UTFT& myGLCD, Set set) {
  this->Move(set);
  this->draw(myGLCD);
}
