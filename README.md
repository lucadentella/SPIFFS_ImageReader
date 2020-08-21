# SPIFFS_ImageReader

Companion library for Adafruit_GFX to load images from SPIFFS partition; tested with Arduino core for the ESP32.

Requires Adafruit_GFX library and one of the SPI color graphic display libraries, e.g. Adafruit_ILI9341.

## Installation

- Install the library via Arduino Library Manager
- To upload data to SPIFFS partition, I strongly suggested to install [Arduino ESP32 filesystem uploader](https://github.com/me-no-dev/arduino-esp32fs-plugin)

## Usage

- Put BMP images in "data" subfolder of your project's main folder

![](/images/howto-01.png)

- Upload images via ESP32 filesystem uploader

![](/images/howto-02.png)

- Include the required libraries in your sketch:
```
#include <SPIFFS.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h> // use the correct library for your display
#include <SPIFFS_ImageReader.h>
```
- Create an instance of SPIFFS_ImageReader
```
SPIFFS_ImageReader reader;
```
- Initialize SPIFFS
```
if(!SPIFFS.begin()) 
```
- Display the image
```
reader.drawBMP("/minion.bmp", tft, 0, 0);
```
![](/images/howto-03.png)

## Available methods
- **drawBMP**, draws a BMP image starting at x,y
```
ImageReturnCode drawBMP(char *filename, Adafruit_SPITFT &tft, int16_t x, int16_t y);
```
- **loadBMP**, loads a BMP image from SPIFFS in RAM (**does not** draw it)
```
ImageReturnCode loadBMP(char *filename, SPIFFS_Image &img);
```
- **bmpDimensions**, returns image's width and height without loading it in RAM
```
ImageReturnCode bmpDimensions(char *filename, int32_t *w, int32_t *h);
```
- **printStatus**, prints a friendly message of a given return code
```
void printStatus(ImageReturnCode stat, Stream &stream = Serial);
```
