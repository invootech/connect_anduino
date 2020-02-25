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
  This is the example of getting the Sensor value (Orientation)
  from the android app and performing desired task.
  
  Recieve the data and control you BOT, RC CAR or any Project using the
  Sensor feature (Orientation).
  See documentation for more details.

  Sensor Functions
  -- setOrientation() -> Sets listening to Orientation
  -- getAzimuth() -> Azimuth -> Return type double
  -- getPitch() -> Pitch -> Return type double
  -- getRoll() -> Roll -> Return typr double
  
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
double azimuth = 0, pitch = 0, roll = 0;

void setup() {
  /*
   * Use the begin function to initialise the serial communication
   * begin(BAUD_RATE)
   * Enter the baud rate at which you want the serial communication
   * with bluetooth connected on the Serial port
   * Note: This will initialise Serial.begin(BAUD_RATE)
   */
  sensor.begin(9600);
  sensor.setOrientation(); //Enables getting data for Orientation
}

void loop() {
  do_azimuth();
  do_pitch();
  do_roll();
}

/*
 * Function for getting Azimuth and performing desired task
 */
void do_azimuth(){
  azimuth = sensor.getAzimuth();  //use getAzimuth() to get Azimuth
  //Serial.println(String("Azimuth: ") + azimuth);
  //@todo azimuth function
}

/*
 * Function for getting Pitch and performing desired task
 */
void do_pitch(){
  pitch = sensor.getPitch();  //use getPitch() to get Pitch
  //Serial.println(String("Pitch: ") + pitch);
  //@todo pitch function
}

/*
 * Function for getting Roll and performing desired task
 */
void do_roll(){
  roll = sensor.getRoll();  //use getRoll() to get Roll
  //Serial.println(String("Roll: ") + roll);
  //@todo roll function
}
