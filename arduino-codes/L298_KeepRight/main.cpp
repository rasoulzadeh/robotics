
/*
    L298_KeepRight

    This is a sample to use l298 dc motor driver with an arduino board.
    In this sample both motors turn on, go forward for 2 seconds, the right
     motor turns off for half a second to cause the car to turn right, then
     loop repeats.

    Owner: https://github.com/mvpxcoder/arduino_robotics
*/

/*
    Circuit Pinout

    L298 Module  <>  Arduino UNO
            ENA  <-  3 ~
            IN1  <-  2
            IN2  <-  4
            ENB  <-  6 ~
            IN3  <-  5
            IN4  <-  7
*/

/// @brief One time setup, runs only once
void setup(){

    // Setup the pin modes:
    pinMode(3, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(7, OUTPUT);

    // Turn the motors off
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);

    // Set direction to forward for both
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(7, LOW);
}

/// @brief Infinite loop, runs forever
void loop(){

    // Go forward for 2 seconds:
    digitalWrite(3, HIGH);
    digitalWrite(6, HIGH);

    delay(2000);

    // Turn right
    digitalWrite(3, HIGH);
    digitalWrite(6, LOW);

    delay(500);
}
