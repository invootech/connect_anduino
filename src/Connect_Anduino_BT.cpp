/**
 * @file       Connect_Anduino_BT.cpp
 * @author     Ashish Kumar
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2018 Ashish Kumar
 * @date       Jun 2018
 * @brief
 *
 */

#include "Connect_Anduino_BT.h"

Connect_Anduino_BT::~Connect_Anduino_BT(){
}

void Connect_Anduino_BT::begin(long baud){
   //Begin the Serial communication at specified baud rate for connected bluetooth on serial port RX->0 and TX->1
  Serial.begin(baud); 
}
