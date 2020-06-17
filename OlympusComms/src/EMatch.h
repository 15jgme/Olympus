#ifndef EMATCH_H
#define EMATCH_H
#include "thread"

class EMatch
{
    int pin;
    int duration = 1; //seconds
    bool release = false;
    std::thread EM_thread;

public:
    EMatch(int pinNumber); //GPIO associated with EMatch
    void begin(); //Fire the ematch for a certain time
    void changeDelay(double delay); //Change the firing time from the default
    void fire(); //release firing thread
    bool getFired(){return release;};

    static void startLoop(void *thisPtr);
    //THREADING
    void threadRun(); //Begin the...well...begin thread

};
#endif