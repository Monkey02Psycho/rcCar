#include <IRremote.h>
#include <Servo.h>

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;
Servo myservo;

const int controlPin1 = 11;
const int controlPin2 = 3;
const int enablePin = 5;
const int irPin = 2;

int pos = 0;

bool isMotorOn = false;

void setup() {
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);

  myservo.attach(8);
  
  Serial.begin(9600);
  
  irrecv.enableIRIn();

}

void loop() {
  if (irrecv.decode(&results)) {
    if(results.value == 0x511DBB){
      motorMove(true);
      pos++;
    }
    if(results.value == 0xA3C8EDDB){
      motorMove(false);
      pos--;
    }
    if(results.value == 0xE318261B){
      motorState();
    }
    irrecv.resume(); // Receive the next value
  }
  analogWrite(enablePin, isMotorOn);
  Serial.println(isMotorOn);
}

void motorMove(bool motorDirection){
  //left is true, right is false
  if(motorDirection){
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
  if(!motorDirection){
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
}

void motorState(){
  isMotorOn = !isMotorOn;
}
/* up down left right power
511DBB
A3C8EDDB
52A3D41F
20FE4DBB
E318261B

 * 
 * 
 * /
 */
