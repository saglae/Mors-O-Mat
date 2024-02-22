#include <Arduino.h>
#include "Ucglib.h"
#include "Parameters.h"
#include "Alphabet.h"
#include "Display_Functions.h"

Ucglib_ILI9341_18x240x320_HWSPI ucg(lcd_dc, lcd_cs, lcd_reset);

void write_to_lcd(String text)
{
  ucg.clearScreen();
  ucg.setRotate270();
  ucg.setFont(ucg_font_ncenR14_tr);
  ucg.setPrintPos(25,25);
  ucg.setColor(255, 255, 255);
  ucg.print(text);

  delay(2000);
}

void show_letter(Letter x)
{
  write_to_lcd(x.definition);
}