#include <IRremote.h>
#include <IRremoteInt.h>
#define UP 13
#define RIGHT 14
#define LEFT 15
#define DOWN 16
const int controlPinA1 = 2; // connected to pin 7 on the H-bridge
const int controlPinA2 = 3; // connected to pin 2 on the H-bridge
const int controlPinB1 = 4; // connected to pin 15 on the H-bridge
const int controlPinB2 = 5; // connected to pin 10 on the H-bridge'
const int enablePinA = 9;   // connected to pin 1 on the H-bridge
const int enablePinB = 10;  // connected to pin 9 on the H-bridge
//codes[0]-codes[9] keys 0-9
//codes[10] - *
//codes[11] - #
//codes[12] - ok
//codes[13] - up
//codes[14] - right
//codes[15] - left
//codes[16] - down
const unsigned long codes[] = {0xff4ab5,0xff6897,0xff9867,0xffb04f,0xff30cf,
    0xff18e7,0xff7a85,0xff10ef,0xff38c7,0xff5aa5,0xff42bd,
    0xff52ad,0xff02fd,0xff629D,0xffc23d,0xff22dd,0xffa857};



int RECV_PIN = 6;
IRrecv irrecv(RECV_PIN);
decode_results results;
int key;
void forward(){
	digitalWrite(controlPinA1, HIGH);
	digitalWrite(controlPinA2, LOW);
	analogWrite(enablePinA,128);
	digitalWrite(controlPinB1, HIGH);
	digitalWrite(controlPinB2, LOW);
	analogWrite(enablePinB,128);
	delay(1000);
	analogWrite(enablePinA,0);
	analogWrite(enablePinB,0);
	delay(1000);
}

void backward(){
	digitalWrite(controlPinA1, LOW);
	digitalWrite(controlPinA2, HIGH);
	analogWrite(enablePinA,128);
	digitalWrite(controlPinB1, LOW);
	digitalWrite(controlPinB2, HIGH);
	analogWrite(enablePinB,128);
	delay(1000);
	analogWrite(enablePinA,0);
	analogWrite(enablePinB,0);
	delay(1000);
}
void left(){
	digitalWrite(controlPinA1, HIGH);
	digitalWrite(controlPinA2, LOW);
	digitalWrite(enablePinA,128);
	digitalWrite(controlPinB1,LOW);
	digitalWrite(controlPinB2,HIGH);
	analogWrite(enablePinB,128);
	delay(1000);
	analogWrite(enablePinA,0);
	analogWrite(enablePinB,0);
	delay(1000);
}
void right(){
	digitalWrite(controlPinA1, LOW);
	digitalWrite(controlPinA2, HIGH);
	digitalWrite(enablePinA,128);
	digitalWrite(controlPinB1,HIGH);
	digitalWrite(controlPinB2,LOW);
	analogWrite(enablePinB,128);
	delay(1000);
	analogWrite(enablePinA,0);
	analogWrite(enablePinB,0);
	delay(1000);
}

void setup()
{
  // intialize the inputs and outputs
  pinMode(controlPinA1, OUTPUT);
  pinMode(controlPinA2, OUTPUT);
  pinMode(enablePinA, OUTPUT);
  pinMode(controlPinB1, OUTPUT);
  pinMode(controlPinB2, OUTPUT);
  pinMode(enablePinB, OUTPUT);

  // pull the enable pin LOW to start
  digitalWrite(enablePinA, LOW);
  digitalWrite(enablePinB, LOW);
  
  Serial.begin(9600);
  irrecv.enableIRIn();
  forward();
}

void loop()
{
  if (irrecv.decode(&results))
  {
    key = -1;
    
    for (int i=0; i<18; i++){
      if (results.value == codes[i]){
        key = i;
        break;
      }
    }
    Serial.println(results.value);
    Serial.println(codes[UP]);
    Serial.println(key);
    if (key == UP)
     forward();
    else
     if (key == DOWN)
      backward();
     else 
      if (key == LEFT)
       left();
      else
       if (key == RIGHT)
        right();
    irrecv.resume();
  }
    
    
}