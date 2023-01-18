// #include <Arduino.h>

// class PID {
//   public:
//     PID(float kp, float ki, float kd, float minOutput, float maxOutput);
//     void setTarget(float target);
//     void setConstants(float kp, float ki, float kd);
//     void setOutputLimits(float minOutput, float maxOutput);
//     void setTimeStep(unsigned long timeStep);
//     void reset();
//     float update(float currentValue);
//   private:
//     float kp;
//     float ki;
//     float kd;
//     float minOutput;
//     float maxOutput;
//     float target;
//     float integral;
//     float lastError;
//     unsigned long timeStep;
//     unsigned long lastUpdateTime;
// };

// PID::PID(float kp, float ki, float kd, float minOutput, float maxOutput) {
//   this->kp = kp;
//   this->ki = ki;
//   this->kd = kd;
//   this->minOutput = minOutput;
//   this->maxOutput = maxOutput;
//   this->target = 0;
//   this->integral = 0;
//   this->lastError = 0;
//   this->timeStep = 0;
//   this->lastUpdateTime = 0;
// }

// void PID::setTarget(float target) {
//   this->target = target;
// }

// void PID::setConstants(float kp, float ki, float kd) {
//   this->kp = kp;
//   this->ki = ki;
//   this->kd = kd;
// }

// void PID::setOutputLimits(float minOutput, float maxOutput) {
//   this->minOutput = minOutput;
//   this->maxOutput = maxOutput;
// }

// void PID::setTimeStep(unsigned long timeStep) {
//   this->timeStep = timeStep;
// }

// void PID::reset() {
//   this->integral = 0;
//   this->lastError = 0;
//   this->lastUpdateTime = 0;
// }

// float PID::update(float currentValue) {
//   unsigned long currentTime = millis();
//   if (this->lastUpdateTime == 0) {
//     this->lastUpdateTime = currentTime;
//     return 0;
//   }
//   float dt = (currentTime - this->lastUpdateTime) / 1000.0;
//   float error = this->target - currentValue;
//   this->integral += error * dt;
//   float derivative = (error - this->lastError) / dt;
//   this->lastError = error;
//   this->lastUpdateTime = currentTime;
//   float output = this->kp * error + this->ki * this->integral + this->kd * derivative;
//   if (output > this->maxOutput) {
//     output = this->maxOutput;
//   } else if (output < this->minOutput) {
//     output = this->minOutput;
//   }
//   return output;
// }