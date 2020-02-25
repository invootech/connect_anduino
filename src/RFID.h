/**
 * @file       RFID.h
 * @author     Ashish Kumar
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2018 Ashish Kumar
 * @date       Jun 2018
 * @brief
 *
 */

#ifndef RFID_h
#define RFID_h

#include <include/Variables.h>

class RFID{
  public:    
    ~RFID();
    String getRFID();
    String gettech();
};

#endif
