#include <wire.h>
#include "QGPMaker_MotorShied.h"

QGPMaker_MotorShield AFMS = QGPMaker_MotorShield(); //创建驱动对象

QGPMaker_Servo *Servo1 = AFMS.getServo(0); //获取3号舵机
QGPMaker_Servo *Servo2 = AFMS.getServo(3);
QGPMaker_Servo *Servo3 = AFMS.getServo(4);
QGPMaker_Servo *Servo4 = AFMS.getServo(7);

void setup()
{
    Serial.begin(9600);
    Serial.println("DC Motor Test!");
    AFMS.begin(50);
}

void loop()
{
    Servo1->wroteServo(160);
    Servo2->wroteServo(140);
    Servo3->wroteServo(0);
    Servo4->wroteServo(30);
    delay(5000);

    Servo3->writeServo(100);
    delay(1000);
    Servo1->writeServo(145);
    delay(300);
    Servo1->writeServo(130);
    delay(300);
    Servo2->writeServo(90);
    delay(500);
    Servo2->writeServo(75);
    delay(500);
    Servo2->writeServo(60);
    delay(3000);

    Servo2->writeServo(85);
    Servo3->writeServo(82);
    delay(500);
    Servo1->writeServo(120);

    Servo2->writeServo(120);
    Servo3->writeServo(64);
    delay(500);
    Servo1->writeServo(110);

    Servo2->writeServo(140);
    Servo3->writeServo(48);
    delay(500);
    Servo1->writeServo(100);
    delay(1000);

    Servo4->weiteServo(68);
    delay(1000);

    Servo1->writeServo(160);
    Servo2->writeServo(140);
    Servo3->writeServo(0);
    delay(10000000);
}