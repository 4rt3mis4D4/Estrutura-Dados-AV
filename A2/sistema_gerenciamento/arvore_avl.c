#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arvore_avl.h"

// definição global do contador de rotações (era extern sem definição)
int totalRotacoes = 0;

// Criar Novo Nó
NO* criarNo(int id, int tipo, int severidade, int regiao){
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL){
		return NULL;
	}

	novo->idEvento = id;

	novo->tipo = (TipoEvento)tipo;
	novo->nivelSeveridade = severidade;
	novo->regiao = (RegiaoCidade)regiao;
	novo->status = ATIVO;

	novo->altura = 0;
	novo->esq = NULL;
	novo->dir = NULL;

	// Data e Hora do Sistema
	time_t t = time(NULL);
	struct tm *tm_info = localtime(&t);

	novo->dataHora.dia = tm_info->tm_mday;
	novo->dataHora.mes = tm_info->tm_mon + 1;
	novo->dataHora.ano = tm_info->tm_year + 1900;
	novo->dataHora.hora = tm_info->tm_hour;
	novo->dataHora.minuto = tm_info->tm_min;

	return novo;
}

// Altura do Nó
int alturaNO(NO *no){
	return (no == NULL) ? -1 : no->altura;
}

int maior(int a, int b) {
	return (a > b) ? a : b;
}

// Cálculo fator de balanceamento
int fatorBalanceamento(NO *no) {
	return (no == NULL) ? 0 : alturaNO(no->esq) - alturaNO(no->dir);
}

// Rotações: RR, LL, LR, RL

// Rotação Simples à esquerda (RR)
NO *rotacaoRR(NO *raiz) {
	NO *no = raiz->dir;
	raiz->dir = no->esq;
	no->esq = raiz;
	raiz->altura = maior(alturaNO(raiz->esq), alturaNO(raiz->dir)) + 1;
	no->altura = maior(alturaNO(no->esq), alturaNO(no->dir)) + 1;
	totalRotacoes++; // Incrementa contador a cada rotação
	return no;
}

// Rotação Simples à direita (LL)
NO *rotacaoLL(NO *raiz){
	NO *no = raiz->esq;
	raiz->esq = no->dir;
	no->dir = raiz;
	raiz->altura = maior(alturaNO(raiz->esq), alturaNO(raiz->dir)) + 1;
	no->altura = maior(alturaNO(no->esq), alturaNO(no->dir)) + 1;
	totalRotacoes++; // Incrementa contador a cada rotação
	return no;
}

// Rotação Dupla à direita (LR)
NO *rotacaoLR(NO *raiz){
	raiz->esq = rotacaoRR(raiz->esq);
	return rotacaoLL(raiz);
}

// Rotação Dupla à esquerda (RL)
NO *rotacaoRL(NO *raiz){
	raiz->dir = rotacaoLL(raiz->dir);
	return rotacaoRR(raiz);
}

// Inserção de eventos com:
//	- Cálculo do fator de balanceamento
//	- Aplicação de rotações simples e duplas
NO *inserir(NO *raiz, NO *novo){
	if (raiz == NULL){
		return novo;
	}

	if (novo->idEvento < raiz->idEvento){
		raiz->esq = inserir(raiz->esq, novo);
	} else if (novo->idEvento > raiz->idEvento){
		raiz->dir = inserir(raiz->dir, novo);
	} else {
		return raiz;
	}

	raiz->altura = maior(alturaNO(raiz->esq), alturaNO(raiz->dir)) + 1;

	// Cálculo do fator de balanceamento
	int fb = fatorBalanceamento(raiz);

	// Aplicação de rotações para balanceamento
	if (fb > 1 && novo->idEvento < raiz->esq->idEvento){
		return rotacaoLL(raiz);
	}
	if (fb < -1 && novo->idEvento > raiz->dir->idEvento){
		return rotacaoRR(raiz);
	}
	if (fb > 1 && novo->idEvento > raiz->esq->idEvento){
		return rotacaoLR(raiz);
	}
	if (fb < -1 && novo->idEvento < raiz->dir->idEvento){
		return rotacaoRL(raiz);
	}

	return raiz;
}

NO *menorValor(NO *no){
	NO *atual = no;
	while (atual->esq != NULL) {
		atual = atual->esq;
	}
	return atual;
}

// Remoção de eventos:
//	- Apenas eventos com status Resolvido podem ser removidos
//	- Rebalanceamento obrigatório após remoção
NO *remover(NO *raiz, int idEvento){
	if (raiz == NULL){
		return raiz;
	}

	if (idEvento < raiz->idEvento){
		raiz->esq = remover(raiz->esq, idEvento);
	} else if (idEvento > raiz->idEvento){
		raiz->dir = remover(raiz->dir, idEvento);
	} else {
		// Se for status "ativo" imprime mensagem de erro e retorna raiz
		if (raiz->status != RESOLVIDO){
			printf("\n FALHA! O evento %d ainda esta ATIVO e nao pode ser removido. \n", idEvento);
			return raiz;
		}

		if (raiz->esq == NULL || raiz->dir == NULL) {
			NO *temp = raiz->esq ? raiz->esq : raiz->dir;
			if (temp == NULL){
				temp = raiz;
				raiz = NULL;
			} else {
				*raiz = *temp;
			}
			free(temp);
		} else {
			NO *temp = menorValor(raiz->dir);
			raiz->idEvento       = temp->idEvento;
			raiz->tipo           = temp->tipo;
			raiz->nivelSeveridade = temp->nivelSeveridade;
			raiz->regiao         = temp->regiao;
			raiz->status         = temp->status;
			raiz->dataHora       = temp->dataHora;
			raiz->dir = remover(raiz->dir, temp->idEvento);
		}
	}

	if (raiz == NULL){
		return raiz;
	}

	raiz->altura = maior(alturaNO(raiz->esq), alturaNO(raiz->dir)) + 1;
	int fb = fatorBalanceamento(raiz);

	// Rebalanceamento
	if (fb > 1 && fatorBalanceamento(raiz->esq) >= 0) {
		return rotacaoLL(raiz);
	}
	if (fb > 1 && fatorBalanceamento(raiz->esq) < 0) {
		return rotacaoLR(raiz);
	}
	if (fb < -1 && fatorBalanceamento(raiz->dir) <= 0) {
		return rotacaoRR(raiz);
	}
	if (fb < -1 && fatorBalanceamento(raiz->dir) > 0) {
		return rotacaoRL(raiz);
	}

	return raiz;
}

// Busca de evento por ID
NO* buscarId(NO* raiz, int idEvento) {
	if (raiz == NULL || raiz->idEvento == idEvento){
		return raiz;
	}

	if (idEvento < raiz->idEvento){
		return buscarId(raiz->esq, idEvento);
	}

	return buscarId(raiz->dir, idEvento);
}