#pragma once
#include <UTFT.h>
#include <TouchScreen.h>

//Родительский класс для пользовательской и вражеской платформы
class Plat {
protected:
  //Текущие координаты
	double x;
	double y;

 //Основной метод взаимодействия с loop()
  void draw(UTFT&);

  //Сеттеры, обрабатывающие структуру TSPoint
  void setX(const TSPoint);
  void setY(const TSPoint);

  //Предыдущие к текущим координатам координаты
  double prevX;
  double prevY;
  
public:
	Plat();

  //Геттеры для текущих координат
	double getX() const;
	double getY() const;
};
