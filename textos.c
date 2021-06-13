//Trabalho Prático Programacao
//Jogo do Semaforo
//Bruno Amado Sousa a2020132971@isec.pt
//DEIS-LEI


#include <ctype.h>
#include "textos.h"
#include <stdio.h>

void logo(){

    printf("\t\t############  #########   ##########  ##########\n");
    printf("\t\t     ###      ##          ##          ##        \n");
    printf("\t\t     ###      #########   ##########  ##        \n");
    printf("\t\t     ###             ##   ##          ##        \n");
    printf("\t\t############  #########   ##########  ##########\n");
}


int menu_jogo(char jogador,int Limite_Pedra,int Limite_Linha_Coluna) {
    int jogo_escolha;

    printf("\nO que o jogador %c deseja fazer?  \n",jogador);
    printf("\n1-Colocar uma peca Verde(G) numa celula vazia.\n");
    printf("2-Trocar uma peca Verde que esteja colocada no tabuleiro por uma peca Amarela.\n");
    printf("3-Trocar uma peca Amarela que esteja colocada no tabuleiro por uma peca Vermelha.\n");
    printf("4-Colocar uma pedra numa celula vazia(restantes %d).\n",Limite_Pedra);
    printf("5-Adicionar uma linha ou uma coluna ao final do tabuleiro(restantes %d).\n",Limite_Linha_Coluna);
    printf("6-Verificar jogadas anteriores.\n");
    printf("7-Sair do jogo\n");
    printf("O que deseja fazer?");
    do{
        scanf("%d",&jogo_escolha);
        if(jogo_escolha<1 || jogo_escolha >7) {
            printf("\nPor favor, selecione um dos itens jogador %c: ",jogador);
        }

    }while(jogo_escolha<1 || jogo_escolha >7);


    return jogo_escolha;
}

char Coluna_linha() {
    char character;

    do{
        printf("Deseja Inserir uma Coluna ou uma Linha (C/L)? ");
        scanf(" %c",&character);

        character= toupper(character);

        if (character != 'C' && character!= 'L'){
            printf("Opcao Valida- C ou L.\n");
        }

    }while (character != 'C' && character!= 'L');

    return character;
}


int Jogadas_Recuar() {
    int jogadas;
    do {
        printf("\nQuantas jogadas deseja ver(k=0=todas)?  ");
        scanf("%d",&jogadas);
        if(jogadas <0)
            printf("\nErro, insira um k maior ou igual a 0.\n");

    }while(jogadas<0);

    return jogadas;
}
