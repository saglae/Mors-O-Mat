#include "Input.h"

int dit_pause_counter = 0;



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
  int category = map(current_value, 0, 850, 1, 5); //Erste Tests zeigten, dass die 1023 nie vollständig erreicht werden.
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

bool speed_changed = false;

bool understood = false;


void get_settings()
{
  bool mod1_old = mod1;
  bool mod2_old = mod2;
  bool mod3_old = mod3;
  bool mod4_old = mod4;

  mod1 = interpret_modus_switch(modus_1);
  mod2 = interpret_modus_switch(modus_2);
  mod3 = interpret_modus_switch(modus_3);
  mod4 = interpret_modus_switch(modus_4);

  if(mod1_old == mod1 && mod2_old == mod2 && mod3_old == mod3 && mod4_old == mod4)
  {
    mod_changed = false;
  }
  else
  {
    mod_changed = true;
    understood = false;
  }

  current_speed_level=interpret_potentiometer(speed);
  current_difficulty_level=interpret_potentiometer(difficulty);
  current_volume_level=interpret_potentiometer(volume);

  old_dit_duration = current_dit_duration;

  current_dit_duration = (float) 60.0 * 1000.0 / (float)((current_speed_level * 4 + 4) * 50); //in ms                    
                                                                  //     8             12           16              20             24         WPM entsprechend nach Paris Norm:  	
                                                              //    400dit/min      600dit/min    800dit/min    1000dit/min   1200dit/min
                                                              //     150ms/dit      100ms/dit     75ms/dit       60ms/dit       50ms/dit
  
  if(old_dit_duration == current_dit_duration)
  {
    speed_changed = false;
  }
  else
  {
    speed_changed = true;
  }

  if(analogRead(input_switch)>500){
    paddle = true;
  }
  else{
    paddle = false;
  }
}



//------------------------------------------------------------Interpret Dits--------------------------------------

char current_input_structure[20] = {};
char current_interpreted_input[20] = {};


int check_dits()
{
  //Return Values: 0: Pause; 1: Dit; 2: Dah
  int output = 0;
  if(analogRead(dot)>500)
  {
    output = 1;
  }
  else if(analogRead(dash)>500)
  {
    output = 2;
  }
  return output;
}


bool check_long_Pause_letter()
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
    if(check_long_Pause_letter());
    {
      //New Letter
      interpret_Structure();
    }
  }
  else if(action == 1)
  { // Dit
    playTone(buzzer,440,current_dit_duration,current_volume_level);
    append_Structure('.');
    dit_pause_counter = 0;
  }
  else if(action == 2)
  { //Dah
    playTone(buzzer,440,current_dit_duration*3,current_volume_level);
    append_Structure('-');
    dit_pause_counter = 0;
  }
  delay(current_dit_duration);

}


void append_Structure(char toAppend) 
{
    int index = get_current_structure_lenght();
    if(index<20)
    {
      current_input_structure[index+1] = toAppend;
    }
    else
    { //Buffer Overflow
      clear_Structure();
      current_input_structure[0] = toAppend;
    }
}



void clear_Structure()
{
  for (int i = 0; i < 20; ++i) 
  {
    current_input_structure[i] = '\0';
  }
}



void show_Structure()
{
  int row = 1; 
  lcd_spreadStructure(current_input_structure,row);
}



const char* interpret_Structure()
{
  int lenght = get_current_structure_lenght();
  char structure[lenght + 1] = {};   // + \0 

  for(int i = 0; i <= lenght; i++)
  {
    structure[i] = current_input_structure[i];
  }

  Letter found_letter = check_if_Structure_is_Letter(structure);
  clear_Structure();

  return found_letter.name; //A,B,C,...
}




int get_current_structure_lenght()
{
  int index = 0; 
  while (current_input_structure[index] != '\0') 
  {
    index++;
  }
  return index;
}



Letter check_if_Structure_is_Letter(const char* structure)
{
  for(int letter = 0; letter < total_letters; letter++)
  {
    if(all_Letters[letter].structure == structure)
    {
      return all_Letters[letter];
    }
    else
    {
      return Letter("?","?","?",0);
    }
  }
}

void show_interpreted_Structure()
{
  write_to_lcd(interpret_Structure(),0,false);
}

//---------------------------------------------------------------------------


