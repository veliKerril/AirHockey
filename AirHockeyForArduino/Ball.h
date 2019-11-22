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
  int up = 1;
  int right = 1;
  int myPoint = 0;
  int enemyPoint = 0;
  void draw(UTFT&, Set);
  void tr(const MyPlat&, const EnemyPlat&, Set);
  void startMy();
  void startEn();
  
public:
	Ball();
  void setMyPoint(int);
  void setEnemyPoint(int);
  int getMyPoint() const;
  int getEnemyPoint() const;
  void push(UTFT&, const MyPlat&, const EnemyPlat&, Set);
};
