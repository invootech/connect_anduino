/**
 * @file       Connect_Anduino_IoT.cpp
 * @author     Ashish Kumar
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2018 Ashish Kumar
 * @date       Oct 2019
 * @brief
 *
 */

#include "Connect_Anduino_IoT.h"
#include <WString.h>

Connect_Anduino_IoT::~Connect_Anduino_IoT(){
}

char* Connect_Anduino_IoT::CA_HOST(){
  return "http://www.invootech.com";
}

char* Connect_Anduino_IoT::CA_APIROOT(){
  return "/world/connect_anduino_iot.php";
}

String Connect_Anduino_IoT::getJSON(String jsonString, String key){
  int t = jsonString.indexOf(key)+key.length()+2;
  if(jsonString.charAt(t) == '\"'){
    return jsonString.substring(t+1,jsonString.indexOf(jsonString.charAt(t),t+2));
  } else if(jsonString.charAt(t) == '['){
    return jsonString.substring(t+1,jsonString.indexOf(']',t+2));
  }
}
