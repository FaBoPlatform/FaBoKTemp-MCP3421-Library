#include "fabo-mcp3421.h"
#include "Wire.h"

void setup() {
  Serial.begin(9600);
  Serial.println("Init...");
  
  faboKTemp.configuration();
  if(faboKTemp.searchDevice()){
    Serial.println("I am MCP3421");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  double temp = faboKTemp.readTemperature();
  Serial.print("Temp: ");
  Serial.println(temp);
}
