#include "Modus_4.h"




Q_Code::Q_Code(Letter* abbreviation, const char* translation, const char* possible_answers[], int sum_answers)
{
    this->abbreviation = abbreviation; 
    this->translation = translation; 
    this->sum_answers = sum_answers;
    for(int i = 0; i< sum_answers; i++)
    {
      this->possible_answers[i] = possible_answers[i];
    }
    
};