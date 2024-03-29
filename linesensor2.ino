#define ledPin 13
#define LINE_DETTECT_WHITE 1
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
  return sum;

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
  sum = read_digital_line_sensor();


   Serial.print("Input data = ");
   for(int i=0;i<5;i++){
    Serial.print(linesensor_data[i]);
    Serial.print(" ");
   }
   Serial.print("sum = ");
   Serial.print(sum);
   Serial.println(" ");
}
