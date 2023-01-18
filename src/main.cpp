#include <Arduino.h>
const int pin = A1;
const int forward = 6;
const int back = 5;
const int powerPin = 9;
const int potentiometerPin = A3;
double target = 9.8;


// Constants for the PID control
const float kP = 60;
const float kI = 0.5;
const float kD = 7;

// Variables to store the error values and integral
float error;
float prevError;
float integral;

double pid(float target, float current)
{
  // Calculate the error
  error = target - current;

  // Calculate the integral
  integral += error;

  // Calculate the derivative
  float derivative = error - prevError;

  // Calculate the power
  double power = kP * error + kI * integral + kD * derivative;

  // Store the error for the next iteration
  prevError = error;

  return power;
}


void setup()
{
  // put your setup code here, to run once:
  pinMode(pin, INPUT);
  pinMode(potentiometerPin, INPUT);
  Serial.begin(9600);
  pinMode(powerPin, OUTPUT);
  pinMode(back, OUTPUT);
  pinMode(forward, OUTPUT);
}

void loop()
{

  target = map(analogRead(potentiometerPin), 0, 1023, 10.7, 21);
  delay(1);
  double val = analogRead(pin);
  double sensor = exp(8.5841 - log(val)); // worked out from datasheet graph
  double dis = 0;
  // slow down serial port
  for (int i = 0; i < 10; i++)
  {
    dis = dis + sensor;
  }
  dis = dis / 10;
  double power = pid(target, dis) + 70;
  if (power >= 255)
      power = 255;
  

  if (power > 0)
  {
    digitalWrite(forward, HIGH);
    digitalWrite(back, LOW);
  }
  else
  {
    digitalWrite(forward, LOW);
    digitalWrite(back, HIGH);
  }
  analogWrite(powerPin, power);
  Serial.print("power: ");
  Serial.print(power);
  Serial.print(" distance: ");
  Serial.println(dis);
}

