#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Firebase_ESP_Client.h>
#include "FcmPush.h"
#include "PirModule.h"
#include "FCM.h"
#include "wifi.h"
#include "LedAnimation.h"

//PINES
#define LED_BUILTIN 2
#define PIR_PIN 5
   
  //FCM
  FirebaseData fireData;
  FcmPush pushFcm(FIREBASE_FCM_SERVER_KEY,&fireData);

  //PIR
  PirModule pirModule(PIR_PIN);

 //Leds
  LedAnimation ledAnimation;
  
  
void setup() {
  // El LED integrado está conectado al pin 2.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);  
  Serial.println((String)"Conectandose a red  (((( "+ssid+" ))))");

  //Conexión a la red
  WiFi.begin(ssid, password); 
  while (WiFi.status() != WL_CONNECTED)
  {
    ledAnimation.loadAnimation();   
  }
  
  Serial.println("WiFi conectado");
  //Obtenemos la IP
  Serial.println(WiFi.localIP());
  
  pushFcm.init();
  pirModule.init();
  ledAnimation.readyAnimation();
  pushFcm.sendNotification(FCM_TOPIC,"Sensor Iniciado","El sistema se encuentra listo para operar-");
}
 
void loop() {
  
    if (pirModule.readState() == HIGH){   // si la señal esta en alto indicando movimiento
      Serial.println("DETECCION");
      pushFcm.sendNotification(FCM_TOPIC,"Movimiento Detectado","El sensor detecto actividad en el area de cobertura.");
      delay(7000);    // demora de 4 segundos
  } else {
    
  }
  
}
