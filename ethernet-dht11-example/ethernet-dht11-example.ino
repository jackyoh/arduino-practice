#include <SPI.h>
#include <Ethernet.h>
#include <dht.h>
#define DHT11_PIN 2

dht DHT;

byte mac[] = {
   0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED 
};


IPAddress ip(192, 168, 0, 177);
EthernetServer server(80);


void setup() {
  Serial.begin(9600);
  while(!Serial){
     ;
  }
  Ethernet.begin(mac,ip);
  server.begin();
}

void loop() {
  EthernetClient client = server.available();
  if(client){
     Serial.println("new client");
     
     client.println("HTTP/1.1 200 OK");
     client.println("Content-Type:text/html");
     client.println("Connection:close");
     client.println("Refresh:5");
     client.println();
     client.println("<!DOCTYPE HTML>");
     client.println("<html>");

     int chk = DHT.read11(DHT11_PIN);
     switch(chk){
       case DHTLIB_OK:
           client.print("OK ");
           break;
      case DHTLIB_ERROR_CHECKSUM:
           client.print("Checksum error");
           break;
      case DHTLIB_ERROR_TIMEOUT:
          client.print("Time out error"); 
          break;
      default:
          client.print("Unknown error");
          break; 
    }
    client.print("<apan style='color:blue;'>humidity(%)</span>");
    client.print(DHT.humidity, 2);
    client.print(", ");
    client.print("<span style='color:blute'>temperature</span>");
    client.print(DHT.temperature,2);
    client.println("</html>");

    delay(1);
    client.stop();
    Serial.println("client disconnected");
     
  }

}
