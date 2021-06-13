//Trabalho Pr�tico Programacao
//Jogo do Semaforo
//Bruno Amado Sousa a2020132971@isec.pt
//DEIS-LEI

#ifndef UTILS_H
#define UTILS_H


// Inicializa o gerador de numeros aleatorios.
// Esta funcao deve ser chamada apenas uma vez no inicio da execucao do programa
void initRandom();

//Devolve um valor inteiro aleatorio distribuido uniformemente entre [a, b]
int intUniformRnd(int a, int b);

// Devolve o valor 1 com probabilidade prob. Caso contrario, devolve 0
int probEvento(float prob);

int CheckPar(int Number);

#endif /* UTILS_H */
