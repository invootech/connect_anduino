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
  This is the example of getting the Sensor value (Rotation scalar component)
  from the android app and performing desired task.
  
  Recieve the data and control you BOT, RC CAR or any Project using the
  Sensor feature (Rotation scalar component).
  See documentation for more details.

  Sensor Functions
  -- setOrientation() -> Sets listening to Rotation scalar component
  -- getcos() -> Scalar component -> Return type double
  
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
double scalar_cos = 0;

void setup() {
  /*
   * Use the begin function to initialise the serial communication
   * begin(BAUD_RATE)
   * Enter the baud rate at which you want the serial communication
   * with bluetooth connected on the Serial port
   * Note: This will initialise Serial.begin(BAUD_RATE)
   */
  sensor.begin(9600);
  sensor.setScalar(); //Enables getting data for Rotation scalar component
}

void loop() {
  do_cos();
}

/*
 * Function for getting scalar component and performing desired task
 */
void do_cos(){
  scalar_cos = sensor.getcos();  //use getcos() to get Scalar component cos(thetha/2)
  //Serial.println(String("Scalar component: ") + scalar_cos);
  //@todo scalar function
}
