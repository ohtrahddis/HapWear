//#include <ctype.h>
#include <SoftwareSerial.h>
/*
#define bit9600Delay 84  
#define halfBit9600Delay 42
#define bit4800Delay 188 
#define halfBit4800Delay 94 
*/
byte rx = 6;
byte tx = 7;

double xvect;
double yvect;

double lat;
double longt;

char sbuff[32];
const char* sendbuff = "hello hai";

//SoftwareSerial mySerial(rx, tx);

void setup(){
  Serial.begin(9600);
  //mySerial.begin(9600);
}

void loop(){
  /* Check number of available bytes. */
  int numchars = Serial.available();
  //Serial.print("numchars = ");
  //Serial.println(numchars);
    
  /* Check the header: if a byte is incorrect, try again soon. */
  if(numchars < 20){
    delay(500);
    return;
  }

  /* We require a 4 byte header (0x01020304), then 2 doubles. */
  /*char headerBuf;
  for (int i=0; i < 4; ++i) {
    Serial.readBytes(&headerBuf, 1);
    if (headerBuf != (i + 1)) {
      Serial.println("Invalid header.");
      return;
    }
  }*/
  
  /* Grab the data. */
  Serial.readBytes(sbuff, 16);    
  xvect = *((double*)sbuff);
  yvect = *((double*)(sbuff+8));
  
  Serial.println(xvect, 32);
  Serial.println(yvect, 32);
  delay(100);
}
