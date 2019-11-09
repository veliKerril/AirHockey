#include "EnemyPlat.h"
#include <UTFT.h>
#include <TouchScreen.h>

EnemyPlat::EnemyPlat() {

}

void EnemyPlat::Move() {

}

void EnemyPlat::push(UTFT& myGLCD) {
	this->x = 300;
  this->y = 120;
  this->draw(myGLCD);
}
