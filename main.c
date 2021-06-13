// Trabalho Pr�tico Programacao
// DEIS-ISEC 2020-2021
// Bruno Sousa - a2020132971@isec.pt
// DEIS-LEI


#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"
#include "textos.h"
#include "files.h"

#define MAX 30


int main()
{


    logo();

    while(1){
        /***************************************************/
        /*              DEFINICAO DE VARIAVEIS             */
        /***************************************************/
        int Running = 1;
        char escolha_menu='0';
        char N_jogador1='A';
        char N_jogador2='B';

        //files variabels
        char File_NameTxt[MAX];

        int interrupt = 0; //verificar se o jogo foi interrompido

        //Game variabless
        initRandom();
        int jogo_escolha=0;
        //estrutura dinamica para guardar o tabuleiro atual
        char **board;
        //guardar o estado das jogadas
        BoardS* root = NULL;
        //conta numero de jogadas para efeitos algaritmicos
        int IDjogada =0;
        int jogador = 1;
        int linhas = intUniformRnd(3,5);
        int colunas = linhas;
        int vitoria = 0; // analisa se alguem venceu
        int k_jogadas; // quantas jogadas o jogador deseja ver

        //variaveis limites
        int Limite_Pedra_A=1;
        int Limite_Pedra_B=1;
        int Limite_Coluna_Linha_A=2;
        int Limite_Coluna_Linha_B=2;

        //variaveis erro;
        int erro=0;

        //Ponteiro para o array dinamico que ira para o ficheiro .bin
        //SaveBinBoard *record = NULL;
        //total de tabuleiros armazenados
        //int total_tabs =0;

        /***************************************************/
        /*          FIM DA DEFINICAO DE VARIAVEIS          */
        /***************************************************/

        /***************************************************/
        /*                  MENU INCIAL                    */
        /***************************************************/

        //LOGO
        printf("\n\n\t\t\t\tMENU\n");
        printf("\n\t\t 1-Jogar Pessoa Contra Pessoa\n");
        printf("\n\t\t 2-Jogar Pessoa Contra Computador\n");
        printf("\n\t\t 3-Sair do Jogo\n");
        printf("\n\nOpcao: ");
        scanf(" %c",&escolha_menu);
        //Menu


        while(getchar()!='\n');

        /***************************************************/
        /*               FIM MENU INCIAL                   */
        /***************************************************/


        switch (escolha_menu) {
            case '1':  //Iniciar Jogo Pessoa x Pessoa



                /***************************************************/
                /*            NOVO JOGO PESSOA X PESSOA            */
                /***************************************************/


                    /**************************/
                    /* INICIALIZAR TABULEIRO  */
                    /*        DO JOGO         */
                    /**************************/
                //criar uma tabela com o numero de linhas e colunas iguais mas aleatorios.

                board=Cria_matriz_dinamica(board,linhas,colunas);


                //loop do jogo

                while (1) {
                    printf("\n");
                    draw_tabuleiro_inicial(board,linhas,colunas);
                    if (jogador==1)
                        jogo_escolha= menu_jogo(N_jogador1,Limite_Pedra_A,Limite_Coluna_Linha_A); //escolha jogador1
                    else
                        jogo_escolha= menu_jogo(N_jogador2,Limite_Pedra_B,Limite_Coluna_Linha_B); //escolha jogador2


                    //INSERIR PECA VERDE

                    if (jogo_escolha==1){
                        board=inserir_peca_celula_vazia(board,linhas,colunas,0); //0 is player 1 is bot
                        IDjogada ++;
                        if (jogador==1){
                            new_node_tabuleiro(&root,board,colunas,linhas,'G',N_jogador1,IDjogada); //atualizar lista ligada do tabuleiro

                            jogador++; //muda de jogador
                        }
                        else{
                            new_node_tabuleiro(&root,board,colunas,linhas,'G',N_jogador2,IDjogada);//atualizar lista ligada do tabuleiro
                            jogador--;//muda de jogador
                        }




                        //verificar se nenhum jogador venceu
                        vitoria = verifica_vitoria(board,colunas,linhas);
                        if (vitoria==1){
                            draw_tabuleiro_inicial(board,linhas,colunas); //desenhar o tabuleiro final antes de o loop ser interrompido
                            if (jogador==1)
                                printf("\n\nParabens Jogador A\n\n");
                            else
                                printf("\n\nParabens Jogador B\n\n");
                            break;
                        }



                    }
                      //INSERIR PECA VERDE FIM


                     //INSERIR PECA AMARELA

                    if (jogo_escolha==2){
                        board=troca_amarela_por_verde(board,linhas,colunas,0,&erro); //substituir peca verde por amarela
                        if (erro !=1){
                            IDjogada ++; //incrementar a jogada para controlar o numero de jogadas ao longo do jogo
                            if (jogador==1){
                                new_node_tabuleiro(&root,board,colunas,linhas,'Y',N_jogador1,IDjogada); //atualizar lista ligada do tabuleiro
                                jogador++; //mudar de jogador
                            }
                            else{
                                new_node_tabuleiro(&root,board,colunas,linhas,'Y',N_jogador2,IDjogada); //atualizar lista ligada do tabuleiro
                                jogador--;//mudar de jogador
                            }



                            vitoria = verifica_vitoria(board,colunas,linhas);
                            if (vitoria==1){
                                draw_tabuleiro_inicial(board,linhas,colunas);
                                if (jogador==1)
                                    printf("\n\nParabens Jogador A\n\n");
                                else
                                    printf("\n\nParabens Jogador B\n\n");
                                break;
                            }

                        }


                    }

                    ////INSERIR PECA VERMELHA

                    if (jogo_escolha==3)
                    {
                        board=trocar_vermelha_por_amarela(board,linhas,colunas,0,&erro);//Trocar peça amarela por peça vermelha
                        if (erro !=1) {
                            IDjogada ++;
                            if (jogador==1){
                                new_node_tabuleiro(&root,board,colunas,linhas,'R',N_jogador1,IDjogada);//atualizar lista ligada do tabuleiro
                                jogador++;
                            }
                            else{
                                new_node_tabuleiro(&root,board,colunas,linhas,'R',N_jogador2,IDjogada);//atualizar lista ligada do tabuleiro
                                jogador--;
                            }
                        }




                        vitoria = verifica_vitoria(board,colunas,linhas);
                        if (vitoria==1){
                            draw_tabuleiro_inicial(board,linhas,colunas);
                            if (jogador==1)
                                printf("\n\nParabens Jogador A\n\n");
                            else
                                printf("\n\nParabens Jogador B\n\n");
                            break;
                        }
                    }
                    //INSERIR PEDRA
                    if (jogo_escolha==4)
                    {

                        if (jogador==1){
                            if (Limite_Pedra_A !=0){ //Verificar por limites no jogador 1
                                board=inserir_pedra(board,linhas,colunas,0); //Inserir uma pedra no tabuleiro
                                IDjogada ++;
                                new_node_tabuleiro(&root,board,colunas,linhas,'P',N_jogador1,IDjogada);
                                jogador++;
                                Limite_Pedra_A--; //Decrementar o numero de jogadas possiveis com esta opcao
                            }
                            else{
                                printf("\nJogada Esgotada, tente novamente.\n\n");

                            }


                        }
                        else{
                            if (Limite_Pedra_B !=0){ //Verificar limite de jogada com o jogador B
                                board=inserir_pedra(board,linhas,colunas,0);
                                IDjogada ++;
                                new_node_tabuleiro(&root,board,colunas,linhas,'P',N_jogador2,IDjogada);
                                jogador--;
                                Limite_Pedra_B--;
                            }
                            else{
                                printf("\nJogada Esgotada, tente novamente.\n\n");

                            }

                        }



                    }


                        ;
                    if (jogo_escolha==5){
                        char a= Coluna_linha();
                        if (jogador==1 && Limite_Coluna_Linha_A!=0 || jogador ==2 &&Limite_Coluna_Linha_B!=0){


                            //aumentar linha
                            if (a=='L'){
                                //verificar se existem jogadas possiveis jogador A
                                if (jogador==1){

                                    board = Aumenta_Linha(board,&linhas,colunas);
                                    IDjogada ++;
                                    new_node_tabuleiro(&root,board,colunas,linhas,'L',N_jogador1,IDjogada);
                                    jogador++;
                                    Limite_Coluna_Linha_A--;



                                }
                                //verificar se existem jogadas possiveis jogador B
                                else{


                                    board = Aumenta_Linha(board,&linhas,colunas);
                                    IDjogada ++;
                                    new_node_tabuleiro(&root,board,colunas,linhas,'L',N_jogador2,IDjogada);
                                    jogador--;
                                    Limite_Coluna_Linha_B--;


                                }



                            }

                            else{

                                if (jogador==1){


                                    board = Aumenta_Coluna(board,linhas,&colunas);
                                    IDjogada ++;
                                    new_node_tabuleiro(&root,board,colunas,linhas,'C',N_jogador1,IDjogada);
                                    jogador++;
                                    Limite_Coluna_Linha_A--;


                                }
                                else{

                                    board = Aumenta_Coluna(board,linhas,&colunas);
                                    IDjogada ++;
                                    new_node_tabuleiro(&root,board,colunas,linhas,'C',N_jogador2,IDjogada);
                                    jogador--;
                                    Limite_Coluna_Linha_B--;

                                }
                            }
                        }
                        //Se as jogada nao for permitida
                        else
                            printf("\nJogada Esgotada, tente novamente.\n\n");

                    }
                    if (jogo_escolha==6){
                        if (IDjogada >0){
                            k_jogadas = Jogadas_Recuar();
                            mostrar_kjogadas(&root,k_jogadas,IDjogada);
                        }
                        else
                            printf("\nNenhuma jogada realizada!\n\n\n");

                    }

                    if (jogo_escolha==7){
                        interrupt = 1;
                        break;
                    }


                }



                    /**************************/
                    /*      FIM TABULEIRO     */
                    /*        DO JOGO         */
                    /**************************/

                if (vitoria==1) {
                    printf("\n\nInsira o nome do ficheiro onde quer guardar o jogo: ");
                    scanf(" %s", File_NameTxt);
                    write_data(File_NameTxt,&root);
                }
                if (interrupt==1){
                    //printf("\nJogo Guardado com Sucesso\n");
                    save_file(&root);
                    printf("\nJogo Guarda com Sucesso\n");
                }
                //libertar memoria usada no tabuleiro
               for (int i = 0; i < colunas;i++) {
                    free(board[i]);
                    }

                free(board);
                board = NULL;
                desalocacao(&root);
                break;
               /***************************************************/
               /*             FIM JOGO PESSOA X PESSOA            */
               /***************************************************/

               /***************************************************/
               /*             JOGO PESSOA X PROGRAMA              */
               /***************************************************/
            case '2': //Iniciar JOgo Pessoa x Computador


                    /**************************/
                    /* INICIALIZAR TABULEIRO  */
                    /*        DO JOGO         */
                    /**************************/
                //criar uma tabela com o numero de linhas e colunas iguais mas aleatorios.

                board=Cria_matriz_dinamica(board,linhas,colunas);


                //loop do jogo

                while (1) {
                    draw_tabuleiro_inicial(board,linhas,colunas);
                    printf("\n");
                    if (jogador==1) //jogador =1 significa humano
                        jogo_escolha= menu_jogo(N_jogador1,Limite_Pedra_A,Limite_Coluna_Linha_A);
                    else
                        jogo_escolha= intUniformRnd(1,5); //Se e a vez do bot escolher aleatoriamente entre os itens do menu


                    //INSERIR PECA VERDE

                    if (jogo_escolha==1){
                        //verificar se e jogador ou BOT
                        if (jogador==1){
                            board=inserir_peca_celula_vazia(board,linhas,colunas,0); //0 is player 1 is bot
                            IDjogada ++;
                            new_node_tabuleiro(&root,board,colunas,linhas,'G',N_jogador1,IDjogada);
                            jogador++;
                        }
                        else{
                            board=inserir_peca_celula_vazia(board,linhas,colunas,1); //0 is player 1 is bot
                            IDjogada ++;
                            new_node_tabuleiro(&root,board,colunas,linhas,'G',N_jogador2,IDjogada);
                            jogador--;
                        }



                        //verificar se houve vitoria ou nao

                        vitoria = verifica_vitoria(board,colunas,linhas);
                        if (vitoria==1){
                            draw_tabuleiro_inicial(board,linhas,colunas);
                              if (jogador==1)
                                    printf("\n\nParabens Jogador A\n\n");
                                else
                                    printf("\n\nParabens BOT\n\n");
                            break;
                        }



                    }
                      //INSERIR PECA VERDE FIM


                     //INSERIR PECA AMARELA

                    if (jogo_escolha==2){

                        if (jogador==1){
                            board=troca_amarela_por_verde(board,linhas,colunas,0,&erro);
                            if (erro!=1){
                                IDjogada ++;
                                new_node_tabuleiro(&root,board,colunas,linhas,'Y',N_jogador1,IDjogada);
                                jogador++;
                            }

                        }
                        else{
                            board=troca_amarela_por_verde(board,linhas,colunas,1,&erro);
                            if (erro!=1){
                                IDjogada ++;
                                new_node_tabuleiro(&root,board,colunas,linhas,'Y',N_jogador2,IDjogada);
                                jogador--;
                            }
                        }



                            vitoria = verifica_vitoria(board,colunas,linhas);
                            if (vitoria==1){
                                draw_tabuleiro_inicial(board,linhas,colunas);
                                if (jogador==1)
                                    printf("\n\nParabens Jogador A\n\n");
                                else
                                    printf("\n\nParabens BOT\n\n");
                                break;
                            }
                        }


                    //INSERIR PECA VERMELHA

                    if (jogo_escolha==3)
                    {

                        if (jogador==1){
                            board=trocar_vermelha_por_amarela(board,linhas,colunas,0,&erro);
                            if (erro!=1){
                                IDjogada ++;
                                new_node_tabuleiro(&root,board,colunas,linhas,'R',N_jogador1,IDjogada);
                                jogador++;
                            }

                        }
                        else{
                            board=trocar_vermelha_por_amarela(board,linhas,colunas,1,&erro);
                             if (erro!=1){
                                IDjogada ++;
                                new_node_tabuleiro(&root,board,colunas,linhas,'R',N_jogador2,IDjogada);
                                jogador--;
                             }


                        }



                        vitoria = verifica_vitoria(board,colunas,linhas);
                        if (vitoria==1){
                            draw_tabuleiro_inicial(board,linhas,colunas);
                            if (jogador==1)
                                printf("\n\nParabens Jogador A\n\n");
                            else
                                printf("\n\nParabens BOT\n\n");
                            break;
                        }
                    }
                    //FIM INSERIR PECA VERMELHA


                    //INSERIR PEDRA
                    if (jogo_escolha==4)
                    {

                        if (jogador==1){
                            if (Limite_Pedra_A !=0){
                                board=inserir_pedra(board,linhas,colunas,0);
                                IDjogada ++;
                                new_node_tabuleiro(&root,board,colunas,linhas,'P',N_jogador1,IDjogada);
                                jogador++;
                                Limite_Pedra_A--;
                            }
                            else{
                                printf("\nJogada Esgotada, tente novamente.\n\n");

                            }


                        }
                        else{
                            if (Limite_Pedra_B !=0){
                                board=inserir_pedra(board,linhas,colunas,1);
                                IDjogada ++;
                                new_node_tabuleiro(&root,board,colunas,linhas,'P',N_jogador2,IDjogada);
                                jogador--;
                                Limite_Pedra_B--;
                            }
                            else{
                                printf("\nJogada Esgotada, tente novamente.\n\n");

                            }

                        }



                    }
                    //



                    if (jogo_escolha==5){
                        char a;
                        int L_C;
                            //random linha ou coluna
                        if (jogador==1){
                            a= Coluna_linha();
                        }

                        else{
                            L_C = intUniformRnd(0,1);
                            if (L_C==0)
                                a ='L';
                            else
                                a = 'C';
                        }


                        //verificar se existem jogadas possiveis jogador
                        if (jogador==1 && Limite_Coluna_Linha_A!=0 || jogador ==2 &&Limite_Coluna_Linha_B!=0){


                            //aumentar linha
                            if (a=='L'){

                                if (jogador==1){

                                    board = Aumenta_Linha(board,&linhas,colunas);
                                    IDjogada ++;
                                    new_node_tabuleiro(&root,board,colunas,linhas,'L',N_jogador1,IDjogada);
                                    jogador++;
                                    Limite_Coluna_Linha_A--;



                                }
                                //verificar se existem jogadas possiveis jogador B
                                else{


                                    board = Aumenta_Linha(board,&linhas,colunas);
                                    IDjogada ++;
                                    new_node_tabuleiro(&root,board,colunas,linhas,'L',N_jogador2,IDjogada);
                                    jogador--;
                                    Limite_Coluna_Linha_B--;


                                }



                            }

                            else{

                                if (jogador==1){


                                    board = Aumenta_Coluna(board,linhas,&colunas);
                                    IDjogada ++;
                                    new_node_tabuleiro(&root,board,colunas,linhas,'C',N_jogador1,IDjogada);
                                    jogador++;
                                    Limite_Coluna_Linha_A--;


                                }
                                else{

                                    board = Aumenta_Coluna(board,linhas,&colunas);
                                    IDjogada ++;
                                    new_node_tabuleiro(&root,board,colunas,linhas,'C',N_jogador2,IDjogada);
                                    jogador--;
                                    Limite_Coluna_Linha_B--;

                                }
                            }
                        }
                        //Se as jogada nao for permitida
                        else
                            printf("\nJogada Esgotada, tente novamente.\n\n");

                    }
                    if (jogo_escolha==6){
                        if (IDjogada >0){
                            k_jogadas = Jogadas_Recuar();
                            mostrar_kjogadas(&root,k_jogadas,IDjogada);
                        }
                        else
                            printf("\nNenhuma jogada realizada!\n\n\n");

                    }

                    if (jogo_escolha==7){
                        interrupt=1;
                        break;
                    }


                }



                    /**************************/
                    /*      FIM TABULEIRO     */
                    /*        DO JOGO         */
                    /**************************/
                //se o jogo acabou perguntar nome de ficheiro para guardar todos as jogadas ao longo do jogo
                if (vitoria==1) {
                    printf("\n\nInsira o nome do ficheiro onde quer guardar o jogo: \n\n");
                    scanf(" %s", File_NameTxt);
                    write_data(File_NameTxt,&root);

                }
                //se o jogo foi interrompido guardar dados no ficheiro binario
                if (interrupt==1){
                    save_file(&root);
                    printf("\nJogo Guarda com Sucesso\n");
                }

                //libertar memoria usada no tabuleiro
               for (int i = 0; i < colunas;i++) {
                    free(board[i]);
                    }


                //libertar memoria lista ligada
                free(board);
                board = NULL;
                desalocacao(&root);
                break;




               /***************************************************/
               /*         FIM JOGO PESSOA X PROGRAMA              */
               /***************************************************/
            case '3': //Sair do Jogo
                Running=0;
                break;


            default:
                printf("Opcao Invalida!\n");
                break;
        }



        if (!Running) {
            break;
        }

    }

}





