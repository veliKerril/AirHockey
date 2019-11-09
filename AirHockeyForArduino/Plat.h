#pragma once
#include <UTFT.h>
#include <TouchScreen.h>

class Plat {
protected:
	//The place for the variable responsible for graphic
	//Some "graphic" variable for platform;

	//Current coordinates x of the platform
	double x;

	//Current coordinates y of the platform
	double y;

public:
	//Start platform's parameters
	Plat();

	//Get the current x of the platform
	double getX() const;

	//Get the current y of the platform
	double getY() const;

	//Set the current x of the platform
	void setX(const TSPoint);

	//Set the current y of the platform
	void setY(const TSPoint);

	//Visualization of the platform
	void draw(UTFT&);
};
