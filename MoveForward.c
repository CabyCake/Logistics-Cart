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

void setup()
{
    AFMS.begin(50);
    Serial.begin(9600);
}

void loop()
{
    int rpm1=Encoder1.getRPM(); 
    int rpm2=Encoder2.getRPM(); 
    int rpm3=Encoder3.getRPM(); 
    int rpm4=Encoder4.getRPM(); 

    DCMotor_1->run(BACKWARD);
    Motor1->setSpeed(50);
    DCMotor_2->run(BACKWARD);
    Motor1->setSpeed(50);
    DCMotor_3->run(BACKWARD);
    Motor1->setSpeed(50);
    DCMotor_4->run(BACKWARD);
    Motor1->setSpeed(50);
}