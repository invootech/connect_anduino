/**
 * @file       GPS.cpp
 * @author     Ashish Kumar
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2018 Ashish Kumar
 * @date       Jun 2018
 * @brief
 *
 */

#include "GPS.h"

GPS::~GPS(){
}

void GPS::getGPS(){
  while(Serial.available()){
    delay(10);
    VAR_S=Serial.readStringUntil(0x0A);   //recieving the data until the 0x0A is encountered
    switch(VAR_S.charAt(0x01)){
       case 0x41: VAR_1=VAR_S.substring(0x02,VAR_S.indexOf(0x0A)).toDouble();  //Latitude
                  break;
       case 0x4F: VAR_2=VAR_S.substring(0x02,VAR_S.indexOf(0x0A)).toDouble();  //Longitude
                  break;
       case 0x4C: VAR_3=VAR_S.substring(0x02,VAR_S.indexOf(0x0A)).toDouble();  //Altitude
                  break;
       case 0x43: VAR_4=VAR_S.substring(0x02,VAR_S.indexOf(0x0A)).toDouble();  //Accuracy
                  break;
       case 0x50: VAR_5=VAR_S.substring(0x02,VAR_S.indexOf(0x0A)).toDouble();  //Speed
                  break;
       case 0x45: VAR_6=VAR_S.substring(0x02,VAR_S.indexOf(0x0A)).toDouble();  //Bearing
                  break;
       case 0x54: VAR_S1=VAR_S.substring(0x02,VAR_S.indexOf(0x0A));  //UTC Time
                  break;
    }
  }
}

//Gets and return the GPS latitude
double GPS::getLatitude(){
  getGPS();
  return VAR_1;
}

//Gets and return the GPS Longitude
double GPS::getLongitude(){
  getGPS();
  return VAR_2;
}

//Gets and return the GPS Altitude
double GPS::getAltitude(){
  getGPS();
  return VAR_3;
}

//Gets and return the GPS Accuracy
double GPS::getAccuracy(){
  getGPS();
  return VAR_4;
}

//Gets and return the GPS Speed
double GPS::getSpeed(){
  getGPS();
  return VAR_5;
}

//Gets and return the GPS Bearing
double GPS::getBearing(){
  getGPS();
  return VAR_6;
}

//Gets and return the UTC Time in string
String GPS::getUTC(){
  getGPS();
  return VAR_S1;
}
