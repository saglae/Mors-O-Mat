#ifndef BUZZER_FUNCTIONS_H
#define BUZZER_FUNCTIONS_H

#include <Arduino.h>
#include "Parameters.h"
#include "Alphabet.h"
#include "Display_Functions.h"




void playTone(int buzzerPin, int frequency, int duration, int volume);
void playLetter(Letter x);
int get_total_Dashes(Letter x);

#endif