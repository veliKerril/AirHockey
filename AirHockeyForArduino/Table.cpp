#include "Table.h"
#include <UTFT.h>
#include <TouchScreen.h>
#include "Name.h"

void Table::draw(UTFT& myGLCD, Name name) {
  myGLCD.drawLine(0, 140, 319, 140);
  myGLCD.drawLine(106, 0, 106, 240);
  myGLCD.drawLine(212, 0, 212, 240);
  char ch1 = EEPROM.read(9);
  char ch2 = EEPROM.read(10);
  char ch3 = EEPROM.read(11);
  char* ch = new char[4] {ch1, ch2, ch3};
  myGLCD.print(ch, 278, 50, 90);
  ch1 = EEPROM.read(13);
  ch2 = EEPROM.read(14);
  ch3 = EEPROM.read(15);
  ch[0] = ch1;
  ch[1] = ch2;
  ch[2] = ch3;
  myGLCD.print(ch, 168, 50, 90);
  ch1 = EEPROM.read(17);
  ch2 = EEPROM.read(18);
  ch3 = EEPROM.read(19);
  ch[0] = ch1;
  ch[1] = ch2;
  ch[2] = ch3;
  myGLCD.print(ch, 58, 50, 90);

  if (EEPROM.read(8) == 1) {
    myGLCD.fillCircle(260, 170, 5);
  } else if (EEPROM.read(8) == 2) {
    myGLCD.fillCircle(260, 170, 5);
    myGLCD.fillCircle(280, 170, 5);
  } else if (EEPROM.read(8) == 3) {
    myGLCD.fillCircle(260, 170, 5);
    myGLCD.fillCircle(280, 170, 5);
    myGLCD.fillCircle(260, 190, 5);
  } else if (EEPROM.read(8) == 4) {
    myGLCD.fillCircle(260, 170, 5);
    myGLCD.fillCircle(280, 170, 5);
    myGLCD.fillCircle(260, 190, 5);
    myGLCD.fillCircle(280, 190, 5);
  } else if (EEPROM.read(8) == 5) {
    myGLCD.fillCircle(260, 170, 5);
    myGLCD.fillCircle(280, 170, 5);
    myGLCD.fillCircle(260, 190, 5);
    myGLCD.fillCircle(280, 190, 5);
    myGLCD.fillCircle(260, 210, 5);
  } else if (EEPROM.read(8) == 6) {
    myGLCD.fillCircle(260, 170, 5);
    myGLCD.fillCircle(280, 170, 5);
    myGLCD.fillCircle(260, 190, 5);
    myGLCD.fillCircle(280, 190, 5);
    myGLCD.fillCircle(260, 210, 5);
    myGLCD.fillCircle(280, 210, 5);
  } else if (EEPROM.read(8) == 7) {
    myGLCD.setColor(255, 215, 0);
    myGLCD.fillCircle(270, 190, 10);
    myGLCD.setColor(255, 255, 255);
  }

  if (EEPROM.read(12) == 1) {
    myGLCD.fillCircle(150, 170, 5);
  } else if (EEPROM.read(12) == 2) {
    myGLCD.fillCircle(150, 170, 5);
    myGLCD.fillCircle(170, 170, 5);
  } else if (EEPROM.read(12) == 3) {
    myGLCD.fillCircle(150, 170, 5);
    myGLCD.fillCircle(170, 170, 5);
    myGLCD.fillCircle(150, 190, 5);
  } else if (EEPROM.read(12) == 4) {
    myGLCD.fillCircle(150, 170, 5);
    myGLCD.fillCircle(170, 170, 5);
    myGLCD.fillCircle(150, 190, 5);
    myGLCD.fillCircle(170, 190, 5);
  } else if (EEPROM.read(12) == 5) {
    myGLCD.fillCircle(150, 170, 5);
    myGLCD.fillCircle(170, 170, 5);
    myGLCD.fillCircle(150, 190, 5);
    myGLCD.fillCircle(170, 190, 5);
    myGLCD.fillCircle(150, 210, 5);
  } else if (EEPROM.read(12) == 6) {
    myGLCD.fillCircle(150, 170, 5);
    myGLCD.fillCircle(170, 170, 5);
    myGLCD.fillCircle(150, 190, 5);
    myGLCD.fillCircle(170, 190, 5);
    myGLCD.fillCircle(150, 210, 5);
    myGLCD.fillCircle(170, 210, 5);
  } else if (EEPROM.read(12) == 7) {
    myGLCD.setColor(255, 215, 0);
    myGLCD.fillCircle(160, 190, 10);
    myGLCD.setColor(255, 255, 255);
  }

  if (EEPROM.read(16) == 1) {
    myGLCD.fillCircle(40, 170, 5);
  } else if (EEPROM.read(16) == 2) {
    myGLCD.fillCircle(40, 170, 5);
    myGLCD.fillCircle(60, 170, 5);
  } else if (EEPROM.read(16) == 3) {
    myGLCD.fillCircle(40, 170, 5);
    myGLCD.fillCircle(60, 170, 5);
    myGLCD.fillCircle(40, 190, 5);
  } else if (EEPROM.read(16) == 4) {
    myGLCD.fillCircle(40, 170, 5);
    myGLCD.fillCircle(60, 170, 5);
    myGLCD.fillCircle(40, 190, 5);
    myGLCD.fillCircle(60, 190, 5);
  } else if (EEPROM.read(16) == 5) {
    myGLCD.fillCircle(40, 170, 5);
    myGLCD.fillCircle(60, 170, 5);
    myGLCD.fillCircle(40, 190, 5);
    myGLCD.fillCircle(60, 190, 5);
    myGLCD.fillCircle(40, 210, 5);
  } else if (EEPROM.read(16) == 6) {
    myGLCD.fillCircle(40, 170, 5);
    myGLCD.fillCircle(60, 170, 5);
    myGLCD.fillCircle(40, 190, 5);
    myGLCD.fillCircle(60, 190, 5);
    myGLCD.fillCircle(40, 210, 5);
    myGLCD.fillCircle(60, 210, 5);
  } else if (EEPROM.read(16) == 7) {
    myGLCD.setColor(255, 215, 0);
    myGLCD.fillCircle(50, 190, 10);
    myGLCD.setColor(255, 255, 255);
  }
}
