#pragma once
#include <UTFT.h>
#include <TouchScreen.h>
#include "Name.h"
#include "Table.h"
#include "Set.h"

class Menu {
private:
  
public:
  void push(const TSPoint, UTFT&, Name&, Table, Set&);
  void draw(UTFT&);
};
