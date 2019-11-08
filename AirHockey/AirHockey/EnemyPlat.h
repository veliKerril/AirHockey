#pragma once
#include "Plat.h"

class EnemyPlat : public Plat {
public:
	//Start enemy platform's parameters
	EnemyPlat();

	//Get current x of the enemy platform
	const double GetX() override;

	//Get current y of the enemy platform
	const double GetY() override;

	//Set current x of the enemy platform
	void SetX() override;

	//Set current y of the enemy platform
	void SetY() override;

	//Responsible for moving enemy platform
	void Move() override;

	//Change drawing of the platform
	void Push() override;

	//Visualization of the platform
	void Draw() override;
};
