byte seven_seg_digits[10][7]={
  {0,0,0,0,0,0,1},
  {1,0,0,1,1,1,1},
  {0,0,1,0,0,1,0},
  {0,0,0,0,1,1,0},
  {1,0,0,1,1,0,0},
  {0,1,0,0,1,0,0},
  {0,1,0,0,0,0,0},
  {0,0,0,1,1,1,1},
  {0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0}
  };
const int buttonPin=10;
int buttonState=0;
int num=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(9,0);
  digitalWrite(buttonPin,HIGH);
  Serial.begin(19200);
}

void SevenSegWrite(byte digit){
  byte pin=2;
  for(byte seg=0;seg<7;++seg){
    digitalWrite(pin,seven_seg_digits[digit][seg]);
    ++pin;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState=digitalRead(buttonPin);
  Serial.println(num);
  if(buttonState==0){
   
    delay(1000);
    num++;
    //Serial.println(num);
    if(num>9)
    {
      num=0;
    }
  }
  SevenSegWrite(num);

 
}
