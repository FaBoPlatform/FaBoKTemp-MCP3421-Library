/**
 * @file  fabo-mcp3421.h
 * @brief fabo libtary of mcp3421
 * @author Akira Sasaki
 * @date 2,10, 2016
 */
#include "Arduino.h"
#include "Wire.h"

/** SLAVE_ADDRESS (MCP3421:0x68-0x6f) */
#define MCP3421_SLAVE_ADDRESS (0x69)

/** CONFIG Redy Flg ON */
#define MCP3421_CONFIG_RDY_ON 0b10000000
/** CONFIG Redy Flg OFF */
#define MCP3421_CONFIG_RDY_OFF 0b00000000
/** CONFIG Conversion Continuous */
#define MCP3421_CONFIG_CONV_CONTINUOUS 0b00010000
/** CONFIG Conversion One_shot */
#define MCP3421_CONFIG_CONV_ONE_SHOT 0b00000000
/** CONFIG Data Rate 240SPS 12bit */
#define MCP3421_CONFIG_RATE_240SPS 0b0000
/** CONFIG Data Rate 60SPS 14bit */
#define MCP3421_CONFIG_RATE_60SPS 0b0100
/** CONFIG Data Rate 15SPS 16bit */
#define MCP3421_CONFIG_RATE_15SPS 0b1000
/** CONFIG Data Rate 3.75SPS 18bit */
#define MCP3421_CONFIG_RATE_3_75SPS 0b1100
/** CONFIG Gain x1 */
#define MCP3421_CONFIG_GAIN_X1 0b00
/** CONFIG Gain x2 */
#define MCP3421_CONFIG_GAIN_X2 0b01
/** CONFIG Gain x4 */
#define MCP3421_CONFIG_GAIN_X4 0b10
/** CONFIG Gain x8 */
#define MCP3421_CONFIG_GAIN_X8 0b11

/**
 * @class FaBoKTemp
 * @brief MCP3421 Control
 */
class FaBoKTemp
{
public:
  void configuration(void);
  double readTemperature();
private:
  void writeI2c(byte value);
  void readI2c(int num, byte *buf);
};
