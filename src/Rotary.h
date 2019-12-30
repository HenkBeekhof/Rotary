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

#ifndef Rotary_h
#define Rotary_h

class Rotary {
	public:
		Rotary(uint8_t EN1_Pin, uint8_t EN2_Pin, bool swap = false);
		void Rotary::Reset();
		int Rotary::Read();
		bool Rotary::Changed();
		
	private:
		uint8_t EN1, EN2;
		uint8_t A_Previous, A_Current;
		uint8_t B_Previous, B_Current;
		int  rotary_Value;
		bool rotary_Changed;
};
#endif