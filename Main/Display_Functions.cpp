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

void show_start_display()
{
  ucg.setRotate270();
  //Überschrift
  ucg.setFont(ucg_font_courB18_tr);
  ucg.setPrintPos(80,25); 
  ucg.setColor(118,181,197);
  ucg.print("Mors-O-Mat");

  //Unterstreichen 
  ucg.setColor(0, 0, 255, 255);
  ucg.setColor(1, 255, 255, 0);
  ucg.drawGradientLine(50, 40, 220, 0);

  //Willkommen
  ucg.setFont(ucg_font_ncenR14_tr);
  ucg.setPrintPos(60,100); 
  ucg.setColor(255,255,255);
  ucg.print("Herzlich Willkommen!"); 
  //Modus
  ucg.setPrintPos(40,130); 
  ucg.setColor(255,255,255);
  ucg.print("Was willst du heute lernen?");

  //Unterstreichen 
  ucg.setColor(0, 0, 255, 255);
  ucg.setColor(1, 255, 255, 0);
  ucg.drawGradientLine(50, 170, 220, 0);

  //Anzeige der Modi 
  ucg.setFont(ucg_font_ncenR10_tr);
  ucg.setPrintPos(10,220); 
  ucg.setColor(255,255,255);
  ucg.print("Buchstaben  --  Nehmen  --  Geben  --  Q-Code");

}
