#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>

#ifndef APSSID
#define APSSID "ananin_ami"
#define APPSK  "orospu"
#endif

const char* ssid     = "Linksys13619";
const char* password = "3ttamn5ns4";

IPAddress local_IP(192,168,1,25);
IPAddress gateway(192,168,4,9);
IPAddress subnet(255,255,255,0);
//const char *ssid = APSSID;
//const char *password = APPSK;

int incomingByte = 0; // for incoming serial data
//char incomingByteArray[255];
int lengthIncomingByte;

WiFiUDP Udp;
unsigned int localUdpPort = 14445;  // local port to listen on

char incomingPacket[255];
char replyPacket[] = "ESP8266 Got the message :-)";  // a reply string to send back
char img[60][80];
//char  tstMsg[] = "Murat is sending UDP";  // a reply string to send back


void setup()
{ 
int i=0; int j=0;
  while (i<60){
    img[i][j]='9';
    while(j<80){
      img[i][j]='9';
      j++;
    }
  j=0;
  i++;
}
  Serial.begin(115200);
  Serial.println();
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
  Udp.begin(localUdpPort);
  Serial.printf("Now listening at IP %s, UDP port %d\n", WiFi.localIP().toString().c_str(), localUdpPort);
  
  //Serial.print("Setting soft-AP configuration ... ");
  //Serial.println(WiFi.softAPConfig(local_IP, gateway, subnet) ? "Ready" : "Failed!");
  //Serial.print("Setting soft-AP ... ");
  //Serial.println(WiFi.softAP(ssid) ? "Ready" : "Failed!");
  //Serial.print("Soft-AP IP address = ");
  //Serial.println(WiFi.softAPIP());
  //Udp.begin(localUdpPort);
}


void loop()
{
//  if (Serial.available() > 0) {
//    lengthIncomingByte=Serial.available();
//    //incomingByte = Serial.read();// read the incoming byte
//    Serial.readBytes(incomingByteArray,lengthIncomingByte);
//    Serial.println(incomingByteArray);
//    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
//    //Udp.write(incomingByte);
//    Udp.write(incomingByteArray);
//    Udp.endPacket();
//  }

//yukle();

 
int packetSize = Udp.parsePacket();
if (packetSize)
  {
    // receive incoming UDP packets
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
    int len = Udp.read(incomingPacket, 255);
    if (len > 0)
    {
      incomingPacket[len] = 0;
    }
    Serial.printf("UDP packet contents: %s\n", incomingPacket);

    //send back a reply, to the IP address and port we got the packet from
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    //Udp.write(replyPacket);
    
    
    int i=0; int j=0;
    while (i<60){
      while(j<80){
        Udp.write(img[i][j]);
        j++;
      }
      j=0;
      i++;
    }

    //Udp.write(img[60][80]);
    Udp.endPacket();
  }
}

void yukle()
{
for (int i=1;i=5;i++){
  for (int j=1;j=5;j++){
    img[i][j]='A';
    //yield();
    delay(1);
    }
}
}
