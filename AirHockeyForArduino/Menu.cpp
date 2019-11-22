#include "Menu.h"
#include <UTFT.h>
#include <TouchScreen.h>

void Menu::draw(UTFT& myGLCD) {
    myGLCD.drawLine(0, 120, 319, 120);
    myGLCD.drawLine(160, 0, 160, 240);
    
    myGLCD.drawLine(180, 10, 300, 10);
    myGLCD.drawLine(200, 40, 280, 40);
    myGLCD.drawLine(220, 70, 260, 70);
    myGLCD.drawLine(300, 10, 240, 105);
    myGLCD.drawLine(180, 10, 240, 105);
    
    
    myGLCD.drawLine(180, 140, 300, 140);
    myGLCD.drawLine(300, 140, 180, 220);
    myGLCD.drawLine(180, 220, 300, 220);

    myGLCD.drawLine(30, 60, 130, 60);
    myGLCD.drawLine(130, 10, 130, 110);

    myGLCD.drawLine(100, 180, 120, 180);
    myGLCD.drawLine(80, 200, 80, 220);
    myGLCD.drawLine(60, 180, 40, 180);
    myGLCD.drawLine(80, 160, 80, 140);
    myGLCD.drawCircle(80, 180, 20);
}

void Menu::push(const TSPoint p, UTFT& myGLCD, Name& name, Table table, Set& set) {
  this->draw(myGLCD);
}

//p.x - 180
//-p.y + 875
