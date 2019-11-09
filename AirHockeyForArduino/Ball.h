#pragma once
#include "MyPlat.h"
#include "EnemyPlat.h"
#include <UTFT.h>
#include <TouchScreen.h>

class Ball {
private:
	//Current coordinates x of the platform
	double x;

	//Current coordinates y of the ball
	double y;

public:
	//Set start parametrs of the ball
	Ball();

	double getX() const;

	double getY() const;

	void setX(double);

	void setY(double);

	//Change drawing of the ball
	void push(UTFT&, const MyPlat&, const EnemyPlat&);

	//Visualization of the ball
	void draw(UTFT&);

	//Estimation of the ball's trajectory after interection
	//with MyPlat
	void tr(const MyPlat&, const EnemyPlat&);

	//The start position of the ball in the start of game
	//or after missing ball by player
	void startMy();

	//The start position of the ball after missing ball by enemy
	void startEn();
};
