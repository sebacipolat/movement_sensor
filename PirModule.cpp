#include "PirModule.h"
#include <Arduino.h>

PirModule::PirModule(int  pin) {
  pinMode(pin, INPUT); 
  this->pinData=pin;
}

void PirModule::init() {
   Serial.println("Iniciando sensor PIR........");
  // demora para estabilizar el sensor
  delay(25000);      
  Serial.println("Sensor OK");
}

int PirModule::readState() {
    return digitalRead(this->pinData);
}
