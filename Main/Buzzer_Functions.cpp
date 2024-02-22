#include "Buzzer_Functions.h"
#include <Arduino.h>
#include "Parameters.h"



void playTone(int buzzerPin, int frequency, int duration) {  //duration in ms
  int period = 1000 / frequency;  // Berechne die Periode des Tons in Mikrosekunden
  long cycles = duration / period;  // Berechne die Anzahl der Zyklen

  for (long i = 0; i < cycles; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(period / 2);
    digitalWrite(buzzerPin, LOW);
    delay(period / 2);
  }
}