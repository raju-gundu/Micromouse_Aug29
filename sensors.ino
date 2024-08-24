#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include "global.h"


Adafruit_VL53L0X sensorFront = Adafruit_VL53L0X();
Adafruit_VL53L0X sensorLeft = Adafruit_VL53L0X();
Adafruit_VL53L0X sensorRight = Adafruit_VL53L0X();


void SensorInit(){
  // Initialize the first sensor
  pinMode(leftSensor, OUTPUT);
  digitalWrite(leftSensor, LOW);
  pinMode(frontSensor, OUTPUT);
  digitalWrite(frontSensor, LOW);
  pinMode(rightSensor, OUTPUT);
  digitalWrite(rightSensor, LOW);

  delay(10);

  digitalWrite(leftSensor, HIGH);
  delay(10);
  if (!sensorLeft.begin(0x30, &Wire)) { // Assign a new address to the left sensor
    Serial.println(F("Failed to boot left sensor"));
    while (1);
  }

  // Initialize the front sensor
  digitalWrite(frontSensor, HIGH);
  delay(10);
  if (!sensorFront.begin(0x31, &Wire)) { // Assign a new address to the front sensor
    Serial.println(F("Failed to boot front sensor"));
    while (1);
  }

  // Initialize the right sensor
  digitalWrite(rightSensor, HIGH);
  delay(10);
  if (!sensorRight.begin(0x32, &Wire)) { // Assign a new address to the right sensor
    Serial.println(F("Failed to boot right sensor"));
    while (1);
  }
}

void getSensorData(){
  // Read distances from each sensor
  VL53L0X_RangingMeasurementData_t measureLeft;
  VL53L0X_RangingMeasurementData_t measureFront;
  VL53L0X_RangingMeasurementData_t measureRight;

  sensorLeft.rangingTest(&measureLeft, false);
  sensorFront.rangingTest(&measureFront, false);
  sensorRight.rangingTest(&measureRight, false);

  rightDistance = measureRight.RangeMilliMeter/10.0;
  leftDistance = measureLeft.RangeMilliMeter/10.0;
  frontDistance = measureFront.RangeMilliMeter/10.0;
  // Print the results
  Serial.print("Left Sensor : "); Serial.print(measureLeft.RangeMilliMeter/10.0); Serial.print(" cm || ");
  Serial.print("Front Sensor : "); Serial.print(measureFront.RangeMilliMeter/10.0); Serial.print(" cm || ");
  Serial.print("Right Sensor : "); Serial.print(measureRight.RangeMilliMeter/10.0); Serial.println(" cm");
}
