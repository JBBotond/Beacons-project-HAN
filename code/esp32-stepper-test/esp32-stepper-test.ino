const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int number_of_steps = 2048;

// ULN2003 Motor Driver Pins
#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

int step_number = 0;

void setup() {
  // set the speed at 5 rpm
  //myStepper.setSpeed(10);
  // initialize the serial port
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void step(int steps_to_move)
{
  int steps_left = abs(steps_to_move);  // how many steps to take

  int direction = -1;
  // determine direction based on whether steps_to_mode is + or -:
  if (steps_to_move > 0) { direction = 1; }
  if (steps_to_move < 0) { direction = 0; }


  // decrement the number of steps, moving one step each time:
  while (steps_left > 0)
  {
      if ( direction == 1)
      {
         step_number++;
        if ( step_number ==  number_of_steps) {
           step_number = 0;
        }
      }
      else
      {
        if ( step_number == 0) {
           step_number =  number_of_steps;
        }
         step_number--;
      }
      // decrement the steps left:
      steps_left--;
      // step the motor to step number 0, 1, ..., {3 or 10}
    }
}

void stepMotor(int thisStep) {
  switch (thisStep) {
      case 0:  // 1010
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
      break;
      case 1:  // 0110
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
      break;
      case 2:  //0101
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
      break;
      case 3:  //1001
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
      break;
    }
}

void loop() {
  if(Serial.available()) {
    char newRead = Serial.read();
    if(newRead == 'L') {
      Serial.println("Locking, clockwise");
      //step(stepsPerRevolution);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    }
    else if(newRead == 'U') {
      Serial.println("counterclockwise");
      step(-stepsPerRevolution);
    }
  }

}