#include <stdio.h>
#include <stdbool.h>
#define MAX 1000

typedef int TIPOCHAVE;

typedef struct {
    VERTICE v;
    //outros campos...
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int nroElem;
} LISTA;

void inicializarLista(LISTA *l){
    l->nroElem = 0;
}

void exibirLista(LISTA *l){
    int i;
    printf("Lista: \" ");
    for (i = 0; i < l->nroElem; i++)
        printf("%i ", l->A[i].v.ch);
}

bool inserirElemLista(LISTA* l, REGISTRO reg, int i){
    int j;
    if((l->nroElem == MAX) || (i < 0) || (i > l->nroElem))
        return false;
    for(j = l->nroElem; j>i; j--)
        l->A[j] = l->A[j-1];
    l->A[i] = reg;
    l->nroElem++;
    return true;
}

bool pushBackElem(LISTA *l, VERTICE *vert){
    if(l->nroElem == MAX) return false;
    REGISTRO *reg;
    reg->v = *vert;
    l->A[l->nroElem] = *reg;
    return true;
}

ADJACENCIA* minVert(LISTA *l){
    if(l->nroElem == 0) return NULL;
    VERTICE *vert = &l->A[0].v;
    if(vert->head && !vert->visitado){
        ADJACENCIA *temp = vert->head;
        for(int i = 0; i < l->nroElem; i++){
            while(temp->prox){
                if(temp->peso < temp->prox->peso)
                    temp = temp->prox;
            }
        return temp;
        }
    }
    return NULL;
}

bool excluirElemLista(VERTICE v, LISTA* l) {
    int pos, j;
    pos = buscaSequencial(l, v);
    if(pos == -1) return false;
    for(j = pos; j < l->nroElem-1; j++)
        l->A[j] = l->A[j+1];
    l->nroElem--;
    return true;
}

void reinicializarLista(LISTA *l) {
    l->nroElem = 0;
}