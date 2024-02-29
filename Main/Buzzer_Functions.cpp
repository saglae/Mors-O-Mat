#include "Buzzer_Functions.h"
#include <Arduino.h>
#include "Parameters.h"
#include "Alphabet.h"


void playTone(int buzzerPin, int frequency, int duration, int volume) {  //duration in ms
  int period = 1000 / frequency;  // Berechne die Periode des Tons in us
  long cycles = duration / period;  // Berechne die Anzahl der Zyklen

  analogWrite(buzzer,255);
  for (long i = 0; i < cycles; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(period / 2);
    digitalWrite(buzzerPin, LOW);
    delay(period / 2);
  }

}


//Aus Wikipedia: 1 Dah = 3 Dit; 3 Dit für Buchstaben in einem Wort, 7 Dit zwischen Wörtern https://de.wikipedia.org/wiki/Morsecode#Standardisierung
//Paris Norm: PARIS 30/Minute = 30 WPM = 150 BPM --> PARIS hat 50 Dit und somit 1500 Dit / Minute für 30 WPM https://de.wikipedia.org/wiki/Schnelltelegrafie#Definition 

void playLetter(Letter x)
{
  const char* structure = x.structure;
  int sum_chars = sizeof(structure)/sizeof(structure[0]);
  float dit = current_dit_duration; 
  int dah = dit * 3;

  char buffer[20];
  snprintf(buffer, sizeof(buffer), "Dit: %d", dit);
  write_to_lcd(buffer,1,false);
  //write_to_lcd(dah,3,false);

  for(int char_index = 0; char_index < sum_chars; char_index++)
  {
    if(x.structure[char_index] == '-')
    {
      playTone(buzzer,440,dah,current_volume_level);
    }
    else
    {
      playTone(buzzer,440,dit,current_volume_level);
    };
    delay(dit);
  }
  delay(dit*2);
}


  int get_total_Dashes(Letter x)
  {
    int sum_chars = sizeof(x.structure)/sizeof(x.structure[0]);
    int dashes = 0;
    for(int char_index = 0; char_index < sum_chars; char_index++)
    {
      if(x.structure[char_index] == '-')
      {
        dashes++;
      }
    }
    return dashes;
  }

  
  
