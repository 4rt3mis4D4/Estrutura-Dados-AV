#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "interface.h"
#include "arvore_avl.h"
#include "funcionalidades.h"

// Enum para String

const char* getTipoEvento(TipoEvento tipo){
	switch(tipo) {
		case ACIDENTE_TRANSITO:
			return "Acidente de Transito";
		case FALHAS_SEMAFORO:
			return "Falhas em Semaforo";
		case INTERRUPCOES_ENERGIA:
			return "Interrupcao de Energia";
		case ALAGAMENTOS:
			return "Alagamentos";
		case INCENDIOS:
			return "Incendios";
		default:
			return "Desconhecido";
	}
}

const char* getRegiaoCidade(RegiaoCidade regiao){
	switch(regiao){
		case NORTE:
			return "Norte";
		case SUL:
			return "Sul";
		case LESTE:
			return "Leste";
		case OESTE:
			return "Oeste";
		case CENTRO:
			return "Centro";
		default:
			return "Desconhecida";
	}
}

const char* getStatusEvento(StatusEvento status){
	switch(status){
		case ATIVO:
			return "Ativo";
		case RESOLVIDO:
			return "Resolvido";
		default:
			return "Desconhecido";
	}
}

// INTERFACE
void menu(NO** raiz){
	int opcao = -1;

	while(opcao != 0){
		printf("\n=== SISTEMA DE GERENCIAMENTO DE EVENTOS CRITICOS ===");
		printf("\n1. [CADASTRO] Registrar Novo Evento");
		printf("\n2. [STATUS] Marcar Evento como RESOLVIDO");
		printf("\n3. [SEVERIDADE] Atualizar Nivel de Severidade");
		printf("\n4. [REMOVER] Excluir Evento (Apenas Resolvidos)");
		printf("\n5. [RELATORIOS] Consultas e Listagens");
		printf("\n6. [METRICAS] Ver Desempenho da Arvore AVL");
		printf("\n0. Sair");
		printf("\n------------------------------------------------");
		printf("\nDigite a opcao escolhida: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1: {
				printf("\n--- CADASTRO ---");
				int id, tipo, severidade, regiao;

				printf("\nDigite ID do evento: ");
				scanf("%d", &id);

				printf("Digite o tipo do evento (0: Acidente, 1: Semaforo, 2: Energia, 3: Alagamento, 4: Incendio): ");
				scanf("%d", &tipo);

				printf("Digite a severidade do evento (1 a 5): ");
				scanf("%d", &severidade);

				printf("Digite a regiao do evento (0:Norte, 1:Sul, 2:Leste, 3:Oeste, 4:Centro): ");
				scanf("%d", &regiao);

				NO* novo = criarNo(id, tipo, severidade, regiao);

				if(novo){
					*raiz = inserir(*raiz, novo);
					printf("\nEvento %d cadastrado com sucesso.\n", id);
				}
				break;
			}
			case 2: {
				printf("\n--- ATUALIZAR: STATUS ---");
				int id;
				printf("\n>> Informe o ID do evento resolvido: ");
				scanf("%d", &id);
				atualizarStatus(*raiz, id);
				break;
			}
			case 3: {
				printf("\n--- ATUALIZAR: SEVERIDADE ---");
				int id, novaSev;
				printf("\n>> Digite o ID do evento: ");
				scanf("%d", &id);
				printf(">> Informe a nova severidade (1 a 5): ");
				scanf("%d", &novaSev);
				atualizarSeveridade(*raiz, id, novaSev);
				break;
			}
			case 4: {
				printf("\n--- REMOVER ---");
				int id;
				printf("\n>> Digite o ID do evento para remover: ");
				scanf("%d", &id);
				*raiz = remover(*raiz, id);
				break;
			}
			case 5: {
				int escolha;

				printf("\n--- CONSULTAS E RELATORIOS ---");
				printf("\n1. Listar Ativos por Severidade (3 a 5)");
				printf("\n2. Listar Ativos por Regiao");
				printf("\n3. Listar por Intervalo de ID");
				printf("\nDigite a opcao escolhida: ");
				scanf("%d", &escolha);

				if(escolha == 1){
					printf("\n+++ Eventos com Severidade entre 3 e 5 +++\n");
					listarIntervalo(*raiz, 3, 5);
				} else if (escolha == 2){
					int regiao;
					printf("\n>> Informe a Regiao (0:N, 1:S, 2:L, 3:O, 4:C): ");
					scanf("%d", &regiao);
					printf("\n+++ Relatorio Regiao %s +++\n", getRegiaoCidade((RegiaoCidade)regiao));
					relatorioRegiao(*raiz, (RegiaoCidade)regiao);
				} else if (escolha == 3){
					int min, max;
					printf("\n>> Informe o ID do evento para inicio: ");
					scanf("%d", &min);
					printf(">> Informe o ID do evento para final: ");
					scanf("%d", &max);
					printf("\n+++ Eventos no Intervalo: %d -> %d +++\n", min, max);
					listarIntervaloID(*raiz, min, max);
				}
				break;
			}
			case 6: {
				printf("\n--- METRICAS ---");
				printf("\n>> Altura Atual da Arvore:       %d", alturaNO(*raiz));
				printf("\n>> Total de Eventos no Banco:    %d", contarTotalNos(*raiz));
				printf("\n>> Eventos Ativos no Momento:    %d", contarEventosAtivos(*raiz));
				printf("\n>> Fator de Balanceamento Medio: %.2f", calcularFatorMedio(*raiz));
				printf("\n>> Total de Rotacoes Realizadas: %d\n", totalRotacoes);
				break;
			}
			case 0:
				printf("\nEncerrando sistema...\n");
				break;
			default:
				printf("\n[!] Opcao invalida!\n");
		}
	}
}