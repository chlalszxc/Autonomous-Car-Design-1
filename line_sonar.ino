#define ledPin 13
#define LINE_DETTECT_WHITE 1
#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 100
#include <NewPing.h>

NewPing sonar(TRIGGER_PIN,ECHO_PIN, MAX_DISTANCE);

int linesensor_data[5] = {0,0,0,0,0};
int linesensor_pin[5] = {2,3,4,5,6};

int read_digital_line_sensor(void){
  int i;
  int sum=0;
  for(i=0;i<5;i++){
    if(LINE_DETTECT_WHITE == 0)
      linesensor_data[i] = 1 - digitalRead(linesensor_pin[i]);
    else
      linesensor_data[i] = digitalRead(linesensor_pin[i]);

    sum += linesensor_data[i];
  }
  
  if(sum == 5) return sum;

  else if(sum == 2){
    if((linesensor_data[3] == 1)&&(linesensor_data[4]==1)) return 3;
    if((linesensor_data[2] == 1)&&(linesensor_data[3]==1)) return 1;
    if((linesensor_data[1] == 1)&&(linesensor_data[2]==1)) return -1;
    if((linesensor_data[0] == 1)&&(linesensor_data[1]==1)) return -3;
  }
  
  else if(sum == 1)
  {
    if(linesensor_data[0] == 1) return -4;
    if(linesensor_data[1] == 1) return -2;
    if(linesensor_data[2] == 1) return 0;
    if(linesensor_data[3] == 1) return 2;
    if(linesensor_data[4] == 1) return 4;
  }
  
  else if(sum == 3) return -10;

  else return -5;

}

void setup(){
  pinMode(ledPin, OUTPUT);

  for(int i=0;i<5;i++)  
    pinMode(linesensor_pin[i],INPUT);
  
  Serial.begin(9600);
}

void loop(){
  int i;
  int sum = 0;
  float distance = 0.0;
  sum = read_digital_line_sensor();
  distance = sonar.ping_cm();
  if(distance == 0) distance = MAX_DISTANCE;

   Serial.print("Input data = ");
   for(int i=0;i<5;i++){
    Serial.print(linesensor_data[i]);
    Serial.print(" ");
   }
   Serial.print("sum = ");
   Serial.print(sum);
   Serial.println(" ");
   Serial.print("Ping : ");
   Serial.print(distance);
   Serial.println("cm");
}
