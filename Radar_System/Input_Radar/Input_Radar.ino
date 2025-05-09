#include <Servo.h>
const int greenLight = 7;
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int redLight = 12;
// defining time and distance
long duration;
int distance;
float DistanceSec;
Servo myServo; // Object servo
void setup() {
  pinMode(trigPin, OUTPUT); // trigPin as an Output
  pinMode(echoPin, INPUT); // echoPin as an Input
  pinMode(buzzer,OUTPUT);
  pinMode(redLight, OUTPUT); 
  pinMode(greenLight, OUTPUT);
  Serial.begin(9600);
  myServo.attach(8); // Pin Connected To Servo
  DistanceSec = 20;
}
void loop() {
// rotating servo i++ depicts increment of one degree
  
  for(int i=1;i<=180;i++){
    myServo.write(i);
    delay(10);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    if(distance<=DistanceSec){
      if(distance<=DistanceSec/2){
        tone(buzzer,10); //send 1khz sound
        digitalWrite(redLight,HIGH);
        digitalWrite(greenLight,LOW);
        delay(30);
        noTone(buzzer);
        digitalWrite(redLight,LOW);
//        digitalWrite(greenLight,HIGH);
      }else{
        digitalWrite(buzzer, HIGH);
        digitalWrite(redLight, HIGH);
        digitalWrite(greenLight,LOW);
        delay(30);
        digitalWrite(buzzer, LOW);
      }
    }else{
      digitalWrite(buzzer, LOW);
      digitalWrite(redLight,LOW);
      digitalWrite(greenLight,HIGH);
    }
  }
// Repeats the previous lines from 165 to 15 degrees
  for(int i=180;i>1;i--){
    myServo.write(i);
    delay(30);
    distance = calculateDistance();
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
    if(distance<=DistanceSec){
      if(distance<=DistanceSec/2){
        tone(buzzer,10); //send 1khz sound
        digitalWrite(redLight,HIGH);
        digitalWrite(greenLight,LOW);
        delay(30);
        noTone(buzzer);
        digitalWrite(redLight,LOW);
//        digitalWrite(greenLight,HIGH);
      }else{
        digitalWrite(buzzer, HIGH);
        digitalWrite(redLight, HIGH);
        digitalWrite(greenLight,LOW);
        delay(30);
        digitalWrite(buzzer, LOW);
      }
    }else{
      digitalWrite(buzzer, LOW);
      digitalWrite(redLight,LOW);
      digitalWrite(greenLight,HIGH);
    }
  }
}
int calculateDistance(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  return distance;
}
