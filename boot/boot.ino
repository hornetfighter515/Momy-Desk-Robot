#include <TFT_eSPI.h>       // Hardware-specific library
#include "FS.h"
#include <SPIFFS.h>  // Include the SPIFFS library

// Screen
TFT_eSPI tft = TFT_eSPI();  // Invoke custom library
// Include the image
#include "Logo.h"
#include "eyes.h"


void setup() {
  Serial.begin(115200);

  // Check if SD is mount and file "known_networks.json" exist
  if (!SPIFFS.begin())
  {
    Serial.println("Failed to mount file system");
  }

  //Screen Initialized
  tft.begin();
  tft.setRotation(0);	// landscape
  tft.fillScreen(TFT_BLACK);
  tft.setSwapBytes(true); // Swap the colour byte order when rendering

  // Draw the logo
  tft.pushImage(30, 60, logoWidth, logoHeight, logo_momysnow);

  delay(2000);

  // Reset screen
  tft.fillScreen(TFT_BLACK); // Black screen fill
}

void loop() {
  // Draw the eyes
  tft.pushImage(32, 57, eyesWidth, eyesHeight, Occhi_apenti);
  delay(2000);
  tft.pushImage(32, 57, eyesWidth, eyesHeight, occhi_26);
  delay(50);
  tft.pushImage(32, 57, eyesWidth, eyesHeight, occhi_27);
  delay(50);
  tft.pushImage(32, 57, eyesWidth, eyesHeight, occhi_28);
  delay(50);
  tft.pushImage(32, 57, eyesWidth, eyesHeight, occhi_29);
  delay(150);
  tft.pushImage(32, 57, eyesWidth, eyesHeight, occhi_28);
  delay(50);
  tft.pushImage(32, 57, eyesWidth, eyesHeight, occhi_27);
  delay(50);
  tft.pushImage(32, 57, eyesWidth, eyesHeight, occhi_26);
  delay(50);
}