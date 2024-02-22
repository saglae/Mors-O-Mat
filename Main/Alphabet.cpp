#include "Alphabet.h"
#include <Arduino.h>
#include "Parameters.h"

Letter::Letter(const char* structure, const char* definition)  //Konstruktor
{
    this->structure = structure; 
    this->definition = definition;
}

Letter A_M(".-","Alpha");
Letter B_M("-...","Bravo");
Letter C_M("-.-.","Charlie");
Letter D_M("-..","Delta");
Letter E_M(".","Echo");
Letter F_M("..-.","Foxtrott");
Letter G_M("--.","Golf");
Letter H_M("....","Hotel");
Letter I_M("..","India");
Letter J_M(".---","Juliett");
Letter K_M("-.-","Kilo");
Letter L_M(".-..","Lima");
Letter M_M("--","Mike");
Letter N_M("-.","November");
Letter O_M("---","Oscar");
Letter P_M(".--.","Papa");
Letter Q_M("--.-","Quebec");
Letter R_M(".-.","Romeo");
Letter S_M("...","Sierra");
Letter T_M("-","Tango");
Letter U_M("..-","Uniform");
Letter V_M("...-","Victor");
Letter W_M(".--","Whiskey");
Letter X_M("-..-","X-Ray");
Letter Y_M("-.--","Yankee");
Letter Z_M("--..","Zulu");

Letter M_1(".----","Eins");
Letter M_2("..---","Zwei");
Letter M_3("...--","Drei");
Letter M_4("....-","Vier");
Letter M_5(".....","Fünf");
Letter M_6("-....","Sechs");
Letter M_7("--...","Sieben");
Letter M_8("---..","Acht");
Letter M_9("----.","Neun");
Letter M_0("-----","Null");


//Quellen: https://www.marinecom.ch/e-learning/seefunk-alphabet/
//Quellen: https://www.codebug.org.uk/learn/step/540/morse-code-alphabet/


