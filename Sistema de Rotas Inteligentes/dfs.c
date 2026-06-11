// "dfs.c" : Busca em Profundidade

#include <stdio.h>
#include "grafo.h"

void dfs(Grafo* grafo, int v_atual, int visitado[]) {
	// -- marca vértice atual como visitado
	visitado[v_atual] = 1;
	
	printf("%d ", v_atual);
	
	for(int i = 0; i < grafo->numVestices; i++){
		if(grafo->adjMatriz[v_atual][i] != 0 && !visitado[i]) {
			dfs(grafo, i, visitado);
		}
	}
}