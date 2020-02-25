/**
 * @file       Joystick.h
 * @author     Ashish Kumar
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2018 Ashish Kumar
 * @date       Jun 2018
 * @brief
 *
 */

#ifndef Joystick_h
#define Joystick_h

#include <include/Variables.h>

class Joystick{
  private:
    void getJoystick();
  public:    
    ~Joystick();
    int getX_AXIS();
    int getY_AXIS();
    int getAngle();
    int getPower();
};

#endif
