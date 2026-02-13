#define IN1 19
#define IN2 18
#define IN3 5
#define IN4 17

//in global scope defining the pins for the phases
int stepper_pins[4] = {19, 18, 5, 17};

void step(bool forward){
    const uint8_t phase_pattern[][4] = {
        {1,0,0,0},  // Step 1
        {1,1,0,0},  // Step 2  
        {0,1,0,0},  // Step 3
        {0,1,1,0},  // Step 4
        {0,0,1,0},  // Step 5
        {0,0,1,1},  // Step 6
        {0,0,0,1},  // Step 7
        {1,0,0,1}   // Step 8
    };
    static uint8_t current_step = 0;
    if(forward){
        current_step = (current_step + 1) % 4;
    } else {
        current_step = (current_step - 1) % 4;
    }
    for(uint8_t i=0;i<4;i++){
        digitalWrite(stepper_pins[i], phase_pattern[current_step][i]);
    }
}

const int stepsPerRevolution = 2048;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}


void loop() {
    for(int i = 0; i < 4; i++){
        digitalWrite(stepper_pins[i], HIGH);
        delay(100);
        digitalWrite(stepper_pins[i], LOW);
        delay(100);
    }
}
