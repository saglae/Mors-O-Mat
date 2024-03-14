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
Letter M_5(".....","Fuenf","5",1);
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
Letter M_AE(".-.-","Aerger","AE",5);  //Definitionen ausgedacht! 
Letter M_OE("---.","Oefen","OE",5); 
Letter M_UE("..--","Uebel","UE",5);
Letter M_Bruchstrich("-..-.","Bruchstrich","/",5);



Letter all_Letters[] = {E_M, S_M, N_M, O_M, M_Start, M_End, M_Error, T_M, Q_M, M_5,   //10
                        R_M, U_M, M_9, M_Seperate, C_M, D_M, M_0, A_M, L_M, M_8,      //10
                        I_M, X_M, M_4, M_Point, M_M, M_7, Y_M, M_1, H_M, M_6,         //10
                        M_Question_Mark, J_M, M_3, G_M, M_2, V_M, K_M, M_Comma,       //8
                        Z_M, F_M, B_M, P_M, W_M, M_Bruchstrich, M_AE, M_OE, M_UE};    //9


int total_letters = 47;

//Quellen: https://dj4uf.de/morsen 
//Quellen: https://www.marinecom.ch/e-learning/seefunk-alphabet/
//Quellen: https://www.codebug.org.uk/learn/step/540/morse-code-alphabet/

/*
Moltrecht-Lehrgang: https://dj4uf.de/morsen

1. Lektion: e,s,n,o, Start, Stop, Irrung
2. Lektion: t,q,5

3. Lektion: r,u,9
4. Lektion: Trennungszeichen "--", vorwiegend Wiederholung
5. Lektion: c,d,0
6. Lektion: a,l,8

7. Lektion: i,x,4
8. Lektion: ., vorwiegend Wiederholung
9. Lektion: m,7
10. Lektion: y,1
11. Lektion: h,6

12. Lektion: ?, vorwiegend Wiederholung
13. Lektion: j,3
14. Lektion: g,2
15. Lektion: v,k
16. Lektion: , ,vorwiegend Wiederholung

17. Lektion: z,f
18. Lektion: b,p
19. Lektion: w, /
20. Lektion: ä,ö,ü

Danach nurnoch auf Geschwindigkeit...
*/

