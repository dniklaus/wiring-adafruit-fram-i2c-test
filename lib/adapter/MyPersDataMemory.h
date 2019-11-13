/*
 * MyPersDataMemory.h
 *
 *  Created on: 08.11.2019
 *      Author: nid
 */

#ifndef LIB_ADAPTER_MYPERSDATAMEMORY_H_
#define LIB_ADAPTER_MYPERSDATAMEMORY_H_

#include <IPersistentDataMemory.h>

class Adafruit_FRAM_I2C;

class MyPersDataMemory: public IPersistentDataMemory
{
public:
  MyPersDataMemory();
  virtual ~MyPersDataMemory();

  void write(unsigned int address, unsigned char data);
  unsigned char read(unsigned int address);

private:
  Adafruit_FRAM_I2C* m_fram;

private:
  MyPersDataMemory(const MyPersDataMemory &other) = delete;
  MyPersDataMemory(MyPersDataMemory &&other) = delete;
};

#endif /* LIB_ADAPTER_MYPERSDATAMEMORY_H_ */
