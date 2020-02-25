/*************************************************************
  Download latest Connect Anduino library here:
    https://github.com/invootech/connect_anduino

  Connect Anduino is a platform with Android apps to control
  Arduino or any other microcontroller using various features
  like Bluetooth, USB OTG, WiFi and even IoT.
  There are lots of features available like
    -- Joystick
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
  This is the example of getting the GPS value from the android app and performing
  desired task.
  
  Recieve the data and control you BOT, RC CAR or any Project using the GPS feature.
  See documentation for more details.

  Sensor Functions
  -- getLatitude() -> Latitude -> Return type double
  -- getLongitude() -> Longitude -> Return type double
  -- getAltitude() -> Altitude -> Return type double
  -- getSpeed() -> Speed -> Return type double
  -- getAccuracy() -> Accuracy -> Return type double
  -- getBearing() -> Bearing -> Return type double
  -- getUTC() -> UTC Time -> Return type string
  
  Connection for Bluetooth
  ------------------------
  Bluetooth        Arduino
    RX               TX
    TX               RX

  Note: Connect the Bluetooth with the main serial port.
  
  Please make sure to select the right board in the Tools -> Board:
 *************************************************************/
#include <Connect_Anduino_BT.h>

Connect_Anduino_BT gps;
double Speed = 0, accuracy = 0, bearing = 0;
String UTC="";

void setup() {
  /*
   * Use the begin function to initialise the serial communication
   * begin(BAUD_RATE)
   * Enter the baud rate at which you want the serial communication
   * with bluetooth connected on the Serial port
   * Note: This will initialise Serial.begin(BAUD_RATE)
   */
  gps.begin(9600);
}

void loop() {
  do_speed();
  do_accuracy();
  do_bearing();
  do_UTC();
}

/*
 * Function for getting Speed and performing desired task
 */
void do_speed(){
  Speed = gps.getSpeed();  //use getSpeed() to get Speed
  //Serial.println(String("Speed: ") + Speed);
  //@todo Speed function
}

/*
 * Function for getting Accuracy and performing desired task
 */
void do_accuracy(){
  accuracy = gps.getAccuracy();  //use getAccuracy() to get Accuracy
  //Serial.println(String("Accuracy: ") + accuracy);
  //@todo accuracy function
}

/*
 * Function for getting Bearing and performing desired task
 */
void do_bearing(){
  bearing = gps.getBearing();  //use getBearing() to get Bearing
  //Serial.println(String("Bearing: ") + bearing);
  //@todo bearing function
}

/*
 * Function for getting UTC time and performing desired task
 */
void do_UTC(){
  UTC = gps.getUTC();  //use getUTC() to get UTC time
  //Serial.println(String("UTC time: ") + UTC);
  //@todo UTC function
}
