#include <SPI.h>
#include "Ucglib.h"
#include "Parameters.h"
#include "Alphabet.h"
#include "Input.h"
#include "Modus_1.h"
#include "Modus_2.h"
#include "Modus_3.h"
#include "Modus_4.h"
#include "Display_Functions.h"
#include "Buzzer_Functions.h"






//Declarations
void initialize_pins();

int counter = 0; //32 Bit
int counter_10s = 0;
int8_t letter_counter = 0;
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
  if(mod_changed)
  {
    ucg.clearScreen();
  }
  if(difficulty_changed)
  {
    letter_counter = 0;
  }


  if(mod1 && ! mod1_try_yourself)
  {// Buchstaben lernen
    ucg.clearScreen();
    show_mod1_start_display();

    Letter letter = all_Letters[(current_difficulty_level-1)*10+letter_counter];
    show_letter(letter);

    //Abspielen
    playLetter(letter);
    delay(1000);
    playLetter(letter);
    delay(1000);
    playLetter(letter);
    delay(1000);

    write_to_lcd("Probier es selbst!",6,false);
    mod1_try_yourself = true;
    counter_10s = 0;
    if((letter_counter + (current_difficulty_level-1)*10) >= 46)    //Unschöner Workaround! Clean Coding muss leider hier vernachlässigt werden, da ich mir keinen zusätzlichen Speicher leisten darf.
    {
      letter_counter = 0;
    }
    if(letter_counter >= 10)
    { //Da wir nicht den Modus wechseln wollen.
      letter_counter = 0;
    }
    else
    {
      letter_counter++;
    }
  }
  else if(mod1 && mod1_try_yourself)
  {
    get_dit_action();
  } 



  else if(mod2)
  { // Hörverstehen
    show_mod2_start_display();

  }
  else if(mod3)
  { // Wörter geben
    show_mod3_start_display();


  }
  else if(mod4)
  { // Q-Code

      // Currently not usable due to memory shortage --> Upgrade controller. Since this exercise is optional, delay. 

  }

  else
  {
    //Willkommensbildschirm
    show_start_display();
  }

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
  counter_10s++;
  if(counter_10s > 2000) //10s
  {
    mod1_try_yourself = false;
  }  
}