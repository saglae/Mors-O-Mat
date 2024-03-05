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
  Q_Code(Letter* abbreviation, const char* translation, const char* possible_answers[], int sum_answers);
  Letter* abbreviation; 
  const char* translation; 
  const char* possible_answers[3];
  int sum_answers;
};




#endif