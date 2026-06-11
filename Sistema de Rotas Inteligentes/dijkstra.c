// "dijkstra.c" : Encontra a rota mais curta

#include <stdio.h>
#include <limits.h>
#include "grafo.h"

// Função auxiliar para encontrar o vértice não visitado mais próximo
int minDistancia(int dist[], int visitado[], int numVertices){
	int min = INT_MAX; // -- começa com o infinito
	int min_index = -1; // -- índice do menor valor
	
	// -- Analisa todos os vétices
	for (int v = 0; v < numVertices; v++){
		if (!visitado[v] && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}

// Função auxiliar recursiva para imprimir o caminho traçado do inicio ao fim
void imprimirCaminho(int antecessor[], int j) {
	// -- se o vértice for a origem, imprime para a recursão
	if (antecessor[j] == -1) {
		printf("%d", j);
		return;
	}
	imprimirCaminho(antecessor, antecessor[j]);
	printf(" -> %d", j);
}

void dijkstra(Grafo* grafo, int origem, int destino) {
	int quant_v = grafo->numVestices; 
	int menor_dist[MAX_VERTICES];
	int visitado[MAX_VERTICES];
	int antecessor[MAX_VERTICES];
	
	for (int i = 0; i < quant_v; i++){
		menor_dist[i] = INT_MAX;
		visitado[i] = 0;
		antecessor[i] = -1;
	}
	
	menor_dist[origem] = 0;
	
	// Encontra o caminho mais curto para todos os vértices
	for (int count = 0; count < quant_v - 1; count++) {
		// -- vértice próx. não processado
		int u = minDistancia(menor_dist, visitado, quant_v);
		
		if (u == -1) {
			break;
		}
		
		visitado[u] = 1;
		
		// -- atualiza a distância dos vizinhos de "u"
		for (int v = 0; v < quant_v; v++){
			if(!visitado[v] && grafo->adjMatriz[u][v] && menor_dist[u] != INT_MAX &&
				menor_dist[u] + grafo->adjMatriz[u][v] < menor_dist[v]) {
					menor_dist[v] = menor_dist[u] + grafo->adjMatriz[u][v];
					antecessor[v] = u;
				}
		}
	}
	
	// Exibição dos resultados
	printf("\n=== Encontrar menor caminho (Dijkstra) ===\n");
	
	// -- verifica se é possível chegar ao destino
	if (menor_dist[destino] == INT_MAX) {
		printf("Nao ha caminho entre o ponto %d e o ponto %d.\n", origem, destino);
	} else {
		printf("Menor distancia de %d ate %d: %d unidades\n", origem, destino, menor_dist[destino]);
		printf("Rota: ");
		imprimirCaminho(antecessor, destino);
		printf("\n");
	}
}