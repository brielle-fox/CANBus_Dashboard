#include "CANDecoder.h"

// From Dash-HID (0x07)
bool hidUp = false;
bool hidDown = false;
bool hidRight = false;
bool hidLeft = false;
bool hidSelect = false;

// From GPIO FRONT (0x08)
uint8_t diffStateFront =0;
uint16_t rightShockFront =0;
uint16_t leftShockFront =0;

// From GPIO REAR (0x09)
uint8_t diffStateRear =0;
float wheelSpeedRear =0.0f;
uint16_t rightShockRear =0;
uint16_t leftShockRear =0;

// Function declaration
void decodeCAN(uint32_t id, uint8_t* buf, uint8_t len){

  switch(id) {
    // Dash HID Buttons, where 0xFF = Pressed
    case 0x07:
      hidUp = (buf[0] == 0xFF);
      hidDown = (buf[1] == 0xFF);
      hidRight = (buf[2] == 0xFF);
      hidLeft = (buf[3] == 0xFF);
      hidSelect = (buf[4] == 0xFF);
      break;

    case 0x08:
    // Byte layout
      diffStateFront = buf[0];
      rightShockFront = ((buf[1] << 2 | (buf[3] >> 6)));
      leftShockFront = (((buf[3] & 0x3F) << 8) | buf[4]);
      break;

    case 0x09:
    // GPIO rear
      diffStateRear = buf[0];
      {
          uint16_t rawSpeed = (buf[1] << 8) | buf[2];
          wheelSpeedRear = rawSpeed * 0.1f;
      }
      rightShockRear = (buf[3] << 8) | buf[4];
      leftShockRear = (buf[5] << 8) | buf[6];
      break;

    default:
      // Unknown CANID ignore
      break;
  }
}
