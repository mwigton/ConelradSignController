// 
// 
// 

#include "ir.h"

char *IR::Codes::CodeName(const unsigned long code)
{
	switch (code)
	{
		case channel:
			return "Channel";

		case channelPlus:
			return "Channel +";

		case channelMinus:
			return "Channel -";

		case prev:
			return "Prev";

		case play:
			return "Play";

		case next:
			return "Next";

		case minus:
			return "Minus";

		case plus:
			return "Plus";

		case EQ:
			return "EQ";

		case zero:
			return "0";

		case oneHundred:
			return "100";

		case twoHundred:
			return "200";

		case one:
			return "1";

		case two:
			return "2";

		case three:
			return "3";

		case four:
			return "4";

		case five:
			return "5";

		case six:
			return "6";

		case seven:
			return "7";

		case eight:
			return "8";

		case nine:
			return "9";

		case repeat:
			return "repeat";

		default:
			return "Unknown";
	}
}
