#ifndef INPUT_H
#define INPUT_H

#include <Arduino.h>
#include "Parameters.h"
#include "Alphabet.h"
#include "Display_Functions.h"
#include "Buzzer_Functions.h"

int get_Value(int pin);
void show_Value(int pin);
int interpret_potentiometer(int pin);
void get_settings();
bool interpret_modus_switch(int pin);
void show_settings();
bool check_long_Pause();
int check_dits();
void get_dit_action();

extern int dit_pause_counter;
extern const char* current_input;


#endif