#include <Arduino.h>
#include <pico/stdlib.h>
#include <Screen.h>
extern "C"
{
#include <ili9341.h>
#include <gfx.h>
}

unsigned int cs = 20;
unsigned int rst = 19;
unsigned int dc = 18;
unsigned int sck = 2;
unsigned int tx = 3;
unsigned int counter = 0;

void setup()
{
  // put your setup code here, to run once:
  LCD_setPins(dc, cs, rst, sck, tx);
  LCD_initDisplay();
  LCD_setRotation(1);
  GFX_createFramebuf();
}

void moveCircle(unsigned int counter)
{
  unsigned int x = counter * 5;

  if (x > SCREEN_WIDTH)
  {
    counter = 0;
    moveCircle(counter);
    return;
  }

  GFX_fillCircle(x, 160, 50, 0x00FF00);
  counter++;
  return;
}

void loop()
{
  // put your main code here, to run repeatedly:
  GFX_clearScreen();
  GFX_setCursor(0, 0);
  GFX_printf("Hello GFX!\n%d", counter);
  moveCircle(counter);
  GFX_flush();
  delay(500);
}
