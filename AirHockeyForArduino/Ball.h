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
  int myPoint = 0;
  int enemyPoint = 0;

public:
	Ball();
	double getX() const;
	double getY() const;
	void setX(double);
	void setY(double);
  void setMyPoint(int);
  void setEnemyPoint(int);
  int getMyPoint() const;
  int getEnemyPoint() const;
	void push(UTFT&, const MyPlat&, const EnemyPlat&);
	void draw(UTFT&);
	void tr(const MyPlat&, const EnemyPlat&);
	void startMy();
	void startEn();
};
