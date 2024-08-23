#include <Wire.h>
#include <Adafruit_VL53L0X.h>

/************************************************SENSOR INITIALZATION***************************************/
// Create instances for each sensor
Adafruit_VL53L0X sensorFront = Adafruit_VL53L0X();
Adafruit_VL53L0X sensorLeft = Adafruit_VL53L0X();
Adafruit_VL53L0X sensorRight = Adafruit_VL53L0X();

#define XSHUT_FRONT 18
#define XSHUT_LEFT 4
#define XSHUT_RIGHT 19

/************************************************MOTOR INITIALIZION****************************************/
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

void setup() {
  /*****************************************SENSORS********************************************************************/
  Serial.begin(115200);
  Wire.begin();  // Initialize I2C on ESP32 default pins (SDA: GPIO 21, SCL: GPIO 22)

  // Power down all sensors
  pinMode(XSHUT_FRONT, OUTPUT);
  pinMode(XSHUT_LEFT, OUTPUT);
  pinMode(XSHUT_RIGHT, OUTPUT);

  digitalWrite(XSHUT_FRONT, LOW);
  digitalWrite(XSHUT_LEFT, LOW);
  digitalWrite(XSHUT_RIGHT, LOW);
  
  // Initialize each sensor with a unique address

  // Front Sensor
  digitalWrite(XSHUT_FRONT, HIGH);  // Power up front sensor
  delay(10);
  if (!sensorFront.begin(0x30, &Wire)) {
    Serial.println("Failed to initialize front sensor!");
    while (1);
  }
  Serial.println("Front sensor initialized at address 0x30");

  // Left Sensor
  digitalWrite(XSHUT_LEFT, HIGH);  // Power up left sensor
  delay(10);
  if (!sensorLeft.begin(0x31, &Wire)) {
    Serial.println("Failed to initialize left sensor!");
    while (1);
  }
  Serial.println("Left sensor initialized at address 0x31");

  // Right Sensor
  digitalWrite(XSHUT_RIGHT, HIGH);  // Power up right sensor
  delay(10);
  if (!sensorRight.begin(0x32, &Wire)) {
    Serial.println("Failed to initialize right sensor!");
    while (1);
  }
  Serial.println("Right sensor initialized at address 0x32");

 /********************************************MOTOR*******************************************************/
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

void loop() {
  // Test Motor A - Forward
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, leftSpeed); // Max speed
  Serial.println("L_Speed: "+leftSpeed);
  
  
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
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, rightSpeed); // Max speed
  Serial.println("R_Speed: "+rightSpeed);
  delay(2000);
  
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
}
