/*
 * ProductDebug.cpp
 *
 *  Created on: 14.06.2016
 *      Author: nid
 */

#include <Arduino.h>
#include <AppDebug.h>
#include "ProductDebug.h"

void setupProdDebugEnv()
{
  setupDebugEnv();

  Serial.println();
  Serial.println("---------------------------------------------");
  Serial.println("Hello from Adafruit FRAM (I2C) test app!");
  Serial.println("---------------------------------------------");
  Serial.println();
}
