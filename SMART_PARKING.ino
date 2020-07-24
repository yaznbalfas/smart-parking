#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "lDvRzQzBU7Z6OPLogUP-_3ozqSNdNAQ6";   //token dari akun blynk
char ssid[] = "Apaajalah";     //ssid wifi yang terhubung
char pswd[] = "nennymulyani";            // password wifi yang terhubung

WidgetLED led1(V1);            // Virtual LED untuk menampilkan status di aplikasi
int sensor1 = D4;                   //IR sensor

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pswd);
  pinMode(sensor1, INPUT);
  while (Blynk.connect() == false) {
  Serial.println("tidak terkoeksi");
  }
}
void loop()
{
  int sensorval1 = digitalRead(sensor1);
  delay(1000);
if (sensorval1 == 1)
  {
led1.on();
  }
if (sensorval1 == 0)
  {
led1.off();
  }
  Blynk.run();
}
