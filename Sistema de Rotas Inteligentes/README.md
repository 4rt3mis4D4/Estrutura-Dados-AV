# 🚚 Sistema de Rotas Inteligentes para Entregas Urbanas

## 🎓 Disciplina

**Estruturas de Dados Avançadas**

## 👨‍🏫 Professor

**Marcelo Takashi Uemura**

## 👨‍🎓 Aluno

**Gabriela Pedroso dos Santos Pontes**

---

# 📖 Descrição do Projeto

Este projeto implementa um **Sistema de Rotas Inteligentes para Entregas Urbanas** utilizando conceitos de **Grafos**, uma das principais estruturas estudadas na disciplina de Estrutura de Dados.

O sistema representa uma cidade por meio de uma **Matriz de Adjacência**, onde:

* 📍 Os vértices representam pontos da cidade;
* 🛣️ As arestas representam ruas entre os pontos;
* 📏 Os pesos representam as distâncias entre os locais.

Além da representação do grafo, foram implementados três algoritmos clássicos:

* 🔍 **BFS (Busca em Largura)**;
* 🌳 **DFS (Busca em Profundidade)**;
* 🚀 **Dijkstra (Menor Caminho)**.

---

# 📂 Estrutura do Projeto

```text
Atividade Avaliativa - Estrutura de Dados/

├── main.c
├── grafo.h
├── grafo.c
├── bfs.c
├── dfs.c
├── dijkstra.c
├── Sistema_Rotas_Inteligentes_Entregas_Urbanas.dev
├── Makefile.win
```

---

# ⚙️ Funcionalidades

## 🗺️ 1. Exibir Matriz de Adjacência

Mostra a estrutura completa do grafo, apresentando todas as conexões entre os vértices e seus respectivos pesos.

Exemplo:

```text
0:   0   7   9   0   0  14
1:   7   0  10  15   0   0
2:   9  10   0  11   0   2
...
```

---

## 🔍 2. BFS (Busca em Largura)

Percorre o grafo nível por nível a partir de um vértice de origem.

Arquivo responsável:

```c
bfs.c
```

Objetivo:

* 🎯 Encontrar vértices próximos primeiro;
* 📡 Explorar o grafo em largura.

---

## 🌳 3. DFS (Busca em Profundidade)

Percorre o grafo explorando um caminho até o máximo possível antes de retroceder.

Arquivo responsável:

```c
dfs.c
```

Objetivo:

* 🔗 Explorar profundamente as conexões do grafo;
* 🔄 Demonstrar o uso de recursividade.

---

## 🚀 4. Algoritmo de Dijkstra

Calcula o menor caminho entre dois pontos do grafo considerando as distâncias das ruas.

Arquivo responsável:

```c
dijkstra.c
```

Exemplo de saída:

```text
Menor distancia de 0 ate 4: 20 unidades
Rota: 0 -> 2 -> 5 -> 4
```

---

# 🌐 Estrutura do Grafo Utilizada

O sistema cria automaticamente um grafo com 6 vértices:

```text
0 -----7----- 1
|\           /|
| 9       10  |
|  \       /  |
|   \     /   |
14   \   /   15
|     \ /     |
5 ---- 2 ---- 3
 \      \     |
  \      2    6
   \      \   |
    \      \  |
      ---- 4 --
         9
```

---

# 📁 Arquivos do Projeto

## 🏠 main.c

Responsável por:

* Criar o grafo;
* Inserir as arestas;
* Exibir o menu principal;
* Receber as entradas do usuário.

---

## 📘 grafo.h

Arquivo de cabeçalho contendo:

* Definição da estrutura Grafo;
* Constantes;
* Protótipos das funções.

---

## ⚙️ grafo.c

Implementa:

### ➕ criarGrafo()

Cria e inicializa a matriz de adjacência.

### 🔗 adicionarAresta()

Adiciona uma conexão entre dois vértices.

### 📊 exibirMatriz()

Mostra a matriz de adjacência.

---

## 🔍 bfs.c

Implementa o algoritmo de Busca em Largura utilizando fila.

---

## 🌳 dfs.c

Implementa o algoritmo de Busca em Profundidade utilizando recursão.

---

## 🚀 dijkstra.c

Implementa:

* 📏 Cálculo do menor caminho;
* 🛣️ Reconstrução da rota encontrada;
* 📍 Exibição da distância mínima.

---

# 💻 Como Executar no Dev-C++

## 1. 📂 Abrir o Projeto

Abra o arquivo:

```text
Sistema_Rotas_Inteligentes_Entregas_Urbanas.dev
```

---

## 2. 🔨 Compilar

No menu:

```text
Executar → Compilar
```

ou

```text
F9
```

---

## 3. ▶️ Executar

No menu:

```text
Executar → Executar
```

ou

```text
F10
```

---

## 4. 🚀 Compilar e Executar

```text
F11
```

---

# 💻 Como Executar no Visual Studio Code

## 1. 🛠️ Instalar um Compilador C

Recomenda-se:

### 🪟 Windows

Instalar:

* MinGW-w64

Verificar:

```bash
gcc --version
```

---

## 2. 📂 Abrir a Pasta do Projeto

No VS Code:

```text
Arquivo → Abrir Pasta
```

Selecione a pasta do projeto.

---

## 3. 🖥️ Abrir o Terminal

```text
Terminal → Novo Terminal
```

---

## 4. 🔨 Compilar Manualmente

Execute:

```bash
gcc main.c grafo.c bfs.c dfs.c dijkstra.c -o sistema_rotas
```

---

## 5. ▶️ Executar

Windows:

```bash
sistema_rotas.exe
```

Linux/Mac:

```bash
./sistema_rotas
```

---

# 📋 Menu do Sistema

Ao executar o programa será exibido:

```text
=========================================
    SISTEMA DE ROTAS DE ENTREGAS
=========================================

1 - Exibir matriz de adjacencia
2 - Executar BFS
3 - Executar DFS
4 - Encontrar menor caminho (Dijkstra)
5 - Sair
```

---

# 🧠 Conceitos de Estrutura de Dados Aplicados

* 🌐 Grafos
* 📊 Matriz de Adjacência
* 🔍 Busca em Largura (BFS)
* 🌳 Busca em Profundidade (DFS)
* 📥 Filas
* 🔄 Recursividade
* 🚀 Algoritmo de Dijkstra
* 🛣️ Caminho Mínimo
* 💾 Alocação Dinâmica de Memória

---

# 🎯 Objetivo Acadêmico

Este projeto tem como objetivo demonstrar a aplicação prática de estruturas de dados baseadas em grafos para resolver problemas de roteamento e otimização de caminhos em ambientes urbanos, utilizando algoritmos clássicos estudados na disciplina de Estrutura de Dados.

---

## 📜 Licença

Projeto desenvolvido exclusivamente para fins acadêmicos na disciplina de Estrutura de Dados.
