


/*dice array is as follows
 *      diceArr[0]                  diceArr[1]
 *      diceArr[2]    diceArr[3]    diceArr[4]
 *      diceArr[5]                  diceArr[6]

*/
int dice[7][7]= {{0,  0,
                  0,0,0,
                  0,  0},
                  
                 {0,  0,
                  0,1,0,
                  0,  0},
                  
                 {1,  0,
                  0,0,0,
                  0,  1},
                  
                 {1,  0,
                  0,1,0,
                  0,  1},
                  
                 {1,  0,
                  0,0,0,
                  0,  1},
            
                 {1,  1,
                  0,1,0,
                  1,  1},
                  
                 {1,  1,
                  1,0,1,
                  1,  1}};

int dicePorts[7] = {3,4,5,6,7,8,9};
int dthrow =0;
int lightArr[7];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i=0; i<7; i++){
    pinMode(dicePorts[i],OUTPUT);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  dthrow = random(6)+1;
  for (int pinInd = 0; pinInd < 7; pinInd++)
  {
    digitalWrite(dicePorts[pinInd],dice[dthrow][pinInd]);
  }
  Serial.println(dthrow);
  
  delay(3000);
}
