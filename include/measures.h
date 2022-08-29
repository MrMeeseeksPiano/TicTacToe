#ifndef MEASURES_H
#define MEASURES_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct _point_
{
    int X, Y;
}Point;

typedef struct square_measures_
{
    Point LIM_I, LIM_F, CNTR, CDNTS; 

}square_measures;

extern bool DONE;

extern int const GLOBAL_SCR;

extern int const SCR_L, SCR_H, OUT, CRL, CRS;

extern const square_measures SQRS[9];

extern int BRD[3][3];
extern int PLAYER;

extern const Point ERROR;
extern Point SQR_REF;

extern const SDL_Rect RCT_H1;
extern const SDL_Rect RCT_H2;
extern const SDL_Rect RCT_V1;
extern const SDL_Rect RCT_V2;

extern SDL_Rect OUT_CRL;
extern SDL_Rect INN_CRL;
    
extern SDL_Rect VER_LIN;
extern SDL_Rect HOR_LIN;

#endif
