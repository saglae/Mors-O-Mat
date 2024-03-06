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

Letter M_Question_Mark("..--..","Fragezeichen","?");
Letter M_Start("-.-.-","Spruchende","Start"); 
Letter M_End(".-.-.","Spruchanfang","Ende"); 
Letter M_Error("..........","Irrung","Irrung"); 
Letter M_Comma("--..--","Komma",","); 
Letter M_Seperate("-...-","Trennungszeichen","--"); 
Letter M_Point(".-.-.-","Punkt","."); 
Letter M_AE(".-.-","Ärger","Ä");  //Definitionen ausgedacht! 
Letter M_OE("---.","Öfen","Ö"); 
Letter M_UE("..--","Übel","Ü");

Letter all_Letters[] = {A_M, B_M, C_M, D_M, E_M, F_M, G_M, H_M, I_M, J_M, K_M, 
                        L_M, M_M, N_M, O_M, P_M, Q_M, R_M, S_M, T_M, U_M, V_M, 
                        W_M, X_M, Y_M, Z_M, 
                        M_1, M_2, M_3, M_4, M_5, M_6, M_7, M_8, M_9, M_0
                        M_Question_Mark, M_Start, M_End, M_Error, M_Comma, M_Seperate, M_Point, M_AE, M_OE, M_UE};

int total_letters = 46;

//Quellen: https://dj4uf.de/morsen 
//Quellen: https://www.marinecom.ch/e-learning/seefunk-alphabet/
//Quellen: https://www.codebug.org.uk/learn/step/540/morse-code-alphabet/


