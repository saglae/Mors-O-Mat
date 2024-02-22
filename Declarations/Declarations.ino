#include <SPI.h>
#include "Ucglib.h"


#define modus_1 5
#define modus_2 4
#define modus_3 3
#define modus_4 2

#define led_beat 7
#define buzzer 6
#define buzzer_old A7

#define lcd_sck 13
#define lcd_sdi 11
#define lcd_cs 10
#define lcd_reset 9
#define lcd_dc 8
//LED an 3V3 (17) und VCC an 5V (27)

#define speed A0
#define difficulty A1
#define volume A2

#define dot A5
#define dash A4
#define input_switch A3


//Declarations
void initialize_pins();
void write_to_lcd(String);


Ucglib_ILI9341_18x240x320_HWSPI ucg(lcd_dc, lcd_cs, lcd_reset);


void setup() {
  // put your setup code here, to run once:
  initialize_pins();
  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.clearScreen();

}

void loop() {
  // put your main code here, to run repeatedly:

  //write_to_lcd("Test");
  if(digitalRead(modus_1))
  {
    ucg.clearScreen();
    write_to_lcd("Buchstaben lernen");
  }
  else if(digitalRead(modus_2))
  {
    ucg.clearScreen();
    write_to_lcd("Hörverstehen");
  }
  else if(digitalRead(modus_3))
  {
    ucg.clearScreen();
    write_to_lcd("Wörter geben");
  }
  else if(digitalRead(modus_4))
  {
    ucg.clearScreen();
    write_to_lcd("Q-Schlüssel");
  }

  //playTone(buzzer,440,1000);
  delay(1000);

  
  
  


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

void write_to_lcd(String text)
{
  ucg.setRotate90();
  ucg.setFont(ucg_font_ncenR14_tr);
  ucg.setPrintPos(25,25);
  ucg.setColor(255, 255, 255);
  ucg.print(text);

  delay(2000);
   
}

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