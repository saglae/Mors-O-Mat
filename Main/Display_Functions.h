#ifndef DISPLAY_FUNCTIONS_H
#define DISPLAY_FUNCTIONS_H

#include <Arduino.h>
#include "Ucglib.h"
#include "Parameters.h"


void write_to_lcd(String);
void show_letter(Letter);

extern Ucglib_ILI9341_18x240x320_HWSPI ucg;

#endif