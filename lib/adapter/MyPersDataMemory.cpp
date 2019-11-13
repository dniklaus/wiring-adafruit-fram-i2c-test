/*
 * MyPersDataMemory.cpp
 *
 *  Created on: 08.11.2019
 *      Author: nid
 */

#include <Adafruit_FRAM_I2C.h>
#include <MyPersDataMemory.h>

MyPersDataMemory::MyPersDataMemory()
: m_fram(new Adafruit_FRAM_I2C())
{
  if (m_fram->begin())
  {  // you can stick the new i2c addr in here, e.g. begin(0x51);
    Serial.println("Found I2C FRAM");
  }
  else
  {
    Serial.println("I2C FRAM not identified ... check your connections?\r\n");
    Serial.println("Will continue in case this processor doesn't support repeated start\r\n");
  }
}

MyPersDataMemory::~MyPersDataMemory()
{
  delete m_fram;
  m_fram = 0;
}

void MyPersDataMemory::write(unsigned int address, unsigned char data)
{
  m_fram->write8(address, data);
}

unsigned char MyPersDataMemory::read(unsigned int address)
{
  unsigned int readValue = m_fram->read8(address);
  return readValue;
}
