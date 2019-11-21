//  Данный скетч демонстрирует работу TouchScreen на примере дисплея 2.8 TFT 320x240 UNO http://iarduino.ru/shop/Displei/cvetnoy-graficheskiy-displey-2-8-tft-320x240-uno-sensornyy.html
//  Дисплей выполнен в виде модуля для установки на Arduino UNO                          http://iarduino.ru/shop/arduino/arduino-uno-r3.html
//  Для вывода точек касания используется библиотека UTFT                                http://iarduino.ru/file/54.html
//  Подробное описание работы с сенсорными экранами (TouchScreen) находится по ссылке    http://wiki.iarduino.ru/page/rabota-s-touchscreen/
//  Подробное описание работы с TFT цветными графическими дисплеями находится по ссылке  http://wiki.iarduino.ru/page/rabota-s-cvetnym-graficheskim-displeem/

#include <UTFT.h>
#include <TouchScreen.h>
#include "Ball.h"
#include "Plat.h"
#include "MyPlat.h"
#include "EnemyPlat.h"
#include "Field.h"
    
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
    
//Определяем экстремумы для значений считываемых с аналоговых входов при определении точек нажатия на TouchScreen:
const int tsMinX   = 210;                              // соответствующий точке начала координат по оси X
const int tsMinY   = 205;                              // соответствующий точке начала координат по оси Y
const int tsMaxX   = 930;                              // соответствующий максимальной точке координат по оси X
const int tsMaxY   = 915;                              // соответствующий максимальной точке координат по оси Y
const int mipPress = 1;                                // соответствующий минимальной степени нажатия на TouchScreen
const int maxPress = 1000;                             // соответствующий максимальной степени нажатия на TouchScreen

//Создаём объект для работы с дисплеем
UTFT myGLCD(TFT28UNO, RS, WR, CS, RST, SER);
//Создаём объект для работы с TouchScreen
TouchScreen ts = TouchScreen(XP, YP, XM, YM);

Field field;
Ball ball;
MyPlat myPlat;
EnemyPlat enemyPlat;


void setup(void){
    Serial.begin(9600);                                    // Инициируем передачу данных в монитор последовательного порта на скорости 9600 бит/сек
    myGLCD.InitLCD();                                      // Инициируем работу с TFT дисплеем    
    myGLCD.clrScr();                                       // Чистим экран дисплея
    /*myGLCD.setColor(175, 175, 175);
    myGLCD.fillRect(50, 0, 319, 4);
    myGLCD.fillRect(50, 5, 54, 75);
    myGLCD.fillRect(50, 160, 54, 235);
    myGLCD.fillRect(50, 236, 319, 240);
    myGLCD.fillRect(316, 5, 319, 75);
    myGLCD.fillRect(316, 160, 319, 235);
    myGLCD.setColor(255, 255, 255);*/
}

  
  
void loop(){                                               
    //Считываем показания с TouchScreen. Считываем координаты и интенсивность нажатия на TouchScreen в структуру p
    TSPoint p = ts.getPoint();
    
    //Возвращаем режим работы выводов.
    //Возвращаем режим работы вывода X- в значение «выход» для работы с дисплеем
    pinMode(XM, OUTPUT);
    //Возвращаем режим работы вывода Y+ в значение «выход» для работы с дисплеем
    pinMode(YP, OUTPUT);

    field.push(myGLCD);
    myPlat.push(p, myGLCD);
    enemyPlat.push(myGLCD);
    ball.push(myGLCD, myPlat, enemyPlat);
}

/*myGLCD.setColor(255, 255, 255);
  myGLCD.fillCircle(310, 230, 10);*/
/*//  Если зафиксировано нажатие на TouchScreen, то ...
    if(p.z>mipPress && p.z<maxPress){                      // Если степень нажатия достаточна для фиксации координат TouchScreen
//      Выводим «сырые» показания TouchScreen:
/////// Serial.println((String) "X="+p.x+",\tY="+p.y);
//      Преобразуем значения полученные с TouchScreen в координаты дисплея:
        p.x = map(p.x, tsMinX, tsMaxX, 0, 320);            // Преобразуем значение p.x от диапазона tsMinX...tsMaxX, к диапазону 0...320
        p.y = map(-p.y - 500, tsMinY, tsMaxY, 0, 240);     // Преобразуем значение p.y от диапазона tsMinY...tsMaxY, к диапазону 0...240
//      Выводим преобразованные показания TouchScreen:
/////// Serial.println((String) "("+p.x+","+p.y+")");
//      Выводим точку на экране по координатам с TouchScreen:
        myGLCD.fillCircle(p.x,p.y,3);                    // Прорисовываем окружность диаметром 3 пикселя с центром в точке координат считанных с TouchScreen
    }*/
