/*******************************************************************************
  Copyright 2016 ROBOTIS CO., LTD.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*******************************************************************************/
#include <Adafruit_NeoPixel.h>
#include <Dynamixel2Arduino.h>

// Please modify it to suit your hardware.
#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560)  // When using DynamixelShield
#include <SoftwareSerial.h>
SoftwareSerial soft_serial(7, 8);  // DYNAMIXELShield UART RX/TX
#define DXL_SERIAL Serial
#define DEBUG_SERIAL soft_serial
const int DXL_DIR_PIN = 2;      // DYNAMIXEL Shield DIR PIN
#elif defined(ARDUINO_SAM_DUE)  // When using DynamixelShield
#define DXL_SERIAL Serial
#define DEBUG_SERIAL SerialUSB
const int DXL_DIR_PIN = 2;  // DYNAMIXEL Shield DIR PIN
#elif defined(ARDUINO_SAM_ZERO)  // When using DynamixelShield
#define DXL_SERIAL Serial1
#define DEBUG_SERIAL SerialUSB
const int DXL_DIR_PIN = 2;  // DYNAMIXEL Shield DIR PIN
#elif defined(ARDUINO_OpenCM904)  // When using official ROBOTIS board with DXL circuit.
#define DXL_SERIAL Serial3        //OpenCM9.04 EXP Board's DXL port Serial. (Serial1 for the DXL port on the OpenCM 9.04 board)
#define DEBUG_SERIAL Serial
const int DXL_DIR_PIN = 22;  //OpenCM9.04 EXP Board's DIR PIN. (28 for the DXL port on the OpenCM 9.04 board)
#elif defined(ARDUINO_OpenCR)  // When using official ROBOTIS board with DXL circuit.
// For OpenCR, there is a DXL Power Enable pin, so you must initialize and control it.
// Reference link : https://github.com/ROBOTIS-GIT/OpenCR/blob/master/arduino/opencr_arduino/opencr/libraries/DynamixelSDK/src/dynamixel_sdk/port_handler_arduino.cpp#L78
#define DXL_SERIAL Serial3
#define DEBUG_SERIAL Serial
const int DXL_DIR_PIN = 84;  // OpenCR Board's DIR PIN.
#elif defined(ARDUINO_OpenRB)  // When using OpenRB-150
//OpenRB does not require the DIR control pin.
#define DXL_SERIAL Serial1
#define DEBUG_SERIAL Serial
const int DXL_DIR_PIN = -1;
#else  // Other boards when using DynamixelShield
#define DXL_SERIAL Serial1
#define DEBUG_SERIAL Serial
const int DXL_DIR_PIN = 2;  // DYNAMIXEL Shield DIR PIN
#endif

#define LED_PIN 4
#define NUM_LEDS 11

#define BOT_LED_PIN 3
#define BOT_NUM_LEDS 11

const uint8_t DXLA_ID = 1;
const uint8_t DXLB_ID = 2;
const byte SW = 2;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 100;;

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip_bot(BOT_NUM_LEDS, BOT_LED_PIN, NEO_GRBW + NEO_KHZ800);

const float DXL_PROTOCOL_VERSION = 2.0;

Dynamixel2Arduino dxl(DXL_SERIAL, DXL_DIR_PIN);

//This namespace is required to use Control table item names
using namespace ControlTableItem;

void setup() {
  // put your setup code here, to run once:

  // Use UART port of DYNAMIXEL Shield to debug.
  DEBUG_SERIAL.begin(115200);
  //while (!DEBUG_SERIAL);

  // Set Port baudrate to 57600bps. This has to match with DYNAMIXEL baudrate.
  dxl.begin(57600);

  strip.begin();
  strip.show();
  strip_bot.begin();
  strip_bot.show();

  strip.setBrightness(100);
  strip_bot.setBrightness(100);

  // Set Port Protocol Version. This has to match with DYNAMIXEL protocol version.
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);

  // Get DYNAMIXEL information
  dxl.ping(DXLA_ID);
  DEBUG_SERIAL.print("IDA : ");
  DEBUG_SERIAL.print(DXLA_ID);
  DEBUG_SERIAL.print(", Model Number: ");
  DEBUG_SERIAL.println(dxl.getModelNumber(DXLA_ID));

  dxl.ping(DXLB_ID);
  DEBUG_SERIAL.print("IDB : ");
  DEBUG_SERIAL.print(DXLB_ID);
  DEBUG_SERIAL.print(", Model Number: ");
  DEBUG_SERIAL.println(dxl.getModelNumber(DXLB_ID));

  // Turn off torque when configuring items in EEPROM area
  dxl.torqueOff(DXLA_ID);
  dxl.torqueOff(DXLB_ID);
  dxl.setOperatingMode(DXLA_ID, OP_POSITION);
  dxl.setOperatingMode(DXLB_ID, OP_POSITION);
  dxl.torqueOn(DXLA_ID);
  dxl.torqueOn(DXLB_ID);

  // Limit the maximum velocity in Position Control Mode. Use 0 for Max speed
  dxl.writeControlTableItem(PROFILE_VELOCITY, DXLA_ID, 40);
  dxl.writeControlTableItem(PROFILE_ACCELERATION, DXLA_ID, 3);
  dxl.writeControlTableItem(PROFILE_VELOCITY, DXLB_ID, 40);
  dxl.writeControlTableItem(PROFILE_ACCELERATION, DXLB_ID, 3);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Please refer to e-Manual(http://emanual.robotis.com/docs/en/parts/interface/dynamixel_shield/) for available range of value.
  // Set Goal Position in RAW value

  setAll(0,165,255,50);
  setAll_bot(0,165,255,50);

  dxl.setGoalPosition(DXLA_ID, 180, UNIT_DEGREE);
  delay(3000);
  dxl.setGoalPosition(DXLA_ID, 50, UNIT_DEGREE);
  delay(3000);

  dxl.setGoalPosition(DXLB_ID, 180, UNIT_DEGREE);
  delay(3000);
  dxl.setGoalPosition(DXLB_ID, 220, UNIT_DEGREE);   // Max :Positiion
  delay(3000);
  dxl.setGoalPosition(DXLB_ID, 180, UNIT_DEGREE);
  delay(3000);
  dxl.setGoalPosition(DXLB_ID, 130, UNIT_DEGREE);   // Max Position
  delay(3000);


  //dxl.setGoalPosition(DXLB_ID, 180,UNIT_DEGREE);
  //delay(4000);
}
