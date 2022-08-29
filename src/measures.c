#include "measures.h"

bool DONE = false;

int const GLOBAL_SCR = 900;

int const SCR_L = GLOBAL_SCR, SCR_H = GLOBAL_SCR, OUT = GLOBAL_SCR/(GLOBAL_SCR/10), CRL = 2, CRS = 1;

const square_measures SQRS[9] = {{{0, 0}, {SCR_L/3, SCR_H/3}, {SCR_L/6, SCR_H/6}, {0, 0}},
                        {{SCR_L/3, 0}, {2*SCR_L/3, SCR_H/3}, {SCR_L/2, SCR_H/6}, {1, 0}},
                        {{2*SCR_L/3, 0}, {SCR_L, SCR_H/3}, {5*SCR_L/6, SCR_H/6}, {2, 0}},
                        {{0, SCR_H/3}, {SCR_L/3, 2*SCR_H/3}, {SCR_L/6, SCR_H/2}, {0, 1}},
                        {{SCR_L/3, SCR_H/3}, {2*SCR_L/3, 2*SCR_H/3}, {SCR_L/2, SCR_H/2}, {1, 1}},
                        {{2*SCR_L/3, SCR_H/3}, {SCR_L, 2*SCR_H/3}, {5*SCR_L/6, SCR_H/2}, {2, 1}},
                        {{0, 2*SCR_H/3}, {SCR_L/3, SCR_H}, {SCR_L/6, 5*SCR_H/6}, {0, 2}},
                        {{SCR_L/3, 2*SCR_H/3}, {2*SCR_L/3, SCR_H}, {SCR_L/2, 5*SCR_H/6}, {1, 2}},
                        {{2*SCR_L/3, 2*SCR_H/3}, {SCR_L, SCR_H}, {5*SCR_L/6, 5*SCR_H/6}, {2, 2}}};

int BRD[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int PLAYER = CRL;

const Point ERROR = {-1, -1};         
Point SQR_REF;  

const SDL_Rect RCT_H1 = {0, SCR_H/3 - OUT/2, SCR_L, OUT};
const SDL_Rect RCT_H2 = {0, 2*SCR_H/3 - OUT/2, SCR_L, OUT}; 
const SDL_Rect RCT_V1 = {SCR_L/3 - OUT/2, 0, OUT, SCR_H};
const SDL_Rect RCT_V2 = {2*SCR_L/3 - OUT/2, 0, OUT, SCR_H};

SDL_Rect OUT_CRL;
SDL_Rect INN_CRL;
    
SDL_Rect VER_LIN;
SDL_Rect HOR_LIN;