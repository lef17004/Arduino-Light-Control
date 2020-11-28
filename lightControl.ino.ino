#include <string.h>
#include <Ethernet.h>
#include<EthernetUdp.h>
//#define COMMON_ANODE
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

//Change to match your ip address
IPAddress ip(192, 168, 86, 307);

unsigned int localPort = 8888;

EthernetUDP Udp;

const int redPin = 8;
const int greenPin = A0;
const int bluePin = A1;

char recievedString[UDP_TX_PACKET_MAX_SIZE];

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  Udp.begin(localPort);

  setColor(255, 255, 255);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  int stringSize = Udp.parsePacket();


  
  if (stringSize) {
    Udp.read(recievedString, UDP_TX_PACKET_MAX_SIZE);

    if (!strcmp(recievedString, "blu")) {
      setColor(0, 0, 255);
    }
    if (!strcmp(recievedString, "red")) {
      setColor(255, 0, 0);
      
    }
    if (!strcmp(recievedString, "gre")) {
      setColor(0, 255, 0);
    }

    if (!strcmp(recievedString, "aqu")) {
      setColor(0, 255, 255);
    }
    if (!strcmp(recievedString, "whi")) {
      setColor(255, 255, 255);
    }

    if (!strcmp(recievedString, "r&b")) {
      setColor(255, 0, 255);
    }
    
    
  }


  for (int i = 0; i < stringSize; i++) 
  {
    //recievedString[i] = "\0";
  }
  
  delay(1000);
  
}


void setColor(int red, int green, int blue) {

  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif

  
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue); 
}
