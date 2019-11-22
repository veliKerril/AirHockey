#include "Name.h"
#include <UTFT.h>
#include <TouchScreen.h>

void Name::draw(UTFT& myGLCD) {
  myGLCD.drawLine(20, 20, 60, 60);
  myGLCD.drawRect(20, 100, 60, 140);
  myGLCD.drawCircle(40, 200, 20); 
}

void Name::picture1(UTFT& myGLCD) {
  myGLCD.drawLine(160, 70, 260, 170);
  delay(2500);
}

void Name::picture2(UTFT& myGLCD) {
  myGLCD.drawRect(160, 70, 260, 170);
  delay(2500);
}

void Name::picture3(UTFT& myGLCD) {
  myGLCD.drawCircle(210, 120, 50);
  delay(2500);
}
