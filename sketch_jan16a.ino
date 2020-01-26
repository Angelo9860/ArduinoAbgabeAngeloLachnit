#include <LiquidCrystal.h>
#include <dht.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
dht DHT;

#define DHT11_PIN 3
int i = 0;
void setup() {
      // set up the LCD's number of columns and rows:
      lcd.begin(16, 2);
      Serial.begin(9600);
}

void loop() {
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Tempe:");
  if(DHT.temperature > 0){
  lcd.print(DHT.temperature);  
  lcd.print((char)223);
  lcd.print("C");
  }

  
  
  lcd.setCursor(0,1);
  lcd.print("Humi:");
  if(DHT.humidity > 0){
  lcd.print(DHT.humidity);  
    lcd.print("%");
  }
  

    Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(500);
      
}
