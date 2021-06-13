//Trabalho Prático Programacao
//Jogo do Semaforo
//Bruno Amado Sousa a2020132971@isec.pt
//DEIS-LEI

#include "files.h"
#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"


/********************************/
/*      ESCREVER DATA FILE      */
/********************************/

void write_data(char *FILENAME, BoardS** root)
{
    BoardS* curr = *root;
    FILE *f;

    f = fopen(FILENAME,"w");
    if (f==NULL)
        return;



    //escrever no ficheiro
    while (curr != NULL) {
        fprintf(f,"Jogada: %d Tipo: %c\n",curr->IDjogada,curr->jogadaL);
        //Desenhar tabuleiro no ficheiro de dados.
        for(int l = 0; l < curr->colunas; l++) {
            if (l==0)
               fprintf(f,"     ");
            fprintf(f," C%d ",l);
        }
        fprintf(f,"\n");

        for (int l = 0; l < curr->colunas*4+2;l++){
            if (l==0)
                fprintf(f,"   -");
            else
                fprintf(f,"-");
        }
        for (int i = 0; i < curr->linhas;i++){

            fprintf(f,"\n");
            for(int j = 0; j<curr->colunas;j++) {
                if (j ==0) {
                    fprintf(f,"L%d- | %c |",i,curr->tabuleiro[i][j]);
                }
                else
                    fprintf(f," %c |",curr->tabuleiro[i][j]);

            }
            fprintf(f,"\n");
            for (int l = 0; l < curr->colunas*4+2;l++){
                if (l==0)
                    fprintf(f,"   -");
                else
                    fprintf(f,"-");
            }
        }


        fprintf(f,"\n");
        curr = curr->next;
    }


    fclose(f);
}

/********************************/
/*    FIM ESCREVER DATA FILE    */
/********************************/



/********************************/
/*      ESCREVER SAVE FILE      */
/********************************/

void save_file(BoardS** root) {

    BoardS* curr = *root;

    FILE *f;
    f = fopen("save.bin","wb");

    if (f == NULL) {
        printf("\nError To open file\n");
        return;
    }

    while (curr != NULL) {
        fwrite(curr,sizeof(BoardS),1,f);

        curr = curr->next;
    }


    fclose(f);



}

/********************************/
/*    FIM ESCREVER SAVE FILE    */
/********************************/
void read_save_file(BoardS** root) {


     BoardS *curr = *root;
     curr = malloc(sizeof(BoardS));


     FILE *f = fopen("save.bin","rb");

     if(f==NULL){
        printf("\nErro a abrir o ficheiro\n");
        return;
     }
     while(fread(curr,sizeof(BoardS),1,f)) {
        curr = curr->next;
        curr = malloc(sizeof(BoardS));
     }


     fclose(f);

}


/********************************/
/*        LER SAVE FILE         */
/********************************/

/********************************/
/*      FIM LER SAVE FILE       */
/********************************/
