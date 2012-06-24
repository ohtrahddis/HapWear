#include <string.h>

int FRONT = 1;
int MIDDLE = 2;
int BACK = 3;
int LEFT = 5;
int RIGHT = 11;
int FRONTLEFT = 4;
int FRONTRIGHT = 10;
int BACKLEFT = 6;
int BACKRIGHT = 12;
int OPPOSITE = 8;

char orientation[] = "right";
int pitch = 0;
int roll = 0;

int vectorX = 0;
int vectorY = 0;
int vectorZ = 0;

int delayTime = 500;

void setup() {
  for(int i = 0; i < 13; i++) {
    pinMode(i, OUTPUT);
  }   
}

void loop() {
  
  if(strncmp(orientation, "top", 7) == 0) {
    FRONT = 1;
    MIDDLE = 2;
    BACK = 3;
    LEFT = 5;
    RIGHT = 11;
    FRONTLEFT = 4;
    FRONTRIGHT = 10;
    BACKLEFT = 6;
    BACKRIGHT = 12;
    OPPOSITE = 8;
  }
  else if(strncmp(orientation, "left", 7) == 0) {
    FRONT = 4;
    MIDDLE = 5;
    BACK = 6;
    LEFT = 8;
    RIGHT = 2;
    FRONTLEFT = 7;
    FRONTRIGHT = 1;
    BACKLEFT = 9;
    BACKRIGHT = 3;
    OPPOSITE = 11;
  }
  else if(strncmp(orientation, "right", 7) == 0) {
    FRONT = 10;
    MIDDLE = 11;
    BACK = 12;
    LEFT = 2;
    RIGHT = 8;
    FRONTLEFT = 1;
    FRONTRIGHT = 7;
    BACKLEFT = 3;
    BACKRIGHT = 9;
    OPPOSITE = 5;
  }
  else if(strncmp(orientation, "bottom", 7) == 0) {
    FRONT = 7;
    MIDDLE = 8;
    BACK = 9;
    LEFT = 11;
    RIGHT = 5;
    FRONTLEFT = 10;
    FRONTRIGHT = 4;
    BACKLEFT = 12;
    BACKRIGHT = 6;
    OPPOSITE = 2;
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
  
  /*
  for(int i = 1; i < 13; i++) {
    digitalWrite(i, HIGH);
    delay(delayTime);
    digitalWrite(i, LOW);
    delay(delayTime);
  }
  */
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
