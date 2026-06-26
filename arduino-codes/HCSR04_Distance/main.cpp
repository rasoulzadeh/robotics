
/*
    HCSR04_Distance
        Ultrasonic Distance Measurement with HC-SR04 and Arduino

    Owner: https://github.com/mvpxcoder/arduino_robotics
*/

/*
    Circuit Pinout

    HC-SR04 Module  <>  Arduino UNO
              Trig  <-  9
              Echo  ->  10
              Vcc   ==  5V
              Gnd   ==  GND
*/

// Replacing numbers with names is more readable and for easy edit
#define TRIG 9
#define ECHO 10

/// @brief One time setup, runs only once
void setup()
{

    // Start serial communication with computer
    Serial.begin(9600);

    // The trigger is the command sent from our board to sensor -> output
    pinMode(TRIG, OUTPUT);

    // Echo is the returning pulse from the sensor -> input
    pinMode(ECHO, INPUT);

    // 2 seconds delay for sensor to stabilize
    delay(2000);
}

/// @brief Infinite loop, runs forever
void loop()
{

    // Trun on the trig pin for 10us (make a 10us pulse) to enable ultrasonic transmission
    digitalWrite(TRIG, 1);
    delayMicroseconds(10);
    digitalWrite(TRIG, 0);

    // Measure the time duration to receive the echo (in micro seconds). If the not received within 25ms, so the pulse is out of range (~4 meters)
    int duration = 0;
    duration = pulseInLong(ECHO, 1, 25000);

    // Calculate the distance in cm from the speed formula
    float distance = duration * 0.034 / 2;
    float inch = distance * 0.394;

    Serial.print("Measured duration: ");
    Serial.print(duration);
    Serial.print("us\t");
    Serial.print("Calculated distance: ");
    Serial.print(distance);
    Serial.println("cm\t");
    Serial.print(inch);
    Serial.println("inch");

    // Measure every tenth of a second
    delay(100);
}
