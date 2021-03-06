/*
 * wiring-skeleton.cpp
 *
 *  Created on: 15.03.2017
 *      Author: niklausd
 */

#include <Arduino.h>
#include <Wire.h>

// PlatformIO libraries
#include <SerialCommand.h>  // pio lib install 173, lib details see https://github.com/kroimon/Arduino-SerialCommand
#include <Timer.h>          // pio lib install 1699, lib details see https://github.com/dniklaus/wiring-timer
#include <Adafruit_FRAM_I2C.h>

// private libraries
#include <ProductDebug.h>
#include <Assets.h>
#include <IPersistentDataMemory.h>


// local components (lib folder)
#include <Indicator.h>
#include <MyBuiltinLedIndicatorAdapter.h>
#include <MyPersDataMemory.h>


SerialCommand*    sCmd = 0;

// indicator implementation for built in LED
Indicator*        led  = 0;

// LoRaWan Assets
Assets*           assets = 0;

void setup()
{
  delay(5000);

  // setup basic debug environment (heap usage printer, trace ports & dbg cli)
  setupProdDebugEnv();

  // indicator LED
  led = new Indicator("led", "Built in LED.");
  led->assignAdapter(new MyBuiltinLedIndicatorAdapter());

  assets = new Assets(0, new MyPersDataMemory());
}

void loop()
{
  if (0 != sCmd)
  {
    sCmd->readSerial();     // process serial commands
  }
  scheduleTimers();         // process Timers
}
