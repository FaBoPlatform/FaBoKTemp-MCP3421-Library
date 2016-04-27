/**
 @file FaBoKTemp_MCP3421.h
 @brief This is a library for the FaBo KTemp I2C Brick.

   http://fabo.io/209.html

   Released under APACHE LICENSE, VERSION 2.0

   http://www.apache.org/licenses/

 @author FaBo<info@fabo.io>
*/

#ifndef FABOKTEMP_MCP3421_H
#define FABOKTEMP_MCP3421_H

#include <Arduino.h>
#include <Wire.h>

#define MCP3421_SLAVE_ADDRESS 0x69 ///< Default I2C Slave Address

/// @name Config Parameter
/// @{
#define MCP3421_CONFIG_RDY_ON 0b10000000
#define MCP3421_CONFIG_RDY_OFF 0b00000000
#define MCP3421_CONFIG_CONV_CONTINUOUS 0b00010000
#define MCP3421_CONFIG_CONV_ONE_SHOT 0b00000000
#define MCP3421_CONFIG_RATE_240SPS 0b0000
#define MCP3421_CONFIG_RATE_60SPS 0b0100
#define MCP3421_CONFIG_RATE_15SPS 0b1000
#define MCP3421_CONFIG_RATE_3_75SPS 0b1100
#define MCP3421_CONFIG_GAIN_X1 0b00
#define MCP3421_CONFIG_GAIN_X2 0b01
#define MCP3421_CONFIG_GAIN_X4 0b10
#define MCP3421_CONFIG_GAIN_X8 0b11
/// @}


/**
 @class FaBoKTemp
 @brief FaBo KTemp I2C Controll class
*/
class FaBoKTemp {
  public:
    FaBoKTemp(uint8_t addr = MCP3421_SLAVE_ADDRESS);
    void configuration(void);
    double readTemperature(int16_t cp = 500);
  private:
    uint8_t _i2caddr;
    void writeI2c(uint8_t value);
    void readI2c(uint8_t num, uint8_t *buffer);
};

#endif // FABOKTEMP_MCP3421_H
