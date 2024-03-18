#include <NewPing.h>



#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 100
//sonar(TrigPin, EchoPin, MaxDistance);

NewPing sonar(TRIGGER_PIN,ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(115200);
}

void loop() {
  float distance = 0.0;
  delay(50);
  distance = sonar.ping_cm();
  if(distance == 0) distance = MAX_DISTANCE;         
  Serial.print("Ping : ");
  Serial.print(distance);
  Serial.println("cm");
}
