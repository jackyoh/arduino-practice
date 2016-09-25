#define WEBDUINO_FAIL_MESSAGE "No Page"
#include "SPI.h"
#include "Ethernet.h"
#include "WebServer.h"
#include "Streaming.h"

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

void setup() {
  Ethernet.begin(mac, ip);
  webserver.begin();
  webserver.setDefaultCommand(&defaultCmd);
}

void loop() {
  webserver.processConnection();
}
