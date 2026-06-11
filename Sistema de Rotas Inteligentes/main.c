// "main.c" : Monta o grafo (cidade) + menu

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main() {
	// -- criação do grafo de 6 vértices
	Grafo* cidade = criarGrafo(MAX_VERTICES);
	
	// -- ruas + distâncias
	adicionarAresta(cidade, 0, 1, 7);
    adicionarAresta(cidade, 0, 2, 9);
    adicionarAresta(cidade, 0, 5, 14);
    adicionarAresta(cidade, 1, 2, 10);
    adicionarAresta(cidade, 1, 3, 15);
    adicionarAresta(cidade, 2, 3, 11);
    adicionarAresta(cidade, 2, 5, 2);
    adicionarAresta(cidade, 3, 4, 6);
    adicionarAresta(cidade, 4, 5, 9);
    
    int opcao;
    int origem, destino;
    
    // MENU
    do {
    	printf("\n=========================================\n");
        printf("    SISTEMA DE ROTAS DE ENTREGAS (6 Pts) \n");
        printf("=========================================\n");
        printf("1 - Exibir matriz de adjacencia\n");
        printf("2 - Executar BFS\n");
        printf("3 - Executar DFS\n");
        printf("4 - Encontrar menor caminho (Dijkstra)\n");
        printf("5 - Sair\n");
        printf("Digite o numero da opcao escolhida: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
        	case 1: // Exibir matriz de adjacencia
        		printf("\n======================================\n");
        		printf("    1 - Exibir matriz de adjacencia \n");
        		printf("======================================\n");
        		exibirMatriz(cidade);
        		break;
        	
        	case 2: // Executar BFS
        		printf("\n=======================\n");
        		printf("    2 - Executar BFS \n");
        		printf("=======================\n");
        		printf("Informe o ponto de origem (0 a 5): ");
        		scanf("%d", &origem);
        		
        		if(origem >= 0 && origem < MAX_VERTICES) {
        			bfs(cidade, origem);
				} else {
					printf("Ponto Invalido!\n");
				}
				break;
				
			case 3: // Executar DFS
				printf("\n=======================\n");
        		printf("    3 - Executar DFS \n");
        		printf("=======================\n");
				printf("Informe o ponto de origem (0 a 5): ");
        		scanf("%d", &origem);
        		
        		if(origem >= 0 && origem < MAX_VERTICES) {
        			int visitado_dfs[MAX_VERTICES] = {0};
        			
        			printf("\nPercurso DFS (Origem - %d): ", origem);
        			dfs(cidade, origem, visitado_dfs);
        			printf("\n");
				} else {
					printf("Ponto Invalido!\n");
				}
				break;
				
			case 4: // Encontrar menor caminho (Dijkstra)
				printf("\n===========================================\n");
        		printf("    4 - Encontrar menor caminho (Dijkstra) \n");
        		printf("===========================================\n");
				printf("Informe o ponto de origem (0 a 5): ");
        		scanf("%d", &origem);
        		printf("Informe o ponto de destino (0 a 5): ");
        		scanf("%d", &destino);
        		
        		if(origem >= 0 && origem < MAX_VERTICES 
					&& destino >= 0 && destino < MAX_VERTICES) {
						dijkstra(cidade, origem, destino);
					} else {
						printf("Pontos Invalidos!\n");
					}
					break;
			
			case 5:
				printf("\n===============\n");
        		printf("    5 - Sair \n");
        		printf("===============\n");
				printf("Saindo...");
				break;
			
			default:
				printf("Opcao Invalida! Tente Novamente.\n");
		}
        
	} while (opcao != 5);
	
	free(cidade);
	return 0;
}