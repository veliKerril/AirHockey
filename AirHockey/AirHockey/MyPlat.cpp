#include "MyPlat.h"

//����� ��������� ������ � ���� ���������?
MyPlat::MyPlat() {

}

//��� ���������� �������� ���������?
void MyPlat::Move() {

}

//��� ���������� ���?
void MyPlat::push(const TSPoint p, UTFT& myGLCD) {
	this->setX(p);
	this->setY(p);
	this->draw(myGLCD);
}