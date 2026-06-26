
/*
    LCD_WireUp
        Here we connect a 16x2 alphanumerical lcd and print a simple hello on it.

    Owner: https://github.com/mvpxcoder/arduino_robotics
*/

/*
    Circuit Pinout

    LCD Module  <>  Arduino UNO
            RS  <-  12
            En  <-  11
            D4  <-  5
            D5  <-  4
            D6  <-  3
            D7  <-  2
           R/W  <-  GND
           VSS  ==  GND
           VCC  ==  5V
      VEE (V0)  ==  GND through a 5K POT
       LED+(A)  ==  5V through a 1K POT
       LED-(K)  ==  GND
*/

// Install the library for arduino lcd
#include <LiquidCrystal.h>

// Define the lcd pins for more readable code
#define RS 12
#define EN 11
#define D_4 5
#define D_5 4
#define D_6 3
#define D_7 2

// Initialize the library by associating lcd pins
LiquidCrystal lcd(RS, EN, D_4, D_5, D_6, D_7);

/// @brief One time setup, runs only once
void setup(){

    // Start the 16x2 LCD:
    lcd.begin(16, 2);

    // Print a simple message on lcd:
    lcd.print("hello, world!");
}

/// @brief Infinite loop, runs forever
void loop(){

    // Go to the first character (0) and second line (1) of the lcd:
    lcd.setCursor(0, 1); // x, y

    // Print the passed time in seconds from the start of code:
    lcd.print(millis() / 1000);
}
