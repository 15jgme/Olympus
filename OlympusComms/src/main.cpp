#include <Arduino.h>
#include <LED.h>
#include <GroundStation.h>
#include <EMatch.h>

EMatch EM(33);
LED led(22);
GroundStation gs;

void setup() {
  // put your setup code here, to run once:
  EM.threadRun(); //Start ematch thread
  led.threadRun(); //begin led thread 
  gs.begin(); gs.threadRun(); //ISSUES WITH THIS RUN THREAD

  Serial.begin(115200);
  while(!Serial.available()){gs.write("WAITING FOR UNO");} //Await uno system
  gs.assignTextB("RETRACT");
  led.unPause();
  gs.assignTextA("LAUNCH"); gs.assignFnA(&EM); //If text is PARA fire EMs
}

void loop() {
  // put your main code here, to run repeatedly:
}