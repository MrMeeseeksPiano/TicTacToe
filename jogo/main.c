#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "measures.h"
#include "functions.h"
int main(void)
{
    
    //faz a inicializaçao correta da sdl, cria uma tela e um renderizador
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Nao foi possivel inicializar SDL: %s", SDL_GetError());
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Jogo da Velha", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCR_L, SCR_H, 0);

    if(window == NULL)
    {
        SDL_Log("Nao foi possivel inicializar janela: %s", SDL_GetError());
        return -2;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if(renderer == NULL)
    {
        SDL_Log("Nao foi possivel inicializar renderer: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        return -3;
    }

    while(!DONE)
    {   
        //declaraçao de eventos
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                //evento de fechamento do programa
                case SDL_QUIT: DONE = true; break;

                //evento de aperto de botao do mouse
                case SDL_MOUSEBUTTONDOWN:

                if(rtrn_cdnts(event.button.x, event.button.y).X == -1)
                    break;

                if(grid_cntct(event.button.x, event.button.y))
                    break;

                //caso todos as areas estejam preenchidas ou algum jogador tenha vencido
                if(all_done() || victory() != 0)
                {   
                    // limpa a tela com a cor preta e reseta a tabela da preencimento das areas
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                    SDL_RenderClear(renderer);

                    clear_all();

                    break;
                }

                //caso o botao apertado tenha sido o esquerdo e o espaço ainda nao esteja preenchido
                if(event.button.button == SDL_BUTTON_LEFT && fig_eval(rtrn_cdnts(event.button.x, event.button.y)))
                {   
                    //preenche o tabuleiro de anlise das areas pretas com o valor de circle ou cross
                    BRD[rtrn_cdnts(event.button.x, event.button.y).X][rtrn_cdnts(event.button.x, event.button.y).Y] = PLAYER;
                    SQR_REF = rtrn_cntr(event.button.x, event.button.y);
                    
                    //desenha o circle ou o cross 
                    switch(PLAYER)
                    {
                        case 2:
                        OUT_CRL.x = SQR_REF.X - SCR_H/9;
                        OUT_CRL.y = SQR_REF.Y - SCR_H/9;
                        OUT_CRL.w = 2*SCR_H/9;
                        OUT_CRL.h = 2*SCR_H/9;

                        INN_CRL.x = SQR_REF.X - SCR_H/10;
                        INN_CRL.y = SQR_REF.Y - SCR_H/10;
                        INN_CRL.w = SCR_H/5;
                        INN_CRL.h = SCR_H/5;


                        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                        SDL_RenderFillRect(renderer, &OUT_CRL);
                        SDL_RenderPresent(renderer);


                        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                        SDL_RenderFillRect(renderer, &INN_CRL);
                        SDL_RenderPresent(renderer);

                        break;

                        case 1:
                        VER_LIN.x = SQR_REF.X;
                        VER_LIN.y = SQR_REF.Y - SCR_H/9;
                        VER_LIN.w = SCR_H/90;
                        VER_LIN.h = 2*SCR_H/9;

                        HOR_LIN.x = SQR_REF.X - SCR_H/9;
                        HOR_LIN.y = SQR_REF.Y;
                        HOR_LIN.w = 2*SCR_H/9;
                        HOR_LIN.h = SCR_H/90;

                        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                        SDL_RenderFillRect(renderer, &VER_LIN);
                        SDL_RenderPresent(renderer);


                        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                        SDL_RenderFillRect(renderer, &HOR_LIN);
                        SDL_RenderPresent(renderer);
                        break;
                    }
                    
                    //faz a troca dos jogadores
                    PLAYER = swp_p(PLAYER);
                            
                    break;
                }

                break;
            }
        }

        //muda a cor do grid a depender da vitoria de um dos jogadores
        switch (victory())
        {
            case 1: 
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

            break;
                
            case 2:
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            break;
                
            default: 
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            break;
        }

        if(victory() == 0 && all_done())

            SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);

        //apresenta o grid
        SDL_RenderFillRect(renderer, &RCT_H1); //desenha o retangulo de fato 
        SDL_RenderFillRect(renderer, &RCT_H2);
        SDL_RenderFillRect(renderer, &RCT_V1);
        SDL_RenderFillRect(renderer, &RCT_V2);
        SDL_RenderPresent(renderer);

        SDL_Delay(5); 
        
    }

    //encerra corretamente o programa
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    atexit(SDL_Quit);
}
