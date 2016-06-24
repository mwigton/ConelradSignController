#include "ir.h"
#include <IRremoteInt.h>
#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
	Serial.begin(9600);
	irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
	IrLoop();
}

void IrLoop()
{

	if (irrecv.decode(&results))
	{
		#ifdef DEBUG
		Serial.println(IR::Codes::CodeName(results.value));
		Serial.println(results.value, HEX);
		#endif

		irrecv.resume(); // Receive the next value
	}
}