#include <Arduino.h>
#include "Ucglib.h"
#include "Parameters.h"
#include "Alphabet.h"
#include "Display_Functions.h"

Ucglib_ILI9341_18x240x320_HWSPI ucg(lcd_dc, lcd_cs, lcd_reset);

void write_to_lcd(const char* text, int row, bool clear=false)
{
  lcd_home(clear);
  lcd_setRow(row);
  ucg.print(text);
}

void show_letter(Letter x)
{
  write_to_lcd(x.definition,1);
  lcd_spreadStructure(x.structure,2);
  write_to_lcd(x.name,3);
}


void lcd_home(bool clear_display)
{
  ucg.setRotate270();
  ucg.setFont(ucg_font_ncenR14_tr);
  ucg.setPrintPos(25,25);
  ucg.setColor(255, 255, 255);
  if(clear_display)
  {
    ucg.clearScreen();
  }
}

void lcd_setRow(int row)
{
  ucg.setPrintPos(25,25+row*25);
}

void lcd_spreadStructure(const char* structure, int row)
{
  for(int index = 0; index < strlen(structure); index++)
  {
    ucg.setPrintPos(25+index*20,25+row*25);
    ucg.print(structure[index]);
  }
}
