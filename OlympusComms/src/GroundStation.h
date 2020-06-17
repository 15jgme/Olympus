#ifndef GROUNDSTATION_H
#define GROUNDSTATION_H

#include <EMatch.h>
#include <stdbool.h>
#include <Arduino.h>
#include <thread>

class GroundStation
{
    int threadId = 0;
    bool newMessage = false; //Convert to atomic bool later
    bool verbose = true;
    String incoming = "";
    String trigger_A = "";
    String trigger_B = "";
    String trigger_C = "";

    //OBJECT POINTERS
    EMatch *p_A; //Pointer to EMatch
    
    std::thread Listen_thread;
    
    void parse();
    
    public:
    GroundStation();
    void begin();
    //THREADING CONSIDERATIONS
    static void startLoop(void *thisPtr);
    void threadRun();
    int getThreadId(){return threadId;};
    //END OF THREADING CONSIDERATIONS

    void gsListener();


    void assignTextA(String A){trigger_A = A;} //Assign trigger A
    void assignTextB(String B){trigger_B = B;} //Assign trigger B
    void assignTextC(String C){trigger_C = C;} //Assign trigger C

    //Store pointers for a specific class instance
    void assignFnA(EMatch * fnA){p_A = fnA;} //Assign object to p_A
    
    void write(String a); //Write to the ground station
};
#endif