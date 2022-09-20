#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <Firebase_ESP_Client.h>
#include "FcmPush.h"
#include "PirModule.h"

//PINES
#define LED_BUILTIN 2
#define PIR_PIN 16
 
  const char* ssid = "Wifi-Casa";
  const char* password = "starbase2040";
  char* FCM_TOPIC = "/topics/casa";

  char* FIREBASE_FCM_SERVER_KEY = "AAAA-mvD_lE:APA91bEPX1XaaqIE-pu48GKlLMGyYEXYJuSdCffvuWMnaCX9ruNTdKH1ESVk6dXc0aqWBerViwSF4YYfsKF-sgWTczqp-a1INR8PvyBa2qwvX3oaZSsbP3rUKDjyb0qn4TATkLAHXICS";
  
  //FCM
  FirebaseData fireData;
  FcmPush pushFcm(FIREBASE_FCM_SERVER_KEY,&fireData);

  //PIR
  PirModule pirModule(PIR_PIN);
  
void setup() {
  // El LED integrado está conectado al pin 2.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);  
  Serial.println((String)"Conectandose a red  (((( "+ssid+" ))))");
  //Conexión a la red
  WiFi.begin(ssid, password); 
  
  while (WiFi.status() != WL_CONNECTED)
  {
    loadAnimation();   
  }
  Serial.println("WiFi conectado");
  Serial.println(WiFi.localIP());
  //Obtenemos la IP
  pushFcm.init();
  pirModule.init();
  readyAnimation();
  pushFcm.sendNotification(FCM_TOPIC,"Sensor Iniciado","El sistema se encuentra listo para operar-");
}
 
void loop() {
   if (pirModule.readState() == HIGH){   // si la señal esta en alto indicando movimiento
      Serial.println("DETECCION");
      pushFcm.sendNotification(FCM_TOPIC,"Movimiento Detectado","El sensor detecto actividad en el area de cobertura.");
      delay(4000);    // demora de 4 segundos
  } else {
    
  }
  
}

void loadAnimation(){
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

void readyAnimation(){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN, HIGH);    
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);        
}
