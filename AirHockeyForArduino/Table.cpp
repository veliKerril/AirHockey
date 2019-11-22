#include "Table.h"
#include <UTFT.h>
#include <TouchScreen.h>

void Table::draw(UTFT& myGLCD) {
  myGLCD.drawLine(0, 140, 319, 140);
  myGLCD.drawLine(106, 0, 106, 240);
  myGLCD.drawLine(212, 0, 212, 240);
  myGLCD.drawLine(250, 50, 290, 90);
  myGLCD.drawRect(140, 50, 180, 90);
  myGLCD.drawCircle(50, 70, 20);

  if (EEPROM.read(5) == 1) {
    myGLCD.drawCircle(260, 170, 5);
  } else if (EEPROM.read(5) == 2) {
    myGLCD.drawCircle(260, 170, 5);
    myGLCD.drawCircle(280, 170, 5);
  } else if (EEPROM.read(5) == 3) {
    myGLCD.drawCircle(260, 170, 5);
    myGLCD.drawCircle(280, 170, 5);
    myGLCD.drawCircle(260, 190, 5);
  } else if (EEPROM.read(5) == 4) {
    myGLCD.drawCircle(260, 170, 5);
    myGLCD.drawCircle(280, 170, 5);
    myGLCD.drawCircle(260, 190, 5);
    myGLCD.drawCircle(280, 190, 5);
  } else if (EEPROM.read(5) == 5) {
    myGLCD.drawCircle(260, 170, 5);
    myGLCD.drawCircle(280, 170, 5);
    myGLCD.drawCircle(260, 190, 5);
    myGLCD.drawCircle(280, 190, 5);
    myGLCD.drawCircle(260, 210, 5);
  } else if (EEPROM.read(5) == 6) {
    myGLCD.drawCircle(260, 170, 5);
    myGLCD.drawCircle(280, 170, 5);
    myGLCD.drawCircle(260, 190, 5);
    myGLCD.drawCircle(280, 190, 5);
    myGLCD.drawCircle(260, 210, 5);
    myGLCD.drawCircle(280, 210, 5);
  } else if (EEPROM.read(5) == 7) {
    myGLCD.drawCircle(270, 200, 10);
  }

  if (EEPROM.read(6) == 1) {
    myGLCD.drawCircle(150, 170, 5);
  } else if (EEPROM.read(6) == 2) {
    myGLCD.drawCircle(150, 170, 5);
    myGLCD.drawCircle(170, 170, 5);

  } else if (EEPROM.read(6) == 3) {
    myGLCD.drawCircle(150, 170, 5);
    myGLCD.drawCircle(170, 170, 5);
    myGLCD.drawCircle(150, 190, 5);
  } else if (EEPROM.read(6) == 4) {
    myGLCD.drawCircle(150, 170, 5);
    myGLCD.drawCircle(170, 170, 5);
    myGLCD.drawCircle(150, 190, 5);
    myGLCD.drawCircle(170, 190, 5);
  } else if (EEPROM.read(6) == 5) {
    myGLCD.drawCircle(150, 170, 5);
    myGLCD.drawCircle(170, 170, 5);
    myGLCD.drawCircle(150, 190, 5);
    myGLCD.drawCircle(170, 190, 5);
    myGLCD.drawCircle(150, 210, 5);
  } else if (EEPROM.read(6) == 6) {
    myGLCD.drawCircle(150, 170, 5);
    myGLCD.drawCircle(170, 170, 5);
    myGLCD.drawCircle(150, 190, 5);
    myGLCD.drawCircle(170, 190, 5);
    myGLCD.drawCircle(150, 210, 5);
    myGLCD.drawCircle(170, 210, 5);
  } else if (EEPROM.read(6) == 7) {
    myGLCD.drawCircle(160, 190, 10);
  }

  if (EEPROM.read(7) == 1) {
    myGLCD.drawCircle(40, 170, 5);
  } else if (EEPROM.read(7) == 2) {
    myGLCD.drawCircle(40, 170, 5);
    myGLCD.drawCircle(60, 170, 5);
  } else if (EEPROM.read(7) == 3) {
    myGLCD.drawCircle(40, 170, 5);
    myGLCD.drawCircle(60, 170, 5);
    myGLCD.drawCircle(40, 190, 5);
  } else if (EEPROM.read(7) == 4) {
    myGLCD.drawCircle(40, 170, 5);
    myGLCD.drawCircle(60, 170, 5);
    myGLCD.drawCircle(40, 190, 5);
    myGLCD.drawCircle(60, 190, 5);
  } else if (EEPROM.read(7) == 5) {
    myGLCD.drawCircle(40, 170, 5);
    myGLCD.drawCircle(60, 170, 5);
    myGLCD.drawCircle(40, 190, 5);
    myGLCD.drawCircle(60, 190, 5);
    myGLCD.drawCircle(40, 210, 5);
  } else if (EEPROM.read(7) == 6) {
    myGLCD.drawCircle(40, 170, 5);
    myGLCD.drawCircle(60, 170, 5);
    myGLCD.drawCircle(40, 190, 5);
    myGLCD.drawCircle(60, 190, 5);
    myGLCD.drawCircle(40, 210, 5);
    myGLCD.drawCircle(60, 210, 5);
  } else if (EEPROM.read(7) == 7) {
    myGLCD.drawCircle(50, 200, 10);
  }
}
