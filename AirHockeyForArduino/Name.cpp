#include "Name.h"
#include <UTFT.h>
#include <TouchScreen.h>

void Name::draw(UTFT& myGLCD) {
  myGLCD.drawCircle(40, 40, 20);
  myGLCD.drawRect(20, 100, 60, 140);
  myGLCD.drawCircle(40, 200, 20);
}
