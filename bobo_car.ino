#define analogPin1 A1 //最左
#define analogPin2 A2
#define analogPin3 A3
#define analogPin4 A4
#define analogPin5 A5 //最右
int sensorValue1 =digitalRead(A1);
int sensorValue2 =digitalRead(A2);
int sensorValue3 =digitalRead(A3);
int sensorValue4 =digitalRead(A4);
int sensorValue5 =digitalRead(A5);
#define ENA 6
#define IN1 7
#define IN2 5
#define IN3 4
#define IN4 2
#define ENB 3
#include <SoftwareSerial.h>
bool wait=true;
int now_dir=0;
int now_pos=0;
int count_action=0;
int n_act = 0; ////
int reading = 1; ////
char action[100];
bool getting_action=true; ////
SoftwareSerial BT (8, A0);
#include <Servo.h>
Servo myservo;
#include "sanitizer.h"
#include "car_move.h"
#include "LCD.h"
void setup() {
  lcd.begin(16, 2);
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  pinMode(A5,INPUT);
  myservo.attach(9);  //伺服馬達腳位
  Serial.begin(9600);
  BT.begin(9600);
  get_action(); 
}

char receive;
void loop() {
  if(wait){
    if(BT.available()){
      receive=BT.read();
      wait=false;
      if(receive=='#') print_LCD();
      //else if(receive=='?')sanitize();
      else if(receive=='s' )get_action();
    }
  }
   else delay(1000);
}
