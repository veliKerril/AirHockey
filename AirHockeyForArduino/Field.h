#pragma once
#include <UTFT.h>
#include "Ball.h"

class Field {
private:
  void draw(UTFT&);
  void theEnd(UTFT&, Ball&);
  void count(UTFT&, Ball&);
  
public:
	void push(UTFT&, Ball&);
};
