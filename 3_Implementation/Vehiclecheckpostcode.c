#include<avr/io.h>
#include<util/delay.h>
#include<stdio.h>
#define trig 3
#define echo 2
//Servo servo1;
int count=0;
void setup()
{
  Serial.begin(9600);
  //servol.attach(9);
  //pinMode(9, INPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
}
void loop()
{
  int duration,distance;
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
 
  digitalWrite(3,LOW);
  delayMicroseconds(5);
  digitalWrite(3,HIGH);
  delayMicroseconds(10);
  digitalWrite(3,LOW);
  //delayMicroseconds(100);
 
  duration=pulseIn(2,HIGH);
  distance=duration*0.034/2;
  /*Serial.print("Distance=");
  Serial.print(distance);
  Serial.println("cm");*/
 
  if(distance<60)
  {
    Serial.println("Vehicle Approached");
    delay(1000);
    Serial.println("Checking Documents");
    delay(2000);
    Serial.println("Documents are Verified");
    delay(1000);
    Serial.println("Open Gate");
    digitalWrite(4,HIGH);
    delay(100);
    Serial.println("Thank you, You can go");
    Serial.println(" ");
    digitalWrite(5,HIGH);
    delay(1000);
  }
  //delay(1000);
}

