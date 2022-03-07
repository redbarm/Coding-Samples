//initialize the libraries used for the communications
#include <Wire.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
//#include <WiFiClient.h>
#include <WiFiUdp.h>

//Wifi Network Stuff
// Replace with your network credentials
const char* ssid     = "Linksys13619";
const char* password = "3ttamn5ns4";

int incomingByte = 0; // for incoming serial data
int lengthIncomingByte;

WiFiUDP Udp;
unsigned int localUdpPort = 14445;  // local port to listen on

char incomingPacket[255];
char replyPacket[] = "ESP8266 Got the message :-)";  // a reply string to send back
char img[60][80];

//End of Wifi Network stuff


//Flir-Lepton stuff
byte x = 0;

//define memory adresses to acces them
#define ADDRESS  (0x2A)
#define COMMANDID_REG (0x04)
#define DATALEN_REG (0x06)
#define DATA0 (0x08)

//define the comands to control the communication i2c (used for confguring the module)
#define AGC (0x01)
#define SYS (0x02)
#define VID (0x03)
#define OEM (0x08)
#define RAD (0x0E)

#define GET (0x00)
#define SET (0x01)
#define RUN (0x02)

//define de size of a VoSPI packet, 2bytes for ID, 2bytes for CRC and 160bytes for the frame
#define VOSPI_FRAME_SIZE (164)
byte lepton_frame_packet[VOSPI_FRAME_SIZE];

//defining variables related with the image
int image_index;
#define image_x (80)
#define image_y (60)
word image[image_x][image_y];

//Initialize the variables used in this sketch
int i,j;
float AUXtemperature;
String userAction;
word minval = 99999;
boolean captureImage = false;
bool runonce = 0;
bool donecapturing = 0;

void setup()
{ 
  //pinMode(15, OUTPUT);
  //digitalWrite(15, LOW);

  //initialize i2c communication
  Wire.begin();

  Serial.begin(115200);

  //configure spi communication
  pinMode(15, OUTPUT);
  digitalWrite(15, HIGH);
  SPI.setDataMode(SPI_MODE3);
  SPI.setClockDivider(5);

  //initialize SPI communication
  SPI.begin();

  
  //set the time out of the serial input
  Serial.setTimeout(90000UL);

  
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
  
  ESP.wdtDisable();
  *((volatile uint32_t*) 0x60000900) &= ~(1); // Hardware WDT OFF
}


void lepton_sync(void){
int data = 0x0f;
digitalWrite(15, HIGH);
delay(10);
while (data & 0x0f == 0x0f){
  digitalWrite(15, LOW);    
  data = SPI.transfer(0x00) << 8;
  data |= SPI.transfer(0x00);
  digitalWrite(15, HIGH);

  int i=0;
  while (i<((VOSPI_FRAME_SIZE - 2) / 2)){
    digitalWrite(15, LOW); 
    SPI.transfer(0x00);
    SPI.transfer(0x00);
    digitalWrite(15, HIGH);
    i++;
    yield();
  }
  
  //for (i = 0; i < ((VOSPI_FRAME_SIZE - 2) / 2); i++){
  //  digitalWrite(15, LOW); 
  //  SPI.transfer(0x00);
  //  SPI.transfer(0x00);
  //  digitalWrite(15, HIGH);
  //  }
  }
}

void read_lepton_frame(void){
int i=0;
while (i<(VOSPI_FRAME_SIZE / 2)){
  digitalWrite(15, LOW);  
  //  send in the address and value via SPI:
  lepton_frame_packet[2 * i] = SPI.transfer(0x00);
  lepton_frame_packet[2 * i + 1] = SPI.transfer(0x00);
  // take the SS pin high to de-select the chip:
  digitalWrite(15, HIGH);
  i++;
  yield();
}

//for (i = 0; i < (VOSPI_FRAME_SIZE / 2); i++){
//  digitalWrite(15, LOW);  
//  //  send in the address and value via SPI:
//  lepton_frame_packet[2 * i] = SPI.transfer(0x00);
//  lepton_frame_packet[2 * i + 1] = SPI.transfer(0x00);
//  // take the SS pin high to de-select the chip:
//  digitalWrite(15, HIGH);
//  }
}

void buffer_image(void){
//command to get from the lecture the ID of the frame
int j = lepton_frame_packet[1];

int i=0;
while (i<image_x){
  //assign to the variable image[i][j] the data read from the lecture, starts assign from 4th and 5th positions due to the from [0]to[3] are the ID and the CRC
  image[i][j] = ((lepton_frame_packet[2 * i + 4] << 8) + lepton_frame_packet[2 * i + 5]); //-0x1000
  i++;
  yield();
}

//for (int i = 0; i < image_x; i++){
//  //assign to the variable image[i][j] the data read from the lecture, starts assign from 4th and 5th positions due to the from [0]to[3] are the ID and the CRC
//  image[i][j] = ((lepton_frame_packet[2 * i + 4] << 8) + lepton_frame_packet[2 * i + 5]); //-0x1000
//}

if (j == 0x3B) {
  donecapturing = true;
}

}

void loop(){
  //Serial.println("Senin Amina koyayim Ben EYY orospu cocugu ESP");

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

    //Running Lepton Stuff
    lepton_sync();
    delay(5);
    //Serial.println(OK);
    while(donecapturing == false){
      read_lepton_frame();
      buffer_image();
    }

    //for(i=0;i<79;i++){
    //  for(j=0;j<59;j++){
    //    Serial.print((int)image[i][j], DEC);
    //    Serial.print("\t");
    //  }
    //  Serial.print("\n");
    //}
    
    Serial.flush();
    donecapturing = false;
    
    //send back a reply, to the IP address and port we got the packet from
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    //Udp.write(replyPacket);

    int i=0; int j=0;
    while (i<image_x-1){
      while(j<image_y-1){
        Udp.write(image[i][j]);
        Serial.print((int)image[i][j], DEC);
        Serial.print("\t");
        j++;
      }
      j=0;
      i++;
      Serial.print("\n");
    }
    //Udp.write(img[60][80]);
    Udp.endPacket();
  }

}
