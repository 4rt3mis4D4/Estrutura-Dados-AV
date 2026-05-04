#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include "estrutura.h"

// Contador global de rotações 
extern int totalRotacoes;

// a) Gerenciamento da Árvore AVL

// Criação de nó
NO* criarNo(int id, int tipo, int severidade, int regiao);

// Altura de um nó
int alturaNO(NO *no);

// Inserção de eventos
NO* inserir(NO* raiz, NO* novo);

// Remoção de eventos
NO* remover(NO* raiz, int idEvento);

// Busca de evento por ID
NO* buscarId(NO* raiz, int idEvento);

#endif