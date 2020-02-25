/**
 * @file       RFID.cpp
 * @author     Ashish Kumar
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2018 Ashish Kumar
 * @date       Jun 2018
 * @brief
 *
 */

#include "RFID.h"

RFID::~RFID(){
}

//Gets the Card ID
String RFID::getRFID(){
  VAR_S1="NC";
  while(Serial.available()){
    delay(10);
    VAR_S=Serial.readStringUntil(0x0A);   //recieving the data until the 0x0A is encountered
	if(VAR_S.length()>2){
      if(VAR_S.indexOf('-')>0)
        VAR_S1=VAR_S.substring(0x00,VAR_S.indexOf('-'));
      else
        VAR_S1=VAR_S.substring(0x00,VAR_S.indexOf(0x0A));
    }
  }
  return VAR_S1;
}

//Gets technology iformation of card
String RFID::gettech(){
  if(VAR_S.indexOf('-')>0)
    VAR_S1=VAR_S.substring(VAR_S.indexOf('-')+1,VAR_S.indexOf(0x0A));
  else
    VAR_S1="NAN";
  VAR_S="";
  return VAR_S1;
}
