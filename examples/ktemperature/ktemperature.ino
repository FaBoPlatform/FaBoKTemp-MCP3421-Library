#include "fabo-mcp3421.h"
#include "Wire.h"

FaBoKTemp faboKTemp;

void setup() {
  Serial.begin(9600);
  Serial.println("Init...");
  
  faboKTemp.configuration();
}

void loop() {
  // put your main code here, to run repeatedly:
  double temp = faboKTemp.readTemperature();
  Serial.print("Temp: ");
  Serial.println(temp);
  delay(500);
}
