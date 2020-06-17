#include "LED.h"
#include "thread"
#include "chrono"
#include "Arduino.h"
#include "thread"

LED::LED(int p)
{
    pin = p; //assign pin
    pinMode(pin, OUTPUT); //assign appropriate pinmode
}

void LED::run()
{
    while(true)
    {
        while(release)
        {
            digitalWrite(pin, HIGH);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            digitalWrite(pin, LOW);
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    }
}

void LED::pause()
{
    release = false;
}
void LED::unPause()
{
    release = true;
}

void LED::threadRun()
{
    led_thread = std::thread (LED::startLoop, static_cast<void *>(this));
}

void LED::startLoop(void *this_ptr)
{
    static_cast<LED *>(this_ptr)->run();
}