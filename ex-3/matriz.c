
#include "matriz.h"
#include <stdlib.h>

struct {
    int nlinhas;
    int ncolunas;
    int** posicao;
} matriz;

Matriz* inicializaMatriz (int nlinhas, int ncolunas)
{
    Matriz *mat = calloc(1, sizeof(Matriz));

    mat->posicao = malloc(nlinhas * sizeof(int*));

    for(int i=0; i < nlinhas; i++)
    {
        mat->linhas[i] = malloc(ncolunas * sizeof(int));
    }

    mat->nlinhas = nlinhas;
    mat->ncolunas = ncolunas;

    return mat;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem)
{
    mat->posicao[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna)
{
    return mat->posicao[linha][coluna];
}

int recuperaNColunas (Matriz* mat)
{
    return mat->ncolunas;
}

int recuperaNLinhas (Matriz* mat)
{
    return mat->nlinhas;
}

Matriz* transposta (Matriz* mat)
{
    Matriz* trans = inicializaMatriz(mat->nlinhas, mat->ncolunas);
    
    for(int i=0; i< mat->nlinhas)
    {
        for(int j=0; i < mat->ncolunas)
        {
            trans->posicao[j][i] = mat->posicao[i][j];
        }
    }

    return trans;
}

void destroiMatriz (Matriz* mat)
{
    for(int i=0; i < mat->nlinhas; i++)
    {
        free(mat->posicao[i]);
    }

    free(mat->linhas);

    free(mat);
}