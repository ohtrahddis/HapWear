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
byte SWval;

char sbuff[32];
const char* sendbuff = "hello hai";

//SoftwareSerial mySerial(rx, tx);

void setup(){
  Serial.begin(9600);
  //mySerial.begin(9600);
}

void loop(){
  int sbuffpos = 0;
  int numchars = Serial.available();
  if(numchars > 31){
    numchars = 0;
  }
  /*for(sbuffpos = 0; sbuffpos<numchars; sbuffpos++){
    sbuff[sbuffpos] = (char)mySerial.read();
  }
  sbuff[sbuffpos] = 0;
  for(int x = 0; x<numchars; x++)
  {
    //blah = mySerial.read();
    if(sbuff[x] != 0){
      Serial.write(sbuff[x]);
    }
    //if(mySerial.read() == compare.toCharArray())
    //{
    //  Serial.write("got hello");
    //}
  }*/
  //mySerial.write("hi\0");
  Serial.readBytes(sbuff, 8);
  delay(1000);
}
