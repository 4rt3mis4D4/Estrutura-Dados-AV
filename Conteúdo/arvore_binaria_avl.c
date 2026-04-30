#include <stdio.h>
#include <stdlib.h>

// Definição do nó da árvore AVL
typedef struct NO {
    int valor;
    int altura;
    struct NO *esq;
    struct NO *dir;
} NO;

// Função para calcular a altura de um nó
int altura_NO(struct NO *no) {
    if (no == NULL)
        return -1;
    return no->altura;
}

// Função para calcular o maior valor entre dois números
int maior(int a, int b) {
    return (a > b) ? a : b;
}

// Função para criar um novo nó
struct NO *novoNO(int valor) {
    struct NO *no = (struct NO *)malloc(sizeof(struct NO));
    no->valor = valor;
    no->altura = 0;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

// Função para realizar rotação simples à esquerda
struct NO *rotacaoRR(struct NO *raiz) {
    struct NO *no = raiz->dir;
    raiz->dir = no->esq;
    no->esq = raiz;
    raiz->altura = maior(altura_NO(raiz->esq), altura_NO(raiz->dir)) + 1;
    no->altura = maior(altura_NO(no->esq), altura_NO(no->dir)) + 1;
    return no;
}

// Função para realizar rotação simples à direita
struct NO *rotacaoLL(struct NO *raiz) {
    struct NO *no = raiz->esq;
    raiz->esq = no->dir;
    no->dir = raiz;
    raiz->altura = maior(altura_NO(raiz->esq), altura_NO(raiz->dir)) + 1;
    no->altura = maior(altura_NO(no->esq), altura_NO(no->dir)) + 1;
    return no;
}

// Função para realizar rotação dupla à esquerda-direita
struct NO *rotacaoLR(struct NO *raiz) {
    raiz->esq = rotacaoRR(raiz->esq);
    return rotacaoLL(raiz);
}

// Função para realizar rotação dupla à direita-esquerda
struct NO *rotacaoRL(struct NO *raiz) {
    raiz->dir = rotacaoLL(raiz->dir);
    return rotacaoRR(raiz);
}

// Função para calcular o fator de balanceamento
int fatorBalanceamento(struct NO *no) {
    if (no == NULL)
        return 0;
    return altura_NO(no->esq) - altura_NO(no->dir);
}

// Função de inserção em uma árvore AVL
struct NO *inserir(struct NO *raiz, int valor) {
    if (raiz == NULL)
        return novoNO(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);
    else
        return raiz; // Valor duplicado não permitido

    raiz->altura = maior(altura_NO(raiz->esq), altura_NO(raiz->dir)) + 1;

    int fb = fatorBalanceamento(raiz);

    // Casos de desbalanceamento
    if (fb > 1 && valor < raiz->esq->valor)
        return rotacaoLL(raiz);

    if (fb < -1 && valor > raiz->dir->valor)
        return rotacaoRR(raiz);

    if (fb > 1 && valor > raiz->esq->valor)
        return rotacaoLR(raiz);

    if (fb < -1 && valor < raiz->dir->valor)
        return rotacaoRL(raiz);

    return raiz;
}

// Função para encontrar o menor valor em uma subárvore
struct NO *menorValor(struct NO *no) {
    struct NO *atual = no;
    while (atual->esq != NULL)
        atual = atual->esq;
    return atual;
}

// Função de remoção
struct NO *remover(struct NO *raiz, int valor) {
    if (raiz == NULL)
        return raiz;

    // Busca pelo nó a ser removido
    if (valor < raiz->valor)
        raiz->esq = remover(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = remover(raiz->dir, valor);
    else {
        // Caso 1: Nó com zero ou um filho
        if (raiz->esq == NULL || raiz->dir == NULL) {
            struct NO *temp = raiz->esq ? raiz->esq : raiz->dir;
            if (temp == NULL) {
                temp = raiz;
                raiz = NULL;
            } else {
                *raiz = *temp;
            }
            free(temp);
        }
        // Caso 2: Nó com dois filhos
        else {
            struct NO *temp = menorValor(raiz->dir);
            raiz->valor = temp->valor;
            raiz->dir = remover(raiz->dir, temp->valor);
        }
    }

    // Se a árvore estiver vazia após a remoção
    if (raiz == NULL)
        return raiz;

    // Atualiza a altura
    raiz->altura = maior(altura_NO(raiz->esq), altura_NO(raiz->dir)) + 1;

    // Rebalanceamento
    int fb = fatorBalanceamento(raiz);

    // LL
    if (fb > 1 && fatorBalanceamento(raiz->esq) >= 0)
        return rotacaoLL(raiz);

    // LR
    if (fb > 1 && fatorBalanceamento(raiz->esq) < 0)
        return rotacaoLR(raiz);

    // RR
    if (fb < -1 && fatorBalanceamento(raiz->dir) <= 0)
        return rotacaoRR(raiz);

    // RL
    if (fb < -1 && fatorBalanceamento(raiz->dir) > 0)
        return rotacaoRL(raiz);

    return raiz;
}

// Função para imprimir a árvore em ordem
void imprimirEmOrdem(struct NO *raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->dir);
    }
}

// Função principal
int main() {
    struct NO *raiz = NULL;

    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 25);

    printf("Arvore AVL em ordem: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    raiz = remover(raiz, 20);

    printf("Arvore AVL apos a remocao do valor 20: ");
    imprimirEmOrdem(raiz);
    printf("\n");


    return 0;
}

