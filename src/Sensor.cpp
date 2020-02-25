/**
 * @file       Sensor.cpp
 * @author     Ashish Kumar
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2018 Ashish Kumar
 * @date       Jun 2018
 * @brief
 *
 */

#include "Sensor.h"

Sensor::~Sensor(){
}

double Sensor::getSensor(){
  while(Serial.available()){
    delay(10);
    VAR_S=Serial.readStringUntil(0x0A);   //recieving the data until the 0x0A is encountered
    if(VAR_C==VAR_S.charAt(0x00)){
       switch(VAR_S.charAt(0x01)){
            case 0x58: VAR_1=VAR_S.substring(0x02,VAR_S.indexOf(0x0A)).toDouble();   //X-Axis
                       break;
            case 0x59: VAR_2=VAR_S.substring(0x02,VAR_S.indexOf(0x0A)).toDouble();   //Y-Axis
                       break;
            case 0x5A: VAR_3=VAR_S.substring(0x02,VAR_S.indexOf(0x0A)).toDouble();   //Z-Axis
                       break;
      }
    }
  }
}

double Sensor::getSensor1(){
  while(Serial.available()){
    delay(10);
    VAR_S=Serial.readStringUntil(0x0A);   //recieving the data until the 0x0A is encountered
    if(VAR_C==VAR_S.charAt(0x00)){
       switch(VAR_S.charAt(0x01)){
            case 0x41: VAR_1=VAR_S.substring(0x02,VAR_S.indexOf(0x0A)).toDouble();   //Azimuth
                       break;
            case 0x50: VAR_2=VAR_S.substring(0x02,VAR_S.indexOf(0x0A)).toDouble();   //Pitch
                       break;
            case 0x52: VAR_3=VAR_S.substring(0x02,VAR_S.indexOf(0x0A)).toDouble();   //Roll
                       break;
      }
    }
  }
}

double Sensor::getSensor2(){
  while(Serial.available()){
    delay(10);
    VAR_S=Serial.readStringUntil(0x0A);   //recieving the data until the 0x0A is encountered
    switch(VAR_S.charAt(0x00)){
       case 0x53: VAR_1=VAR_S.substring(0x01,VAR_S.indexOf(0x0A)).toDouble();   //cos(thetha/2) 
                  break;
    }
  }
}

//Set for listening to Accelerometer including gravity
void Sensor::setAccelerometer(){
  VAR_C=0x41;
}

//Set for listening to Accelerometer excluding gravity
void Sensor::setAccelerometer2(){
  VAR_C=0x4C;
}

//Set for listening to Gyroscope rate of rotation
void Sensor::setGyroscope(){
  VAR_C=0x47;
}

//Set for listening to Gyroscope rate of rotation without drift compensation
void Sensor::setGyroscope2(){
  VAR_C=0x55;
}

//Set for listening to Gyroscope estimated drift
void Sensor::setGyroscope3(){
  VAR_C=0x44;
}

//Set for listening to Gravity
void Sensor::setGravity(){
  VAR_C=0x42;
}

//Set for listening to Rotation vector component
void Sensor::setVector(){
  VAR_C=0x52;
}

//Set for listening to Rotation scalar component
void Sensor::setScalar(){
  VAR_C=0x53;
}

//Set for listening to Magnetic field
void Sensor::setMagnetic(){
  VAR_C=0x4D;
}

//Set for listening to Orientation
void Sensor::setOrientation(){
  VAR_C=0x4F;
}

//Gets and return X-Axis value    
double Sensor::getX(){
  getSensor();
  return VAR_1;
}

//Gets and return Y-Axis value   
double Sensor::getY(){
  getSensor();
  return VAR_2;
}

//Gets and return Z-Axis value   
double Sensor::getZ(){
  getSensor();
  return VAR_3;
}

//Gets and return Azimuth value   
double Sensor::getAzimuth(){
  getSensor1();
  return VAR_1;
}

//Gets and return Pitch value   
double Sensor::getPitch(){
  getSensor1();
  return VAR_2;
}

//Gets and return Roll value   
double Sensor::getRoll(){
  getSensor1();
  return VAR_3;
}

//Gets and return scalar component cos(thetha/2) value   
double Sensor::getcos(){
  getSensor2();
  return VAR_1;
}
