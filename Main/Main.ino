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
  //Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  get_settings();

  //show_settings();
  //playLetter(A_M);
  //playLetter(M_9);
  //playLetter(B_M);
  get_dit_action();
  

}


//Definitions
void initialize_pins()
{
  int total_number_of_pins = get_total_amount_of_used_Pins();
  for (int pin = 0; pin < total_number_of_pins; pin++)
  {
    if (Pins[pin].input)
    {
      pinMode(Pins[pin].pinName, INPUT);
    }
    else
    {
      pinMode(Pins[pin].pinName, OUTPUT);
    }
  }
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