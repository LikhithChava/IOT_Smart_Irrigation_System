#include <Adafruit_Sensor.h>
#include "DHT.h"
#define DHTPIN 10    
#define DHTTYPE DHT22  
DHT dht(DHTPIN, DHTTYPE);

void setup() {
Serial.begin(9600);
pinMode(A1,INPUT);
pinMode(A0,INPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);

Serial.println("DHT11 test!");
dht.begin();

}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float a =  analogRead(A0);  
  float b =  analogRead(A1);

float moisture;
float rain;
moisture = (100 - ((a/1024.00) * 100));
rain = (100 - ((b/1024.00) * 100));

  Serial.print("Humidity: \t" );
  Serial.print(h);
  Serial.print(" %\n");
  Serial.print("Temperature: \t");
  Serial.print(t);
  Serial.print(" *C \n");
  delay(5000);
  Serial.print("Soil_Moisture :    ");
  Serial.print(moisture);
  Serial.println( "%");

  if(moisture <= 49 ||  rain <= 19){
  digitalWrite(12,HIGH);
  Serial.println("Motor is ON");
}
if(moisture >= 50 || rain >= 19){
  digitalWrite(12,LOW);
  Serial.println("Motor is off");
}

  delay(5000);

  Serial.print("rain :     ");
  Serial.print(rain);
  Serial.println("%");

if (rain >= 50){
  digitalWrite(11,HIGH);
  Serial.println("Buzzer is on");
}
if (rain <= 49){
  digitalWrite(11,LOW);
  Serial.println("Buzzer is off");
}



delay(5000); 

Serial.println("______________________");

}
