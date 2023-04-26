//Senser Time
#include <ThreeWire.h>  
#include <RtcDS1302.h>
ThreeWire myWire(D4,D5,D2); // DAT/IO, CLK/SCLK, RST/CE
RtcDS1302<ThreeWire> Rtc(myWire);

//Senser Temp
#include "DHT.h"
#define DHTPIN D1 //PIN D1
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

void setup () 
{
    Serial.begin(115200);
    Setup_SenserTemp();
    Setup_SenserTime ();
}

void loop () 
{
    Output();
}
