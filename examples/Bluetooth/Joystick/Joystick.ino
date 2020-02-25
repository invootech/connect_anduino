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
  This is the example of getting the Joystic value from the android app
  and performing desired task.
  
  Recieve the data and control you BOT, RC CAR or any Project using the
  Joystic feature.
  See documentation for more details.

  Joystic Functions
  -- getAngle() -> Joystic Angle -> Return type integer
  -- getPower() -> Joystic Power -> Return type integer
  -- getX_Axis() -> Joystic X-Axis -> Return type integer
  -- getY_Axis() -> Joystic Y-Axis -> Return typr integer
  
  Connection for Bluetooth
  ------------------------
  Bluetooth        Arduino
    RX               TX
    TX               RX

  Note: Connect the Bluetooth with the main serial port.
  
  Please make sure to select the right board in the Tools -> Board:
 *************************************************************/
#include <Connect_Anduino_BT.h>

Connect_Anduino_BT joystick;
int x_axis = 0, y_axis = 0, angle = 0, power = 0;

void setup() {
  /*
   * Use the begin function to initialise the serial communication
   * begin(BAUD_RATE)
   * Enter the baud rate at which you want the serial communication
   * with bluetooth connected on the Serial port
   * Note: This will initialise Serial.begin(BAUD_RATE)
   */
  joystick.begin(9600);
}

void loop() {
  doangle();
  dopower();
  dox_axis();
  doy_axis();
}

/*
 * Function for getting Angle and performing desired task
 */
void doangle(){
  angle = joystick.getAngle();  //use getAngle() to get angle (of Joystick)
  //Serial.println(String("Angle: ") + angle);
  //@todo angle
}

/*
 * Function for getting Power and performing desired task
 */
void dopower(){
  power = joystick.getPower();  //use getPower() to get power (of Joystick)
  //Serial.println(String("Power: ") + power);
  //@todo power
}

/*
 * Function for getting X-Axis and performing desired task
 */
void dox_axis(){
  x_axis = joystick.getX_AXIS();  //use getX_Axis() to get X-Axis (of Joystick)
  //Serial.println(String("X-Axis: ") + x_axis);
  //@todo x_axis function
}

/*
 * Function for getting Y-Axis and performing desired task
 */
void doy_axis(){
  y_axis = joystick.getY_AXIS();  //use getY_Axis() to get Y-Axis (of Joystick)
  //Serial.println(String("Y-Axis: ") + y_axis);
  //@todo y_axis function
}
