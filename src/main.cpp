#include <Arduino.h>
#include <SPI.h>

#define RST_PIN 4
#define DC_PIN 15
#define LED_PIN 21

void setup()
{

  Serial.begin(9600);

  // Set pin modes
  pinMode(RST_PIN, OUTPUT);
  pinMode(DC_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(RST_PIN, HIGH);
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(DC_PIN, HIGH);

  delay(1000);

  // Initializes the SPI bus by setting SCK, MOSI, and SS to outputs, pulling SCK and MOSI low, and SS high.
  Serial.println("Initialize SPI bus");
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);

  // Apply a RES pulse to reset all internal registers
  Serial.println("Reset the LCD");
  digitalWrite(RST_PIN, LOW);
  delay(50);
  digitalWrite(RST_PIN, HIGH);

  // Function set
  Serial.println("Send Function set instruction to LCD");
  digitalWrite(DC_PIN, LOW);
  // SPI.beginTransaction(SPISettings(20000000, MSBFIRST, SPI_MODE0));
  SPI.transfer(0b00100000);
  SPI.transfer(0b00001001);
  SPI.endTransaction();
}

void loop()
{
  // put your main code here, to run repeatedly:
}
