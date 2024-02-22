#include <SPI.h>
#include "Ucglib.h"
#include "Parameters.h"
#include "Display_Functions.h"
#include "Buzzer_Functions.h"
#include "Alphabet.h"



//Declarations
void initialize_pins();




void setup() {
  // put your setup code here, to run once:
  initialize_pins();
  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.clearScreen();
  

}

void loop() {
  // put your main code here, to run repeatedly:

  if(analogRead(dot)>900)
  {
    //playTone(buzzer,440,200);
    write_to_lcd(".");
  }
  if(analogRead(dash)>900)
  {
    //playTone(buzzer,440,600);
    write_to_lcd("-");
  }

  //playTone(buzzer,440,1000);
 



}


//Definitions
void initialize_pins()
{
  pinMode(modus_1,INPUT);
  pinMode(modus_2,INPUT);
  pinMode(modus_3,INPUT);
  pinMode(modus_4,INPUT);

  pinMode(led_beat,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(buzzer_old, OUTPUT);

  pinMode(lcd_sck,OUTPUT);
  pinMode(lcd_sdi,OUTPUT);
  pinMode(lcd_cs,OUTPUT);
  pinMode(lcd_reset,OUTPUT);
  pinMode(lcd_dc,OUTPUT);

  pinMode(speed,INPUT);
  pinMode(difficulty,INPUT);
  pinMode(volume,INPUT);

  pinMode(dot,INPUT);
  pinMode(dash,INPUT);
  pinMode(input_switch,INPUT);
}





void checkMode()
{

  //write_to_lcd("Test");
  if(digitalRead(modus_1))
  {
    
    write_to_lcd("Buchstaben lernen");
  }
  else if(digitalRead(modus_2))
  {
    write_to_lcd("Hörverstehen");
  }
  else if(digitalRead(modus_3))
  {
    write_to_lcd("Wörter geben");
  }
  else if(digitalRead(modus_4))
  {
    write_to_lcd("Q-Schlüssel");
  }
}