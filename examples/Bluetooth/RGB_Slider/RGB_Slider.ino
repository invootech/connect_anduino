/*************************************************************
  Download latest Connect Anduino library here:
    https://github.com/invootech/connect_anduino

  Connect Anduino is a platform with Android apps to control
  Arduino or any other microcontroller using various features
  like Bluetooth, USB OTG, WiFi and even IoT.
  There are lots of features available like
    -- RGB Slider
    -- Sensor
    -- GPS
    -- GSM
    -- RTC
    -- RFID
    -- Notification
    -- Graph and lot more
  So that you can build what you want.

  You can contact us at invootech@gmail.com with your queries.
  You can also find the app on the play store 
   https://play.google.com/store/apps/details?id=invootech.ashish.anduino_connect
/*************************************************************
  This is the example of getting the Slider value from the android app
  and performing desired task.
  
  Recieve the data and control you BOT, RC CAR, Light or any Project using the
  RGB+ feature.
  See documentation for more details.

  RGB Functions
  -- getRed() -> Red Slider -> Return type integer
  -- getGreen() -> Green Slider -> Return type integer
  -- getBlue() -> Blue Slider -> Return type integer
  -- getIntensity() -> Intensity Slider -> Return type integer
  
  Connection for Bluetooth
  ------------------------
  Bluetooth        Arduino
    RX               TX
    TX               RX

  Note: Connect the Bluetooth with the main serial port.
  
  Please make sure to select the right board in the Tools -> Board:
 *************************************************************/
#include <Connect_Anduino_BT.h>

Connect_Anduino_BT rgb;
int red = 0, green = 0, blue = 0, intensity = 0;

void setup() {
  /*
   * Use the begin function to initialise the serial communication
   * begin(BAUD_RATE)
   * Enter the baud rate at which you want the serial communication
   * with bluetooth connected on the Serial port
   * Note: This will initialise Serial.begin(BAUD_RATE)
   */
  rgb.begin(9600);
}

void loop() {
  doRed();
  doGreen();
  doBlue();
  doIntensity();
}

/*
 * Function for getting Red slider value and performing desired task
 */
void doRed(){
  red = rgb.getRed();  //use getRed() to get Red slider value
  //Serial.println(String("Red Slider: ") + red);
  //@todo red
}

/*
 * Function for getting Green slider value and performing desired task
 */
void doGreen(){
  green = rgb.getGreen();  //use getGreen() to get Green slider value
  //Serial.println(String("Green Slider: ") + green);
  //@todo green
}

/*
 * Function for getting Blue slider value and performing desired task
 */
void doBlue(){
  blue = rgb.getBlue();  //use getBlue() to get Blue slider value
  //Serial.println(String("Blue Slider: ") + blue);
  //@todo blue
}

/*
 * Function for getting Intensity slider value and performing desired task
 */
void doIntensity(){
  intensity = rgb.getIntensity();  //use getIntensity() to get Intensity slider value
  //Serial.println(String("Intensity Slider: ") + intensity);
  //@todo intensity
}
