/**
 * @file       Connect_Anduino_IoT.h
 * @author     Ashish Kumar
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2018 Ashish Kumar
 * @date       Oct 2019
 * @brief
 *
 */

#ifndef Connect_Anduino_IoT_h
#define Connect_Anduino_IoT_h
#include <WString.h>

class Connect_Anduino_IoT {
  public:
    ~Connect_Anduino_IoT();
    char* CA_HOST();
    char* CA_APIROOT();
    String getJSON(String, String);
};

#endif
