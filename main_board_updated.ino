#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "gSTi5LZ0To-q1aML2OCJU_DNllDNlk-K"; //You will get this Auth Token in Gmail if you signin Blynk app with your Gmail ID

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "--------"; //Enter your WIFI Name
char pass[] = "--------";//Enter your WIFI Password

int ldr=A0;
int pir=13;//D7
void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(ldr,INPUT);
  pinMode(pir,INPUT);
  pinMode(D2,OUTPUT);
  
  Blynk.begin(auth, ssid, pass);
}
void loop()
{
  int ldrdata=analogRead(ldr);
  if(ldrdata==HIGH)
  {
   digitalWrite(D2,HIGH);
   }
   long pirdata=digitalRead(pir);
   if(pirdata==HIGH)
   {
    digitalWrite(D2,HIGH);
    }

  Blynk.run();
}
