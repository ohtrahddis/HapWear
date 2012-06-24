#include <string.h>

int FRONT = 2;
int MIDDLE = 3;
int BACK = 4;
int LEFT = 6;
int RIGHT = 12;
int FRONTLEFT = 5;
int FRONTRIGHT = 11;
int BACKLEFT = 7;
int BACKRIGHT = 13;
int OPPOSITE = 9;

char orientation[] = "right";

int vectorX = 0;
int vectorY = 0;
int vectorZ = 0;

const float g = -9.8;

int x;
int y;
int z;

int xold = 0;
int yold = 0;
int zold = 0;

float pitch;
float roll;
float yaw;

int dx = 0.1; //these are lee-way callibrations to account for jitter
int dy = 0.2;
int dz = 0.5;

int xDif;
int yDif;
int zDif;
int zGdif;

int xEff;
int yEff;
int zEff;

int delayTime = 250;

void setup() {
  for(int i = 0; i < 14; i++) {
    pinMode(i, OUTPUT);
  }   
  Serial.begin(9600);
  //pinmode(nelsoncode, INPUT);
  x = 0;
  y = 0;
  z = g;
  xEff = 0;
  yEff = 0;
  zEff = 0;
}

void left() {
  digitalWrite(MIDDLE, HIGH);
  delay(delayTime);
  digitalWrite(MIDDLE, LOW);
  delay(delayTime);
  digitalWrite(LEFT, HIGH);
  delay(delayTime);
  digitalWrite(LEFT, LOW);
  delay(delayTime);
  digitalWrite(LEFT, HIGH);
  delay(delayTime);
  digitalWrite(LEFT, LOW);
  delay(delayTime);
}

void right() {
  digitalWrite(MIDDLE, HIGH);
  delay(delayTime);
  digitalWrite(MIDDLE, LOW);
  delay(delayTime);
  digitalWrite(RIGHT, HIGH);
  delay(delayTime);
  digitalWrite(RIGHT, LOW);
  delay(delayTime);
  digitalWrite(RIGHT, HIGH);
  delay(delayTime);
  digitalWrite(RIGHT, LOW);
  delay(delayTime);
}

void front() {
  digitalWrite(MIDDLE, HIGH);
  delay(delayTime);
  digitalWrite(MIDDLE, LOW);
  delay(delayTime);
  digitalWrite(FRONT, HIGH);
  delay(delayTime);
  digitalWrite(FRONT, LOW);
  delay(delayTime);
  digitalWrite(FRONT, HIGH);
  delay(delayTime);
  digitalWrite(FRONT, LOW);
  delay(delayTime);
}

void back() {
  digitalWrite(MIDDLE, HIGH);
  delay(delayTime);
  digitalWrite(MIDDLE, LOW);
  delay(delayTime);
  digitalWrite(BACK, HIGH);
  delay(delayTime);
  digitalWrite(BACK, LOW);
  delay(delayTime);
  digitalWrite(BACK, HIGH);
  delay(delayTime);
  digitalWrite(BACK, LOW);
  delay(delayTime);
}

void frontLeft() {
  digitalWrite(MIDDLE, HIGH);
  delay(delayTime);
  digitalWrite(MIDDLE, LOW);
  delay(delayTime);
  digitalWrite(FRONT, HIGH);
  delay(delayTime);
  digitalWrite(FRONT, LOW);
  delay(delayTime);
  digitalWrite(FRONTLEFT, HIGH);
  delay(delayTime);
  digitalWrite(FRONTLEFT, LOW);
  delay(delayTime);
}

void frontRight() {
  digitalWrite(MIDDLE, HIGH);
  delay(delayTime);
  digitalWrite(MIDDLE, LOW);
  delay(delayTime);
  digitalWrite(FRONT, HIGH);
  delay(delayTime);
  digitalWrite(FRONT, LOW);
  delay(delayTime);
  digitalWrite(FRONTRIGHT, HIGH);
  delay(delayTime);
  digitalWrite(FRONTRIGHT, LOW);
  delay(delayTime);
}

void backLeft() {
  digitalWrite(MIDDLE, HIGH);
  delay(delayTime);
  digitalWrite(MIDDLE, LOW);
  delay(delayTime);
  digitalWrite(BACK, HIGH);
  delay(delayTime);
  digitalWrite(BACK, LOW);
  delay(delayTime);
  digitalWrite(BACKLEFT, HIGH);
  delay(delayTime);
  digitalWrite(BACKLEFT, LOW);
  delay(delayTime);
}

void backRight() {
  digitalWrite(MIDDLE, HIGH);
  delay(delayTime);
  digitalWrite(MIDDLE, LOW);
  delay(delayTime);
  digitalWrite(BACK, HIGH);
  delay(delayTime);
  digitalWrite(BACK, LOW);
  delay(delayTime);
  digitalWrite(BACKRIGHT, HIGH);
  delay(delayTime);
  digitalWrite(BACKRIGHT, LOW);
  delay(delayTime);
}

void up() {
  digitalWrite(OPPOSITE, HIGH);
  delay(delayTime);
  digitalWrite(OPPOSITE, LOW);
  delay(delayTime);
  digitalWrite(MIDDLE, HIGH);
  delay(delayTime);
  digitalWrite(MIDDLE, LOW);
  delay(delayTime);
  digitalWrite(MIDDLE, HIGH);
  delay(delayTime);
  digitalWrite(MIDDLE, LOW);
  delay(delayTime);
}

void down() {
  digitalWrite(MIDDLE, HIGH);
  delay(delayTime);
  digitalWrite(MIDDLE, LOW);
  delay(delayTime);
  digitalWrite(OPPOSITE, HIGH);
  delay(delayTime);
  digitalWrite(OPPOSITE, LOW);
  delay(delayTime);
  digitalWrite(OPPOSITE, HIGH);
  delay(delayTime);
  digitalWrite(OPPOSITE, LOW);
  delay(delayTime);
}

void updateData(){
  xold = x;
  yold = y;
  zold = z;
  x = digitalRead(12);
  y = digitalRead(11);
  z = digitalRead(10);
  
  pitch = digitalRead(12);
  roll = digitalRead(11);
  yaw = digitalRead(10);
  
  xDif = x - xold;
  yDif = y - yold;
  zDif = z - zold;
  zGdif = z-g;
}

boolean checkStillHand(){
  if(xDif != NULL && yDif != NULL && zDif != NULL){
    if(abs(xDif) < dx && abs(yDif) < dy && abs(zDif) < dz ){
      return true;
    }
    else{
      return false;
    }
  }
  else{
    return false;
  }
}

void checkDiff(){
  if(abs(xDif) < dx){
    xEff = xold;
  }else{
    xEff = x;
  }
  
  if(abs(yDif) < dy){
    yEff = yold;
  }else{
    yEff = y;
  }
  
  if(abs(zDif) < dz){
    zEff = zold;
  }else{
    zEff = z;
  }
}

boolean checkUpright(){
  
}

void loop() {
  
  updateData();
  checkDiff();
  boolean IsHandStill = checkStillHand();
  if(IsHandStill){
    Serial.write("Hand is Still");
  }
  
  if(strncmp(orientation, "top", 7) == 0) {
    FRONT = 2;
    MIDDLE = 3;
    BACK = 4;
    LEFT = 6;
    RIGHT = 12;
    FRONTLEFT = 5;
    FRONTRIGHT = 11;
    BACKLEFT = 7;
    BACKRIGHT = 13;
    OPPOSITE = 9;
  }
  else if(strncmp(orientation, "left", 7) == 0) {
    FRONT = 5;
    MIDDLE = 6;
    BACK = 7;
    LEFT = 9;
    RIGHT = 3;
    FRONTLEFT = 8;
    FRONTRIGHT = 2;
    BACKLEFT = 10;
    BACKRIGHT = 4;
    OPPOSITE = 12;
  }
  else if(strncmp(orientation, "right", 7) == 0) {
    FRONT = 11;
    MIDDLE = 12;
    BACK = 13;
    LEFT = 3;
    RIGHT = 9;
    FRONTLEFT = 2;
    FRONTRIGHT = 8;
    BACKLEFT = 4;
    BACKRIGHT = 10;
    OPPOSITE = 6;
  }
  else if(strncmp(orientation, "bottom", 7) == 0) {
    FRONT = 8;
    MIDDLE = 9;
    BACK = 10;
    LEFT = 12;
    RIGHT = 6;
    FRONTLEFT = 11;
    FRONTRIGHT = 5;
    BACKLEFT = 13;
    BACKRIGHT = 7;
    OPPOSITE = 3;
  }
  
  if(vectorZ >= 0 && abs(vectorZ) >= abs(vectorX) && abs(vectorZ) >= abs(vectorY)) {
    up();
  }
  else if(vectorZ < 0 && abs(vectorZ) >= abs(vectorX) && abs(vectorZ) >= abs(vectorY)) {
    down();
  }
  else if(vectorX <= 0 && abs(vectorX) >= abs(vectorY) && abs(vectorX) >= abs(vectorZ)) {
    if(vectorY >= 0 && abs(vectorY) >= 0.5 * (float)abs(vectorX)) {
      frontLeft();
    }
    else if(vectorY < 0 && abs(vectorY) >= 0.5 * (float)abs(vectorX)) {
      backLeft();
    }
    else{
      left();
    }
  }
  else if(vectorX > 0 && abs(vectorX) >= abs(vectorY) && abs(vectorX) >= abs(vectorZ)) {
    if(vectorY >= 0 && abs(vectorY) >= 0.5 * (float)abs(vectorX)) {
      frontRight();
    }
    else if(vectorY < 0 && abs(vectorY) >= 0.5 * (float)abs(vectorX)) {
      backRight();
    }
    else{
      right();
    }
  }
  else if(vectorY >= 0 && abs(vectorY) >= abs(vectorX) && abs(vectorY) >= abs(vectorZ)) {
    if(vectorX >= 0 && abs(vectorX) >= 0.5 * (float)abs(vectorY)) {
      frontRight();
    }
    else if(vectorX < 0 && abs(vectorX) >= 0.5 * (float)abs(vectorY)) {
      frontLeft();
    }
    else{
      front();
    }
  }
  else if(vectorY < 0 && abs(vectorY) >= abs(vectorX) && abs(vectorY) >= abs(vectorZ)) {
    if(vectorX >= 0 && abs(vectorX) >= 0.5 * (float)abs(vectorY)) {
      backRight();
    }
    else if(vectorX < 0 && abs(vectorX) >= 0.5 * (float)abs(vectorY)) {
      backLeft();
    }
    else{
      back();
    }
  }
  
  
  
  
  for(int i = 1; i < 14; i++) {
    digitalWrite(i, HIGH);
    delay(delayTime);
    digitalWrite(i, LOW);
    delay(delayTime);
  }
}


