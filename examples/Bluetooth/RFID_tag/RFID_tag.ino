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
  This is the example of getting the RFID value from the android app
  and performing desired task.
  
  Recieve the data and make your own attendance system,RFID controlled Light or any other
  Project using the RFID feature.
  See documentation for more details.

  RFID Functions
  -- getRFID() -> Gets the card number (HEX) and technology information ->
               -> Return type string -- Card number (Hex)
               -> If NC is recieved then NO CARD information was read/present
  -- gettech() -> Get the Technology used in the card
               -> Return type string -- Technologies
               -> If NAN is returned that means no technology was sent
  
  Connection for Bluetooth
  ------------------------
  Bluetooth        Arduino
    RX               TX
    TX               RX

  Note: Connect the Bluetooth with the main serial port.
  
  Please make sure to select the right board in the Tools -> Board:
 *************************************************************/
#include <Connect_Anduino_BT.h>

Connect_Anduino_BT rfid;
String cardno,tech;

void setup() {
  /*
   * Use the begin function to initialise the serial communication
   * begin(BAUD_RATE)
   * Enter the baud rate at which you want the serial communication
   * with bluetooth connected on the Serial port
   * Note: This will initialise Serial.begin(BAUD_RATE)
   */
  rfid.begin(9600);
}

void loop() {
  cardno=rfid.getRFID(); //Getting the card information
  if(cardno!="NC"){
    //@ToDo card number
    Serial.println(String("Card Number in HEX is: ")+cardno);  //Displaying Card Number. Comment this section when finished
    
    //Reading technologies used
    tech=rfid.gettech();
    if(tech!="NAN"){
      //@ToDo technology
      Serial.println(String("Technologies: ")+tech); //Displaying Technologies. Comment this section when finished
    }
  }
}

