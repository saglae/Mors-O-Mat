#include <SPI.h>
#include "Ucglib.h"
#include "Parameters.h"
#include "Alphabet.h"
#include "Display_Functions.h"
#include "Buzzer_Functions.h"
#include "Input.h"
#include "Modus_1.h"
#include "Modus_2.h"
#include "Modus_3.h"
#include "Modus_4.h"




//Declarations
void initialize_pins();

int counter = 0; //32 Bit
int blinking_period = 0;




void setup() {
  // put your setup code here, to run once:
  initialize_pins();
  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.clearScreen();
  clear_Structure();
  interrupts();
  timer_configuration();
  //Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  get_settings();
  if(speed_changed)
  {//Currently signals when a new word would start.
    blinking_period = current_dit_duration * 7 / 5;
  }



  //show_settings();
  //delay(1000);
  //playLetter(A_M);
  //playLetter(M_9);
  //playLetter(B_M);
  //get_dit_action();
  //playLetter(M_M);
  //playLetter(M_9);
  //playLetter(S_M);
  //play_Word(words_difficulty_1, 3);
  //delay(2000);
  
  //show_Structure();
  //show_interpreted_Structure();
  

}


//Definitions
void initialize_pins()
{
  pinMode(modus_1, INPUT);
  pinMode(modus_2, INPUT);
  pinMode(modus_3, INPUT);
  pinMode(modus_4, INPUT);

  // LED und Buzzer
  pinMode(led_beat, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buzzer_old, INPUT);

  // LCD
  pinMode(lcd_sck, OUTPUT);
  pinMode(lcd_sdi, OUTPUT);
  pinMode(lcd_cs, OUTPUT);
  pinMode(lcd_reset, OUTPUT);
  pinMode(lcd_dc, OUTPUT);

  // Analoge Eingänge
  pinMode(speed, INPUT);
  pinMode(difficulty, INPUT);
  pinMode(volume, INPUT);

  // Taster
  pinMode(dot, INPUT);
  pinMode(dash, INPUT);
  pinMode(input_switch, INPUT);
}



void timer_configuration()
{
  noInterrupts();
  TCCR1A = 0;               // Setzen Sie die Timer-Konfigurationsregister zurück
  TCCR1B = 0;

  TCCR1A |= (1 << WGM12);                  //CTC
  TCCR1B |= (0 << CS12) | (0 << CS11) | (1 << CS10);    //8 Vorteiler

  unsigned long timer_limit = (F_CPU) / (1*200)  - 1 ;    //8 Vorteiler   //Datenblatt: fOCnA = FCPU / (2*Vorteiler*(1+OCRnA)); 

  OCR1A = timer_limit;

  TIMSK1 |= (1 << OCIE1A);
  interrupts();   //Enable Interrupts globally
}





void checkMode()
{

  //write_to_lcd("Test");
  if(digitalRead(modus_1))
  {
    
    write_to_lcd("Buchstaben lernen",1,true);
  }
  else if(digitalRead(modus_2))
  {
    write_to_lcd("Hörverstehen",1,true);
  }
  else if(digitalRead(modus_3))
  {
    write_to_lcd("Wörter geben",1,true);
  }
  else if(digitalRead(modus_4))
  {
    write_to_lcd("Q-Schlüssel",1,true);
  }
}

//-------------------------ISR------------------------------------


ISR(TIMER1_COMPA_vect)
{
  //Wird alle 5 ms aufgerufen
  counter++;
  if(counter >= blinking_period) //blinking period 150 ... 60 --> counter 30 ... 12
  {
    digitalWrite(led_beat, !digitalRead(led_beat));
    counter = 0;
  }
  
}