/**
 * @file  fabo-mcp3421.cpp
 * @brief fabo libtary of mcp3421
 * @author Akira Sasaki
 * @date 2,10, 2016
 */
#include "fabo-mcp3421.h"

/**
 * @brief Set Config
 */
void FaBoKTemp::configuration()
{
 byte conf = MCP3421_CONFIG_RDY_ON;
 conf |= MCP3421_CONFIG_CONV_CONTINUOUS;
 conf |= MCP3421_CONFIG_RATE_3_75SPS;
 conf |= MCP3421_CONFIG_GAIN_X8;

 writeI2c(conf);
}

/**
 * @brief Read MCP3421
 * @return double : Temprature Data
 */
double FaBoKTemp::readTemperature()
{
  int32_t data;
  double temp;
  uint16_t mvuv = 1 << (3+2*3);
  int cp = 407;
  byte sign = 0x00;
  byte buffer[4];
  readI2c(4, buffer);

  sign = buffer[0] & 0x80 ? 0xff : 0;
  data = (sign << 24) + (buffer[0] << 16) + (buffer[1] << 8) + buffer[2];
  temp = (((double)data * 1000 )/mvuv + cp) / 40.7;

  return temp;
}

/**
 * @brief Write I2C Data
 * @param [in] value  : Write Data
 */
void FaBoKTemp::writeI2c(byte value) {
  Wire.begin();
  Wire.beginTransmission(MCP3421_SLAVE_ADDRESS);
  Wire.write(value);
  Wire.endTransmission();
}

/**
 * @brief Read I2C Data
 * @param [in] num   : Data Length
 * @param [out] *buf : Read Data
 */
void FaBoKTemp::readI2c(int num, byte buffer[]) {
  Wire.begin();
  Wire.beginTransmission(MCP3421_SLAVE_ADDRESS);
  Wire.endTransmission();

  Wire.beginTransmission(MCP3421_SLAVE_ADDRESS);
  Wire.requestFrom(MCP3421_SLAVE_ADDRESS, num);

  int i = 0;
  while(Wire.available())
  {
    buffer[i] = Wire.read();
    i++;
  }
  Wire.endTransmission();
}
