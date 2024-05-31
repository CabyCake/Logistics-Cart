#include <wire.h>
#include "QGPMaker_MotorShied.h"
#include "QGPMaker_Encoder.h"

QGPMaker_MotorShield AFMS = QGPMaker_MortorShield();
QGPMaker_DCMotor *Motor1 = AFMS.getMotor(1);
QGPMaker_DCMotor *Motor2 = AFMS.getMotor(2);
QGPMaker_DCMotor *Motor3 = AFMS.getMotor(3);
QGPMaker_DCMotor *Motor4 = AFMS.getMotor(4);

QGPMaker_DCMotor *DCMotor_1 = AFMS.getMotor(1);
QGPMaker_Encoder Encoder(1);
QGPMaker_DCMotor *DCMotor_2 = AFMS.getMotor(3);
QGPMaker_Encoder Encoder(2);
QGPMaker_DCMotor *DCMotor_3 = AFMS.getMotor(3);
QGPMaker_Encoder Encoder(3);
QGPMaker_DCMotor *DCMotor_4 = AFMS.getMotor(4);
QGPMaker_Encoder Encoder(4);

io.pinMode(INPUT_PIN_S0, INPUT);
io.pinMode(INPUT_PIN_S1, INPUT);
io.pinMode(INPUT_PIN_S2, INPUT);
io.pinMode(INPUT_PIN_S3, INPUT);
io.pinMode(INPUT_PIN_S4, INPUT);

int stat()
{
    int adval[5];
    int ret = 0;
    for (int i = 0; i < 5; i++)
    {
        adval[i] = io.digitalRead(i);
        if (adval[i] <= 0)
          ret += (0x1 <<i);
    }
    return ret;
}

void turnright (int v)
{
    DCMotor_1->run(BACKWARD);
    Motor1->setSpeed(v);
    DCMotor_2->run(BACKWARD);
    Motor2->setSpeed(v);
    DCMotor_3->run(FORWARD);
    Motor3->setSpeed(v);
    DCMotor_4->run(FORWARD);
    Motor4->setSpeed(v);
    delay(100);
}

void turnleft (int v)
{
    DCMotor_1->run(FORWARD);
    Motor1->setSpeed(v);
    DCMotor_2->run(FORWARD);
    Motor2->setSpeed(v);
    DCMotor_3->run(BACKWARD);
    Motor3->setSpeed(v);
    DCMotor_4->run(BACKWARD);
    Motor4->setSpeed(v);
    delay(100);
}

void moveforward()
{
    DCMotor_1->run(BACKWARD);
    Motor1->setSpeed(180);
    DCMotor_2->run(BACKWARD);
    Motor1->setSpeed(180);
    DCMotor_3->run(BACKWARD);
    Motor1->setSpeed(180);
    DCMotor_4->run(BACKWARD);
    Motor1->setSpeed(180);
}

void loop()
{
    int pos = stat();

    if(pos==B00010||POS==B00001||POS==B00011)
    turnright(160);

    if(pos==B10000)
    turnleft(160);

    moveforward();
}