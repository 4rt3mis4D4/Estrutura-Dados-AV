// "grafo.c" : Cria a matriz de adjacência e conectar as ruas (arestas) com suas respectivas distâncias (pesos)

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h" // Definições do grafo

// Função para criar o Grafo e inicializar a Matriz de Adjacência
Grafo* criarGrafo(int vertices) {
	Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
	
	// Define a quantidade de pontos do bairro (vértices)
	grafo->numVestices = vertices;
	
	for (int i = 0; i < vertices; i++){
		for (int j = 0; j < vertices; j++){
			grafo->adjMatriz[i][j] = 0;
		}
	}
	
	return grafo;
}

// Função para adicionar uma rua (aresta) entre dois pontos (vértices), com uma distância (peso)
void adicionarAresta(Grafo* grafo, int origem, int destino, int peso) {
	grafo->adjMatriz[origem][destino] = peso; // Ida: origem para destino
	grafo->adjMatriz[destino][origem] = peso; // Volta: destino para origem
}

// Função para imprimir a Matriz
void exibirMatriz(Grafo* grafo){
	for (int i = 0; i < grafo->numVestices; i++){
		printf("%d: ", i);
		for (int j = 0; j < grafo->numVestices; j++){
			printf("%3d ", grafo->adjMatriz[i][j]);
		}
		printf("\n");
	}
	printf("-----------------------------------------\n");
}