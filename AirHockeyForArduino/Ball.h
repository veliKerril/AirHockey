#pragma once
#include "MyPlat.h"
#include "EnemyPlat.h"
#include "Set.h"
#include <UTFT.h>
#include <TouchScreen.h>

class Ball {
private:
	double x;
	double y;
  double prevX;
  double prevY;
  int up = 1;
  int right = 1;
  void draw(UTFT&, Set);
  void tr(UTFT&, const MyPlat&, const EnemyPlat&, Set);
  void startEn();
  
public:
	Ball();
  void setMyPoint(int);
  void setEnemyPoint(int);
  int getMyPoint() const;
  int getEnemyPoint() const;
  void push(UTFT&, const MyPlat&, const EnemyPlat&, Set);
  int myPoint = 0;
  int enemyPoint = 0;
  void startMy();
};
