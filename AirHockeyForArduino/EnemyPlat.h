#pragma once
#include "Plat.h"
#include "Set.h"
#include <UTFT.h>
#include <TouchScreen.h>

class EnemyPlat : public Plat {
private:
  int right = 1;
  void Move(Set);
  
public:
	EnemyPlat();
	void push(UTFT&, Set);
};
