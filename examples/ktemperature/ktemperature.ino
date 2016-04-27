/**
 @file ktemperature.ino
 @brief This is an Example for the FaBo KTemp I2C Brick.

   http://fabo.io/208.html

   Released under APACHE LICENSE, VERSION 2.0

   http://www.apache.org/licenses/

 @author FaBo<info@fabo.io>
*/

#include <Wire.h>
#include <FaBoKTemp_MCP3421.h>

FaBoKTemp faboKTemp;

void setup() {
  Serial.begin(9600);
  Serial.println("RESET");
  Serial.println();

  faboKTemp.configuration();
}

void loop() {
  double temp = faboKTemp.readTemperature();
  Serial.print("Temp: ");
  Serial.println(temp);
  delay(1000);
}
