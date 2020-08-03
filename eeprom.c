#include <xc.h>
#include "eeprom.h"


uint8_t EEPROM_Read(uint8_t Wordadd)
{
  uint8_t Data;
  I2C_Master_Start();                          // Send Start bit
  while(I2C_Master_Write(EEPROM_ADDRESS_W))    // Wait Until EEPROM Is IDLE
    I2C_Master_RepeatedStart();
  I2C_Master_Write(Wordadd);                   // Send Word address
  I2C_Master_Start();                          // Send a start to start a read communication 
  I2C_Master_Write(EEPROM_ADDRESS_R);
  Data = I2C_Read_Byte();                      // Read Received byte
  I2C_NACK();                                  // Send a NACK bit
  I2C_Master_Stop();                           // Stop communication
  return Data;
}

void EEPROM_Write(uint8_t Data,uint8_t Wordadd)
{
  I2C_Master_Start();                           // Send Start bit
  while(I2C_Master_Write(EEPROM_ADDRESS_W))     // Wait Until EEPROM Is IDLE
    I2C_Master_RepeatedStart();
  I2C_Master_Write(Wordadd);                    // Send Word address
  I2C_Master_Write(Data);                       // Send the Data
  I2C_Master_Stop();                            // Stop the communication
}

