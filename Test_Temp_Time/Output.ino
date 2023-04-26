void Output() {

//Senser Time
RtcDateTime now = Rtc.GetDateTime();
printDateTime(now);

//Senser Temp  
   float h = dht.readHumidity();
   float t = dht.readTemperature();
   float f = dht.readTemperature(true);
if (isnan(h) || isnan(t) || isnan(f)) {
Serial.println(" Failed to read from DHT sensor! ");  
return;
}
Serial.print(" Temperature: ");
Serial.print(t);
Serial.print(" *C ");
Serial.println();

if (!now.IsValid()){
     Serial.println("Date & Time wrong!!!");
}
    delay(1000); // 1 seconds
}

//Senser Time
#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt)
{
char datestring[20];
snprintf_P(datestring, 
  countof(datestring),
  PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Day(),            
            dt.Month(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
Serial.print(datestring);
}
