#include "functions.h"

Point rtrn_cdnts(int X, int Y)
{
    for (int i = 0; i < 9; ++i)
        if (SQRS[i].LIM_I.X < X && X < SQRS[i].LIM_F.X && SQRS[i].LIM_I.Y < Y && Y < SQRS[i].LIM_F.Y)
            return SQRS[i].CDNTS;

    return ERROR;
}

bool grid_cntct(int X, int Y)
{
    if(X >= RCT_H1.x && Y >= RCT_H1.y && X <= RCT_H1.x + RCT_H1.w && Y <= RCT_H1.y + RCT_H1.h)
        return true;
    
    else if(X >= RCT_H2.x && Y >= RCT_H2.y && X <= RCT_H2.x + RCT_H2.w && Y <= RCT_H2.y + RCT_H2.h)
        return true;

    else if(X >= RCT_V1.x && Y >= RCT_V1.y && X <= RCT_V1.x + RCT_V1.w && Y <= RCT_V1.y + RCT_V1.h)
        return true;

    else if(X >= RCT_V2.x && Y >= RCT_V2.y && X <= RCT_V2.x + RCT_V2.w && Y <= RCT_V2.y + RCT_V2.h)
        return true;
    
    else
        return false;
}

//diz se há alguma figura preenchendo a area desjada
bool fig_eval(Point A)
{
    return BRD[A.X][A.Y] == 0? true: false;
}

//retorna o centro da area quadrada recebendo as corrdenadas do clique do mouse
Point rtrn_cntr(int X, int Y)
{
    for (int i = 0; i < 9; ++i)
        if (SQRS[i].LIM_I.X < X && X < SQRS[i].LIM_F.X && SQRS[i].LIM_I.Y < Y && Y < SQRS[i].LIM_F.Y)
            return SQRS[i].CNTR;
}

//verifica se todos os espaços estao preenchidos
bool all_done(void)
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(BRD[i][j] == 0)
                return false;
    
    return true;
}

//limpa o ma matriz tabuleiro
void clear_all(void)
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            BRD[i][j] = 0;
}

//faz alternancia entre jogadores 
int swp_p(int A)
{
   return (A == CRL? CRS: CRL);
}

//analisa todas as condiçoes de vitoria, retornando cross ou circle
int victory(void)
{
    if((BRD[0][0] == 1 && BRD[0][1] == 1 && BRD[0][2] == 1)|| (BRD[1][0] == 1 && BRD[1][1] == 1 && BRD[1][2] == 1) || (BRD[2][0] == 1 && BRD[2][1] == 1 && BRD[2][2] == 1))
    return 1;

    else if((BRD[0][0] == 1 && BRD[1][0] == 1 && BRD[2][0] == 1)|| (BRD[0][1] == 1 && BRD[1][1] == 1 && BRD[2][1] == 1) || (BRD[0][2] == 1 && BRD[1][2] == 1 && BRD[2][2] == 1))
    return 1;

    else if((BRD[0][0] == 1 && BRD[1][1] == 1 && BRD[2][2] == 1) || (BRD[0][2] == 1 && BRD[1][1] == 1 && BRD[2][0] == 1))
    return 1;

    else if((BRD[0][0] == 2 && BRD[0][1] == 2 && BRD[0][2] == 2)|| (BRD[1][0] == 2 && BRD[1][1] == 2 && BRD[1][2] == 2) || (BRD[2][0] == 2 && BRD[2][1] == 2 && BRD[2][2] == 2))
    return 2;

    else if((BRD[0][0] == 2 && BRD[1][0] == 2 && BRD[2][0] == 2)|| (BRD[0][1] == 2 && BRD[1][1] == 2 && BRD[2][1] == 2) || (BRD[0][2] == 2 && BRD[1][2] == 2 && BRD[2][2] == 2))
    return 2;

    else if((BRD[0][0] == 2 && BRD[1][1] == 2 && BRD[2][2] == 2) || (BRD[0][2] == 2 && BRD[1][1] == 2 && BRD[2][0] == 2))
    return 2;

    else
    return 0;
}   