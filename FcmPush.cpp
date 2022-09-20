#include "FcmPush.h"
#include <Firebase_ESP_Client.h>
#include <Arduino.h>


FcmPush::FcmPush(char* tokenFcm, FirebaseData *fireClient) {
      this->fireClient=fireClient;  
      this->token=tokenFcm;  

}

void FcmPush::init(){
      Firebase.FCM.setServerKey(this->token);
      Firebase.reconnectWiFi(true);
}


void FcmPush::sendNotification(char* topic,char* title, char* message){
      FCM_Legacy_HTTP_Message msg;

      msg.targets.to = topic;
      msg.options.time_to_live = "1000";
      msg.options.priority = "high";
      msg.payloads.notification.title = title;
      msg.payloads.notification.body = message;


      if (Firebase.FCM.send(this->fireClient, &msg)) // send message to recipient
          Serial.printf("ok\n%s\n\n", Firebase.FCM.payload(this->fireClient).c_str());
      else
          Serial.println(this->fireClient->errorReason());
          
}
