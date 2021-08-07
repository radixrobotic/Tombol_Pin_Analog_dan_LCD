#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int KeyA, Max, Output;
char KarKey;
bool Trig;
int Sama;
#define Key A0

void setup()
{
  Serial.begin(9600);
  pinMode(Key,INPUT);
  
  lcd.init();                      // initialize the lcd 
  lcd.backlight(); //ON Backligh
  delay(2000);
  lcd.noBacklight();  //OFF BackLight
  lcd.setCursor(0,0);
  lcd.print("KEYPAD MATRIX");
  lcd.setCursor(0,1);
  lcd.print("KEYPAD = ");
  delay(2000);
  lcd.backlight(); //ON Backligh
}


void loop()
{
  KeyA=analogRead(Key);
  Sama=0;
  Trig = 0;
  BacaKeypad();
  if(Max>10)
  {
    KarakterKey();
    lcd.setCursor(9,1);
    lcd.print(KarKey);
    delay(500);
    Max=0;
    Output=0;
  }
}
