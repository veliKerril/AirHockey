#include "Set.h"
#include <UTFT.h>
#include <TouchScreen.h>

void Set::picture1(UTFT& myGLCD) {
  myGLCD.fillRect(160, 0, 319, 80);
  delay(2500);
}

void Set::picture2(UTFT& myGLCD) {
  myGLCD.fillRect(160, 80, 319, 160);
  delay(2500);
}

void Set::picture3(UTFT& myGLCD) {
  myGLCD.fillRect(160, 160, 319, 240);
  delay(2500);
}

void Set::picture4(UTFT& myGLCD) {
  myGLCD.fillRect(0, 0, 160, 80);
  delay(2500);
}

void Set::picture5(UTFT& myGLCD) {
  myGLCD.fillRect(0, 80, 160, 160);
  delay(2500);
}

void Set::picture6(UTFT& myGLCD) {
  myGLCD.fillRect(0, 160, 160, 240);
  delay(2500);
}

void Set::draw(UTFT& myGLCD) {
    myGLCD.drawLine(0, 80, 319, 80);
    myGLCD.drawLine(0, 160, 319, 160);
    myGLCD.drawLine(160, 0, 160, 240);
    myGLCD.drawCircle(80, 40, 3);
    myGLCD.drawCircle(120, 120, 3);
    myGLCD.drawCircle(40, 120, 3);
    myGLCD.drawCircle(120, 200, 3);
    myGLCD.drawCircle(80, 200, 3);
    myGLCD.drawCircle(40, 200, 3);
    myGLCD.drawCircle(240, 40, 3);
    myGLCD.drawCircle(280, 120, 3);
    myGLCD.drawCircle(200, 120, 3);
    myGLCD.drawCircle(280, 200, 3);
    myGLCD.drawCircle(240, 200, 3);
    myGLCD.drawCircle(200, 200, 3);
}
