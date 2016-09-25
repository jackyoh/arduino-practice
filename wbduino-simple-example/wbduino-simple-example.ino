#define WEBDUINO_FAIL_MESSAGE "No Page"
#include "SPI.h"
#include "Ethernet.h"
#include "WebServer.h"
#include "Streaming.h"
#include <dht.h>
#define DHT11_PIN 2
dht DHT;

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 0, 177);
WebServer webserver("", 80);

void defaultCmd(WebServer &server,WebServer::ConnectionType type, char *url_tail, bool tail_complete){
   P(homePage) =
      "<!DOCTYPE HTML>"
      "<html>"
      "<head><title>test</title></head>"
      "<body>this is a test</body>"
      "</html>";
  server.httpSuccess();
  if(type != WebServer::HEAD){
    server.printP(homePage);
  }
  
}
void dhtCmd(WebServer &server, WebServer::ConnectionType type, char *url_tail,bool tail_complete){
  P(dntHead) =
    "<!DOCTYPE HTML>"
    "<html>"
       "<head><title>test</title></head>"
       "<body>";
       
  P(dntEnd) =
       "<a href=\"http://192.168.0.177\">GO HOME</a>"
       "</body>"
       "</html>";

  server.httpSuccess();
  if(type != WebServer::HEAD){
      server.printP(dntHead);
  }

  int chk = DHT.read11(DHT11_PIN);
  switch(chk){
    case DHTLIB_OK:
        Serial.print("OK, \t");
        break;
    case DHTLIB_ERROR_CHECKSUM:
        Serial.print("Checksum error,\t");
        break;
    case DHTLIB_ERROR_TIMEOUT:
        Serial.print("Time out error,\t");
        break;
    default:
        Serial.print("Unknown error, \t");
        break;
  }

  server<<"<span style='color:red;'>humidity</span>"<<DHT.humidity<<"<br/>";
  server<<"<span style='color:red;'>temperature</span>"<<DHT.temperature<<"<br/>";
  server.printP(dntEnd);
}

void setup() {
  Ethernet.begin(mac, ip);
  webserver.begin();
  webserver.setDefaultCommand(&defaultCmd);
  webserver.addCommand("dht", &dhtCmd);
}

void loop() {
  webserver.processConnection();
}
