#include <LiquidCrystal.h>
LiquidCrystal  LCD(12, 11, 5, 4, 3, 2);
 
int  trigPin=9;
int echoPin=7;
int myCounter=0;
int servoControlPin=6;
float pingTime; 
float targetDistance;
float  speedOfSound=776.5;
 
void setup() {
  
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
LCD.begin(16,2);
LCD.setCursor(0,0);
LCD.print("Distance:");
}
 
void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,  HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  
  pingTime = pulseIn(echoPin, HIGH);
  pingTime=pingTime/1000000;
  pingTime=pingTime/3600;
  targetDistance=  speedOfSound * pingTime;
  targetDistance=targetDistance/2;
  targetDistance=  targetDistance*160934,4;

 
  
  LCD.setCursor(0,1);
  LCD.print("                ");
  LCD.setCursor(0,1);
  LCD.print(targetDistance);
  LCD.print("  centimeters");
  delay(250);
  
}
