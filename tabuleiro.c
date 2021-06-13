//Trabalho Prático Programacao
//Jogo do Semaforo
//Bruno Amado Sousa a2020132971@isec.pt
//DEIS-LEI


#include <ctype.h>
#include "tabuleiro.h"
#include "utils.h"
#include <stdlib.h>




/************************************/
/*       Desenhar Tabuleiro         */
/************************************/

void draw_tabuleiro_inicial(char **board, int linhas,int colunas) {

     //Imprimir os C de coluna ao longo das colunas
     for(int l = 0; l < colunas; l++) {
        if (l==0)
            printf("     ");
        printf(" C%d ",l);
     }
     printf("\n");
    //imprimir separador de colunas
    for (int l = 0; l < colunas*4+2;l++){
            if (l==0)
                printf("   -");
            else
                printf("-");
        }
        //loop que imprime o resto do tabuleiro

     for (int i = 0; i < linhas;i++){

        printf("\n");
        for(int j = 0; j<colunas;j++) {
            if (j ==0) {
                printf("L%d- | %c |",i,board[i][j]);
            }
            else
                printf(" %c |",board[i][j]);

        }
        printf("\n");
        for (int l = 0; l < colunas*4+2;l++){
            if (l==0)
                printf("   -");
            else
                printf("-");
        }
    }

}
/************************************/
/*      FIM Desenhar Tabuleiro      */
/************************************/

/************************************/
/*    Inserir Verde No Tabuleiro    */
/************************************/
char** inserir_peca_celula_vazia(char **board, int linhas,int colunas,int bot) {
    initRandom();

    // posicao onde inserir a peca
    char Cor = 'G';
    int POSc, POSl;
    //verificar se e bot ou nao
    if (bot==0){

        do{
            printf("\nInsira a Linha e a Coluna: ");
            scanf("%d %d",&POSl,&POSc);

            //se a posicao onde o jogador que por a peca nao estiver livre mostrar erro
            if (board[POSl][POSc]!= ' ')
                printf("\nEssa celula esta ocupada. Jogada nao permitida.\n");


        }while(POSl < 0 || POSl > linhas-1 ||POSc < 0 || POSc>colunas-1 || board[POSl][POSc]!= ' ');

    }

    //se o jogador e um bot entao:
    if (bot==1){
        do{ //posicoes sao escolhidas aleatoriamente
            POSl = intUniformRnd(0,linhas-1);
            POSc = intUniformRnd(0,colunas-1);


        }while(POSl < 0 || POSl > linhas ||POSc < 0 || POSc>colunas-1 || board[POSl][POSc]!= ' ');
         printf("\nBOT jogada  V L-%d C-%d\n",POSl,POSc);
    }





    board[POSl][POSc] = Cor;
    return board;

}


/************************************/
/*         Fim Inserir Verde        */
/************************************/



/************************************/
/*     Trocar Amarela por Verde     */
/************************************/


char** troca_amarela_por_verde(char **board, int linhas,int colunas,int bot,int *erro) {
    initRandom();
    //verificacao se o tabuleiro esta vazio ou tem alguma pessa verde

    int tamanho = linhas * colunas;
    int contador = 0;
    *erro = 0;

    for (int i=0; i< linhas; i++) {
         for (int l=0; l< colunas; l++) {
            if (board[i][l]!='G')
                contador ++;
        }
    }

    if (contador == tamanho) {
        printf("\n\nNenhuma peca VERDE no tabuleiro. Jogada Indisponível!\n\n");
        *erro = 1;
        return board;
    }


    char Cor = 'Y';
    int POSc, POSl;

    if (bot==0){

        do{
            printf("\nInsira a Linha e a Coluna: ");
            scanf("%d %d",&POSl,&POSc);


            if (board[POSl][POSc]!= 'G')
                printf("\nEssa celula não tem peca VERDE para trocar. Jogada nao permitida.\n");


        } while(POSl < 0 || POSl > linhas-1 ||POSc < 0 || POSc>colunas-1 || board[POSl][POSc]!= 'G');
    }
     if (bot==1){

        for (int i=0; i< linhas; i++) {
            for (int l=0; l< colunas; l++) {
                if (board[i][l]=='G') {
                    POSl =i;
                    POSc = l;
                }


            }

        }
     }




    board[POSl][POSc] = Cor;
    return board;

}

/************************************/
/*   FIM Trocar Amarela por Verde   */
/************************************/



/************************************/
/*    Trocar Vermelha por Amarela   */
/************************************/

char** trocar_vermelha_por_amarela(char **board, int linhas,int colunas,int bot,int *erro) {
    //verificacao se o tabuleiro esta vazio ou tem alguma pessa verde
    int tamanho = linhas * colunas;
    int contador = 0;
    *erro = 0;

    for (int i=0; i< linhas; i++) {
         for (int l=0; l< colunas; l++) {
            if (board[i][l]!='Y')
                contador ++;
        }
    }

    if (contador == tamanho) {
        printf("\n\nNenhuma peca AMARELA no tabuleiro. Jogada Indisponível!\n\n");
        *erro=1;
        return board;
    }

    char Cor = 'R';
    int POSc, POSl;

    if(bot==0){
        do{
        printf("\nInsira a Linha e a Coluna: ");
        scanf("%d %d",&POSl,&POSc);


        if (board[POSl][POSc]!= 'Y')
            printf("\nEssa celula não tem peca AMARELA para trocar. Jogada nao permitida.\n");


        } while(POSl < 0 || POSl > linhas-1 ||POSc < 0 || POSc>colunas-1 || board[POSl][POSc]!= 'Y');

    }
    if (bot ==1){
        for (int i=0; i< linhas; i++) {
            for (int l=0; l< colunas; l++) {
                if (board[i][l]=='Y'){
                    POSl = i;
                    POSc = l;
                }

            }
        }


    }



    board[POSl][POSc] = Cor;
    return board;
}

/************************************/
/* FIM Trocar Vermelha por Amarela  */
/************************************/

/************************************/
/*          INSERIR PEDRA           */
/************************************/


char** inserir_pedra(char **board, int linhas,int colunas,int bot) {
    initRandom();
    char Pedra = 'P';
    int POSc, POSl;

    if (bot == 0){

        do{
            printf("\nInsira a Linha e a Coluna: ");
            scanf("%d %d",&POSl,&POSc);


            if (board[POSl][POSc]!= ' ')
                printf("\nEssa celula nao esta vazia para trocar. Jogada nao permitida.\n");


        } while(POSl < 0 || POSl > linhas-1 ||POSc < 0 || POSc>colunas-1 || board[POSl][POSc]!= ' ');
    }
    if (bot == 1) {

        do{

            POSl = intUniformRnd(0,linhas-1);
            POSc = intUniformRnd(0,colunas-1);


        } while(POSl < 0 || POSl > linhas-1 ||POSc < 0 || POSc>colunas-1 || board[POSl][POSc]!= ' ');
    }



    board[POSl][POSc] = Pedra;
    return board;
}

/************************************/
/*        FIM INSERIR PEDRA         */
/************************************/

/************************************/
/*      CRIAR TABELA DINAMICA       */
/************************************/

char** Cria_matriz_dinamica(char **board,int linhas,int colunas)
{

    int i,j;
    board = (char**)malloc(sizeof(char*)*linhas);
    if (board==NULL) {
        printf("Erro na alocacao de memoria");
        return NULL;

    }
    for (i =0; i<linhas;i++) {
        board[i] = (char*)malloc(sizeof(char)* colunas);
        if (board[i]==NULL){
            printf("Erro na alocacao de memoria");
            return NULL;
        }
        for (j=0;j<colunas;j++) {
            board[i][j] =' ';
        }
    }
    return board;
}
//Cria outra matriz dinamica no ambito de criar um tabuleiro para cada nó da lista ligada
char** Cria_Nova_matriz_dinamica(char **board,int linhas,int colunas)
{
    char **aux;

    int i,j;
    aux = (char**)malloc(sizeof(char*)*linhas);
    if (aux==NULL) {
        printf("Erro na alocacao de memoria");
        return NULL;

    }
    for (i =0; i<linhas;i++) {
        aux[i] = (char*)malloc(sizeof(char)* colunas);
        if (aux[i]==NULL){
            printf("Erro na alocacao de memoria");
            return NULL;
        }
        for (j=0;j<colunas;j++) {
            aux[i][j] =board[i][j];
        }
    }
    return aux;
}

/************************************/
/*   FIM CRIAR TABELA DINAMICA      */
/************************************/



/************************************/
/*          INSERIR LINHA           */
/************************************/

char** Aumenta_Linha(char **board, int* linhas,int colunas) {

    char **auxl;
    char *auxc;
    int i,j;
    (*linhas)++;

    //printf("\n%d\n",*linhas);

    auxl = (char **)realloc(board,sizeof(char*)*(*linhas)); //realocar memoria para a linha

    //printf("\n%d\n",1);

    if (auxl==NULL) {
        printf("Erro na alocacao de memoria\n");
        return NULL;

    }
    board=auxl;

    //auxc= (char *)realloc(board[(*linhas)-1],sizeof(char)*colunas);
    auxc=malloc(colunas *sizeof(char));


    if(auxc == NULL)
    {

        printf("Erro na alocação de memoria\n");
        return NULL;

    }
    board[(*linhas)-1] = auxc;

    for(j=0;j<colunas;j++) {
        board[(*linhas)-1][j] = ' ';
    }

    return board;

}


/************************************/
/*        FIM INSERIR LINHA         */
/************************************/






/************************************/
/*          INSERIR COLUNA          */
/************************************/

char** Aumenta_Coluna(char **board, int linhas,int *colunas) {

    char **auxl;
    char *auxc;
    int i,j;
    (*colunas)++;

    for(i=0;i<linhas;i++) {
        auxc = (char *)realloc(board[i],sizeof(char)*(*colunas)); //realocar memoria para coluna

        if (auxc == NULL) {
            printf("Erro na alocacao de memoria!");
            return NULL;
        }

        board[i] = auxc;

    }
    for(int i=0; i<linhas; i++)
        board[i][(*colunas)-1] = ' ';
    return board;

}


/************************************/
/*        FIM INSERIR COLUNA        */
/************************************/

/************************************/
/*           Verificar Vitoria      */
/************************************/

int verifica_vitoria(char **board,int colunas,int linhas) {

    int i,j;
    int vitoria = 0;
    //verifica linha
    for(i=0;i<linhas;i++) {
        for (j=1;j<colunas;j++) {
            if (board[i][0]==board[i][j] && board[i][j]!=' ') {
                vitoria ++;
            }
            else {
                vitoria =0;

            }
        }
        if (vitoria ==colunas-1){

            return 1;

        }

        else
            vitoria = 0;

    }

    //verificar colunas
    for(i=0;i<colunas;i++) {
        vitoria =0;
        for (j=1;j<linhas;j++) {
            if (board[j][i] == board[0][i] && board[j][i]!=' ')
                vitoria ++;
            else
                vitoria = 0;

        }
         if (vitoria ==linhas-1)
            return 1;

    }
    //verifica diagonal
    if (colunas ==linhas) {
        for (i=0;i<linhas;i++) {
            if (board[0][0]== board[i][i] && board[i][i]!=' ')
                vitoria ++;
            else{
                vitoria = 0;

            }


        }
        if (vitoria == colunas)
            return 1;
        else
            vitoria = 0;
    }
    if (colunas ==linhas) {


        for (i=0,j=colunas-1;i<linhas;i++,j--) {


                if (board[linhas-1][0]== board[i][j] && board[i][j]!=' ')

                    vitoria ++;
                else{
                    vitoria = 0;

                }



            }
            if (vitoria == colunas)
                    return 1;
                else
                    vitoria= 0;


        }





    return vitoria;


}

/************************************/
/*      FIM  Verificar Vitoria      */
/************************************/



/************************************/
/*   Verificar Jogadas Tabuleiro    */
/************************************/

void new_node_tabuleiro(BoardS** root, char **board,int colunas,int linhas,char jogada,char jogador,int IDjogada) {
    //obter um tabuleiro para cada no para evitar que todos os nós para o mesmo tabuleiro no final.
    char **Board_Copia;
    BoardS* new_board=  malloc(sizeof(BoardS));
    if(new_board == NULL) {
        printf("Erro na alocacao de memoria");
        exit(1);
    }

    Board_Copia = Cria_Nova_matriz_dinamica(board,linhas,colunas);


    new_board->tabuleiro = Board_Copia;
    new_board->jogadaL = jogada;
    new_board->colunas = colunas;
    new_board->linhas = linhas;
    new_board->jogador = jogador;
    new_board->IDjogada = IDjogada;
    new_board->next = NULL;

    if(*root == NULL) {
        *root = new_board;
        return;
    }

    BoardS* curr= *root;
    while(curr->next !=NULL) {
        curr = curr->next;
    }
    curr->next = new_board;

}


/************************************/
/* FIM Verificar Jogadas Tabuleiro  */
/************************************/



/************************************/
/*        Desenhar k jogadas        */
/************************************/

void mostrar_kjogadas(BoardS** root, int k, int Tjogadas) { //k representa a jogadas que o jogador deseja ver
    BoardS* curr = *root;
    int jogada;
    if (k==0)
        jogada =1;

    else if(k>0 && k<=Tjogadas)
        jogada = Tjogadas-k;
    else{
        printf("K maior que jogadas totais, mostrando desde o início.\n");
        jogada= 1;
    }




    while (curr->next != NULL) {
        //printf("\n%d\n",jogada);
        if (curr->IDjogada>jogada &&k!=0) {
            printf("\nJogada %d Tipo:%c\n",curr->IDjogada,curr->jogadaL);
            draw_tabuleiro_inicial(curr->tabuleiro,curr->linhas,curr->colunas);

            printf("\n");
        }
        if (k==0) {
            printf("\nJogada %d  Tipo:%c\n",curr->IDjogada,curr->jogadaL);
            draw_tabuleiro_inicial(curr->tabuleiro,curr->linhas,curr->colunas);

            printf("\n");
        }


        curr = curr->next;
    }

    printf("\nUltima Jogada   Tipo:%c\n",curr->jogadaL);

}


/************************************/
/*     FIM Desenhar k jogadas       */
/************************************/



/************************************/
/*      DESALOCACAO DE MEMORIA      */
/************************************/

void desalocacao(BoardS** root) {
    BoardS* curr= *root;
    while(curr != NULL) {
        BoardS* aux = curr;
        curr = curr->next;
        free(aux);

    }
    *root = NULL;
}

/************************************/
/*    FIM DESALOCACAO DE MEMORIA    */
/************************************/



