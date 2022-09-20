#ifndef FcmPush_h
#define FcmPush_h
#include <Firebase_ESP_Client.h>


class FcmPush {
    private:
      FirebaseData *fireClient;
      char* token;

     
   public:
     FcmPush(char* token,FirebaseData *fireClient);    
     void init();
     void sendNotification(char* topic,char* title, char * message);

};
#endif
