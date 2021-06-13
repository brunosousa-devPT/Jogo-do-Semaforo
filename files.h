//Trabalho Prático Programacao
//Jogo do Semaforo
//Bruno Amado Sousa a2020132971@isec.pt
//DEIS-LEI


#ifndef FILES_H
#define FILES_H

#include "tabuleiro.h"

void write_data(char *FILENAME, BoardS** root);



void save_file(BoardS** root);
void read_save_file(BoardS** root);
#endif // FILES_H
