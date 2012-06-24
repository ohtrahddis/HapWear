

const float g = -9.8;

int x;
int y;
int z;

int xold = 0;
int yold = 0;
int zold = 0;

float pitch;
float roll
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

void setup(){
  Serial.begin(9600);
  pinMode(12, INPUT); //x
  pinMode(11, INPUT); //y
  pinMode(10, INPUT); //z
  x = 0;
  y = 0;
  z = g;
  xEff = 0;
  yEff = 0;
  zEff = 0;
}

void loop(){
  updateData();
  checkDiff();
  boolean IsHandStill = checkStillHand();
  if(IsHandStill){
    Serial.write("Hand is Still");
  }
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
