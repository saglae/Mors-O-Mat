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
int check_dits();
void get_dit_action();
void append_Structure(char toAppend);
void clear_Structure();
void show_Structure();
char interpret_Structure();
void show_interpreted_Structure();
int get_current_structure_lenght();
void append_letter_to_structure(char toAppend);


Letter check_if_Structure_is_Letter(const char* structure);


extern int dit_pause_counter;
extern char current_input_structure[10];   //Check for only ONE Structure at a time, then delete.
extern char current_interpreted_input[10];


extern bool speed_changed;
extern bool difficulty_changed;
extern bool word_is_ready;
extern bool letter_is_ready;

#endif