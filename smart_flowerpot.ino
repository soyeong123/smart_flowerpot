#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int Relaypin = 8;
int buzzer=9;

void setup()
{
  Serial.begin(9600);
  lcd.init();

  lcd.backlight();
  pinMode(Relaypin,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(9,OUTPUT);

}
void loop()
{
  Serial.println(analogRead(A1));
  /*토양습도 계산하기*/
  int humidity = map(analogRead(A1),250,1023,100,0);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity:");
  lcd.setCursor(0,1);
  lcd.print(humidity);
  lcd.print("%");
  /*Buzzer*/
  int x = analogRead (A0);
   if (x < 500)
  {     
   tone(9,1000,100);
  }  
  else  
  {    
    digitalWrite (buzzer, LOW);
  }  
  delay (1000);
/*water pump*/
  if (humidity < 40) {
  digitalWrite(Relaypin, LOW);}
  else{
  digitalWrite(Relaypin, HIGH);}
}
