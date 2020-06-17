#include <Arduino.h>
#include <Servo.h>

int b1Pin = 14;
int b2Pin = 15;
int servPin =  9;
double pos = 20;

Servo servo;

void setup() 
{
  Serial.begin(9600);
  servo.attach(9);
  pinMode(b1Pin, INPUT);
  pinMode(b2Pin, INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  Serial.println(String(digitalRead(b1Pin)) + ", " + String(digitalRead(b2Pin)));

  if(!digitalRead(b1Pin) && !digitalRead(b2Pin))
  {
    //Serial.println("Locked for flight");
    //Also send a lil message to athena
  }
  else if (!digitalRead(b1Pin))
  {
    pos += 1;
    servo.write(pos);
    //Serial.println("move forward");
  }
  else if (!digitalRead(b2Pin))
  {
    pos -= 1;
    servo.write(pos);
    //Serial.println("move backward");
  }

  delay(10);

}