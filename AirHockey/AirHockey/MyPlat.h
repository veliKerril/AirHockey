#pragma once
#include "Plat.h"

class MyPlat : public Plat {
public:
	//Start my platform's parameters
	MyPlat();

	//Get current x of the my platform
	const double GetX() override;

	//Get current y of the my platform
	const double GetY() override;

	//Set current x of the my platform
	void SetX() override;

	//Set current y of the my platform
	void SetY() override;

	//Responsible for moving my platform
	void Move() override;

	//Change drawing of the platform
	void Push() override;

	//Visualization of the platform
	void Draw() override;
};