#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <Arduino.h>



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

#define dot A4
#define dash A5
#define input_switch A3

class PinInfo
{
  public:
    PinInfo(int pinNumber, const char* pinName, bool input, bool digital);
    int pinNumber = 0;
    const char* pinName; 
    bool input = false;
    bool digital = false;
};

extern PinInfo modus_1_Info;
extern PinInfo modus_2_Info;
extern PinInfo modus_3_Info;
extern PinInfo modus_4_Info;
extern PinInfo led_beat_Info;
extern PinInfo buzzer_Info;
extern PinInfo buzzer_old_Info;
extern PinInfo lcd_sck_Info;
extern PinInfo lcd_sdi_Info;
extern PinInfo lcd_cs_Info;  
extern PinInfo lcd_reset_Info;
extern PinInfo lcd_dc_Info;
extern PinInfo speed_Info;
extern PinInfo difficulty_Info;
extern PinInfo volume_Info;
extern PinInfo dot_Info;
extern PinInfo dash_Info;
extern PinInfo input_switch_Info;

extern PinInfo Pins[];

int get_total_amount_of_used_Pins();

// Level von 1...5
extern int current_speed_level;
extern int current_difficulty_level;
extern int current_volume_level;
extern float current_dit_duration;

extern bool mod1;
extern bool mod2;
extern bool mod3;
extern bool mod4;

extern bool paddle;

#endif
