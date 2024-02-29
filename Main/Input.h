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
bool check_long_Pause_letter();
int check_dits();
void get_dit_action();
void append_Structure(const char* toAppend);
void clear_Structure();
void show_Structure();
const char* interpret_Structure();
void show_interpreted_Structure();
const char** seperate_Structure();
void shift_Buffer_to_first_Semikolon();
Letter check_if_Structure_is_Letter(const char* structure);


extern int dit_pause_counter;
extern char* current_input_structure;


#endif