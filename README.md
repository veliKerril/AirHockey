# AirHockey
Проектная работа для "Практикума на ЭВМ"
Программа реализует аэрохоккей для arduino с цветным сенсорным экраном с разрешением 320х240.

## **Начало игры.**

При запуске программы пользователь встретит анимированную вставку, после которой попадет в меню.
1. Во вкладке "N" ("Name") пользователь может выбрать желаемый никнейм из 3 символов. Кружечек слева позволяет идти вверх по алфавиту, справа - вниз. Квадратик переключается на следующий символ. Для выхода необходимо пройти все три символа.
2. Во вкладке "T" ("Table") пользователь может посмотреть таблицу рекородов.
3. В нижней правой вкладке находятся настройки (на ней изображена шестеренка). В верхнем ряду пользователь может выбрать желаемую скорость для мяча и вражеской платформе, в нижнем - размер мяча.
4. Нажав на верхнюю левую вкладку, пользователь переходит непосредственно в игру.

По умолчанию стоят заводские настройки и никнейм "ААА". Если программа уже запускалась на устройстве, то имя и настройки сохраняются с предыдущей сессии.

## **Игровой процесс.**

Суть игры заключается в том, чтобы игрок забил гол в ворота противника и не допустил, чтобы он был забит ему.
Игра заканчивается, когда какая-либо сторона набирает семь очков.

1. Поле представляет прямоугольник, нижняя часть которая - наша, верхняя - вражеская.
2. Счет высвечивается справа посередине. На нашей стороны - наши баллы, на вражеской, соответственно, вражеские.
3. В нижнем левом углу высвечивается имя, под которым пользователь зашел в игровую сессию.
4. При желании в правом нижнем углу находится кнопка выхода в меню. При этом весь текущий игровой прогресс будет утерян.

### **Использованные библиотеки**

["UTFT.h"](https://github.com/telamon/utft) была использована для вывода информации на экран.

["TouchScreen.h"](https://github.com/adafruit/Adafruit_TouchScreen) была использована для обработки нажатий на сенсорный экран.

### **Аппаратная поддержка**

Игра тестировалась на следующей конфигурации: "Arduino Uno R3" и "TFT LCD Touch screen 2.4". Подключение их друг к другу интуитивно понятно.
