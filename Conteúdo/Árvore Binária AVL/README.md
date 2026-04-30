---

# 🌳 Árvores AVL 

Este diretório contém a implementação e revisão teórica sobre **Árvores Binárias Balanceadas (AVL)**.

---

## 📌 Conceito Base

Uma **árvore binária de busca (BST)** é considerada **balanceada** quando:

* A diferença de altura entre subárvores esquerda e direita de qualquer nó é:

  👉 **-1, 0 ou +1**

---

## ⚖️ Fator de Balanceamento (FB)

O **FB** é calculado como:

```
FB = Altura(esquerda) - Altura(direita)
```

### Valores possíveis:

* `0` → perfeitamente balanceado
* `+1` → esquerda maior
* `-1` → direita maior
* `±2` → ❌ árvore desbalanceada (precisa de rotação)

---

## 🌲 Árvores AVL

* Criadas em **1962 (Adelson-Velsky e Landis)**
* São **árvores binárias de busca auto-balanceadas**
* Garantem eficiência:

| Operação | Complexidade |
| -------- | ------------ |
| Busca    | O(log n)     |
| Inserção | O(log n)     |
| Remoção  | O(log n)     |

---

## 🔄 Quando ocorre o desbalanceamento?

Após:

* Inserção
* Remoção

➡️ É necessário:

1. Calcular o FB
2. Identificar o tipo de desbalanceamento
3. Aplicar rotação

---

## 🔁 Tipos de Rotações

### ✅ 1. Rotação Simples à Direita (LL)

**Caso:**

* FB = +2
* Inserção ocorreu na esquerda da esquerda

**Ação:**

* Filho esquerdo vira a nova raiz

---

### ✅ 2. Rotação Simples à Esquerda (RR)

**Caso:**

* FB = -2
* Inserção ocorreu na direita da direita

**Ação:**

* Filho direito vira a nova raiz

---

### 🔁 3. Rotação Dupla à Direita (LR)

**Caso:**

* FB = +2
* Inserção ocorreu na direita da esquerda

**Ação:**

1. Rotação à esquerda no filho
2. Rotação à direita no nó

---

### 🔁 4. Rotação Dupla à Esquerda (RL)

**Caso:**

* FB = -2
* Inserção ocorreu na esquerda da direita

**Ação:**

1. Rotação à direita no filho
2. Rotação à esquerda no nó

---

## 🧠 Resumo Rápido sobre Rotação

| Situação      | Tipo |
| ------------- | ---- |
| +2 e filho +1 | LL   |
| -2 e filho -1 | RR   |
| +2 e filho -1 | LR   |
| -2 e filho +1 | RL   |

---

## ⚙️ Fluxo do Código em C

### 📥 Inserção

1. Inserir como em uma BST
2. Atualizar alturas
3. Calcular FB
4. Verificar desbalanceamento
5. Aplicar rotação

---

### 🧮 Cálculo da Altura

* Altura = maior altura entre filhos + 1

---

### ⚖️ Cálculo do FB

```c
fb = altura(esq) - altura(dir);
```

---

### 🔄 Rebalanceamento

* Se `|FB| <= 1` → nada a fazer
* Se `|FB| > 1` → aplicar rotação adequada

---

## 🎯 Objetivo do Código

O código em C implementa:

* Estrutura de nó (valor + ponteiros)
* Inserção em árvore binária
* Cálculo de altura
* Cálculo de FB
* Identificação do tipo de rotação
* Rebalanceamento da árvore

---

## ⚠️ ATENÇÃO: 

* Sempre verifique o **FB primeiro**
* Lembre: AVL ≠ árvore qualquer (ela **se ajusta automaticamente**)
* Saber identificar os **4 casos de rotação é essencial**
* Entender o **fluxo inserção → cálculo → rotação**

---

## 🚀 Conclusão

Árvores AVL são fundamentais para garantir:

* **Busca rápida**
* **Estrutura balanceada**
* **Performance previsível**
