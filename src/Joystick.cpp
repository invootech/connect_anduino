/**
 * @file       Joystick.cpp
 * @author     Ashish Kumar
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2018 Ashish Kumar
 * @date       Jun 2018
 * @brief
 *
 */

#include "Joystick.h"

Joystick::~Joystick(){
}

void Joystick::getJoystick(){
  while(Serial.available()){
    delay(10);
    VAR_S=Serial.readStringUntil(0x0A);   //recieving the data until the 0x0A is encountered
    switch(VAR_S.charAt(0x00)){
       case 0x41: VAR_1=VAR_S.substring(0x01,VAR_S.indexOf(0x0A)).toInt();  //Angle
                  break;
       case 0x50: VAR_2=VAR_S.substring(0x01,VAR_S.indexOf(0x0A)).toInt();  //Power
                  break;
       case 0x58: VAR_3=VAR_S.substring(0x01,VAR_S.indexOf(0x0A)).toInt();  //X-Axis
                  break;
       case 0x59: VAR_4=VAR_S.substring(0x01,VAR_S.indexOf(0x0A)).toInt();  //Y-Axis
                  break;
    }
  }
}

//Gets and return the Joystic X Axis value
int Joystick::getX_AXIS(){
  getJoystick();
  return VAR_3;
}

//Gets and return the Joystic Y Axis value
int Joystick::getY_AXIS(){
  getJoystick();
  return VAR_4;
}

//Gets and return the Joystic Angle value
int Joystick::getAngle(){
  getJoystick();
  return VAR_1;
}

//Gets and return the Joystic Power value
int Joystick::getPower(){
  getJoystick();
  return VAR_2;
}
