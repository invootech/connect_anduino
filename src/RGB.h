/**
 * @file       RGB.h
 * @author     Ashish Kumar
 * @license    This project is released under the MIT License (MIT)
 * @copyright  Copyright (c) 2018 Ashish Kumar
 * @date       Jun 2018
 * @brief
 *
 */

#ifndef RGB_h
#define RGB_h

#include <include/Variables.h>

class RGB{
  private:
    void getSlider();
  public:    
    ~RGB();
    int getRed();
    int getGreen();
    int getBlue();
    int getIntensity();
};

#endif
