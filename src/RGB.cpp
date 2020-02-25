/**
 * @file       RGB.cpp
 * @author     Ashish Kumar
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2018 Ashish Kumar
 * @date       Jun 2018
 * @brief
 *
 */

#include "RGB.h"

RGB::~RGB(){
}

//Gets the data of Red Slider
void RGB::getSlider(){
  while(Serial.available()){
    delay(10);
    VAR_S=Serial.readStringUntil(0x0A);   //recieving the data until the 0x0A is encountered
    if(VAR_S.charAt(0x00)==0x52)
       VAR_1=VAR_S.substring(0x01,VAR_S.indexOf(0x0A)).toInt();   //red slider value
    else if(VAR_S.charAt(0x00)==0x47)
       VAR_2=VAR_S.substring(0x01,VAR_S.indexOf(0x0A)).toInt();   //green slider value
    else if(VAR_S.charAt(0x00)==0x42)
       VAR_3=VAR_S.substring(0x01,VAR_S.indexOf(0x0A)).toInt();   //blue slider value
    else if(VAR_S.charAt(0x00)==0x49)
       VAR_4=VAR_S.substring(0x01,VAR_S.indexOf(0x0A)).toInt();   //intensity slider value
  }
}

//Gets the data of Red Slider
int RGB::getRed(){
  getSlider();
  return VAR_1;
}

//Gets the data of Green Slider
int RGB::getGreen(){
  getSlider();
  return VAR_2;
}

//Gets the data of Blue Slider
int RGB::getBlue(){
  getSlider();
  return VAR_3;
}

//Gets the data of Intensity Slider
int RGB::getIntensity(){
  getSlider();
  return VAR_4;
}
