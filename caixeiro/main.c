#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

GRAFO* geraGrafo(){
    int matrix[11][11] = {0, 30, 84, 56, -1, -1, -1, 75, -1, 80,
                         30, 0, 65, -1, -1, -1, 70, -1, -1, 40,
                         84, 65, 0, 74, 52, 55, -1, 60, 143, 48,
                         56, -1, 74, 0, 135, -1 -1, 20, -1, -1,
                         -1, -1, 52, 135, 0, 70, -1, 122, 98, 80,
                         70, -1, 55, -1, 70, 0, 63, -1, 82, 35,
                         -1, 70, -1, -1, -1, 63, 0, -1, 120, 57,
                         75, -1, 135, 20, 122, -1, -1, 0, -1, -1,
                         -1, -1, 143, -1, 98, 82, 120, -1, 0, -1,
                         80, 40, 48, -1, 80, 35, 57, -1, -1, 0};
    
    GRAFO *gr = criaGrafo(9);
    
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            if(matrix[i][j] > 0)
                criaAresta(gr, i, j, matrix[i][j]);
        }
    }
    return gr;
}

GRAFO* subida_da_encosta(GRAFO* g, int start_point){
    
    int oldWay_value, currWay_value, n_vert;
    while(1){
        GRAFO* temp = g;
        while(1){
            if(currWay_value > oldWay_value){
                break;
            }
            VERTICE *v = &g->adj[n_vert];
            
        }
    }
}

int main(){

    GRAFO *g = geraGrafo();
    imprime(g);
}
