#include "Arduino.h"
#include "Wire.h"

#define MCP3421_SLAVE_ADDRESS (0x69)

#define MCP3421_CONFIG_REG 0x00
#define MCP3421_DEVICE_REG 0x00

#define MCP3421_CONFIG_RDY_ON 0b10000000
#define MCP3421_CONFIG_RDY_OFF 0b00000000
#define MCP3421_CONFIG_CONV_CONTINUOUS 0b00010000
#define MCP3421_CONFIG_CONV_ONE_SHOT 0b00000000
#define MCP3421_CONFIG_RATE_240SPS 0b00
#define MCP3421_CONFIG_RATE_60SPS 0b01
#define MCP3421_CONFIG_RATE_15SPS 0b10
#define MCP3421_CONFIG_RATE_3_75SPS 0b11
#define MCP3421_CONFIG_GAIN_X1 0b00
#define MCP3421_CONFIG_GAIN_X2 0b01
#define MCP3421_CONFIG_GAIN_X4 0b10
#define MCP3421_CONFIG_GAIN_X8 0b11

#define MCP3421_DEVICE 0xD0

class mcp3421
{
public:
  bool searchDevice(void);
  void configuration(void);
  void powerOn(void);
  void readXYZ(int *x, int *y, int *z);
  double readTemperature();
  void enableTap();
  bool isDoubleTap(byte value);
  bool isSingleTap(byte value);
private:
  void readI2c(byte register_addr, int num, byte *buf);
  void writeI2c(byte register_addr, byte value);
};

extern mcp3421 faboKTemp;
