#include <TMRpcm.h>
#include <pcmRF.h>
#include <SD.h>

#include <pcmConfig.h>
#include "ir.h"
#include <IRremoteInt.h>
#include <IRremote.h>

const int irReceiverPin = 11;
const int sdCardPin = 4;
const int audioOutPin = 9;

IRrecv irReceiver(irReceiverPin);
decode_results irResults;

TMRpcm audioPlayer;

void setup()
{
	Serial.begin(9600);
	SetupIR();
	SetupAudioPlayer();
}

void loop()
{
	IrLoop();
}

void SetupAudioPlayer()
{
	audioPlayer.speakerPin = audioOutPin;
	if (!SD.begin(sdCardPin))
	{
		Serial.println("SD card failure");
		return;
	}

	audioPlayer.setVolume(6);
}

void SetupIR()
{
	irReceiver.enableIRIn(); // Start the receiver
}

void IrLoop()
{

	if (irReceiver.decode(&irResults))
	{
		#ifdef DEBUG
		Serial.println(IR::Codes::CodeName(irResults.value));
		Serial.println(irResults.value, HEX);
		#endif

		switch (irResults.value)
		{
			using namespace IR::Codes;

			case one:
				audioPlayer.play("test.wav");
				break;
		}

		irReceiver.resume(); // Receive the next value
	}
}