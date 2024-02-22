#ifndef ALPHABET_H
#define ALPHABET_FUNCTIONS_H

#include <Arduino.h>
#include "Parameters.h"

class Letter 
{
  public: 
      Letter(const char* structure, const char* definition); //Konstruktor: Structure, Definition
      const char* structure;
      const char* definition;
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





#endif