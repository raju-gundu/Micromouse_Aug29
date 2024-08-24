// Define motor control pins
//A- left & B-Right
#define AIN1 27
#define AIN2 14
#define PWMA 13
#define BIN1 25
#define BIN2 33
#define PWMB 32
#define STBY 26

// ratio = 0.9833

#define leftSpeed 180
#define rightSpeed 180

void motorInit() {
  // Set control pins as output
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(STBY, OUTPUT);
  delay(5000);
  // Set motor standby pin HIGH to enable motors
  digitalWrite(STBY, HIGH);
  
}

void moveForward(){
  //left wheel
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, leftSpeed); // Max speed

  //right wheel
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, rightSpeed); // Max speed
  

}

void stopMotors(){
  

  // Stop left Motor 
  
  analogWrite(PWMA, LOW);
  // Stop Motor B
  
  analogWrite(PWMB, LOW);
}

void turnLeft(){
  //left wheel reverse
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 80);// Max speed

    //right wheel forward
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 120);
}

void turnRight(){
  delay(100);
  stopMotors();
  delay(100);
  //left wheel forward
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 100);// Max speed

  //right wheel reverse
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, 80);
  delay(100);
}
// void loop() {
//   // Test Motor A - Forward
//   digitalWrite(AIN1, LOW);
//   digitalWrite(AIN2, HIGH);
//   analogWrite(PWMA, leftSpeed); // Max speed
//   Serial.println("L_Speed: "+leftSpeed);
  
  
  // // Stop Motor A
  // analogWrite(PWMA, 0);
  // delay(1000);
  
  // // Test Motor A - Reverse
  // digitalWrite(AIN1, LOW);
  // digitalWrite(AIN2, HIGH);
  // analogWrite(PWMA, 255); // Max speed
  // delay(2000);
  
  // // Stop Motor A
  // analogWrite(PWMA, 0);
  // delay(1000);
  
  // Test Motor B - Forward
  // digitalWrite(BIN1, HIGH);
  // digitalWrite(BIN2, LOW);
  // analogWrite(PWMB, rightSpeed); // Max speed
  // Serial.println("R_Speed: "+rightSpeed);
  // delay(2000);
  
  // // Stop Motor B
  // analogWrite(PWMB, 0);
  // delay(1000);
  
  // // Test Motor B - Reverse
  // digitalWrite(BIN1, LOW);
  // digitalWrite(BIN2, HIGH);
  // analogWrite(PWMB, 255); // Max speed
  // delay(2000);
  
  // // Stop Motor B
  // analogWrite(PWMB, 0);
  // delay(1000);
// }
