#include <SPI.h>
#include "Ucglib.h"
#include "Parameters.h"
#include "Alphabet.h"
#include "Display_Functions.h"
#include "Buzzer_Functions.h"
#include "Input.h"



//Declarations
void initialize_pins();




void setup() {
  // put your setup code here, to run once:
  initialize_pins();
  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.clearScreen();
  clear_Structure();
  interrupts();
  //Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  get_settings();
  if(speed_changed)
  {
    timer_configuration(current_dit_duration);
  }

  //digitalWrite(led_beat,HIGH);

  //show_settings();
  //playLetter(A_M);
  //playLetter(M_9);
  //playLetter(B_M);
  get_dit_action();
  
  show_Structure();
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

void timer_configuration(int milliseconds)
{

  noInterrupts();
  TCCR1A = 0;               // Setzen Sie die Timer-Konfigurationsregister zurück
  TCCR1B = 0;

  TCCR1B |= (1 << CS12) | (1 << CS10);

  unsigned long timer_limit = (milliseconds * 16000000UL) / 1024 / 1000;

  OCR1A = timer_limit;

  TIMSK1 |= (1 << OCIE1A);
  interrupts();

}

ISR(TIMER1_COMPA_vect)
{
  digitalWrite(led_beat, !digitalRead(led_beat));
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