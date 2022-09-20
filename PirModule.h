#ifndef PirModule_h
#define PirModule_h


class PirModule {
    private:
      int pinData;
      
   public:
     PirModule(int  pin);    
     void init();
     int readState();
};
#endif
