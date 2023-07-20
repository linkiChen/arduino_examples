/*
   Copyright 2022 Achim Pieters | StudioPieters®

   Permission is hereby granted, free of charge, to any person obtaining a copy
   of this software and associated documentation files (the "Software"), to deal
   in the Software without restriction, including without limitation the rights
   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
   copies of the Software, and to permit persons to whom the Software is
   furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in all
   copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
   CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

 /*
  * ESP32 C3 板载RGB LED颜色渐变
  */

#define REDPIN 3
#define GREENPIN 4
#define BLUEPIN 5
#define COLD_WHITE 18
#define WARM_WHITE 19


#define FADESPEED 20     // make this higher to slow down

void setup() {
        pinMode(REDPIN, OUTPUT);
        pinMode(GREENPIN, OUTPUT);
        pinMode(BLUEPIN, OUTPUT);
        pinMode(COLD_WHITE, OUTPUT);
        pinMode(WARM_WHITE, OUTPUT);
}


void loop() {
        int r, g, b, cw, ww;

        // fade from blue to violet
        // 从蓝色过度到紫色
        for (r = 0; r < 256; r++) {
                analogWrite(REDPIN, r);
                analogWrite(COLD_WHITE, 0);
                analogWrite(WARM_WHITE, 0);
                delay(FADESPEED);
        }
        // fade from violet to red
        // 从紫色过度到红色
        for (b = 255; b > 0; b--) {
                analogWrite(BLUEPIN, b);
                analogWrite(COLD_WHITE, 0);
                analogWrite(WARM_WHITE, 0);
                delay(FADESPEED);
        }
        // fade from red to yellow
        // 从红色过度到黄色
        for (g = 0; g < 256; g++) {
                analogWrite(GREENPIN, g);
                analogWrite(COLD_WHITE, 0);
                analogWrite(WARM_WHITE, 0);
                delay(FADESPEED);
        }
        // fade from yellow to green
        // 从黄色过度到绿色
        for (r = 255; r > 0; r--) {
                analogWrite(REDPIN, r);
                analogWrite(COLD_WHITE, 0);
                analogWrite(WARM_WHITE, 0);
                delay(FADESPEED);
        }
        // fade from green to teal
        // 从绿色过度到蓝绿色
        for (b = 0; b < 256; b++) {
                analogWrite(BLUEPIN, b);
                analogWrite(COLD_WHITE, 0);
                analogWrite(WARM_WHITE, 0);
                delay(FADESPEED);
        }
        // fade from teal to blue
        // 从蓝绿色过度到蓝色
        for (g = 255; g > 0; g--) {
                analogWrite(GREENPIN, g);
                analogWrite(COLD_WHITE, 0);
                analogWrite(WARM_WHITE, 0);
                delay(FADESPEED);
        }
        // fade from off to cold white
        for (cw = 0; cw < 256; cw++) {
//                analogWrite(REDPIN, 0);
//                analogWrite(GREENPIN, 0);
//                analogWrite(BLUEPIN, 0);
                analogWrite(COLD_WHITE, cw);
                analogWrite(WARM_WHITE, 0);
                delay(FADESPEED);
        }
        // fade from off to warm white
        for (ww = 0; ww < 256; ww++) {
//                analogWrite(REDPIN, 0);
//                analogWrite(GREENPIN, 0);
//                analogWrite(BLUEPIN, 0);
                analogWrite(WARM_WHITE, ww);
                analogWrite(COLD_WHITE, 0);
                delay(FADESPEED);
        }
}
