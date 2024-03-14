#ifndef ALPHABET_H
#define ALPHABET_H

#include <Arduino.h>
#include "Parameters.h"

class Letter 
{
  public: 
      Letter () {};
      Letter(const char* structure, const char* definition, const char* name); //Konstruktor: Structure, Definition
      const char* structure;
      const char* definition;
      const char* name;
};

extern Letter A_M;
extern Letter B_M;
extern Letter C_M;
extern Letter D_M;
extern Letter E_M;
extern Letter F_M;
extern Letter G_M;
extern Letter H_M;
extern Letter I_M;
extern Letter J_M;
extern Letter K_M;
extern Letter L_M;
extern Letter M_M;
extern Letter N_M;
extern Letter O_M;
extern Letter P_M;
extern Letter Q_M;
extern Letter R_M;
extern Letter S_M;
extern Letter T_M;
extern Letter U_M;
extern Letter V_M;
extern Letter W_M;
extern Letter X_M;
extern Letter Y_M;
extern Letter Z_M;

extern Letter M_1;
extern Letter M_2;
extern Letter M_3;
extern Letter M_4;
extern Letter M_5;
extern Letter M_6;
extern Letter M_7;
extern Letter M_8;
extern Letter M_9;
extern Letter M_0;

extern Letter M_Question_Mark;
extern Letter M_Start; 
extern Letter M_End; 
extern Letter M_Error; 
extern Letter M_Comma; 
extern Letter M_Seperate; 
extern Letter M_Point; 
extern Letter M_AE; 
extern Letter M_OE; 
extern Letter M_UE;
extern Letter M_Bruchstrich;



extern Letter all_Letters[];
extern int total_letters;


#endif