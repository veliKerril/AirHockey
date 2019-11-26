#include <UTFT.h>
#include <TouchScreen.h>
#include <EEPROM.h>
#include "Ball.h"
#include "Plat.h"
#include "MyPlat.h"
#include "EnemyPlat.h"
#include "Field.h"
#include "Menu.h"
#include "Name.h"
#include "Table.h"
#include "Set.h"


//Определяем выводы используемые для управления дисплеем 2.8" TFT 320x240 UNO:
const uint8_t RS   = A2;                               // 
const uint8_t WR   = A1;                               // 
const uint8_t CS   = A3;                               // 
const uint8_t RST  = A4;                               // 
const uint8_t SER  = A0;                               // 
//Определяем выводы используемые для чтения данных с TouchScreen:
const uint8_t YP   = A2;                               // Вывод Y+ должен быть подключен к аналоговому входу
const uint8_t XM   = A3;                               // Вывод X- должен быть подключен к аналоговому входу
const uint8_t YM   = 8;                                // Вывод Y-
const uint8_t XP   = 9;                                // Вывод X+

//Создаём объект для работы с дисплеем
UTFT myGLCD(TFT28UNO, RS, WR, CS, RST, SER);
//Создаём объект для работы с TouchScreen
TouchScreen ts = TouchScreen(XP, YP, XM, YM);

Menu menu;
Name name;
Table table;
Set set;
Field field;
Ball ball;
MyPlat myPlat;
EnemyPlat enemyPlat;

void setup(void){
    // Инициируем передачу данных в монитор последовательного порта на скорости 9600 бит/сек
    Serial.begin(9600);
    // Инициируем работу с TFT дисплеем
    myGLCD.InitLCD();
    // Чистим экран дисплея
    myGLCD.clrScr();

    /*myGLCD.setColor(226, 87, 30);
    myGLCD.fillRect(0, 0, 319, 240);
    myGLCD.setColor(255, 127, 0);
    myGLCD.fillRect(0, 0, 319, 240);
    myGLCD.setColor(255, 255, 0);
    myGLCD.fillRect(0, 0, 319, 240);
    myGLCD.setColor(150, 191, 51);
    myGLCD.fillRect(0, 0, 319, 240);
    myGLCD.setColor(0, 0, 255);
    myGLCD.fillRect(0, 0, 319, 240);
    myGLCD.setColor(75, 0, 130);
    myGLCD.fillRect(0, 0, 319, 240);
    myGLCD.setColor(139, 0, 255);
    myGLCD.fillRect(0, 0, 319, 240);
    delay(1500);
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRect(0, 0, 319, 240);
    myGLCD.setColor(255, 255, 255);*/
    
   
}
  
void loop(){

   while (true)
    {
      TSPoint p = ts.getPoint();
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      menu.draw(myGLCD);
      if (p.z > 5)
      {
        if ((p.x - 180 > 340)&& (-p.y + 875 > 320))
        {
          myGLCD.clrScr();
          while (true)
          {
            TSPoint p1 = ts.getPoint();
            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            name.draw(myGLCD);
            if (p1.z > 5)
            {
              if (-p1.y + 875 < 200) {
                name.nameOf = 1;
                EEPROM.write(4, 1);
                name.picture1(myGLCD);
                myGLCD.clrScr();
                break;
              } else if ((-p1.y + 875 > 200) && (-p1.y + 875 < 500)) {
                name.nameOf = 2;
                EEPROM.write(4, 2);
                name.picture2(myGLCD);
                myGLCD.clrScr();
                break;
              } else {
                name.nameOf = 3;
                EEPROM.write(4, 3);
                name.picture3(myGLCD);
                myGLCD.clrScr();
                break;
              }
            }
          }
        }
        
        if ((p.x - 180 < 340) && (-p.y + 875 < 320)) {
          myGLCD.clrScr();
          table.draw(myGLCD);
          delay(5000);
          myGLCD.clrScr();
        }
        
        if ((p.x - 180 < 340) && (-p.y + 875 > 320)) {
          myGLCD.clrScr();
          while (true)
          {
            TSPoint p2 = ts.getPoint();
            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            set.draw(myGLCD);
            if (p2.z > 5)
            {
              if (p2.x - 180 > 340) {
                if ((-p2.y + 875 < 200) ) {
                  set.speedOfBall = 5;
                  EEPROM.write(1, 5);
                  set.speedOfEnemyPlatform = 10;
                  EEPROM.write(2, 10);
                  set.picture1(myGLCD);
                  myGLCD.clrScr();
                  break;
                } else if ((-p2.y + 875 > 200) && (-p2.y + 875 < 500)) {
                  set.speedOfBall = 5;
                  EEPROM.write(1, 5);
                  set.speedOfEnemyPlatform = 20;
                  EEPROM.write(2, 20);
                  set.picture2(myGLCD);
                  myGLCD.clrScr();
                  break;
                } else{
                  set.speedOfBall = 10;
                  EEPROM.write(1, 10);
                  set.speedOfEnemyPlatform = 30;
                  EEPROM.write(2, 30);
                  set.picture3(myGLCD);
                  myGLCD.clrScr();
                  break;
                }
                } else {
                  if (-p2.y + 875 < 200) {
                    set.sizeOfBall = 3;
                    EEPROM.write(3, 3);
                    set.picture4(myGLCD);
                    myGLCD.clrScr();
                    break;
                  } else if ((-p2.y + 875 > 200) && (-p2.y + 875 < 500)) {
                    set.sizeOfBall = 4;
                    EEPROM.write(3, 4);
                    set.picture5(myGLCD);
                    myGLCD.clrScr();
                    break;
                  } else {
                    set.sizeOfBall = 5;
                    EEPROM.write(3, 5);
                    set.picture6(myGLCD);
                    myGLCD.clrScr();
                    break;
                  }
              }
            }
          }
        }
        
        if ((p.x - 180 > 340) && (-p.y + 875 < 320)) {
          myGLCD.clrScr();
          break;
        }
      }
    }

  while (true) {
    //Считываем показания с TouchScreen. Считываем координаты и интенсивность нажатия на TouchScreen в структуру p
    TSPoint p = ts.getPoint();

    //Возвращаем режим работы выводов.
    //Возвращаем режим работы вывода X- в значение «выход» для работы с дисплеем
    pinMode(XM, OUTPUT);
    //Возвращаем режим работы вывода Y+ в значение «выход» для работы с дисплеем
    pinMode(YP, OUTPUT);
  
    field.push(myGLCD, ball, name);
    myPlat.push(p, myGLCD);
    enemyPlat.push(myGLCD, set);
    ball.push(myGLCD, myPlat, enemyPlat, set);

    if ((p.x - 180 < 200 ) && (-p.y + 875 > 650)) {
      ball.enemyPoint = 0;
      ball.myPoint = 0;
      ball.startMy();
      myGLCD.clrScr();
      break;
    }
    
  }
}


/*EEPROM.write(1, 5);   //1 - скорость мяча
  EEPROM.write(2, 10);  //2 - скорость платформы
  EEPROM.write(3, 5);   //3 - размер мяча 
  EEPROM.write(4, 1);   //4 - номер аккаунта
  EEPROM.write(5, 0);   //5 - счет первого аккаунта
  EEPROM.write(6, 0);   //6 - счет второго аккаунта
  EEPROM.write(7, 0);   //7 - счет третьего аккаунта*/
