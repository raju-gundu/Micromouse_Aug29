#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include "global.h"

/************************************************SENSOR INITIALZATION***************************************/
// Create instances for each sensor

void setup() {
  Serial.begin(115200);
  Wire.begin();
  SensorInit();
  motorInit();
}

void loop() {
  getSensorData();

  if ((frontDistance > frontThreshold)) {
    moveForward();
    if (leftDistance < wallThreshold && rightDistance > wallThreshold) {
      
      turnRight();
      
      
      
    } else if (leftDistance > wallThreshold && rightDistance < wallThreshold) {
      
      stopMotors();
      delay(100);
      turnLeft();
      delay(150);
      
    } else if(leftDistance > wallThreshold && rightDistance > wallThreshold){
      
      turnRight();
      
      
      
    }
   
  } 
  else {
    
    if (leftDistance < wallThreshold && rightDistance > wallThreshold) {
      
      turnRight();
      
      
      
    } else if (leftDistance > wallThreshold && rightDistance < wallThreshold) {
      
      stopMotors();
      delay(150);
      turnLeft();
      delay(100);
      
    } else if(leftDistance > wallThreshold && rightDistance > wallThreshold){
      
      turnRight();
      
      
    }
     else if(leftDistance < wallThreshold && rightDistance < wallThreshold){
      stopMotors();
      delay(100);
      turnRight();
      turnRight();
      delay(50);
      stopMotors();
    }
  }
}

// if(leftDistance<wallThreshold && rightDistance<wallThreshold && frontDistance>frontThreshold){
//   moveForward();
//   Serial.println("moving forward");
// }
// else if(rightDistance>wallThreshold && leftDistance<wallThreshold && frontDistance<frontThreshold){
//   stopMotors();
//   delay(100);
//   turnRight();
//   stopMotors();
//   delay(100);
//   Serial.println("turn right");
// }

