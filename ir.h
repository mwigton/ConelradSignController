#ifndef _IR_h
	#define _IR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

namespace IR
{
	namespace Codes
	{
		const unsigned long channel = 0xFF629D;
		const unsigned long channelPlus = 0xFFE21D;
		const unsigned long channelMinus = 0xFFA25D;
		const unsigned long prev = 0xFF22DD;
		const unsigned long play = 0xFFC23D;
		const unsigned long next = 0xFF02FD;
		const unsigned long minus = 0xFFE01F;
		const unsigned long plus = 0xFFA857;
		const unsigned long EQ = 0xFF906F;
		const unsigned long zero = 0xFF6897;
		const unsigned long oneHundred = 0xFF9867;
		const unsigned long twoHundred = 0xFFB04F;
		const unsigned long one = 0xFF30CF;
		const unsigned long two = 0xFF18E7;
		const unsigned long three = 0xFF7A85;
		const unsigned long four = 0xFF10EF;
		const unsigned long five = 0xFF38C7;
		const unsigned long six = 0xFF5AA5;
		const unsigned long seven = 0xFF42BD;
		const unsigned long eight = 0xFF4AB5;
		const unsigned long nine = 0xFF52AD;
		
		const unsigned long repeat = 0xFFFFFFFF;

		char *CodeName(const unsigned long code);
	}

}


#endif

