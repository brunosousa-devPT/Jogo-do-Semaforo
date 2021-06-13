//Trabalho Prático Programacao
//Jogo do Semaforo
//Bruno Amado Sousa a2020132971@isec.pt
//DEIS-LEI


#ifndef TABULEIRO_H
#define TABULEIRO_H
#define MAX 30

typedef struct BoardS {
    char **tabuleiro;
    char jogador;
    int IDjogada;
    int colunas;
    int linhas;
    char jogadaL;
    struct BoardS* next;
}BoardS;





void draw_tabuleiro_inicial(char **board, int linhas,int colunas);

//Funcao para inserir uma peca verde numa celula vazia, retorna erro es o utilizador tentar colocar num sitio indisponivel.
char** inserir_peca_celula_vazia(char **board, int linhas,int colunas,int bot);

//Funcao para trocar uma peça amarela por uma peça verde, retorna error se este tentar por num sitio sem verde. Retorna outro erro se nao existir peças verdes no tabuleiro
char** troca_amarela_por_verde(char **board, int linhas,int colunas,int bot,int *erro);

//Funcao para trocar uma peça Vermelha por uma peça amarela, retorna error se este tentar por num sitio sem amarela. Retorna outro erro se nao existir peças amarelas no tabuleiro
char** trocar_vermelha_por_amarela(char **board, int linhas,int colunas,int bot,int *erro);

//Funcao para inserir uma pedra no tabuleiro, cada jogador apenas pode usar esta funcao 1 vez bloqueando assim a vitoria atraves daquela linha, coluna ou diagonal
char** inserir_pedra(char **board, int linhas,int colunas,int bot);

char** Cria_matriz_dinamica(char **board,int linhas,int colunas);

char** Cria_Nova_matriz_dinamica(char **board,int linhas,int colunas);

char** Aumenta_Linha(char **board, int* linhas,int colunas);
char** Aumenta_Coluna(char **board, int linhas,int *colunas);

int verifica_vitoria(char **board,int colunas,int linhas);

void new_node_tabuleiro(BoardS** root, char **board,int colunas,int linhas,char jogada,char jogador,int IDjogada);

void desalocacao(BoardS** root);

#endif // TABULEIRO_H
