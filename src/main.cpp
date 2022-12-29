#include <Arduino.h>
#include <PID.cpp> 
#include <LED.cpp>

PID pid(0,0,0,0,0);
LED led(0,0,0);
void setup() {
  // put your setup code here, to run once:
  led.init();
}

void loop() {
  // put your main code here, to run repeatedly:
led.setColor(led.WHITE);
}