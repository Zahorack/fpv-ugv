#ifndef CONTROL_H_
#define CONTROL_H_

#include <Arduino.h>
#include "stdint.h"

//const uint16_t PACKET_MARK = 0x4B4C;
const uint8_t PACKET_MARK[2] = {0x4B, 0x4C};

#pragma pack(push,1)
typedef struct {
    uint8_t forward;
    uint8_t backward;
    uint8_t right;
    uint8_t left;
} controlData_t;
#pragma pack(pop)

#endif
