#include <SPI.h>
#include "Ucglib.h"



//******************************* Declarations ******************************

//Component Tests
void test_chooseMode(int pin_in, int pin_out);
void test_potentiometer(int adc_in, int pin_out);
void test_display();
void test_tone(int frequency, int pin);

//Functional Software


//Pins

#define cs   9
#define dc   8
#define rst  7
#define sclk 13
#define mosi 11
#define miso 12


Ucglib_ILI9341_18x240x320_HWSPI ucg(dc, cs, rst);

//***************************** Setup **************************************

void setup() {
  // put your setup code here, to run once:
  //pinMode(A1,INPUT);
  //pinMode(13,OUTPUT);

  ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.clearScreen();

  //pinMode(LED_BUILTIN, OUTPUT);
  


}

//*************************** Main *****************************************

void loop() {
  // put your main code here, to run repeatedly:
   //test_chooseMode(A1,13);
   //test_potentiometer(A2);

 
  //test_display();
  test_tone(440, 3);
  //test_chooseMode(A3,3);
 

}


// **************************** Definitions *********************************

void test_chooseMode(int pin_in, int pin_out)
{
  pinMode(pin_in, INPUT);
  pinMode(pin_out, OUTPUT);

  if(digitalRead(pin_in)== 1){
    digitalWrite(pin_out,HIGH);
    }
    else{
      digitalWrite(pin_out,LOW);
    }
    return;
}

void test_display()
{
  ucg.setRotate90();
  ucg.setFont(ucg_font_ncenR14_tr);
  ucg.setPrintPos(25,25);
  ucg.setColor(255, 255, 255);
  ucg.print("Hello World!");

  delay(500); 
 
}

void test_potentiometer(int adc_in)
{
  int value = 0;
  Serial.begin(9600);
  value = analogRead(adc_in);
  Serial.println(value);
  delay(1000);
  return;
}

void test_tone(int frequency, int pin)
{
  pinMode(pin, OUTPUT);
  tone(pin, frequency);
  delay(2000);
  pinMode(pin, INPUT);
  delay(2000);
}