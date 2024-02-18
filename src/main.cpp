#include <Arduino.h>
#include <pico/stdlib.h>
#include <Screen.h>
extern "C"
{
#include <ili9341.h>
#include <gfx.h>
}

// pin definitions

void setup()
{
  // put your setup code here, to run once:
  LCD_setPins(DC_PIN, CS_PIN, RST_PIN, SCK_PIN, TX_PIN);
  LCD_initDisplay();
  LCD_setRotation(1);
  GFX_createFramebuf();
}

void loop()
{
  // put your main code here, to run repeatedly:
  GFX_clearScreen();
  GFX_setCursor(0, 0);
  GFX_printf("Hello GFX!\n");
  GFX_drawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 80, NEON_GREEN); // center circle
  GFX_flush();
  delay(500);
}
