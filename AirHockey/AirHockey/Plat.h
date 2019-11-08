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
	virtual const double GetX();

	//Get the current y of the platform
	virtual const double GetY();

	//Set the current x of the platform
	virtual void SetX();

	//Set the current y of the platform
	virtual void SetY();

	//Change drawing of the platform
	virtual void Push();

	//Visualization of the platform
	virtual void Draw();
};