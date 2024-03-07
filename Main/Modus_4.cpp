#include "Modus_4.h"




Q_Code::Q_Code(Letter abbreviation[4], const char* translation, const char* possible_answers[], int sum_answers)
{
    for (int i = 0; i < 4; i++) {
        this->abbreviation[i] = abbreviation[i];
    }
    this->translation = translation; 
    this->sum_answers = sum_answers;
    for(int i = 0; i < sum_answers; i++)
    {
      this->possible_answers[i] = possible_answers[i];
    }
    
};



Q_Code QAM({Q_M, A_M, M_M, M_Question_Mark}, "Wie ist der Wetterbericht?", {"SONNIG", "WOLKIG", "REGNERISCH"}, 3);
Q_Code QFE({Q_M, F_M, E_M, M_Question_Mark}, "Ihr gemessener Luftdruck am Boden an Ihrem Standort?", {"1013"}, 1);
Q_Code QNH({Q_M, N_M, H_M, M_Question_Mark}, "Ihr geschaetzter Druck auf Meereshoehe an Ihrem Standort?", {"1013"}, 1);
Q_Code QRA({Q_M, R_M, A_M, M_Question_Mark}, "Wie lautet der Name Ihrer Funkstelle?", {"ERDFUST", "WRFUST", "RETGERFUST"}, 3);  //Auf Logik prüfen
Q_Code QRB({Q_M, R_M, B_M, M_Question_Mark}, "In welcher Entfernung befinden Sie sich von mir?", {"100M", "1KM", "10KM"}, 3);
Q_Code QRG({Q_M, R_M, G_M, M_Question_Mark}, "Wie ist Ihre Frequenz?", {"10,1MH", "3,5MH", "50MH"}, 3);
Q_Code QRH({Q_M, R_M, H_M, M_Question_Mark}, "Schwankt meine Frequenz?", {"QRH", "C", "N"}, 3);
Q_Code QRI({Q_M, R_M, I_M, M_Question_Mark}, "Wie ist der Ton meiner Aussendung?", {"QRI1", "QRI3", "QRI5"}, 3);
Q_Code QRL({Q_M, R_M, L_M, M_Question_Mark}, "Sind Sie beschaeftigt?", {"QRL", "N", "GA"}, 3);
Q_Code QRM({Q_M, R_M, M_M, M_Question_Mark}, "Werden Sie durch andere Signale gestoert?", {"QRM1", "QRM3", "QRM5"}, 3); 
Q_Code QRN({Q_M, R_M, N_M, M_Question_Mark}, "Werden Sie ddurch atmosphräische Stoerungen beeinträchtigt?", {"QRN1", "QRN3", "QRN5"}, 3); 
Q_Code QRO({Q_M, R_M, O_M, M_Question_Mark}, "Soll ich die Sendeleistung erhoehen?", {"QRO", "N", "QRP"}, 3); 
Q_Code QRP({Q_M, R_M, P_M, M_Question_Mark}, "Soll ich die Sendeleistung verringern?", {"QRP", "N", "QRO"}, 3);
Q_Code QRQ({Q_M, R_M, Q_M, M_Question_Mark}, "Soll ich schneller geben?", {"QRQ", "QRS", "N"}, 3);
Q_Code QRS({Q_M, R_M, S_M, M_Question_Mark}, "Soll ich langsamer geben?", {"QRS", "QRQ", "N"}, 3);
Q_Code QRT({Q_M, R_M, T_M, M_Question_Mark}, "Soll ich die Uebermittlung einstellen?", {"QRT", "J", "99"}, 3);
Q_Code QRU({Q_M, R_M, U_M, M_Question_Mark}, "Haben Sie was fuer mich?", {"QRU", "NIX", "C"}, 3);
Q_Code QRV({Q_M, R_M, V_M, M_Question_Mark}, "Sind Sie bereit?", {"QRV", "AS", "GA"}, 3);
Q_Code QRZ({Q_M, R_M, Z_M, M_Question_Mark}, "Wer ruft mich?", {"DE DLOXXX"}, 1);
Q_Code QSB({Q_M, S_M, B_M, M_Question_Mark}, "Schwankt die Staerke meiner Zeichen?", {"QSB", "BD", "N"}, 3);
Q_Code QSD({Q_M, S_M, D_M, M_Question_Mark}, "Sind meine Zeichen verstuemmelt?", {"QSD", "BD", "N"}, 3); 
Q_Code QSK({Q_M, S_M, K_M, M_Question_Mark}, "Koennen Sie mich zwischen Ihren Zeichen hören? Darf ich sie unterbrechen?", {"QSK", "GA", "BK!"}, 3); 
Q_Code QSL({Q_M, S_M, L_M, M_Question_Mark}, "Koennen Sie den Empfang bestätigen?", {"QSL", "R", "RCVD"}, 3); 
Q_Code QSV({Q_M, S_M, V_M, M_Question_Mark}, "Soll ich eine Reihe Vs senden zum Abstimmen des Empfaengers?", {"QSV", "VVVVV"}, 2); 
Q_Code QSY({Q_M, S_M, Y_M, M_Question_Mark}, "Soll ich zum Senden auf eine andere Frequenz gehen?", {"QSY UP", "QSY UKW", "QSY RF"}, 3); 
Q_Code QTC({Q_M, T_M, C_M, M_Question_Mark}, "Wie viele Telegramme haben Sie?", {"QTC 1", "QTC VL", "QTC NIX"}, 3); 
Q_Code QTH({Q_M, T_M, H_M, M_Question_Mark}, "Wie ist Ihre Position?", {"QTH JN48", "QTH JN49", "QTH JN39"}, 3);     //QTH Locator: https://www.dl2fbo.de/locator-2/
Q_Code QTR({Q_M, T_M, R_M, M_Question_Mark}, "Welches ist die genaue Uhrzeit?", {"QTR 900", "QTR 1500", "QTR 1900"}, 3);  //Theoretisch implentierung mit RTC möglich --> Zu lernzwecken einfach 900, 1500, 1900


