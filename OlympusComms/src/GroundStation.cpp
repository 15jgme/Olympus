#include <GroundStation.h>
#include <Arduino.h>
#include <BluetoothSerial.h>
#include <thread>
#include <chrono>


GroundStation::GroundStation(){}

BluetoothSerial bt; //Innitialize the bluetooth connection

void GroundStation::begin()
{
    bt.begin("OLYMPUS GSE"); //innitialize BT
}

void GroundStation::startLoop(void *this_ptr)
{
    static_cast<GroundStation *>(this_ptr)->gsListener();
}

void GroundStation::threadRun()
{
    Listen_thread = std::thread (GroundStation::startLoop, static_cast<void *>(this));
}

void GroundStation::gsListener()
{
    Serial.println("GS LISTENEING");
    while(true)
    {
        if(bt.available())
        {
            incoming = bt.readStringUntil('\n');
            incoming.trim();
            Serial.println(incoming);
            newMessage = true;
            parse();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void GroundStation::parse()
{
    if(incoming.equals(trigger_A)){p_A->fire();}
    else if(incoming.equals(trigger_B)){write("RETRACT");}
    else if(incoming.equals(trigger_C)){}
    else
    {
        if(verbose)
        {
            Serial.println("Unrecognized message"); //Also print to BT serial
        }
    }
    
}
void GroundStation::write(String a)
{
    bt.println(a);
}

