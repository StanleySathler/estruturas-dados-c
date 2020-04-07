### Exercício

O programa da Figura 4.4 (checa se cadeia de caracteres é palíndroma) não reconhece `"Amor a Roma"` como uma cadeia palíndroma. Use a função `toupper()`, declarada em `ctype.h`, para resolver esse problema (essa função converte uma letra minúscula em maiúscula).

### Solução

> Nota: esse algoritmo pode ser desenvolvido com diferentes maneiras. No livro, para praticar, a solução é desenvolvida com o auxílio de uma Pilha e uma Fila.

- Declara Pilha v_pilha
- Declara Fila v_fila
- Para cada i em [expressao]
  - Empilha i em v_pilha
  - Enfileira i em v_fila
- Para cada i em [v_fila]
  - Desempilha j de [v_pilha]
  - Se i != j
    - Retorna falso
- Retorna verdadeiro
