#include "fabo-mcp3421.h"

bool mcp3421::searchDevice()
{
    
  byte device[5];
  readI2c(0x00, 5, device);
 
  if((device[1] & 0xf0) == MCP3421_DEVICE){
      return true;
  } else{
      return false;
  }
  
}

void mcp3421::configuration()
{
   byte conf = MCP3421_CONFIG_RDY_ON;
   conf |= MCP3421_CONFIG_CONV_CONTINUOUS;
   conf |= MCP3421_CONFIG_RATE_240SPS;
   conf |= MCP3421_CONFIG_GAIN_X8;
   
   writeI2c(MCP3421_CONFIG_REG, conf);
}

double mcp3421::readTemperature()
{
  double data;
  double temp;
  int mvuv = 1 << (3+2*3);
  int cp = 407; 

  byte buffer[5];
  readI2c(0x00, 5, buffer);
 
  
  data = (buffer[2] << 16) + (buffer[3] << 8) + buffer[4];
  

   temp = (data *1000/mvuv + cp) / 40.7;
  
    return temp;
  
}

// I2Cへの書き込み
void mcp3421::writeI2c(byte register_addr, byte value) {
  Wire.begin();       // I2Cの開始
  Wire.beginTransmission(MCP3421_SLAVE_ADDRESS);  
  Wire.write(register_addr);         
  Wire.write(value);                 
  Wire.endTransmission();        
}

// I2Cへの読み込み
void mcp3421::readI2c(byte register_addr, int num, byte buffer[]) {
  Wire.begin();       // I2Cの開始
  Wire.beginTransmission(MCP3421_SLAVE_ADDRESS); 
  Wire.write(register_addr);           
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

mcp3421 faboKTemp;
