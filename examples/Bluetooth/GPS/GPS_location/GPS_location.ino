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
double latitude = 0, longitude = 0, altitude = 0;

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
  do_latitude();
  do_longitude();
  do_altitude();
}

/*
 * Function for getting Latitude and performing desired task
 */
void do_latitude(){
  latitude = gps.getLatitude();  //use getLatitude() to get Latitude
  Serial.println(String("Latitude: ") + String(latitude,6));
  //@todo latitude function
}

/*
 * Function for getting Longitude and performing desired task
 */
void do_longitude(){
  longitude = gps.getLongitude();  //use getLongitude() to get Longitude
  Serial.println(String("Longitude: ") + longitude);
  //@todo longitude function
}

/*
 * Function for getting Altitude and performing desired task
 */
void do_altitude(){
  altitude = gps.getAltitude();  //use getAltitude() to get Altitude
  Serial.println(String("Altitude: ") + altitude);
  //@todo altitude function
}
