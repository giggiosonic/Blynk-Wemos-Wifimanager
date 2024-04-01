#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino
//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

#define BLYNK_PRINT Serial // Comment this out to disable prints and save space
#include <BlynkSimpleEsp8266.h>
  
 char ssid[] = "";
 char pass[] = "";
 const char* auth = "";

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    WiFi.begin(ssid, pass);
    //WiFiManager
    //Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;
    wifiManager.EC_begin();  
    wifiManager.EC_read();
     
 
     
     
    //reset saved settings
    wifiManager.resetSettings();
  
    //set custom ip for portal
    //wifiManager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));
 
    //fetches ssid and pass from eeprom and tries to connect
    wifiManager.autoConnect("BLYNK_Config", "password"); // Nombre del punto de acceso Wi-FI y contraseña para la configuración WEMOS D1 (ESP8266)
    //or use this for auto generated name ESP + ChipID
    //wifiManager.autoConnect();

    
    //if you get here you have connected to the WiFi
    Serial.println("connected...WI-FI)");
  
  const char* auth = wifiManager.getAuth();
 
  delay (1000);
   
 Blynk.begin(auth, ssid, pass, "micasa442.ddns.net", 8080);
}


void loop() {
    // put your main code here, to run repeatedly:

  Blynk.run();  
}
