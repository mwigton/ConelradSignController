#include <TMRpcm.h>
#include <pcmRF.h>
#include <SD.h>

#include <pcmConfig.h>
#include "ConerladSignController.h"
#include <SPI.h>

TMRpcm audioPlayer;
SignState state = Idle;
RemoteState remoteState;
RemoteState lastRemoteState;

void setup()
{
	Serial.begin(9600);
	Serial.println("Init");
	SetupPins();
	SetupAudioPlayer();
	state = BlinkRed;
}

void SetupPins()
{
	pinMode(whiteLightPin, OUTPUT);
	pinMode(redLightPin, OUTPUT);
	
	pinMode(aRfButtonPin, INPUT_PULLUP);
	pinMode(bRfButtonPin, INPUT_PULLUP);
	pinMode(cRfButtonPin, INPUT_PULLUP);
	pinMode(dRfButtonPin, INPUT_PULLUP);
}

void loop()
{
	GetRemoteState();
	RemoteStateLoop();
	StateLoop();
}

void SetupAudioPlayer()
{
	audioPlayer.speakerPin = audioOutPin;
	if (!SD.begin(sdCardPin))
	{
		Serial.println("SD card failure");
		return;
	}

	audioPlayer.setVolume(5);
}

void GetRemoteState()
{
	if (digitalRead(aRfButtonPin) == ACTIVE)
	{
		remoteState = A;
		return;
	}

	if (digitalRead(bRfButtonPin) == ACTIVE)
	{
		remoteState = B;
		return;
	}

	if (digitalRead(cRfButtonPin) == ACTIVE)
	{
		remoteState = C;
		return;
	}

	if (digitalRead(dRfButtonPin) == ACTIVE)
	{
		remoteState = D;
		return;
	}
}

void RemoteStateLoop()
{
	if (remoteState == lastRemoteState) return;

	switch (remoteState)
	{
		case A:
			audioPlayer.stopPlayback();
			Serial.println("A Selected");
			TurnLightOff(Red);
			TurnLightOn(White);
			state = Idle;
		break;

		case B:
			Serial.println("B Selected");
			TurnLightOff(White);
			audioPlayer.play("test.wav");
			state = BlinkRed;
			break;

		case C:
			Serial.println("C Selected");
			break;

		case D:
			Serial.println("D Selected");
			break;
	}

	lastRemoteState = remoteState;
}

void StateLoop()
{
	switch (state)
	{
		case BlinkRed:
			BlinkLight(Red, blinkRate);
		return;
	}
}

void TurnLightOn(LightColor light)
{
	digitalWrite((int)light, HIGH);
}

void TurnLightOff(LightColor light)
{
	digitalWrite((int)light, LOW);
}

void BlinkLight(LightColor light, unsigned long rate)
{
	TurnLightOn(light);
	delay(rate);
	TurnLightOff(light);
	delay(rate);
}
