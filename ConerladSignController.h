#define ACTIVE HIGH

const int sdCardPin = 4;
const int audioOutPin = 9;

const int redLightPin = 2;
const int whiteLightPin = 3;

//Remote Chip Pins:
//D0 D
//D1 C
//D2 B
//D3 A
const int aRfButtonPin = 7;
const int bRfButtonPin = 6;
const int cRfButtonPin = 5;
const int dRfButtonPin = 10;

const int blinkRate = 1000;

enum LightColor
{
	Red = redLightPin,
	White = whiteLightPin
};

enum SignState
{
	Idle,
	BlinkRed
};

enum RemoteState
{
	A, B, C, D
};