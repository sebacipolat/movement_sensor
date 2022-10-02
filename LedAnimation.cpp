#include "LedAnimation.h"
#include <Arduino.h>

LedAnimation::LedAnimation() {
  
}


void LedAnimation::loadAnimation() {
    Serial.println("  /");
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("  -");
    delay(200);
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("  \\");
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("  |");
    delay(200);
}

void LedAnimation::readyAnimation() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);    
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);       
}
