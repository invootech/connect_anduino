/**
 * @file       Connect_Anduino_BT.h
 * @author     Ashish Kumar
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2018 Ashish Kumar
 * @date       Jun 2018
 * @brief
 *
 */

#ifndef Connect_Anduino_BT_h
#define Connect_Anduino_BT_h

#include "Joystick.h"
#include "Sensor.h"
#include "GPS.h"
#include "RGB.h"
#include "RFID.h"

class Connect_Anduino_BT : public Joystick, public Sensor, public GPS, public RGB, public RFID {
  public:    
    ~Connect_Anduino_BT();
    void begin(long);
};

#endif
