

/*
Connections
===========
OLED -> NodeMCU
---------------
VCC -> 3.3V
GND -> GND
SCL -> D1
SDA -> D2

DHT11 -> NodeMCU
---------------
VCC -> 3.3V
GND -> GND
DATA -> D3
===========
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define DHTPIN 0

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHT dht(DHTPIN, DHT11);

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println("SSD1306 allocation failed");
    for(;;);
  }
  delay(1000);
  
  display.clearDisplay();
  display.setTextSize(1);             
  display.setTextColor(WHITE);        
  display.setCursor(0,20);
  display.setTextSize(2);              
  display.println("Welcome To");
  display.setCursor(30,50);
  display.println("Tempu");
  display.display();
  delay(5000); 
}
void loop() {
  float temp = dht.readTemperature();
  float humid = dht.readHumidity();

  if (!isnan(temp) && !isnan(humid)) {
    display.clearDisplay();
    display.setTextSize(1);             
    display.setTextColor(WHITE);        
    display.setCursor(30,20);
    display.setTextSize(2);              
    display.println("Tempu");
    display.setTextSize(1); 
    display.print("Temperature: ");
    display.println(temp);
    display.print("Humidity: ");
    display.println(humid);
    display.display();
  }
  delay(5000);
  
  
}
