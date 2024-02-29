#include "Parameters.h"


PinInfo::PinInfo(int pinNumber, const char* pinName, bool input, bool digital)
{
  this->pinNumber = pinNumber; 
  this->pinName = pinName; 
  this->input = input;
  this->digital = digital; 
};

PinInfo modus_1_Info(5, "modus_1", true, true);
PinInfo modus_2_Info(4, "modus_2", true, true);
PinInfo modus_3_Info(3, "modus_3", true, true);
PinInfo modus_4_Info(2, "modus_4", true, true);
PinInfo led_beat_Info(7, "led_beat", false, true);
PinInfo buzzer_Info(6, "buzzer", false, true);
PinInfo buzzer_old_Info(A7, "buzzer_old", false, false);
PinInfo lcd_sck_Info(13, "lcd_sck", false, true);
PinInfo lcd_sdi_Info(11, "lcd_sdi", false, true);
PinInfo lcd_cs_Info(10, "lcd_cs", false, true);
PinInfo lcd_reset_Info(9, "lcd_reset", false, true);
PinInfo lcd_dc_Info(8, "lcd_dc", false, true);
PinInfo speed_Info(A0, "speed", true, false);
PinInfo difficulty_Info(A1, "difficulty", true, false);
PinInfo volume_Info(A2, "volume", true, false);
PinInfo dot_Info(A4, "dot", true, false);
PinInfo dash_Info(A5, "dash", true, false);
PinInfo input_switch_Info(A3, "input_switch", true, false);

PinInfo Pins[] = {modus_1_Info, modus_2_Info, modus_3_Info, modus_4_Info, led_beat_Info,
                  buzzer_Info, buzzer_old_Info, lcd_sck_Info, lcd_sdi_Info, lcd_cs_Info,
                  lcd_reset_Info, lcd_dc_Info, speed_Info, difficulty_Info, volume_Info,
                  dot_Info, dash_Info, input_switch_Info};

int get_total_amount_of_used_Pins()
{
  int count = 0;
  for (const PinInfo& pinInfo : Pins)
  {
    if (pinInfo.pinNumber == 0 && pinInfo.pinName == 0 && pinInfo.input == false)
    {
      break;  // Stoppe die Iteration beim Pin mit Standardwerten
    }
    count++;
  }
  return count;
}

// Level von 1...5
int current_speed_level = 0;
int current_difficulty_level = 0;
int current_volume_level = 0;
float current_dit_duration;

bool mod1 = false;
bool mod2 = false;
bool mod3 = false;
bool mod4 = false;

bool paddle = false;

