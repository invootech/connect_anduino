/**
 * @file       Sensor.h
 * @author     Ashish Kumar
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2018 Ashish Kumar
 * @date       Jun 2018
 * @brief
 *
 */

#ifndef Sensor_h
#define Sensor_h

#include <include/Variables.h>

class Sensor{
  private:
    double getSensor();
    double getSensor1();
    double getSensor2();
  public:    
    ~Sensor();
    void setAccelerometer();
    void setAccelerometer2();
    void setGyroscope();
    void setGyroscope2();
    void setGyroscope3();
    void setGravity();
    void setVector();
    void setScalar();
    void setMagnetic();
    void setOrientation();
    double getX();
    double getY();
    double getZ();
    double getcos();
    double getAzimuth();
    double getPitch();
    double getRoll();
};

#endif
