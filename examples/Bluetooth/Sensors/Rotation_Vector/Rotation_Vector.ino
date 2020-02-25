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
  This is the example of getting the Sensor value (Gravity)
  from the android app and performing desired task.
  
  Recieve the data and control you BOT, RC CAR or any Project using the
  Sensor feature (Gravity).
  See documentation for more details.

  Sensor Functions
  -- setGravity() -> Sets listening to Gravity
  -- getX() -> X-Axis -> Return type double
  -- getY() -> Y-Axis -> Return type double
  -- getZ() -> Z-Axis -> Return typr double
  
  Connection for Bluetooth
  ------------------------
  Bluetooth        Arduino
    RX               TX
    TX               RX

  Note: Connect the Bluetooth with the main serial port.
  
  Please make sure to select the right board in the Tools -> Board:
 *************************************************************/
#include <Connect_Anduino_BT.h>

Connect_Anduino_BT sensor;
double x_axis = 0, y_axis = 0, z_axis = 0;

void setup() {
  /*
   * Use the begin function to initialise the serial communication
   * begin(BAUD_RATE)
   * Enter the baud rate at which you want the serial communication
   * with bluetooth connected on the Serial port
   * Note: This will initialise Serial.begin(BAUD_RATE)
   */
  sensor.begin(9600);
  sensor.setGravity(); //Enables getting data for Gravity
}

void loop() {
  dox_axis();
  doy_axis();
  doz_axis();
}

/*
 * Function for getting X-Axis and performing desired task
 */
void dox_axis(){
  x_axis = sensor.getX();  //use getX() to get X-Axis
  //Serial.println(String("X-Axis: ") + x_axis);
  //@todo x_axis function
}

/*
 * Function for getting Y-Axis and performing desired task
 */
void doy_axis(){
  y_axis = sensor.getY();  //use getY() to get Y-Axis
  //Serial.println(String("Y-Axis: ") + y_axis);
  //@todo y_axis function
}

/*
 * Function for getting Z-Axis and performing desired task
 */
void doz_axis(){
  z_axis = sensor.getZ();  //use getZ() to get Z-Axis
  //Serial.println(String("Z-Axis: ") + z_axis);
  //@todo z_axis function
}
