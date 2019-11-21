#pragma once
#include "MyPlat.h"
#include "EnemyPlat.h"
#include <UTFT.h>
#include <TouchScreen.h>

class Ball {
private:
	double x;
	double y;
  int up = 1;
  int right = 1;
  int MyPoint = 0;
  int EnemyPoint = 0;

public:
	Ball();
	double getX() const;
	double getY() const;
	void setX(double);
	void setY(double);
	void push(UTFT&, const MyPlat&, const EnemyPlat&);
	void draw(UTFT&);
	void tr(const MyPlat&, const EnemyPlat&);
	void startMy();
	void startEn();
};
