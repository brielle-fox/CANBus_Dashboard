#include <LiquidCrystal_I2C.h>
#include "CANDecoder.h"

// Draws the LCD display based on the decoded CAN data from CANDecoder.cpp
void updateDisplay(LiquidCrystal_I2C &lcd) {

  lcd.clear();

  // Row 1: Speed and Diff State
  lcd.setCursor(0, 0);
  lcd.print("SPD:");
  lcd.print(wheelSpeedRear, 1); // Display rear wheel speed with 1 decimal place

  lcd.setCursor(10, 0);
  lcd.print("F:");
  lcd.print(diffStateFront);

  lcd.setCursor(14, 0);
  lcd.print("R:");  
  lcd.print(diffStateRear);

  // Row 2: HID Buttons
  lcd.setCursor(0, 1);
  lcd.print("RF:");
  lcd.print(rightShockFront);

  lcd.setCursor(6, 1);
  lcd.print("LF:");
  lcd.print(leftShockFront);

  lcd.setCursor(12, 1);
  lcd.print("RR:");
  lcd.print(rightShockRear);
}
