#pragma once
#include <UTFT.h>
#include "Ball.h"
#include "Name.h"

class Field {
private:
  void draw(UTFT&, Name);
  void theEnd(UTFT&, Ball&, Name);
  void count(UTFT&, Ball&, Name);
  
public:
	void push(UTFT&, Ball&, Name);
};
