#pragma once
#include <UTFT.h>
#include <TouchScreen.h>

class Plat {
protected:
	double x;
	double y;
  void draw(UTFT&);
  void setX(const TSPoint);
  void setY(const TSPoint);
  
public:
	Plat();
	double getX() const;
	double getY() const;
};
