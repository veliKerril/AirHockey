#pragma once

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

	//Responsible for moving the platform
	virtual void Move();

	//Get the current x of the platform
	double getX() const;

	//Get the current y of the platform
	double getY() const;

	//Set the current x of the platform
	void setX(const TSPoint);

	//Set the current y of the platform
	void setY(const TSPoint);

	//Change drawing of the platform
	virtual void push(const TSPoint p, UTFT& myGLCD);

	//Visualization of the platform
	void draw(UTFT&);
};