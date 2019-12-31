#include <Wire.h>

double measureSoundLevel() {
  
   double x = analogRead(0);
   return x/100;
   
}

void setup() {
  Serial.begin(9600);
  Wire.begin(8);                
  Wire.onRequest(requestEvent); 
}

void loop() {
  delay(100);
}

void requestEvent() {
   char arr[10];

   
   double x = measureSoundLevel();
   
   Serial.print(x);
   dtostrf(x, 4, 2, arr);
   
   Wire.write(arr);
}