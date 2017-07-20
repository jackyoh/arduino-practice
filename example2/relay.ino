#define WEBDUINO_FAIL_MESSAGE
#include "SPI.h"
#include "Ethernet.h"
#include "WebServer.h"

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(10, 1, 1, 177);
WebServer webserver("", 80);
byte LED_PIN = 3;

void defaultCmd(WebServer &server,WebServer::ConnectionType type, char *url_tail, bool tail_complete){
   P(homePage) =
      "<!DOCTYPE HTML>"
      "<html>"
      "<head><title>test</title></head>"
      "<body>"
        "<a href=\"http://10.1.1.177/lighton\">On</a>"
        "<br>"
         "<a href=\"http://10.1.1.177/lightoff\">Off</a>"
      "</body>"
      "</html>";
  server.httpSuccess();
  if(type != WebServer::HEAD){
    server.printP(homePage);
  }
}

void lightOn(WebServer &server,WebServer::ConnectionType type, char *url_tail, bool tail_complete){
  digitalWrite(LED_PIN, HIGH);
  P(lightOnPage) =
    "<!DOCTYPE HTML>"
    "<html>"
    "<head><title>test</title></head>"
        "<body>"
        "<a href=\"http://10.1.1.177\">Go Home</a>"
      "</body>"
      "</html>";
   server.httpSuccess();
  if(type != WebServer::HEAD){
    server.printP(lightOnPage);
  }     
  
}

void lightOff(WebServer &server,WebServer::ConnectionType type, char *url_tail, bool tail_complete){
  digitalWrite(LED_PIN, LOW);
  P(lightOffPage) =
    "<!DOCTYPE HTML>"
    "<html>"
    "<head><title>test</title></head>"
        "<body>"
        "<a href=\"http://10.1.1.177\">Go Home</a>"
      "</body>"
      "</html>";
   server.httpSuccess();
   if(type != WebServer::HEAD){
     server.printP(lightOffPage);
   } 
}


void setup() {
   pinMode(LED_PIN, OUTPUT);

   Ethernet.begin(mac, ip);
   webserver.begin();
   webserver.setDefaultCommand(&defaultCmd);
   webserver.addCommand("lighton", &lightOn);
   webserver.addCommand("lightoff", &lightOff);
}

void loop() {
  webserver.processConnection();
}
