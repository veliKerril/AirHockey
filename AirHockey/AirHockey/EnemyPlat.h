#pragma once
#include "Plat.h"

class EnemyPlat : public Plat {
public:
	//Start enemy platform's parameters
	EnemyPlat();

	//Responsible for moving enemy platform
	void Move() override;

	//Change drawing of the platform
	void Push() override;

	//Visualization of the platform
	void Draw() override;
};
