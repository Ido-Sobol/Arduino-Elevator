#include <Arduino.h>
#include <PID.cpp>

class Motor {
  public:
    Motor(int forwardPin, int reversePin, float motorPerPhysicalUnitsRatio, PID pid);
    void setPosition(float wantedPosition);
  private:
int forwardPin; 
int reversePin;
float motorPerPhysicalUnitsRatio;
float power;
PID pid;
};

Motor::Motor(int forwardPin, int reversePin, float motorPerPhysicalUnitsRatio, PID pid) {
    this->forwardPin = forwardPin;
    this->reversePin = reversePin;
    this->motorPerPhysicalUnitsRatio = motorPerPhysicalUnitsRatio;
    this->pid = pid;
}


void Motor::setPosition(float wantedPosition){

}