#include <LiquidCrystal.h>
#include <EduIntro.h>

int C;
float F;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
byte degree[8] = {0b11100, 0b10100, 0b11100, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000}; // degree symbol

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT11 dht11(D7);

void setup()
{
    lcd.begin(16, 2);
}

void loop()
{
    dht11.update();

    C = dht11.readCelsius();
    F = dht11.readFahrenheit();

    lcd.createChar(0, degree);
    lcd.setCursor(0, 0);
    lcd.write(byte(0));
    lcd.setCursor(1, 0);
    lcd.print("C");
    lcd.setCursor(3, 0);
    lcd.print("Temperature");
    lcd.setCursor(13, 0);
    lcd.createChar(0, degree);
    lcd.setCursor(14, 0);
    lcd.write(byte(0));
    lcd.print("F");
    lcd.setCursor(0, 1);
    lcd.print(C);
    lcd.setCursor(14, 1);
    lcd.print(F);
    lcd.print(C);
    delay(1000);
}