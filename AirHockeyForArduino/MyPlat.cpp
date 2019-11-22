#include "MyPlat.h"
#include <UTFT.h>
#include <TouchScreen.h>

void MyPlat::push(const TSPoint p, UTFT& myGLCD) {
  this->setX(p);
  this->setY(p);
	this->draw(myGLCD);
}





 /*if(p.z > 0) { 
    if (this->x <= p.x - 200) {
     this->setXplus();
    } else {
      this->setXminus();
    }
   if (this->y <= -p.y + 600) {
     this->setYplus();
    } else {
      this->setYminus();
    }
  }*/
