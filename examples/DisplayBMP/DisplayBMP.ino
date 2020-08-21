/*  
 *  Basic example to show how to read a BMP image from SPIFFS
 *  and display using Adafruit GFX
 *  
 *  Tested with esp32 devboard and 160x128 ST7735 display
 *  
 */

// Required libraries
#include <SPIFFS.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPIFFS_ImageReader.h>

// Display interface configuration
#define TFT_CS_PIN    GPIO_NUM_5
#define TFT_DC_PIN    GPIO_NUM_2
#define TFT_MOSI_PIN  GPIO_NUM_23
#define TFT_SCLK_PIN  GPIO_NUM_18
#define TFT_RST_PIN   GPIO_NUM_4
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS_PIN, TFT_DC_PIN, TFT_MOSI_PIN, TFT_SCLK_PIN, TFT_RST_PIN);

// Display backlight enable pin
#define TFT_BACKLIGHT_PIN GPIO_NUM_32

// Image reader
SPIFFS_ImageReader reader;


void setup() {

  Serial.begin(115200);

  // initialize SPIFFS
  if(!SPIFFS.begin()) {
    Serial.println("SPIFFS initialisation failed!");
    while (1);
  }

  // initialize display and turn on backlight
  tft.initR(INITR_BLACKTAB);
  delay(500);
  pinMode(TFT_BACKLIGHT_PIN, OUTPUT);
  digitalWrite(TFT_BACKLIGHT_PIN, HIGH);

  // draw image
  reader.drawBMP("/minion.bmp", tft, 0, 0);
}

void loop() {

}
