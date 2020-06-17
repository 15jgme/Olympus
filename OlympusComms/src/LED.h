#ifndef LED_H
#define LED_H
#endif
#include "thread"

//typedef void (LED::*ledMemFn)(char x);

class LED
{
    int pin;
    bool release = false;
    static void startLoop(void *thisPtr);
    std::thread led_thread;

public:
    LED(int p); //assign GPIO pin
    void run();
    void pause();
    void unPause();

    void threadRun();
};