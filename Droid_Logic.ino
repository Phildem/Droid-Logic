/*
Droid Logic display Cyrob 2021

=====================================================================================
==========================   OPEN SOURCE LICENCE   ==================================
=====================================================================================

Copyright 2021,2022,2023 Philippe Demerliac Cyrob.org

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING 
BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.

IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

................................................................................................................
Release history
................................................................................................................
Version Date      Author    Comment
1.0     14/15/21  Phildem   Tested OK
*/

/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     -1      // Reset pin # (or -1 if sharing Arduino reset pin) NOT USED!!!
#define SCREEN_ADDRESS 0x3C   //< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

#define kDiam       4         // Circle diameter in pixel

// Display global
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {

   pinMode(LED_BUILTIN, OUTPUT);  // Built in led is an indicator

  // Display Init
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    for(;;){                            // Init Error indicator
      digitalWrite(LED_BUILTIN, HIGH);
      delay(250);
      digitalWrite(LED_BUILTIN, LOW);
      delay(250);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(250);
      digitalWrite(LED_BUILTIN, LOW);
      delay(2000);
      }
    }
 
  // Test display
  display.display();          // Display Adafruit Splash for test
  delay(2000);                // Pause for 2 seconds
  display.clearDisplay();     // Clear the buffer

}

void loop() {
  delay(random(50,500));          // Change random betewwen 50 and 500ms

  display.clearDisplay();
    
  for(int X=kDiam/2;X<SCREEN_WIDTH;X+=kDiam+2)
    for(int Y=kDiam/2;Y<SCREEN_HEIGHT;Y+=kDiam+2){
      if (random(0,4)==1)                             // 1 chance/3 to dispaly a circle
         //display.writeFillRect(X, Y, Wr, Wr, SSD1306_WHITE);
         display.fillCircle(X, Y, kDiam, SSD1306_WHITE);
         
    }

  digitalWrite(LED_BUILTIN, HIGH);        // Light internal led to indicate measure
  display.display();                      // refresh display
  digitalWrite(LED_BUILTIN, LOW); 
 }
