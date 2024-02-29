#ifndef INPUT_H
#define INPUT_H

#include <Arduino.h>
#include "Parameters.h"
#include "Alphabet.h"
#include "Display_Functions.h"

int get_Value(int pin);
void show_Value(int pin);
int interpret_potentiometer(int pin);
void get_settings();
bool interpret_modus_switch(int pin);
void show_settings();


#endif