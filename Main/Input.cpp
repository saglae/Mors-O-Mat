#include "Input.h"

int dit_pause_counter = 0;
const char* current_input = "";


int get_Value(int pin)
{
  return analogRead(pin);
}



void show_Value(int pin)
{
  char output[20];
  snprintf(output, sizeof(output), "Pin %d:   %d", pin, get_Value(pin));
  write_to_lcd(output, 0, true);
  delay(1000);
}

int interpret_potentiometer(int pin)
{ //Abstufungen von 1...5
  //0: Fehler
  int current_value = get_Value(pin);
  int category = map(current_value, 0, 900, 1, 5); //Erste Tests zeigten, dass die 1023 nie vollständig erreicht werden.
  return category;
}

bool interpret_modus_switch(int pin)
{
  int current_value = digitalRead(pin);
  if(current_value==1)
  {
    return true;
  }
  else
  {
    return false;
  }
}


void get_settings()
{
  mod1 = interpret_modus_switch(modus_1);
  mod2 = interpret_modus_switch(modus_2);
  mod3 = interpret_modus_switch(modus_3);
  mod4 = interpret_modus_switch(modus_4);

  current_speed_level=interpret_potentiometer(speed);
  current_difficulty_level=interpret_potentiometer(difficulty);
  current_volume_level=interpret_potentiometer(volume);


  current_dit_duration = (float) 60.0 * 1000.0 / (float)((current_speed_level * 4 + 4) * 50); //in ms                    
                                                                  //     8             12           16              20             24         WPM entsprechend nach Paris Norm:  	
                                                              //    400dit/min      600dit/min    800dit/min    1000dit/min   1200dit/min
                                                              //     150ms/dit      100ms/dit     75ms/dit       60ms/dit       50ms/dit
  
  if(analogRead(input_switch)>500){
    paddle = true;
  }
  else{
    paddle = false;
  }
}

void show_settings()
{
  const char output[30];
  write_to_lcd("----Settings----",0,true);
  snprintf(output, sizeof(output), "Modus 1:   %s", mod1 ? "true" : "false");
  write_to_lcd(output,1,false);
  snprintf(output, sizeof(output), "Modus 2:   %s", mod2 ? "true" : "false");
  write_to_lcd(output,2,false);
  snprintf(output, sizeof(output), "Modus 3:   %s", mod3 ? "true" : "false");
  write_to_lcd(output,3,false);
  snprintf(output, sizeof(output), "Modus 4:   %s", mod4 ? "true" : "false");
  write_to_lcd(output,4,false);

  snprintf(output, sizeof(output), "Speed:     %d/5     Dit: %d ms", current_speed_level, current_dit_duration);
  write_to_lcd(output,5,false);
  snprintf(output, sizeof(output), "Difficulty:   %d/5", current_difficulty_level);
  write_to_lcd(output,6,false);
  snprintf(output, sizeof(output), "Volume:   %d/5", current_volume_level);
  write_to_lcd(output,7,false);

  snprintf(output, sizeof(output), "Paddle:   %s", paddle ? "true" : "false");
  write_to_lcd(output,8,false);
}

int check_dits()
{
  //Return Values: 0: Pause; 1: Dit; 2: Dah
  int output = 0;
  if(analogRead(dot)>850)
  {
    output = 1;
  }
  else if(analogRead(dash)>850)
  {
    output = 2;
  }
  return output;
}


bool check_long_Pause()
{
  if(dit_pause_counter==3)
  {
    dit_pause_counter = 0;
    return true;
  }
  else
  {
    return false;
  }
}

void get_dit_action()
{
  int action = check_dits();
  bool wait = false;

  if(action == 0)
  { //Pause
    dit_pause_counter++;
    delay(current_dit_duration);
    if(check_long_Pause());
    {
      //delay(current_dit_duration*2); // hat schon einmal!
    }
  }
  else if(action == 1)
  { // Dit
    playTone(buzzer,440,current_dit_duration,current_volume_level);
    //delay(current_dit_duration);
    dit_pause_counter = 0;
  }
  else if(action == 2)
  { //Dah
    playTone(buzzer,440,current_dit_duration*3,current_volume_level);
    //delay(current_dit_duration*3);
    dit_pause_counter = 0;
  }
  delay(current_dit_duration);

}


