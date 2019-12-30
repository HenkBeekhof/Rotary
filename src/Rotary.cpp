/*
  Rotary.h - library for Arduino
  Copyright (c) 2019 Henk Beekhof.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include "Rotary.h"

// Constructor: Define the two pins, and optinally swap direction
Rotary::Rotary(uint8_t EN1_Pin, uint8_t EN2_Pin, bool swap = false) {
  EN1 = (!swap) ? EN1_Pin : EN2_Pin;
  EN2 = (!swap) ? EN2_Pin : EN1_Pin;

  // Set both pins as input pins, with internal pullup  
  pinMode(EN1, INPUT_PULLUP);
  pinMode(EN2, INPUT_PULLUP);

  // Define default values
  A_Previous = digitalRead(EN1);
  B_Previous = digitalRead(EN2);
  
  rotary_Value = 0;
  rotary_Changed = false;
}

// Reset the rotary value to zero
void Rotary::Reset() {
  rotary_Value = 0;
}

// Check if the rotary value has changed
bool Rotary::Changed() {
	bool current = rotary_Changed;
	rotary_Changed = false;
	return current;
}

// Read the rotary value
int Rotary::Read() {
  A_Current = digitalRead(EN1);
  B_Current = digitalRead(EN2);
  rotary_Changed = false;
  
  if (A_Current != A_Previous) {
	A_Previous = A_Current;
	rotary_Changed = true;
    if (A_Current != B_Current) {
      rotary_Value++;
    } else {
      rotary_Value--;
    }
  }
  if (B_Current != B_Previous) {
    B_Previous = B_Current;
	rotary_Changed = true;
    if (A_Current == B_Current) {
      rotary_Value++;
    } else {
      rotary_Value--;
    }
  }
  
  // Debouce: Add 50us delay between reads
  delayMicroseconds(50);
  return rotary_Value;  
}