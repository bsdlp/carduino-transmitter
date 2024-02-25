#include <Arduino.h>
#include <pico/stdlib.h>
#include <Screen.h>
extern "C"
{
#include <ili9341.h>
#include <gfx.h>
}

void setup()
{
  LCD_setPins(DC_PIN, CS_PIN, RST_PIN, SCK_PIN, TX_PIN);
  LCD_initDisplay();
  LCD_setRotation(1);
  GFX_createFramebuf();
}

unsigned long allSeconds;
int uptimeHours;
int secondsRemaining;
int uptimeMinutes;
int uptimeSeconds;

void loop()
{
  GFX_clearScreen();

  // DATA COLLECTION
  // fetch battery info

  // fetch time since boot
  // https://www.arduino.cc/reference/en/language/functions/time/millis/
  allSeconds = millis() / 1000;
  uptimeHours = allSeconds / 3600;
  secondsRemaining = allSeconds % 3600;
  uptimeMinutes = secondsRemaining / 60;
  uptimeSeconds = secondsRemaining % 60;

  // PRINT DATA
  // print time and battery info

  GFX_setCursor(0, 0);
  GFX_printf("uptime: %02d:%02d:%02d\n", uptimeHours, uptimeMinutes, uptimeSeconds);
  GFX_drawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 80, NEON_GREEN); // center circle
  GFX_flush();
  delay(500);
}
