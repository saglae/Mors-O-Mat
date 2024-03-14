#include "Alphabet.h"
#include <Arduino.h>
#include "Parameters.h"

Letter::Letter(const char* structure, const char* definition, const char* name, int difficulty)  //Konstruktor
{
    this->structure = structure; 
    this->definition = definition;
    this->name = name;
    this->difficulty = difficulty;
}



//Instanzen der Klasse

Letter A_M(".-","Alpha","A",2);
Letter B_M("-...","Bravo","B",5);
Letter C_M("-.-.","Charlie","C",2);
Letter D_M("-..","Delta","D",2);
Letter E_M(".","Echo","E",1);
Letter F_M("..-.","Foxtrott","F",5);
Letter G_M("--.","Golf","G",4);
Letter H_M("....","Hotel","H",3);
Letter I_M("..","India","I",3);
Letter J_M(".---","Juliett","J",4);
Letter K_M("-.-","Kilo","K",4);
Letter L_M(".-..","Lima","L",2);
Letter M_M("--","Mike","M",3);
Letter N_M("-.","November","N",1);
Letter O_M("---","Oscar","O",1);
Letter P_M(".--.","Papa","P",5);
Letter Q_M("--.-","Quebec","Q",1);
Letter R_M(".-.","Romeo","R",2);
Letter S_M("...","Sierra","S",1);
Letter T_M("-","Tango","T",1);
Letter U_M("..-","Uniform","U",2);
Letter V_M("...-","Victor","V",4);
Letter W_M(".--","Whiskey","W",5);
Letter X_M("-..-","X-Ray","X",3);
Letter Y_M("-.--","Yankee","Y",3);
Letter Z_M("--..","Zulu","Z",5);

Letter M_1(".----","Eins","1",3);
Letter M_2("..---","Zwei","2",4);
Letter M_3("...--","Drei","3",4);
Letter M_4("....-","Vier","4",3);
Letter M_5(".....","Fünf","5",1);
Letter M_6("-....","Sechs","6",3);
Letter M_7("--...","Sieben","7",3);
Letter M_8("---..","Acht","8",2);
Letter M_9("----.","Neun","9",2);
Letter M_0("-----","Null","0",2);

Letter M_Question_Mark("..--..","Fragezeichen","?",4);
Letter M_Start("-.-.-","Spruchende","Start",1); 
Letter M_End(".-.-.","Spruchanfang","Ende",1); 
Letter M_Error("..........","Irrung","Irrung",1); 
Letter M_Comma("--..--","Komma",",",4); 
Letter M_Seperate("-...-","Trennungszeichen","--",2); 
Letter M_Point(".-.-.-","Punkt",".",3); 
Letter M_AE(".-.-","Ärger","Ä",5);  //Definitionen ausgedacht! 
Letter M_OE("---.","Öfen","Ö",5); 
Letter M_UE("..--","Übel","Ü",5);
Letter M_Bruchstrich("-..-.","Bruchstrich","/",5);


Letter all_Letters[] = {A_M, B_M, C_M, D_M, E_M, F_M, G_M, H_M, I_M, J_M, K_M, 
                        L_M, M_M, N_M, O_M, P_M, Q_M, R_M, S_M, T_M, U_M, V_M, 
                        W_M, X_M, Y_M, Z_M, 
                        M_1, M_2, M_3, M_4, M_5, M_6, M_7, M_8, M_9, M_0,
                        M_Question_Mark, M_Start, M_End, M_Error, M_Comma, M_Seperate, M_Point, M_AE, M_OE, M_UE, M_Bruchstrich};

int total_letters = 47;

//Quellen: https://dj4uf.de/morsen 
//Quellen: https://www.marinecom.ch/e-learning/seefunk-alphabet/
//Quellen: https://www.codebug.org.uk/learn/step/540/morse-code-alphabet/


