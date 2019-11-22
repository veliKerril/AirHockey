#include "EnemyPlat.h"
#include "Set.h"
#include <UTFT.h>
#include <TouchScreen.h>

EnemyPlat::EnemyPlat() {
  x = 300;
  y = 120;  
}

void EnemyPlat::Move(Set set) {  
  if ((y > 200) || (y < 40)) {
    right = (right + 1) % 2;
  }
  
  if (right) {
    y += set.speedOfEnemyPlatform;
  }
  else {
    y -= set.speedOfEnemyPlatform;
  }
  
}

void EnemyPlat::push(UTFT& myGLCD, Set set) {
  this->Move(set);
  this->draw(myGLCD);
}
