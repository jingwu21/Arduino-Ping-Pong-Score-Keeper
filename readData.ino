#include <Wire.h>
#include <LiquidCrystal.h>




const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String temp = "";
String temp2 = "";
int playerScore1 = 0;
int playerScore2 = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(4, 0);
  lcd.print("A");
  lcd.setCursor(8, 0);
  lcd.print("|");
  lcd.setCursor(12, 0);
  lcd.print("B");
  Wire.begin();        // join i2c bus (address optional for master);
  Serial.begin(9600);  // start serial for output
}


void loop() {
  lcd.setCursor(0, 1);
  lcd.print("P1: ");
  lcd.setCursor(3, 1);

  Wire.requestFrom(7, 4);    // request 6 bytes from slave device #8
 
  

  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    
    temp += c;
    Serial.print(c);
   
  }
  lcd.print(temp);
 

  Wire.requestFrom(8, 4);
  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    //lcd.print(c);
    temp2 += c;
    Serial.print(c);         // debugging purposes
  }
  lcd.setCursor(8, 1);
  lcd.print("P2: ");
  lcd.setCursor(11, 1);
  lcd.print(temp2);
  lcd.print(" ");
  temp = "";
  temp2 = "";
  delay(500);
  
  

}