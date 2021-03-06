/**
 @file FaBoKTemp_MCP3421.cpp
 @brief This is a library for the FaBo KTemp I2C Brick.

   http://fabo.io/209.html

   Released under APACHE LICENSE, VERSION 2.0

   http://www.apache.org/licenses/

 @author FaBo<info@fabo.io>
*/

#include "FaBoKTemp_MCP3421.h"

/**
 @brief Constructor
*/
FaBoKTemp::FaBoKTemp(uint8_t addr) {
  _i2caddr = addr;
  Wire.begin();
}

/**
 @brief Configure Device
 @param [in] config Configure Parameter
*/
void FaBoKTemp::configuration() {
 byte conf = MCP3421_CONFIG_RDY_ON;
 conf |= MCP3421_CONFIG_CONV_CONTINUOUS;
 conf |= MCP3421_CONFIG_RATE_3_75SPS;
 conf |= MCP3421_CONFIG_GAIN_X8;

 writeI2c(conf);
}

/**
 @brief Read Temperature Data
 @param [out] value Temperature Data
*/
double FaBoKTemp::readTemperature(int16_t cp)
{
  int32_t data;
  double temp;
  uint16_t mvuv = 1 << (3+2*3);
  byte sign = 0x00;
  byte buffer[4];
  readI2c(4, buffer);

  sign = buffer[0] & 0x80 ? 0xff : 0;
  data = (sign << 24) + (buffer[0] << 16) + (buffer[1] << 8) + buffer[2];
  temp = (((double)data * 1000 )/mvuv + cp) / 40.7;

  return temp;
}

/**
 @brief Write I2C
 @param [in] value write data
*/
void FaBoKTemp::writeI2c(uint8_t value) {
  Wire.beginTransmission(_i2caddr);
  Wire.write(value);
  Wire.endTransmission();
}

/**
 @brief Read I2C
 @param [in] num read length
 @param [out] buffer read data
*/
void FaBoKTemp::readI2c(uint8_t num, uint8_t *buffer) {
  Wire.beginTransmission(_i2caddr);
  Wire.endTransmission();

  Wire.requestFrom(_i2caddr, num);

  uint8_t i = 0;
  while(Wire.available())
  {
    buffer[i] = Wire.read();
    i++;
  }
}
