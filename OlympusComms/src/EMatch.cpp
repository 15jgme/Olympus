#include "EMatch.h"
#include "Arduino.h"
#include "thread"
#include "chrono"

EMatch::EMatch(int pinNumber)
{
    pin = pinNumber; //Assign pin to object
    pinMode(pin, OUTPUT); //Set the appropriate pin mode 
}

void EMatch::changeDelay(double delay)
{
    duration = delay;
}

void EMatch::begin()
{
    while(!release){std::this_thread::sleep_for(std::chrono::milliseconds(50));}
    //Fire match
    digitalWrite(pin, HIGH);
    Serial.println("FIRING");

    //Assume the fn is being trigger via a thread
    //Be prepared to catch if this is not the case
    try
    {
        std::this_thread::sleep_for(std::chrono::seconds(duration));
    }
    catch(...)
    {
        Serial.println("thread error");
        delay(duration * 1000);
    }

    //Disable match
    digitalWrite(pin, LOW);
}

void EMatch::fire()
{
    release = true; //Allow fire thread to continue
}

void EMatch::threadRun()
{
    EM_thread = std::thread(EMatch::startLoop, static_cast<void *>(this));
}

void EMatch::startLoop(void *this_ptr)
{
    static_cast<EMatch *>(this_ptr)->begin();
}