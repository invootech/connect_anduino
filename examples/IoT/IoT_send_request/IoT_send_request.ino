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
  This is the example of sending the data to the Connect Anduino server and displaying
  the response on the serial monitor (Note: this is just for sending and getting the response
  no operation based on the server response is done).

  IoT Functions
  -- CA_HOST() -> Gets host website address
  -- CA_APIROOT() -> Gets the api address for communication

  Code Tested on: NodeMCU, ESP8266

  Note: Install the board from the ESP8266 community in the arduino software
  HOW TO:- https://www.youtube.com/watch?v=rCBuQabojp0&t
  Note: Required library are ESP8266WiFi.h and ESP8266HTTPClient.h

  Please make sure to select the right board in the Tools -> Board:
 *************************************************************/
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Connect_Anduino_IoT.h>

Connect_Anduino_IoT iot_ca;
HTTPClient http;

char WFSSID[21] = "YOUR_WIFI_SSID";
char WFPASS[21] = "YOUR_WIFI_PASSWORD";
String fingerprint = "YOUR_FINGERPRINT";  //You will find the fingerprint on the Connect Anduino android app IoT section
String roomAccessId = "YOUR_ROOM_ACCESSID"; //You will find the access id for room on the Connect Anduino android app IoT section
String deviceAccessId = "YOUR_DEVICE_ACCESSID"; //You will find the access id for device on the Connect Anduino android app IoT section
String url;

void ConnectNetwork(void);

void setup() {
  delay(2000);
  Serial.begin(115200);
  url = String(iot_ca.CA_HOST()) + iot_ca.CA_APIROOT(); //Gets the url for connections
  // Network connect
  ConnectNetwork();
}

void loop() {
  /*
   In this code the device is ON for 10 seconds and then OFF for 10 seconds
  */
  sendRequest(deviceAccessId, "1");
  delay(10000);
  sendRequest(deviceAccessId, "0");
  delay(10000);
}

void sendRequest(String id, String value){
  String postData = "fingerprint="+fingerprint+"&accessid="+id+"&value="+value;  //Prepares the post data for fetching the data from the server
  http.begin(url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");  //This is something you dont want to miss
  int httpCode = http.POST(postData);  //Get the response which is a HTTP code (200 is the OK)
  String payload = http.getString();  //Gets the response from the server
  Serial.println(httpCode); //Displays the HTTP code
  Serial.println(payload);  //Displays the string (Response you get from the server is in JSON format)
  http.end();   //You might want to end the connection after you get the response
  delay(10000);  //Adding a delay is fine so that you don't bother the server too much...
}

// Network connect
void ConnectNetwork() {
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.print(F("\n\nConnecting to Network: "));
  Serial.println(WFSSID);
  Serial.print(F("Password of Network: "));
  Serial.println(WFPASS);
  WiFi.begin(WFSSID, WFPASS);
  for (int i = 0; WiFi.status() != WL_CONNECTED; i++) {
    delay(500);
    if (i < 50) {
      Serial.print('.');
    } else {
      Serial.print(F("Failed to "));
      break;
    }
  }
  Serial.println(F("connected!"));
}
