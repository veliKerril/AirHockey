#include "Plat.h"
#include <UTFT.h>
#include <TouchScreen.h>

Plat::Plat() {}

double Plat::getX() const{
	return this->x;
}

double Plat::getY() const {
	return this->y;
}

//Коллибровка входящей из нажатий на экран информации
void Plat::setX(const TSPoint p) {
	this->x = p.x - 100;
}

void Plat::setY(const TSPoint p) {
	this->y = -p.y + 600;
}

void Plat::draw(UTFT& myGLCD) {
  double rX = abs(x - prevX);
  double rY = abs(y - prevY);

  //Именно этот алгоритм позволяет не мигать объектам при движении
  if ((rX < 5) && (rY < 40)) {
	myGLCD.fillRect(x - 2, y - 20, x + 2, y + 20);
  myGLCD.setColor(0, 0, 0);
  myGLCD.fillRect(x - 2 - rX, y - 20 - rY, x - 2, y + 20 + rY);
  myGLCD.fillRect(x + 2, y - 20 - rY, x + 2 + rX, y + 20 + rY);
  myGLCD.fillRect(x - 2 - rX, y - 20 - rY, x + 2 + rX, y - 20);
  myGLCD.fillRect(x - 2 - rX, y + 20, x + 2 + rX, y + 20 + rY);
  myGLCD.setColor(225, 225, 225);
  delay(10);
  } else {
    myGLCD.fillRect(x - 2, y - 20, x + 2, y + 20);
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(prevX - 2, prevY - 20, prevX + 2, prevY + 20);
    myGLCD.setColor(225, 225, 225);
    delay(10);
  }
  
}
