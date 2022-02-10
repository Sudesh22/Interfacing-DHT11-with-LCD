# Interfacing-DHT11-with-LCD
This project is developed by using LCD disply and DHT 11 temperature sensor. The readings from the DHT 11 are taken by the Arduino and then are displayed onto the LCD Display.

## Understanding the Code
Just as we start every program, we start by initializing the libraries used.
```C++
#include <LiquidCrystal.h>
#include <EduIntro.h>
```

Then we initialize the variables required for the program. We initialize the variable for Celsius as an integer and the variable for Fahrenheit as a float. Then we declare all the constant integers required for the LCD Module. And then we initialize the degree symbol as an array of eight bytes, one for each row.
```C++
int C;
float F;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
byte degree[8] = {0b11100, 0b10100, 0b11100, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000}; // degree symbol
```

Then we create a LiquidCrystal object `lcd` with all the pins we initialized in the previous step. We also create a DHT11 object `dht11` and assign it to pin `D7` of Arduino
```C++
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT11 dht11(D7);
```

In the `Setup` function, we initialize the LCD using `lcd.begin()` function by giving it 2 parameters that are columns and rows respectively.
```C++
void setup()
{
    lcd.begin(16, 2);
}
```

In the `Loop` function we start by updating the values from DHT 11 sensor. then we assign the values to the Celsius and Fahrenheit variables using the `readCelsius()` and `readFahrenheit()` functions respectively. Then we position all the values and the text on the LCD display using the `setCursor()` function and then  dislay the text using `print()` function.
```C++
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
```


## Snaps of Project
<p align=center>
  <img src="Resources/example.svg">
  <p align=center>Circuit in Action</p>
</p>