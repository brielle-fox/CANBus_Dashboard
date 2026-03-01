#ifndef CANDECODER_H
#define CANDECODER_H

#include <Arduino.h>

// From Dash-HID (0x07)
extern bool hidUp;
extern bool hidDown;
extern bool hidRight;
extern bool hidLeft;
extern bool hidSelect;

// From GPIO FRONT (0x08)
extern uint8_t diffStateFront;
extern uint16_t rightShockFront;
extern uint16_t leftShockFront;

// From GPIO REAR (0x09)
extern uint8_t diffStateRear;
extern float wheelSpeedRear;
extern uint16_t rightShockRear;
extern uint16_t leftShockRear;

// Function declaration
void decodeCAN(uint32_t id, uint8_t* buf, uint8_t len);

#endif // CANDECODER_H