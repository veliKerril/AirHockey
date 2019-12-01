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

    if (EEPROM.read(2) == 10) {
      myGLCD.drawLine(170, 30, 180, 40);
      myGLCD.drawLine(170, 50, 180, 40);
    } else if (EEPROM.read(2) == 20) {
      myGLCD.drawLine(170, 110, 180, 120);
      myGLCD.drawLine(170, 130, 180, 120);
    } else {
      myGLCD.drawLine(170, 190, 180, 200);
      myGLCD.drawLine(170, 210, 180, 200);
    }

    if (EEPROM.read(3) == 3) {
      myGLCD.drawLine(10, 30, 20, 40);
      myGLCD.drawLine(10, 50, 20, 40);
    } else if (EEPROM.read(3) == 4) {
      myGLCD.drawLine(10, 110, 20, 120);
      myGLCD.drawLine(10, 130, 20, 120);
    } else {
      myGLCD.drawLine(10, 190, 20, 200);
      myGLCD.drawLine(10, 210, 20, 200);
    }
}
