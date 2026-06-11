// "grafo.h" : Definição da estrutura do grafo e funções base

#ifndef GRAFO_H
#define GRAFO_H

#define MAX_VERTICES 6

// Declaração da estrutura do grafo
typedef struct Grafo {
	int numVestices;
	int adjMatriz[MAX_VERTICES][MAX_VERTICES];
} Grafo;

// Declaração das funções 
Grafo* criarGrafo(int vertices);
void adicionarAresta(Grafo* grafo, int origem, int destino, int peso);
void exibirMatriz(Grafo* grafo);

// Declaração da função do arquivo bfs.c
void bfs(Grafo* grafo, int inicio);

// Declaração da função do arquivo dfs.c
void dfs(Grafo* grafo, int v, int visitado[]);

// Declaração da função do arquivo dijkstra.c
void dijkstra(Grafo* grafo, int origem, int destino);

#endif
	
