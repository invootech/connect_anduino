/**
 * @file       GPS.h
 * @author     Ashish Kumar
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2018 Ashish Kumar
 * @date       Jun 2018
 * @brief
 *
 */

#ifndef GPS_h
#define GPS_h

#include <include/Variables.h>

class GPS{
  private:
    void getGPS();
  public:    
    ~GPS();
    double getLatitude();
    double getLongitude();
    double getAltitude();
    double getSpeed();
    double getAccuracy();
    double getBearing();
    String getUTC();
};

#endif
