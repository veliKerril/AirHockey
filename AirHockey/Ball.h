#pragma once
#include "MyPlat.h"
#include "EnemyPlat.h"
#include "Set.h"
#include "Name.h"
#include <UTFT.h>
#include <TouchScreen.h>

class Ball {
private:
  //Текущие координаты
	double x;
	double y;

  //Предшествующие текущим координатам координаты
  double prevX;
  double prevY;
  
  //Отвечающие за направление движения переменные
  int up = 1;
  int right = 1;

  //Отрисовка мяча
  void draw(UTFT&, Set);

  //Высчитывание траектории мяча, а также
  void tr(UTFT&, const MyPlat&, const EnemyPlat&, Set, Name);

  //Функция, отвечающая за старт мяча с вражеской стороны
  void startEn();
  
public:
	Ball();
  void setMyPoint(int);
  void setEnemyPoint(int);
  int getMyPoint() const;
  int getEnemyPoint() const;

  //Основная функция взаимодействия с loop()
  void push(UTFT&, const MyPlat&, const EnemyPlat&, Set, Name);
  
  //Счетчики игрового счета
  int myPoint = 0;
  int enemyPoint = 0;

  //Функция, отвечающая за старт мяча с вражеской стороны
  void startMy();
};
