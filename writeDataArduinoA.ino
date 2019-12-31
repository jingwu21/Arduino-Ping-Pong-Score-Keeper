int sensorPin = A0;
void setup() {
  pinMode(7, INPUT);
  Serial.begin(9600);
}

void loop() {
 
  
  unsigned int sensorValue = analogRead(sensorPin);
  
  Serial.println(sensorValue);
  delay(500);
}