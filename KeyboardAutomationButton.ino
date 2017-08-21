/*
  Keyboard automation button

  This project provides Digispark button to automate keyboard based tasks.

  Two example tasks are provided but other keyboard tasks can easily be added. 

  created   Aug 2017
  by CheapskateProjects

  ---------------------------
  The MIT License (MIT)

  Copyright (c) 2017 CheapskateProjects

  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
#include "DigiKeyboard.h"

void setup() {
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);

  digitalWrite(1, LOW);
  digitalWrite(2, HIGH);

  // Makes OS identify this device as keyboard
  DigiKeyboard.sendKeyStroke(0);
}

void loop()
{
  if(digitalRead(0) == HIGH)
  {
    generatePassword();    
  }
}

// Example to use Digispark as physical password token
void insertPassword()
{
  DigiKeyboard.println("SuperSecretPassword");
}

// Example to open terminal and call script to generate new password
void generatePassword()
{
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_T, MOD_CONTROL_LEFT | MOD_ALT_LEFT);
  delay(500);
  DigiKeyboard.println("randpass");
  delay(500);
  DigiKeyboard.println("exit");
}


