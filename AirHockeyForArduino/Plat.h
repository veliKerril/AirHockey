#pragma once
#include <UTFT.h>
#include <TouchScreen.h>

class Plat {
protected:
	double x;
	double y;

public:
	Plat();
	double getX() const;
	double getY() const;
	void setX(const TSPoint);
	void setY(const TSPoint);
  void setX(double);
  void setY(double);
	void draw(UTFT&);
};
