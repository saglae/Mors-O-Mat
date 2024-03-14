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
  ucg.setFont(ucg_font_ncenR18_tr);
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
  ucg.setFont(ucg_font_ncenR18_tr);
  ucg.setPrintPos(80,25); 
  ucg.setColor(118,181,197);
  ucg.print("Mors-O-Mat");

  //Unterstreichen 
  ucg.setColor(0, 0, 255, 255);
  ucg.setColor(1, 255, 255, 0);
  ucg.drawGradientLine(50, 40, 220, 0);

  //Willkommen
  ucg.setFont(ucg_font_ncenR18_tr);
  ucg.setPrintPos(35,100); 
  ucg.setColor(255,255,255);
  ucg.print("Herzlich Willkommen!"); 
  //Modus
  ucg.setPrintPos(40,130); 
  ucg.setColor(255,255,255);
  ucg.print("Was willst du lernen?");

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



void show_mod1_start_display()
{
  ucg.setRotate270();
  //Überschrift
  ucg.setFont(ucg_font_ncenR18_tr);
  ucg.setPrintPos(55,25); 
  ucg.setColor(118,181,197);
  ucg.print("Buchstaben lernen");

  //Unterstreichen 
  ucg.setColor(0, 0, 255, 255);
  ucg.setColor(1, 255, 255, 0);
  ucg.drawGradientLine(50, 40, 220, 0);

  //Erklärung
  ucg.setFont(ucg_font_ncenR10_tr);
  ucg.setPrintPos(15,80); 
  ucg.setColor(255,255,255);
  ucg.print("Ich spiele gleich Buchstaben vor. Auf dem"); 
  ucg.setPrintPos(15,100); 
  ucg.print("Display siehst du dazu relevante Infos."); 
  ucg.setPrintPos(15,120); 
  ucg.print("Nach 3 Wiederholungen bist du dran! :)"); 
  ucg.setPrintPos(15,140); 
  ucg.print("Alles verstanden? Dann starte mit einem dit.");  

  //Unterstreichen 
  ucg.setColor(0, 0, 255, 255);
  ucg.setColor(1, 255, 255, 0);
  ucg.drawGradientLine(50, 160, 220, 0);

  //Tipp
  ucg.setFont(ucg_font_ncenR10_tr);
  ucg.setColor(118,181,197); 
  ucg.setPrintPos(10,200); 
  ucg.print("Tipp: Du kennst schon alles, was ich");
  ucg.setPrintPos(10,220); 
  ucg.print("          vorspiele? Erhoehe die Schwierigkeit!"); 
}

void show_mod2_start_display()
{
  //Überschrift
  ucg.setFont(ucg_font_ncenR18_tr);
  ucg.setPrintPos(50,25); 
  ucg.setColor(118,181,197);
  ucg.print("5er Gruppen geben");

  //Unterstreichen 
  ucg.setColor(0, 0, 255, 255);
  ucg.setColor(1, 255, 255, 0);
  ucg.drawGradientLine(50, 40, 220, 0);

  //Erklärung
  ucg.setFont(ucg_font_ncenR10_tr);
  ucg.setPrintPos(15,80); 
  ucg.setColor(255,255,255);
  ucg.print("Schnapp dir Stift und Papier! Schreibe"); 
  ucg.setPrintPos(15,100); 
  ucg.print("die nachfolgenden 5er Gruppen auf. Mit"); 
  ucg.setPrintPos(15,120); 
  ucg.print("einem dit erscheint die Loesung."); 
  ucg.setPrintPos(15,140); 
  ucg.print("Alles verstanden? Dann starte mit einem dit.");  

  //Unterstreichen 
  ucg.setColor(0, 0, 255, 255);
  ucg.setColor(1, 255, 255, 0);
  ucg.drawGradientLine(50, 160, 220, 0);

  //Tipp
  ucg.setFont(ucg_font_ncenR10_tr);
  ucg.setColor(118,181,197); 
  ucg.setPrintPos(10,180); 
  ucg.print("Tipp: Wenn du etwas nicht erkennst, dann");
  ucg.setPrintPos(10,200); 
  ucg.print("          wechsle mit dem gleichen Schwierig-"); 
  ucg.setPrintPos(10,220); 
  ucg.print("          keitsgrad in Modus 1 zum Ueben."); 
}

void show_mod3_start_display()
{
  //Überschrift
  ucg.setFont(ucg_font_ncenR18_tr);
  ucg.setPrintPos(35,25); 
  ucg.setColor(118,181,197);
  ucg.print("5er Gruppen nehmen");

  //Unterstreichen 
  ucg.setColor(0, 0, 255, 255);
  ucg.setColor(1, 255, 255, 0);
  ucg.drawGradientLine(50, 40, 220, 0);

  //Erklärung
  ucg.setFont(ucg_font_ncenR10_tr);
  ucg.setPrintPos(15,80); 
  ucg.setColor(255,255,255);
  ucg.print("Gebe die gezeigten 5er Gruppen. Ein _ "); 
  ucg.setPrintPos(15,100); 
  ucg.print("zeigt dir den aktuellen Buchstaben. Achte"); 
  ucg.setPrintPos(15,120); 
  ucg.print("auf das Tempo!"); 
  ucg.setPrintPos(15,140); 
  ucg.print("Alles verstanden? Dann starte mit einem dit.");  

  //Unterstreichen 
  ucg.setColor(0, 0, 255, 255);
  ucg.setColor(1, 255, 255, 0);
  ucg.drawGradientLine(50, 160, 220, 0);

  //Tipp
  ucg.setFont(ucg_font_ncenR10_tr);
  ucg.setColor(118,181,197); 
  ucg.setPrintPos(130,200); 
  ucg.print("Viel Spass!");
}



