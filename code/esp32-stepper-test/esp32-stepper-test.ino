#include <Stepper.h>

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution

// ULN2003 Motor Driver Pins
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

// initialize the stepper library
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  // set the speed at 5 rpm
  myStepper.setSpeed(10);
  // initialize the serial port
  Serial.begin(115200);
}

void loop() {
  if(Serial.available()) {
    char newRead = Serial.read();
    if(newRead == 'L') {
      Serial.println("Locking, clockwise");
      myStepper.step(stepsPerRevolution);
    }
    else if(newRead == 'U') {
      Serial.println("counterclockwise");
      myStepper.step(-stepsPerRevolution);
    }
  }

}