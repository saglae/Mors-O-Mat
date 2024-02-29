#ifndef DISPLAY_FUNCTIONS_H
#define DISPLAY_FUNCTIONS_H

#include <Arduino.h>
#include "Ucglib.h"
#include "Parameters.h"


void write_to_lcd(const char* text, int row, bool clear=false);
void show_letter(Letter);
void lcd_home(bool clear_display);
void lcd_setRow(int row);
void lcd_spreadStructure(const char* structure, int row);

extern Ucglib_ILI9341_18x240x320_HWSPI ucg;

#endif