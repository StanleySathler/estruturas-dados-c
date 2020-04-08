## Coloração com flood-fill

- Declara Pilha pilha

- Pega cor c do pixel p selecionado
- Colore p com c
- Empilha p em pilha
- Enquanto pilha não estiver vazia
  - Desempilha p de pilha
  - Se vizinho de cima é da cor c
    - Colore vizinho de cima com c
    - Empilha vizinho de cima em pilha
  - Se vizinho de cima, à direita, é da cor c
    - Colore vizinho de cima, à direita, com c
    - Empilha vizinho de cima, à direita, em pilha
  - Se vizinho direito é da cor c
    - Colore vizinho direito com c
    - Empilha vizinho direito em pilha
  - Se vizinho de baixo, à direita, é da cor c
    - Colore vizinho de baixo, à direita, com c
    - Empilha vizinho de baixo, à direita, em pilha
  - Se vizinho de baixo é da cor c
    - Colore vizinho de baixo com c
    - Empilha vizinho de baixo em pilha
  - Se vizinho de baixo, à esquerda, é da cor c
    - Colore vizinho de baixo, à esquerda, com c
    - Empilha vizinho de baixo, à esquerda, em pilha
  - Se vizinho esquerdo é da cor c
    - Colore vizinho esquerdo com c
    - Empilha vizinho esquerdo em pilha
  - Se vizinho de cima, à esquerda, é da cor c
    - Colore vizinho de cima, à esquerda, com c
    - Empilha vizinho de cima, à esquerda, em pilha