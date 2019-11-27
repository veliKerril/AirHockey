#pragma once
#include "Plat.h"
#include "Set.h"
#include <UTFT.h>
#include <TouchScreen.h>

//Вражеская платформа
class EnemyPlat : public Plat {
private:
  //Направление движение
  int right = 1;

  //Движение платформы
  void Move(Set);
  
public:
	EnemyPlat();

  //Основная функция взаимодействия с loop()
	void push(UTFT&, Set);
};
