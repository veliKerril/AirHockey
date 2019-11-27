#pragma once
#include <UTFT.h>
#include <TouchScreen.h>

//Родительский класс для нашей и вражеской платформы
class Plat {
protected:
  //Текущие координаты
	double x;
	double y;

 //Основная функция взаимодействия с loop()
  void draw(UTFT&);

  //Сетеры, обрабатывающие структуру TSPoint
  void setX(const TSPoint);
  void setY(const TSPoint);

  //Предыдущие текущим координатам координаты
  double prevX;
  double prevY;
  
public:
	Plat();

  //Гетеры для текущих координат
	double getX() const;
	double getY() const;
};
