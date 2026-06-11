// bfs.c : Busca em Largura

#include <stdio.h>
#include "grafo.h"

void bfs(Grafo* grafo, int inicio) {
	// -- vetor para marcar vértices visitados
	int visitado[MAX_VERTICES] = {0};
	
	// -- declaração variáveis da fila
	int fila[MAX_VERTICES];
	int frente = 0; 
	int tras = 0;
	
	visitado[inicio] = 1; // -- marca vértice inicial como visitado
	fila[tras] = inicio; // -- adicionar inicio na fila
	tras++; // -- aumenta o tamanho da fila
	
	printf("\nExecutando BFS de inicio %d...\n", inicio);
	
	// -- executa enquanto houver elementos na fila
	while(frente < tras) {
		// -- salva vértice atual
		int atual = fila[frente];
		// -- avança 1 elemento na fila
		frente++;
		
		printf("%d ", atual);
		
		for (int v = 0; v < grafo->numVestices; v++) {
			if (grafo->adjMatriz[atual][v] != 0 && !visitado[v]){
				visitado[v] = 1;
				fila[tras] = v;
				tras++;
			}
		}
	}
	
	printf("\n");
}