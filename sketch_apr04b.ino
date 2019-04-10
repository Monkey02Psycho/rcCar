const int controlPin1 = 11;
const int controlPin2 = 3;
const int enablePin = 5;
const int irPin = 2;


void setup() {
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  
  digitalWrite(controlPin1, LOW);
  digitalWrite(controlPin2, HIGH);
  
  digitalWrite(enablePin, HIGH);
  
  Serial.begin(9600);
  delay(2000); while (!Serial); //delay for Leonardo

}

void loop() {
  if (Serial.available() > 0) {
    bool incomingByte = Serial.read() - 48;
    if(incomingByte){
      Serial.println("works");
    }
    Serial.println(incomingByte);
    motorMove(incomingByte);
  }
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
