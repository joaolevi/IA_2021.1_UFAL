#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2
typedef int bool;
typedef int TIPOPESO;

typedef struct adjacencia{
    int vertice;
    TIPOPESO peso;
    struct adjacencia *prox;
} ADJACENCIA;

typedef struct vertice{
    // Dados armazenados vão aquo
    ADJACENCIA *head;
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
        g->adj[i].head = NULL;
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
        novo->prox = gr->adj[vi].head;
        gr->adj[vi].head = novo;
        gr->arestas++;
        return(true);
}

void imprime(GRAFO *gr){
    print("Vertices: %d. Arestas %d. \n", gr->vertices, gr->arestas);
    int i;
    for(i = 0; i < gr->vertices; i++){
        print("v%d: ", i);
        ADJACENCIA *ad = gr->adj[i].head;
        while(ad){
            print("v%d(%d) ", ad->vertice, ad->peso);
            ad = ad->prox;
        }
        print("\n");
    }
}

void profundidade(GRAFO *g) {
    int cor[g->vertices];

    int u;
    for (u = 0; u < g->vertices; u++){
        cor[u] = BRANCO;
    }
    for (u = 0; u < g->vertices; u++){
        if (cor[u] == BRANCO)
            visitaP(g, u, cor);
    }

}

void visitaP(GRAFO *g, int u, int *cor) {
    cor[u] = AMARELO;
    ADJACENCIA *v = g->adj[u].head;
    while(v){
        if (cor[v->vertice] == BRANCO)
            visitaP(g, v->vertice, cor);
        v = v->prox;
    }
    cor[u] = VERMELHO;
}
















