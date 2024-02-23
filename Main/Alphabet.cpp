#include "Alphabet.h"
#include <Arduino.h>
#include "Parameters.h"

Letter::Letter(const char* structure, const char* definition, const char* name)  //Konstruktor
{
    this->structure = structure; 
    this->definition = definition;
    this->name = name;
}

//Instanzen der Klasse

Letter A_M(".-","Alpha","A");
Letter B_M("-...","Bravo","B");
Letter C_M("-.-.","Charlie","C");
Letter D_M("-..","Delta","D");
Letter E_M(".","Echo","E");
Letter F_M("..-.","Foxtrott","F");
Letter G_M("--.","Golf","G");
Letter H_M("....","Hotel","H");
Letter I_M("..","India","I");
Letter J_M(".---","Juliett","J");
Letter K_M("-.-","Kilo","K");
Letter L_M(".-..","Lima","L");
Letter M_M("--","Mike","M");
Letter N_M("-.","November","N");
Letter O_M("---","Oscar","O");
Letter P_M(".--.","Papa","P");
Letter Q_M("--.-","Quebec","Q");
Letter R_M(".-.","Romeo","R");
Letter S_M("...","Sierra","S");
Letter T_M("-","Tango","T");
Letter U_M("..-","Uniform","U");
Letter V_M("...-","Victor","V");
Letter W_M(".--","Whiskey","W");
Letter X_M("-..-","X-Ray","X");
Letter Y_M("-.--","Yankee","Y");
Letter Z_M("--..","Zulu","Z");

Letter M_1(".----","Eins","1");
Letter M_2("..---","Zwei","2");
Letter M_3("...--","Drei","3");
Letter M_4("....-","Vier","4");
Letter M_5(".....","Fünf","5");
Letter M_6("-....","Sechs","6");
Letter M_7("--...","Sieben","7");
Letter M_8("---..","Acht","8");
Letter M_9("----.","Neun","9");
Letter M_0("-----","Null","0");


//Quellen: https://www.marinecom.ch/e-learning/seefunk-alphabet/
//Quellen: https://www.codebug.org.uk/learn/step/540/morse-code-alphabet/


