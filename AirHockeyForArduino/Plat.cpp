#include "Plat.h"
#include <UTFT.h>
#include <TouchScreen.h>

//��������� �������� ���������
Plat::Plat() {}

//��� ����������� ��������� �������� ������ � ��������?
void Plat::Move() {

}

double Plat::getX() const{
	return this->x;
}

double Plat::getY() const {
	return this->y;
}

void Plat::setX(const TSPoint p) {
	this->x = p.x;
}
void Plat::setY(const TSPoint p) {
	/*Check deadline*/
	this->x = p.y;
}

void Plat::push(const TSPoint p, UTFT& myGLCD) {}

//Draw the rect for plat
void Plat::draw(UTFT& myGLCD) {
	myGLCD.drawRect(x - 5, y - 2, x + 5, y + 2);
}
