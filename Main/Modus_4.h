#ifndef MODUS_4
#define MODUS_4


#include "Parameters.h"
#include "Alphabet.h"
#include "Display_Functions.h"
#include "Buzzer_Functions.h"
#include "Input.h"



/*
Beschreibung des Lernmodus: 
Hier soll der Q-Schlüssel bzw gängige Abkürzungen geübt werden. 
Der Mors-O-Mat gibt wie in Modus 2 Wörter/Abkürzungen aus, auf die der Nutzer dann mit einer passenden Antwort (es gibt mehrere Optionen!) antworten kann wie in Modus 3. 

Hier ist ein unterschiedlicher Schwierigkeitsgrad meiner Meinung nach nicht sinnvoll.

*/

class Q_Code
{
  public: 
  Q_Code(Letter abbreviation[4], const char* translation, const char* possible_answers[], int sum_answers);
  Letter abbreviation[4]; 
  const char* translation; 
  const char* possible_answers[3];
  int sum_answers;
};

extern Q_Code QAM;
extern Q_Code QFE;
extern Q_Code QNH;
extern Q_Code QRA;
extern Q_Code QRB;
extern Q_Code QRG; 
extern Q_Code QRH;
extern Q_Code QRI;
extern Q_Code QRL; 
extern Q_Code QRM; 
extern Q_Code QRN; 
extern Q_Code QRO; 
extern Q_Code QRP;
extern Q_Code QRQ;
extern Q_Code QRS;
extern Q_Code QRT;
extern Q_Code QRU;
extern Q_Code QRV;
extern Q_Code QRZ;
extern Q_Code QSB;
extern Q_Code QSD; 
extern Q_Code QSK; 
extern Q_Code QSL; 
extern Q_Code QSV; 
extern Q_Code QSY; 
extern Q_Code QTC; 
extern Q_Code QTH; 
extern Q_Code QTR; 





#endif