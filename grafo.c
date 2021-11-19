#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
typedef int bool;
typedef int TIPOPESO;

typedef struct adjacencia{
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
} ADJACENCIA;

typedef struct vertice{
    // Dados armazenados vão aquo
    ADJACENCIA *cab;
} VERTICE;

typedef struct grafo {
    int vertices;
    int arestas;
    VERTICE *adj;
} GRAFO;

GRAFO *criaGrafo(int v) {
    GRAFO *g = (GRAFO *) malloc (sizeof(GRAFO));
    g->vertices = v;
    g->arestas = 0;
    g->adj = (VERTICE *) malloc(v*sizeof(VERTICE));
    int i;
    for (i = 0; i < v; i++)
        g->adj[i].cab = NULL;
}

ADJACENCIA *criaAdj(int v, int peso) {
    ADJACENCIA *temp = (ADJACENCIA *)malloc(sizeof(ADJACENCIA));
    temp->vertice = v;
    temp->peso = peso;
    temp->prox = NULL;
    return(temp);
}

bool criaAresta(GRAFO *gr, int vi, int vf, TIPOPESO p){
    if (!gr) return(false);
    if ((vf <0) || (vf >= gr->vertices))
        return(false);
    if ((vi<0) || (vi >= gr->vertices))
        return(false);
        ADJACENCIA *novo = criaAdj(vf, p);
        novo->prox = gr->adj[vi].cab;
        gr->adj[vi].cab = novo;
        gr->arestas++;
        return(true);
}

void imprime(GRAFO *gr){
    print("Vertices: %d. Arestas %d. \n", gr->vertices, gr->arestas);
    int i;
    for(i = 0; i < gr->vertices; i++){
        print("v%d: ", i);
        ADJACENCIA *ad = gr->adj[i].cab;
        while(ad){
            print("v%d(%d) ", ad->vertice, ad->peso);
            ad = ad->prox;
        }
        print("\n");
    }
}




















