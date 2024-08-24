#ifndef globals_h
#define globals_h

#include <stdint.h>
#include <Encoder.h>

#define north 0
#define east 1
#define south 2
#define west 3

#define leftSensor 4
#define frontSensor 18
#define rightSensor 19  

#define wallThreshold 15
#define frontThreshold 10

float leftDistance,frontDistance,rightDistance;
extern long newPosition1, newPosition2, oldPosition1, oldPosition2;

extern Encoder myEnc1;
extern Encoder myEnc2;

#endif