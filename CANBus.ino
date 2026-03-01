#include <FlexCAN_T4.h>
#include <LiquidCrystal_I2C.h>

#include "CANDecoder.h"

// Tell the .ino that updateDisplay() exsists in Display.cpp
void updateDisplay(LiquidCrystal_I2C &lcd);

// Create CAN object for CAN1
FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> Can0;

//LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // LCD Setup
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Bobcat Baja CAN Dash");
  delay(1000);

  // CAN Setup
  Can0.begin();
  Can0.setBaudRate(500000); // 500 kbps
}

void loop() {
  // put your main code here, to run repeatedly:
  CAN_message_t msg;

  //Check for incoming CAN frame
  if (Can0.read(msg)) {
    uint32_t id = msg.id;
    uint8_t len = msg.len;
    uint8_t* buf = msg.buf;

    //Decode CAN frame
    decodeCAN(id, buf, len);

    // Update LCD with latest values
    updateDisplay(lcd);
  }

}
