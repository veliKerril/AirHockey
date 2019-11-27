//Подкючаем все необходимые библиотеки
#include <UTFT.h>          //Отвечает за вывод информации на экран
#include <TouchScreen.h>   //Отвечает за считывание прикосновения к экрану
#include <EEPROM.h>        //Отвечает за работу с независимой от элекропитания памяти
#include "Ball.h"
#include "Plat.h"
#include "MyPlat.h"
#include "EnemyPlat.h"
#include "Field.h"
#include "Menu.h"
#include "Name.h"
#include "Table.h"
#include "Set.h"

//Подключения шрифтра
extern uint8_t BigFont[];

//Определяем выводы используемые для управления дисплеем 2.8" TFT 320x240 UNO:
const uint8_t RS   = A2; 
const uint8_t WR   = A1; 
const uint8_t CS   = A3; 
const uint8_t RST  = A4; 
const uint8_t SER  = A0;

//Определяем выводы используемые для чтения данных с TouchScreen:
const uint8_t YP   = A2;   // Вывод Y+ должен быть подключен к аналоговому входу
const uint8_t XM   = A3;   // Вывод X- должен быть подключен к аналоговому входу
const uint8_t YM   = 8;    // Вывод Y-
const uint8_t XP   = 9;    // Вывод X+

//Создаём объект для работы с дисплеем
UTFT myGLCD(TFT28UNO, RS, WR, CS, RST, SER);
//Создаём объект для работы со считывания прикосновению к экрану
TouchScreen ts = TouchScreen(XP, YP, XM, YM);

//Объявление всех необходимых объектов
Menu menu;
Name name;
Table table;
Set set;
Field field;
Ball ball;
MyPlat myPlat;
EnemyPlat enemyPlat;
int flag = 1;

void setup(void){
  // Инициируем передачу данных в монитор последовательного порта на скорости 9600 бит/сек
  Serial.begin(9600);
  //Инициируем работу с дисплеем
  myGLCD.InitLCD();
  //Иницилизируем шрифт
  myGLCD.setFont(BigFont);
  //Чистим экран дисплея
  myGLCD.clrScr();

  //Вступительная анимация в виде цветов радуги 
  myGLCD.setColor(226, 87, 30);
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
  myGLCD.setColor(255, 255, 255);
}
  
void loop(){

   //Часть, отвечающая за меню
   while (true)
   { 
      //Считываем показания с экрана: координаты и интенсивность нажатия в структуру p
      TSPoint p = ts.getPoint();
      //Возвращаем режим работы выводов.
      pinMode(XM, OUTPUT);  //Возвращаем режим работы вывода X- в значение «выход» для работы с дисплеем
      pinMode(YP, OUTPUT);  //Возвращаем режим работы вывода Y+ в значение «выход» для работы с дисплеем
      
      //Отрисовка интерфейса меню
      menu.draw(myGLCD);

      //Реакция на нажатия в меню
      if (p.z > 5)
      {
        //Блок с вводом имени
        if ((p.x - 180 > 340)&& (-p.y + 875 > 320))
        {
          myGLCD.clrScr();
          int i = 0;
          while (true)
          {
            TSPoint p1 = ts.getPoint();
            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);
            name.draw(myGLCD);
            if (flag == 1) {
              myGLCD.drawLine(120, 100, 140, 100);
            }
            myGLCD.print(name.nameOf, 100, 98, 90);
            if (p1.z > 1)
            {
              if (-p1.y + 875 < 200) {
                if ((name.nameOf[i] + 1) == '[') name.nameOf[i] = '@';
                EEPROM.write(i + 5, ++name.nameOf[i]);
                myGLCD.print(name.nameOf, 100, 98, 90);
              } else if ((-p1.y + 875 > 200) && (-p1.y + 875 < 500)) {
                flag = 0;
                i++;
                if (i == 1) {
                  myGLCD.setColor(0, 0, 0);
                  myGLCD.drawLine(120, 100, 140, 100);
                  myGLCD.setColor(255, 255, 255);
                  myGLCD.drawLine(120, 120, 140, 120);
                } else {
                  myGLCD.setColor(0, 0, 0);
                  myGLCD.drawLine(120, 120, 140, 120);
                  myGLCD.setColor(255, 255, 255);
                  myGLCD.drawLine(120, 135, 140, 135);
                }
                if (i > 2) {
                  myGLCD.clrScr();
                  flag = 1;
                  break;
                }  
              } 
               else {
                if ((name.nameOf[i] - 1) == '@') name.nameOf[i] = '[';
                EEPROM.write(i + 5, --name.nameOf[i]);
                myGLCD.print(name.nameOf, 100, 98, 90);
              }
            }
          }
        }

        //Блок с таблицой рекордов
        if ((p.x - 180 < 340) && (-p.y + 875 < 320)) {
          myGLCD.clrScr();
          table.draw(myGLCD, name);
          delay(5000);
          myGLCD.clrScr();
        }

        //Блок с настройками скорости и масштаба
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

        //Блок с непосредственно началом игры
        if ((p.x - 180 > 340) && (-p.y + 875 < 320)) {
          myGLCD.clrScr();
          break;
        }
      }
    }

  //Начало игры 
  myGLCD.print(name.nameOf, 20, 4, 90);
  while (true) {
    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);

    //Основная логика игры
    field.push(myGLCD, ball, name);
    myPlat.push(p, myGLCD);
    enemyPlat.push(myGLCD, set);
    ball.push(myGLCD, myPlat, enemyPlat, set, name);

    //Выход из игры в меню
    if ((p.x - 180 < 200 ) && (-p.y + 875 > 650)) {
      ball.enemyPoint = 0;
      ball.myPoint = 0;
      ball.startMy();
      myGLCD.clrScr();
      break;
    }
    
  }
}


/*
 * EEPROM.write(1, 5);     //1  - скорость мяча
 * EEPROM.write(2, 10);    //2  - скорость платформы
 * EEPROM.write(3, 5);     //3  - размер мяча 
 * EEPROM.write(4, 1);     //4  - номер аккаунта
 * EEPROM.write(5, 'A');   //5  - первый символ текущего имени
 * EEPROM.write(6, 'A');   //6  - второй символ текущего имени
 * EEPROM.write(7, 'A');   //7  - третий символ текущего имени
 * EEPROM.write(8, 0);     //8  - рекорд первого места
 * EEPROM.write(9, 'A');   //9  - первый символ первого места
 * EEPROM.write(10, 'A');  //10 - второй символ первого места
 * EEPROM.write(11, 'A');  //11 - третий символ первого места
 * EEPROM.write(12, 0);    //12 - рекорд второго места
 * EEPROM.write(13, 'A');  //13 - первый символ второго места
 * EEPROM.write(14, 'A');  //14 - второй символ второго места
 * EEPROM.write(15, 'A');  //15 - третий символ второго места
 * EEPROM.write(16, 0);    //16 - реорд третьего места
 * EEPROM.write(17, 'A');  //17 - первый символ третьего места
 * EEPROM.write(18, 'A');  //18 - второй символ третьего места
 * EEPROM.write(19, 'A');  //19 - третий символ третьего места
 */
