#include "Modus_2.h"


/*Letter words_difficulty_1[17][5] = {{E_M, S_M, N_M, O_M, M_5},      //5er Gruppen
                                {M_Error, T_M, Q_M, E_M, S_M},
                                {M_5, O_M, T_M, Q_M, E_M},
                                {S_M, N_M, O_M, M_Error, T_M},
                                {Q_M, M_5, S_M, E_M, O_M},
                                {N_M, M_Error, Q_M, T_M, M_5},
                                {E_M, S_M, N_M, O_M, M_Error},
                                {T_M, Q_M, M_5, E_M, S_M},
                                {O_M, M_Error, S_M, N_M, T_M},
                                {M_5, Q_M, T_M, E_M, O_M},   
                                {T_M, O_M, S_M, E_M, N_M},                //Wörter
                                {T_M, O_M, N_M, N_M, E_M},
                                {M_M, E_M, T_M, E_M, R_M},
                                {S_M, T_M, O_M, N_M, E_M},
                                {T_M, E_M, S_M, T_M, S_M},
                                {R_M, O_M, S_M, E_M, N_M},
                                {O_M, S_M, T_M, E_M, R_M}};

Letter words_difficulty_2[25][5] = {{M_Seperate, M_0, A_M, C_M, M_8},       //5er Gruppen
                                {R_M, U_M, M_9, D_M, L_M},
                                {C_M, D_M, M_9, M_0, L_M},
                                {U_M, M_Seperate, R_M, M_8, A_M},
                                {M_9, M_Seperate, C_M, D_M, M_0},
                                {E_M, M_5, S_M, M_Error, N_M},
                                {M_0, R_M, D_M, C_M, M_Seperate},
                                {U_M, M_9, L_M, M_Seperate, A_M},
                                {D_M, M_Seperate, M_8, U_M, A_M},
                                {M_9, C_M, L_M, D_M, M_Seperate},
                                {S_M, N_M, O_M, M_5, Q_M},
                                {A_M, M_0, U_M, M_9, M_8},
                                {L_M, M_8, C_M, M_Seperate, M_0},
                                {M_Seperate, M_9, A_M, U_M, M_8},
                                {R_M, L_M, M_0, U_M, M_Seperate},
                                {M_0, M_8, D_M, R_M, U_M},
                                {D_M, M_Seperate, A_M, U_M, M_9},
                                {C_M, L_M, M_0, M_Seperate, R_M},
                                {A_M, D_M, L_M, E_M, R_M},                //Wörter
                                {D_M, A_M, U_M, E_M, R_M},
                                {R_M, U_M, N_M, D_M, E_M},
                                {S_M, T_M, E_M, R_M, N_M},
                                {Q_M, U_M, A_M, L_M, E_M},
                                {N_M, A_M, D_M, E_M, L_M},
                                {N_M, O_M, T_M, E_M, N_M}};  

Letter words_difficulty_3[39][5] = {{X_M, M_7, M_Point, I_M, H_M},            //5er Gruppe
                                {M_M, M_1, M_6, M_4, Y_M},
                                {M_7, I_M, M_6, M_1, X_M},
                                {H_M, M_Point, Y_M, M_M, M_4},
                                {M_6, M_4, M_7, I_M, X_M},
                                {M_1, H_M, M_M, Y_M, M_Point},
                                {M_4, Y_M, X_M, I_M, M_Point},
                                {I_M, M_7, H_M, M_1, M_Point},
                                {Y_M, M_M, M_Point, M_6, X_M},
                                {M_1, I_M, M_7, H_M, M_6},
                                {X_M, M_7, M_Point, I_M, H_M},
                                {M_M, M_1, M_6, M_4, Y_M},
                                {M_7, I_M, M_6, M_1, X_M},
                                {H_M, M_Point, Y_M, M_M, M_4},
                                {M_6, M_4, M_7, I_M, X_M},
                                {M_1, H_M, M_M, Y_M, M_Point},
                                {M_4, Y_M, X_M, I_M, M_Point},
                                {I_M, M_7, H_M, M_1, M_Point},
                                {Y_M, M_M, M_Point, M_6, X_M},
                                {M_1, I_M, M_7, H_M, M_6},
                                {R_M, U_M, M_9, M_Seperate, C_M},
                                {D_M, L_M, M_0, A_M, M_8},
                                {M_Seperate, R_M, M_9, D_M, M_0},
                                {U_M, M_Seperate, R_M, M_8, A_M},
                                {M_9, M_Seperate, C_M, D_M, M_0},
                                {E_M, M_5, S_M, M_Error, N_M},
                                {M_0, R_M, D_M, C_M, M_Seperate},
                                {U_M, M_9, L_M, M_Seperate, A_M},
                                {D_M, M_Seperate, M_8, U_M, A_M},
                                {M_9, C_M, L_M, D_M, M_Seperate},         //Wörter
                                {U_M, N_M, T_M, E_M, R_M},                
                                {M_M, I_M, X_M, E_M, R_M},
                                {H_M, U_M, N_M, D_M, E_M},
                                {Q_M, U_M, A_M, L_M, M_M},
                                {C_M, R_M, E_M, D_M, O_M},
                                {R_M, E_M, N_M, T_M, E_M},
                                {M_M, O_M, R_M, A_M, L_M},                
                                {A_M, U_M, D_M, I_M, O_M},
                                {A_M, R_M, M_M, U_M, T_M}};


Letter words_difficulty_4[44][5] = {{G_M, M_3, M_Question_Mark, M_2, J_M},    //5er Gruppen
                                  {M_2, G_M, M_Comma, M_Question_Mark, J_M},
                                  {M_Comma, G_M, M_3, J_M, V_M},
                                  {V_M, K_M, M_3, M_Question_Mark, J_M},
                                  {M_Question_Mark, M_2, J_M, G_M, V_M},
                                  {X_M, M_7, M_Point, J_M, M_Error},
                                  {Y_M, M_1, M_6, M_M, M_4},
                                  {M_9, H_M, C_M, M_2, M_8},
                                  {L_M, M_0, I_M, M_7, M_2},
                                  {D_M, M_1, M_8, M_7, M_Comma},
                                  {M_8, Q_M, T_M, Y_M, M_5},
                                  {V_M, I_M, M_Point, N_M, A_M},
                                  {M_Error, E_M, M_Question_Mark, R_M, S_M},
                                  {M_6, N_M, H_M, M_0, U_M},
                                  {O_M, I_M, M_9, S_M, M_Seperate},
                                  {T_M, M_1, M_4, M_Question_Mark, C_M},
                                  {M_M, U_M, M_3, M_4, M_1},
                                  {O_M, D_M, M_8, I_M, M_7},
                                  {S_M, M_6, C_M, M_2, M_Seperate},
                                  {A_M, M_5, M_Point, M_Error, M_Question_Mark},
                                  {M_4, M_Seperate, X_M, M_Error, E_M},
                                  {M_0, M_3, S_M, M_5, M_8},
                                  {M_Point, Y_M, M_9, H_M, M_Comma},
                                  {Q_M, M_Seperate, M_Point, M_6, M_4},
                                  {M_2, U_M, M_8, M_3, M_9},
                                  {M_0, M_Seperate, M_Question_Mark, M_5, M_Error},
                                  {M_M, H_M, Q_M, M_2, M_Seperate},
                                  {M_Point, G_M, S_M, M_6, M_4},
                                  {M_1, M_9, M_Comma, M_3, X_M},
                                  {M_8, L_M, M_7, Y_M, M_6},
                                  {A_M, M_2, E_M, M_1, M_9},
                                  {M_4, O_M, M_7, M_M, M_Error},
                                  {M_Seperate, M_Point, M_5, M_Question_Mark, U_M},
                                  {R_M, N_M, T_M, M_3, D_M},
                                  {M_Error, M_8, I_M, M_6, T_M},
                                  {J_M, U_M, N_M, G_M, E_M},          //Wörter               
                                  {K_M, R_M, O_M, N_M, E_M},
                                  {R_M, U_M, H_M, I_M, G_M},
                                  {V_M, O_M, G_M, E_M, L_M},
                                  {K_M, A_M, L_M, L_M, E_M},
                                  {L_M, E_M, S_M, E_M, N_M},
                                  {M_M, O_M, R_M, A_M, L_M},                
                                  {A_M, U_M, D_M, I_M, O_M},
                                  {A_M, R_M, M_M, U_M, T_M}};

Letter words_difficulty_5[64][5] = {{Z_M, F_M, B_M, P_M, W_M},                //5er Gruppen
                                  {M_Bruchstrich, M_AE, M_OE, M_UE, Z_M},
                                  {P_M, W_M, M_Bruchstrich, M_AE, M_OE},
                                  {B_M, P_M, W_M, M_Bruchstrich, M_AE},
                                  {M_OE, M_UE, Z_M, F_M, B_M},
                                  {M_AE, M_UE, M_OE, M_Bruchstrich, W_M},
                                  {B_M, Z_M, F_M, M_Bruchstrich, P_M},
                                  {M_UE, W_M, P_M, M_OE, Z_M},
                                  {Z_M, M_Bruchstrich, M_OE, M_UE, B_M},
                                  {F_M, P_M, M_OE, Z_M, M_Bruchstrich},
                                  {E_M, S_M, N_M, O_M, M_5},
                                  {M_Error, T_M, Q_M, E_M, S_M},
                                  {M_5, O_M, T_M, Q_M, E_M},
                                  {S_M, N_M, O_M, M_Error, T_M},
                                  {Q_M, M_5, S_M, E_M, O_M},
                                  {N_M, M_Error, Q_M, T_M, M_5},
                                  {E_M, S_M, N_M, O_M, M_Error},
                                  {T_M, Q_M, M_5, E_M, S_M},
                                  {O_M, M_Error, S_M, N_M, T_M},
                                  {M_5, Q_M, T_M, E_M, O_M},
                                  {I_M, X_M, M_4, M_Point, M_M},
                                  {M_7, Y_M, M_1, H_M, M_6},
                                  {R_M, U_M, M_9, M_Seperate, C_M},
                                  {D_M, M_0, A_M, L_M, M_8},
                                  {G_M, M_2, V_M, K_M, M_Comma},
                                  {E_M, S_M, N_M, O_M, M_5},
                                  {M_Error, T_M, Q_M, E_M, S_M},
                                  {M_5, O_M, T_M, Q_M, E_M},
                                  {S_M, N_M, O_M, M_Error, T_M},
                                  {Q_M, M_5, S_M, E_M, O_M},
                                  {N_M, M_Error, Q_M, T_M, M_5},
                                  {E_M, S_M, N_M, O_M, M_Error},
                                  {T_M, Q_M, M_5, E_M, S_M},
                                  {O_M, M_Error, S_M, N_M, T_M},
                                  {M_5, Q_M, T_M, E_M, O_M},
                                  {Z_M, F_M, B_M, P_M, W_M},
                                  {M_Bruchstrich, M_AE, M_OE, M_UE, Z_M},
                                  {F_M, B_M, P_M, W_M, M_Bruchstrich},
                                  {M_AE, M_OE, M_UE, Z_M, F_M},
                                  {B_M, P_M, W_M, M_Bruchstrich, M_AE},
                                  {M_OE, M_UE, Z_M, F_M, B_M},
                                  {P_M, W_M, M_Bruchstrich, M_AE, M_OE},
                                  {M_UE, Z_M, F_M, B_M, P_M},
                                  {W_M, M_Bruchstrich, M_AE, M_OE, M_UE},
                                  {Z_M, F_M, B_M, P_M, W_M},
                                  {M_Bruchstrich, M_AE, M_OE, M_UE, Z_M},
                                  {F_M, B_M, P_M, W_M, M_Bruchstrich},
                                  {M_AE, M_OE, M_UE, Z_M, F_M},         //Wörter
                                  {H_M, A_M, F_M, E_M, N_M},
                                  {L_M, A_M, M_M, P_M, E_M},
                                  {B_M, M_AE, U_M, M_M, E_M},
                                  {K_M, A_M, R_M, T_M, E_M},
                                  {Z_M, E_M, B_M, R_M, A_M},
                                  {F_M, L_M, U_M, S_M, S_M},                
                                  {A_M, P_M, F_M, E_M, L_M},
                                  {G_M, R_M, M_UE, N_M, E_M},
                                  {M_M, M_OE, B_M, E_M, L_M},
                                  {Q_M, U_M, A_M, R_M, K_M},
                                  {V_M, A_M, T_M, E_M, R_M},
                                  {B_M, L_M, U_M, M_M, E_M},
                                  {L_M, M_UE, G_M, E_M, N_M},
                                  {S_M, M_UE, D_M, E_M, N_M},                
                                  {M_AE, P_M, F_M, E_M, L_M},
                                  {F_M, L_M, U_M, S_M, S_M}};
*/

/*
void play_Word(int difficulty, int word_nr)
{
  //Probleme da Difficulty Arrays unterschiedliche Dimensionen haben. --> Workaround!
  if(difficulty == 1)
  {
    for (int i = 0; i < 5; i++)
    {
        playLetter(words_difficulty_1[word_nr][i]);
    }
  };

  if(difficulty == 2)
  {
    for (int i = 0; i < 5; i++)
    {
        playLetter(words_difficulty_2[word_nr][i]);
    }
  };

  if(difficulty == 3)
  {
    for (int i = 0; i < 5; i++)
    {
        playLetter(words_difficulty_3[word_nr][i]);
    }
  }; 

  if(difficulty == 4)
  {
    for (int i = 0; i < 5; i++)
    {
        playLetter(words_difficulty_4[word_nr][i]);
    }
  };
  
  if(difficulty == 5)
  {
    for (int i = 0; i < 5; i++)
    {
        playLetter(words_difficulty_5[word_nr][i]);
    }
  };
  
  
  
  delay(current_dit_duration*4); //playLetter verzögert automatisch um 3 dits nach jedem Buchstaben!
}

*/



