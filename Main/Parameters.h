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


// Level von 1...5
extern int current_speed_level;
extern int current_difficulty_level;
extern int current_volume_level;
extern float current_dit_duration;
extern float old_dit_duration;

extern bool mod1;
extern bool mod2;
extern bool mod3;
extern bool mod4;

extern bool paddle;

#endif
