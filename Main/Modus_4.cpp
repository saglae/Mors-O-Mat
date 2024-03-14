#include "Modus_4.h"

/*
Letter qam[4] = {Q_M, A_M, M_M, M_Question_Mark};
const char* qam_answers[3] = {"SONNIG", "WOLKIG", "REGNERISCH"};
const char qam_translation[] = "Wie ist der Wetterbericht?";
Q_Code QAM(qam, qam_translation , qam_answers);

// QFE
Letter qfe[4] = {Q_M, F_M, E_M, M_Question_Mark};
const char* qfe_answers[3] = {"1013", "1013", "1013"};
const char qfe_translation[] = "Ihr gemessener Luftdruck am Boden an Ihrem Standort?";
Q_Code QFE(qfe, qfe_translation, qfe_answers);

// QNH
Letter qnh[4] = {Q_M, N_M, H_M, M_Question_Mark};
const char* qnh_answers[3] = {"1013", "1013", "1013"};
const char qnh_translation[] = "Ihr geschaetzter Druck auf Meereshoehe an Ihrem Standort?";
Q_Code QNH(qnh, qnh_translation, qnh_answers);

// QRA
Letter qra[4] = {Q_M, R_M, A_M, M_Question_Mark};
const char* qra_answers[3] = {"ERDFUST", "WRFUST", "RETGERFUST"};
const char qra_translation[] = "Wie lautet der Name Ihrer Funkstelle?";
Q_Code QRA(qra, qra_translation, qra_answers);

// QRB
Letter qrb[4] = {Q_M, R_M, B_M, M_Question_Mark};
const char* qrb_answers[3] = {"100M", "1KM", "10KM"};
const char qrb_translation[] = "In welcher Entfernung befinden Sie sich von mir?";
Q_Code QRB(qrb, qrb_translation, qrb_answers);

// QRG
Letter qrg[4] = {Q_M, R_M, G_M, M_Question_Mark};
const char* qrg_answers[3] = {"10,1MH", "3,5MH", "50MH"};
const char qrg_translation[] = "Wie ist Ihre Frequenz?";
Q_Code QRG(qrg, qrg_translation, qrg_answers);

// QRH
Letter qrh[4] = {Q_M, R_M, H_M, M_Question_Mark};
const char* qrh_answers[3] = {"QRH", "C", "N"};
const char qrh_translation[] = "Schwankt meine Frequenz?";
Q_Code QRH(qrh, qrh_translation, qrh_answers);

// QRI
Letter qri[4] = {Q_M, R_M, I_M, M_Question_Mark};
const char* qri_answers[3] = {"QRI1", "QRI3", "QRI5"};
const char qri_translation[] = "Wie ist der Ton meiner Aussendung?";
Q_Code QRI(qri, qri_translation, qri_answers);

// QRL
Letter qrl[4] = {Q_M, R_M, L_M, M_Question_Mark};
const char* qrl_answers[3] = {"QRL", "N", "GA"};
const char qrl_translation[] = "Sind Sie beschaeftigt?";
Q_Code QRL(qrl, qrl_translation, qrl_answers);

// QRM
Letter qrm[4] = {Q_M, R_M, M_M, M_Question_Mark};
const char* qrm_answers[3] = {"QRM1", "QRM3", "QRM5"};
const char qrm_translation[] = "Werden Sie durch andere Signale gestoert?";
Q_Code QRM(qrm, qrm_translation, qrm_answers);

// QRN
Letter qrn[4] = {Q_M, R_M, N_M, M_Question_Mark};
const char* qrn_answers[3] = {"QRN1", "QRN3", "QRN5"};
const char qrn_translation[] = "Werden Sie durch atmosphärische Stoerungen beeinträchtigt?";
Q_Code QRN(qrn, qrn_translation, qrn_answers);

// QRO
Letter qro[4] = {Q_M, R_M, O_M, M_Question_Mark};
const char* qro_answers[3] = {"QRO", "N", "QRP"};
const char qro_translation[] = "Soll ich die Sendeleistung erhoehen?";
Q_Code QRO(qro, qro_translation, qro_answers);

// QRP
Letter qrp[4] = {Q_M, R_M, P_M, M_Question_Mark};
const char* qrp_answers[3] = {"QRP", "N", "QRO"};
const char qrp_translation[] = "Soll ich die Sendeleistung verringern?";
Q_Code QRP(qrp, qrp_translation, qrp_answers);

// QRQ
Letter qrq[4] = {Q_M, R_M, Q_M, M_Question_Mark};
const char* qrq_answers[3] = {"QRQ", "QRS", "N"};
const char qrq_translation[] = "Soll ich schneller geben?";
Q_Code QRQ(qrq, qrq_translation, qrq_answers);

// QRS
Letter qrs[4] = {Q_M, R_M, S_M, M_Question_Mark};
const char* qrs_answers[3] = {"QRS", "QRQ", "N"};
const char qrs_translation[] = "Soll ich langsamer geben?";
Q_Code QRS(qrs, qrs_translation, qrs_answers);

// QRT
Letter qrt[4] = {Q_M, R_M, T_M, M_Question_Mark};
const char* qrt_answers[3] = {"QRT", "J", "99"};
const char qrt_translation[] = "Soll ich die Uebermittlung einstellen?";
Q_Code QRT(qrt, qrt_translation, qrt_answers);

// QRU
Letter qru[4] = {Q_M, R_M, U_M, M_Question_Mark};
const char* qru_answers[3] = {"QRU", "NIX", "C"};
const char qru_translation[] = "Haben Sie was fuer mich?";
Q_Code QRU(qru, qru_translation, qru_answers);

// QRV
Letter qrv[4] = {Q_M, R_M, V_M, M_Question_Mark};
const char* qrv_answers[3] = {"QRV", "AS", "GA"};
const char qrv_translation[] = "Sind Sie bereit?";
Q_Code QRV(qrv, qrv_translation, qrv_answers);

// QRZ
Letter qrz[4] = {Q_M, R_M, Z_M, M_Question_Mark};
const char* qrz_answers[3] = {"DE DLOXXX", "DE DLOXXX", "DE DLOXXX"};
const char qrz_translation[] = "Wer ruft mich?";
Q_Code QRZ(qrz, qrz_translation, qrz_answers);


// QSB
Letter qsb[4] = {Q_M, S_M, B_M, M_Question_Mark};
const char* qsb_answers[3] = {"QSB", "BD", "N"};
const char qsb_translation[] = "Schwankt die Staerke meiner Zeichen?";
Q_Code QSB(qsb, qsb_translation, qsb_answers);

// QSD
Letter qsd[4] = {Q_M, S_M, D_M, M_Question_Mark};
const char* qsd_answers[3] = {"QSD", "BD", "N"};
const char qsd_translation[] = "Sind meine Zeichen verstuemmelt?";
Q_Code QSD(qsd, qsd_translation, qsd_answers);

// QSK
Letter qsk[4] = {Q_M, S_M, K_M, M_Question_Mark};
const char* qsk_answers[3] = {"QSK", "GA", "BK!"};
const char qsk_translation[] = "Koennen Sie mich zwischen Ihren Zeichen hören? Darf ich sie unterbrechen?";
Q_Code QSK(qsk, qsk_translation, qsk_answers);

// QSL
Letter qsl[4] = {Q_M, S_M, L_M, M_Question_Mark};
const char* qsl_answers[3] = {"QSL", "R", "RCVD"};
const char qsl_translation[] = "Koennen Sie den Empfang bestätigen?";
Q_Code QSL(qsl, qsl_translation, qsl_answers);

// QSV
Letter qsv[4] = {Q_M, S_M, V_M, M_Question_Mark};
const char* qsv_answers[3] = {"QSV", "VVVVV", "VVVVV"};
const char qsv_translation[] = "Soll ich eine Reihe Vs senden zum Abstimmen des Empfaengers?";
Q_Code QSV(qsv, qsv_translation, qsv_answers);

// QSY
Letter qsy[4] = {Q_M, S_M, Y_M, M_Question_Mark};
const char* qsy_answers[3] = {"QSY UP", "QSY UKW", "QSY RF"};
const char qsy_translation[] = "Soll ich zum Senden auf eine andere Frequenz gehen?";
Q_Code QSY(qsy, qsy_translation, qsy_answers);

// QTC
Letter qtc[4] = {Q_M, T_M, C_M, M_Question_Mark};
const char* qtc_answers[3] = {"QTC 1", "QTC VL", "QTC NIX"};
const char qtc_translation[] = "Wie viele Telegramme haben Sie?";
Q_Code QTC(qtc, qtc_translation, qtc_answers);

// QTH
Letter qth[4] = {Q_M, T_M, H_M, M_Question_Mark};
const char* qth_answers[3] = {"QTH JN48", "QTH JN49", "QTH JN39"};
const char qth_translation[] = "Wie ist Ihre Position?";
Q_Code QTH(qth, qth_translation, qth_answers);

// QTR
Letter qtr[4] = {Q_M, T_M, R_M, M_Question_Mark};
const char* qtr_answers[3] = {"QTR 900", "QTR 1500", "QTR 1900"};
const char qtr_translation[] = "Welches ist die genaue Uhrzeit?";
Q_Code QTR(qtr, qtr_translation, qtr_answers);

*/






/*
Q_Code QFE({Q_M, F_M, E_M, M_Question_Mark}, "Ihr gemessener Luftdruck am Boden an Ihrem Standort?", {"1013", "1013", "1013"});
Q_Code QNH({Q_M, N_M, H_M, M_Question_Mark}, "Ihr geschaetzter Druck auf Meereshoehe an Ihrem Standort?", {"1013", "1013", "1013"});
Q_Code QRA({Q_M, R_M, A_M, M_Question_Mark}, "Wie lautet der Name Ihrer Funkstelle?", {"ERDFUST", "WRFUST", "RETGERFUST"});  
Q_Code QRB({Q_M, R_M, B_M, M_Question_Mark}, "In welcher Entfernung befinden Sie sich von mir?", {"100M", "1KM", "10KM"});
Q_Code QRG({Q_M, R_M, G_M, M_Question_Mark}, "Wie ist Ihre Frequenz?", {"10,1MH", "3,5MH", "50MH"});
Q_Code QRH({Q_M, R_M, H_M, M_Question_Mark}, "Schwankt meine Frequenz?", {"QRH", "C", "N"});
Q_Code QRI({Q_M, R_M, I_M, M_Question_Mark}, "Wie ist der Ton meiner Aussendung?", {"QRI1", "QRI3", "QRI5"});
Q_Code QRL({Q_M, R_M, L_M, M_Question_Mark}, "Sind Sie beschaeftigt?", {"QRL", "N", "GA"});
Q_Code QRM({Q_M, R_M, M_M, M_Question_Mark}, "Werden Sie durch andere Signale gestoert?", {"QRM1", "QRM3", "QRM5"}); 
Q_Code QRN({Q_M, R_M, N_M, M_Question_Mark}, "Werden Sie durch atmosphräische Stoerungen beeinträchtigt?", {"QRN1", "QRN3", "QRN5"}); 
Q_Code QRO({Q_M, R_M, O_M, M_Question_Mark}, "Soll ich die Sendeleistung erhoehen?", {"QRO", "N", "QRP"}); 
Q_Code QRP({Q_M, R_M, P_M, M_Question_Mark}, "Soll ich die Sendeleistung verringern?", {"QRP", "N", "QRO"});
Q_Code QRQ({Q_M, R_M, Q_M, M_Question_Mark}, "Soll ich schneller geben?", {"QRQ", "QRS", "N"});
Q_Code QRS({Q_M, R_M, S_M, M_Question_Mark}, "Soll ich langsamer geben?", {"QRS", "QRQ", "N"});
Q_Code QRT({Q_M, R_M, T_M, M_Question_Mark}, "Soll ich die Uebermittlung einstellen?", {"QRT", "J", "99"});
Q_Code QRU({Q_M, R_M, U_M, M_Question_Mark}, "Haben Sie was fuer mich?", {"QRU", "NIX", "C"});
Q_Code QRV({Q_M, R_M, V_M, M_Question_Mark}, "Sind Sie bereit?", {"QRV", "AS", "GA"});
Q_Code QRZ({Q_M, R_M, Z_M, M_Question_Mark}, "Wer ruft mich?", {"DE DLOXXX", "DE DLOXXX", "DE DLOXXX"});
Q_Code QSB({Q_M, S_M, B_M, M_Question_Mark}, "Schwankt die Staerke meiner Zeichen?", {"QSB", "BD", "N"});
Q_Code QSD({Q_M, S_M, D_M, M_Question_Mark}, "Sind meine Zeichen verstuemmelt?", {"QSD", "BD", "N"}); 
Q_Code QSK({Q_M, S_M, K_M, M_Question_Mark}, "Koennen Sie mich zwischen Ihren Zeichen hören? Darf ich sie unterbrechen?", {"QSK", "GA", "BK!"}); 
Q_Code QSL({Q_M, S_M, L_M, M_Question_Mark}, "Koennen Sie den Empfang bestätigen?", {"QSL", "R", "RCVD"}); 
Q_Code QSV({Q_M, S_M, V_M, M_Question_Mark}, "Soll ich eine Reihe Vs senden zum Abstimmen des Empfaengers?", {"QSV", "VVVVV", "VVVVV"}); 
Q_Code QSY({Q_M, S_M, Y_M, M_Question_Mark}, "Soll ich zum Senden auf eine andere Frequenz gehen?", {"QSY UP", "QSY UKW", "QSY RF"}); 
Q_Code QTC({Q_M, T_M, C_M, M_Question_Mark}, "Wie viele Telegramme haben Sie?", {"QTC 1", "QTC VL", "QTC NIX"}); 
Q_Code QTH({Q_M, T_M, H_M, M_Question_Mark}, "Wie ist Ihre Position?", {"QTH JN48", "QTH JN49", "QTH JN39"});    
Q_Code QTR({Q_M, T_M, R_M, M_Question_Mark}, "Welches ist die genaue Uhrzeit?", {"QTR 900", "QTR 1500", "QTR 1900"});  
*/


