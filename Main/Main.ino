#include <SPI.h>
#include "Ucglib.h"
#include "Parameters.h"
#include "Alphabet.h"
#include "Input.h"
#include "Modus_4.h"
#include "Display_Functions.h"
#include "Buzzer_Functions.h"






//Declarations
void initialize_pins();

int counter = 0; //32 Bit
int counter_10s = 0;
int8_t letter_counter = 0;
int blinking_period = 0;
Letter current_word_to_play[5];


int8_t counter_mod3 = 0;



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
    learn_modus_1();
  }
  else if(mod1 && mod1_try_yourself)
  {
    get_dit_action();
  } 
  else if(mod2)
  { // Hörverstehen
    learn_modus_2();
  }

  else if(mod3)
  { // Wörter geben
    show_mod3_start_display();
    if(init_mod3)
    {
    static Letter word[5];
    static char word_to_display[6]; //+ delimiter
    static char progress[6];

    for(int letter = 0; letter < 5; letter++)
    {
      int randomNumber = generate_random();
      word[letter] = all_Letters[randomNumber];
      word_to_display[letter] = all_Letters[randomNumber].name[0];
      progress[letter] = '\0';
    }
    word_to_display[5] = '\0'; //Delimiter dran
    progress[5] = '\0';

    write_to_lcd("Start >> dit",2,false);
    write_to_lcd(progress,3,false);
    write_to_lcd(word_to_display, 4, false);

    while(analogRead(dot)<500) {};
    }
    
    
    //Write corrected word!

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


void learn_modus_1()
{
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

int generate_random()
{
  int pseudo_random = millis();
  randomSeed(pseudo_random);
  return random(0,(6 + (current_difficulty_level - 1)*10));
}

void learn_modus_2()
{
    show_mod2_start_display();

    char words[3][6];

    write_to_lcd("Hoer zu!", 3, false);
    playLetter(M_Start);

    // 3x 5er Gruppe abspielen
    for(int word = 0; word < 3 ; word++)
    { 
      for(int letter = 0; letter < 5; letter++)
      {
        int randomNumber = generate_random();
        words[word][letter] = all_Letters[randomNumber].name[0]; //Für das Ergebnis sichern!
        playLetter(all_Letters[randomNumber]);
      }
      words[word][5] = '\0'; //Das letzte Element ist der delimiter
      delay(3*current_dit_duration);
    }

    playLetter(M_End);

    write_to_lcd("Ergebnis? >> dit", 6, false);
    while(analogRead(dot) < 500) {}; //
    ucg.clearScreen();

    //Ergebnisse anzeigen 
    show_mod2_start_display();
    write_to_lcd(words[0], 2 ,false);
    write_to_lcd(words[1], 3 ,false);
    write_to_lcd(words[2], 4 ,false);

    //Weiter
    write_to_lcd("Weiter? >> dit", 7, false);
    while(analogRead(dot) < 500) {};
    ucg.clearScreen();
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